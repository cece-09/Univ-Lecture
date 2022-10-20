#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <queue>

#define NONE -1

typedef struct elm_edge {
	int  vf, vr;  // e = (vf, vr) where vf, vr are vertex array indices
	int  cost;    // edge cost
	bool flag;    // true if the edge is in the SP spanning tree, false otherwise 
	int  fp, rp;  // adj list ptr of forward and reverse (-1 if none)
} edge;

typedef struct elm_vertex {
	int  f_hd, r_hd;	// adj list header(-1 if none)
	int  distance;		// distance from src to this vertex
	int  heap_idx;		// minHeap index
	bool inS;			// true if SP length found(true when move from V-S to S) 
} vertex;

void Error_Exit(const char *s);

/* for heap operation */
void heap_push(vertex*, int*, int*, int);
void heap_adjust(vertex*, int*, int*, int);
int  heap_pop(vertex*, int*, int*);

/* for swap and cross reference */
void vertex_heap_idx_swap(vertex*, int*, int, int);
void heap_elem_swap(int*, int*);


int SPT_Dijkstra(
	int src,	// source vertex index
	// graph structure array
	// 1. the adjacency list structure is the same as PHW02
	// 2. additional fields are added for Dijkstra's algorithm(see .h file)
	int Vnum, vertex *V,	// Vertex array size and the array
	int Enum, edge *E,		// Edge array size and the array

	int *minHeap	// array for min heap (array size = Vnum+1)
		// heap index range is 1 ~ (Vnum - 1) note: src must not in the initial heap
		// just arry is passed. must construct min-heap in this function

	// OUTPUT
	// 1. V[].distance : shortest path length from src to this vertex
	// 2. shortest path spanning tree : set E[].flag = true if the edge is in the tree
	// 3. return the sum of edge costs in the shortest path spanning tree.
	//    should be small as possible (think a way to make it small)
) {
	int treeCost = 0;
	// *** 이 함수를 작성하자 ***
	// 반드시 min-heap을 사용하여 O((n+m)logn) 알고리즘을 구현해야 한다(아니면 trivial한 프로그램임)
	// heap 연산 등 필요한 함수는 자유롭게 작성하여 추가한다.
	// 그러나 global 변수, dynamic array 등은 추가로 사용하지 않는다(실제로 필요 없다)
	
	int const INF  = 1000000000;

	// initialize distance
	for (int i = 0; i < Vnum; i++) {
		if (i == src) {
			V[i].distance = 0;
			V[i].inS = true;
		}
		else V[i].distance = INF;
	}

	// check adjacent vertices
	for (int i = 0; i < Enum; i++) {
		if (E[i].vf == src) {
			V[E[i].vr].distance = E[i].cost;
		}
		else if (E[i].vr == src) {
			V[E[i].vf].distance = E[i].cost;
		}
	}
	
	// construct minHeap {V-{s}}
	minHeap[0] = -1;
	int k = 1;
	int tmp = 0;
	int* heap_size = &tmp;

	for (int i = 0; i < Vnum; i++) {
		if (i == src) {
			V[i].heap_idx = -1;
		}
		else {			
			heap_push(V, minHeap, heap_size, i);
		}		
	}
		
	// get shortes path by Dijkstra's Algorithm
	int u, v, e;
	for (int i = 0; i < Vnum - 2; i++) {
		// curr is minimum distance from src
		u = heap_pop(V, minHeap, heap_size); // delete from minHeap
		V[u].inS = true;

		// update distance of adjacent vertices from curr
		if (V[u].f_hd != -1) { // forward
			e = V[u].f_hd;			
			while (e != -1) {
				v = E[e].vr;
				if (V[v].inS == false &&
					(V[u].distance + E[e].cost) < V[v].distance) {
					
					V[v].distance = V[u].distance + E[e].cost;           // update distance
					heap_adjust(V, minHeap, heap_size, V[v].heap_idx);   // cross reference
					
				}
				e = E[e].fp;
			}
		}
		if (V[u].r_hd != -1) { // reverse
			e = V[u].r_hd;			
			while (e != -1) {
				v = E[e].vf;
				if (V[v].inS == false &&
					(V[u].distance + E[e].cost) < V[v].distance) {
					V[v].distance = V[u].distance + E[e].cost;           // update distance
					heap_adjust(V, minHeap, heap_size, V[v].heap_idx);   // cross reference
					
				}
				e = E[e].rp;
			}
		}
	}

	// Dijkstra Backtracing
	for (int i = 0; i < Vnum; i++) {
		if (i == src) continue;

		int u = i;
		int path = -1; int prev = -1;
		
		while (u != src) {
			if (V[u].f_hd != -1) {
				int e = V[u].f_hd;
				while (e != -1) {
					int v = E[e].vr;
					if (V[u].distance - E[e].cost == V[v].distance) {						
						path = e; v = prev;
						break;
					}
					e = E[e].fp;
				}
			}
			if (V[u].r_hd != -1) {
				int e = V[u].r_hd;
				while (e != -1) {
					int v = E[e].vf;
					if (V[u].distance - E[e].cost == V[v].distance) {
						path = e; v = prev;
						break;
					}
					e = E[e].rp;
				}
			}
			if (E[path].flag == false) {
				E[path].flag = true;
				treeCost += E[path].cost;
				u = prev;
			}
			else break;
		}		
	}

	return treeCost;
}

/* for heap operation */
void heap_push(vertex* V, int* heap, int* size, int data) {
	(*size)++;
	heap[*size] = data;
	V[data].heap_idx = *size;

	int index = *size;
	int parent = index / 2;
	int parentData, indexData;

	while (parent >= 1) {
		parentData = V[heap[parent]].distance;
		indexData = V[heap[index]].distance;

		if (parentData < indexData) break;
		heap_elem_swap(&heap[parent], &heap[index]);
		vertex_heap_idx_swap(V, heap, parent, index);

		index = parent;
		parent = index / 2;
	}
}
void heap_adjust(vertex* V, int* heap, int* size, int index) {
	int left = index * 2;
	int right = left + 1;
	int parent = index / 2;

	while (parent >= 1) {
		if (V[heap[index]].distance < V[heap[parent]].distance) {
			heap_elem_swap(&heap[index], &heap[parent]);
			vertex_heap_idx_swap(V, heap, index, parent);
		}
		else break;

		index = parent;
		parent = index / 2;
	}

	while (left <= *size) {
		if (right <= *size && V[heap[left]].distance > V[heap[right]].distance) left = right;
		if (V[heap[index]].distance > V[heap[left]].distance) {
			heap_elem_swap(&heap[index], &heap[left]);
			vertex_heap_idx_swap(V, heap, index, left);
		}
		else break;

		index = left;
		left = index * 2;
		right = left + 1;
	}
}
int  heap_pop(vertex* V, int* heap, int* size) {
	int top = heap[1];
	heap[1] = heap[*size];
	V[heap[1]].heap_idx = 1; // delete from heap
	V[top].heap_idx = -1;

	heap[*size] = -2;
	(*size)--;
	heap_adjust(V, heap, size, 1);
	return top;
}

/* for swap and cross reference */
void vertex_heap_idx_swap(vertex* V, int* heap, int i, int j) {
	V[heap[i]].heap_idx = i;
	V[heap[j]].heap_idx = j;
}
void heap_elem_swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Read_Graph(int Vnum, vertex *V, int Enum, edge *E) {
	// Graph 자료구조를 만드는 함수
	// *** 이 함수를 추가하자 ***
	// PHW02의 Read_Graph_adj_array()를 이 과제의 자료구조에 맞춰 살짝 수정하여 사용한다
	// 즉, Read_Graph_adj_array()에서 불필요한 내용을 제거한 후 사용.

	// initialize the vertex and edge
	for (int i = 0; i < Vnum; i++) {
		V[i].f_hd = -1;
		V[i].r_hd = -1;
		V[i].inS = false;
	}
	for (int i = 0; i < Enum; i++) {
		E[i].fp = -1;
		E[i].rp = -1;
		E[i].flag = false;
	}

	int k = 0;
	while (k < Enum) {
		int i, j, cost;
		scanf_s("%d %d %d", &i, &j, &cost);

		E[k].vf = i;
		E[k].vr = j;
		E[k].cost = cost;

		if (V[i].f_hd == -1) {
			V[i].f_hd = k;
		}
		else {
			E[k].fp = V[i].f_hd;
			V[i].f_hd = k;
		}

		if (V[j].r_hd == -1) {
			V[j].r_hd = k;
		}
		else {
			E[k].rp = V[j].r_hd;
			V[j].r_hd = k;
		}
		k++;
	}
}

// the following functions are for testing if the submitted program is correct.
int  Tree_Check(int src, int Vnum, vertex *V, int Enum, edge *E, int *visited); // check if spanning tree
bool SPT_test(int src, int Vnum, vertex *V, int Enum, edge *E, int *minHeap);

int main ( void ) {
	int		src;
	vertex *V;		int Vnum;
	edge   *E;		int Enum;
	int    *minHeap;
	int    Tree_cost;
	int    Tnum; 		// # of test cases
	clock_t start, finish;
	double cmpt;

	scanf_s("%d", &Tnum);		// read # of tests

	for (int t = 0; t < Tnum; t++ ) {
		scanf_s("%d %d %d", &Vnum, &Enum, &src);
		V = new vertex [Vnum];
		E = new edge [Enum];
		minHeap = new int[Vnum + 1];	// heap array allocation
		if ( V == NULL || E == NULL || minHeap == NULL ) {
			Error_Exit("Memory Allocation Error");
		}
		Read_Graph(Vnum, V, Enum, E);

		/**/start = clock();	// start timer

		Tree_cost = SPT_Dijkstra(src, Vnum, V, Enum, E, minHeap);	// code by students

		/**/finish = clock();	// stop timer
		cmpt = ((double)(finish - start)) / (double)CLK_TCK;

		// 아래 Tree_Check와 SPT_test 함수는 첨부한 SPT_test.obj 파일에 있다.
		// 이 테스트에서 오류로 인하여 프로그램이 정지하면 뭔가 잘못된 것이다(제출해도 0점)
        if (Tree_Check(src, Vnum, V, Enum, E, minHeap) == 0) {
			Error_Exit("   ERROR The result is not a spanning tree");
		}
		if (SPT_test(src, Vnum, V, Enum, E, minHeap) == false) {
			Error_Exit("** Something wrong in applying Dijkstra's");
		}
		if ( t != 0 ) 
			printf("\n");

		printf("**T%d (Dijkstra) (V = %d, E = %d, time = %.3f sec) Tree Cost = %d\n", 
			t+1, Vnum, Enum, cmpt, Tree_cost);

		delete [] minHeap; delete [] V; delete [] E;
	}
	return 0;
}

void Error_Exit (const char *s ) {
  printf("%s\n", s);
  exit(-1);
}
