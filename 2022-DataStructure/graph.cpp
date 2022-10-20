#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;



typedef struct _node {
	int  v;
	int  e;
	bool flag;
	struct _node* p;
}node;
typedef struct _edge {
	int vf, vr;
	int cost;
	bool flag;
}edge;
typedef struct _tree {
	int i;
	struct _tree* left;
	struct _tree* rights;
}tree;

void read_graph(node*, int, edge*, int);
void free_graph(node*, int);

void DFS(node*, edge*, int, int);
void BFS(node*, edge*, int, int);
void connected(node*, edge*, int);
void flag_init(node*, int);

void is_SPT(node*, edge*, int, int);
int  min2(int, int);
void is_articul(node*, edge*, int, int*, int*, int, int);

int  find(int*, int);
void weighted_union(int*, int, int);
void heap_push(edge*, int*, int*, int);
int  heap_pop(edge*, int*, int*);
void up_heapify(edge*, int*, int*, int);
void down_heapify(edge*, int*, int*, int);
void swap(int*, int*);
void kruskal(node*, edge*, int, int, int*, int*, int*);

//
//void prim(node* V, edge* E, int Vnum, int Enum, int* heap, int src) {
//	int TN = 0;
//	node* v = &V[src];
//	while (TN <= Vnum - 1) {
//		int w = v->p->v;
//		int min_cost = E[v->p->e].cost;
//		while (v != NULL) {
//			if (V[w].flag == true) v = v->p;
//			else if (min_cost < E[V[w].e].cost) {
//
//			}
//		}
//	}
//}

int main() {
	int Vnum, Enum;
	node* V;
	edge* E;
	int src;
	int* dfn; int* low;
	int* heap;
	int* parent;

	scanf("%d %d %d", &Vnum, &Enum, &src);
	V = new node[Vnum];
	E = new edge[Enum];
	dfn = new int[Vnum];
	low = new int[Vnum];
	parent = new int[Vnum];
	heap = new int[Enum + 1];
	read_graph(V, Vnum, E, Enum);
	/*
	printf("\n** DFS **\n");
	DFS(V, E, Vnum, src);
	is_SPT(V, E, Vnum, Enum);
	flag_init(V, Vnum, E, Enum);

	printf("\n** BFS **\n");
	BFS(V, E, Vnum, src);
	flag_init(V, Vnum, E, Enum);

	printf("\n** connected components **\n");
	connected(V, E, Vnum);
	flag_init(V, Vnum, E, Enum);

	printf("\n** articulation point\n");
	
	int num = 0; int* num_ptr = &num;
	for (int i = 0; i < Vnum; i++) { dfn[i] = -1; low[i] = -1; }

	dfnlow(V, E, dfn, low, num_ptr, src, -1);
	for (int i = 0; i < Vnum; i++) {
		is_articul(V, E, Vnum, dfn, low, i, src);
	}
	*/
	
	int tmp = 0; int* size = &tmp;
	kruskal(V, E, Vnum, Enum, heap, size, parent);

	/* free */
	free_graph(V, Vnum);
	delete[] V;
	delete[] E;
	delete[] dfn; delete[] low;
	delete[] parent;
	delete[] heap;
	return 0;
}


void read_graph(node* V, int Vnum, edge* E, int Enum) {
	int vf, vr, cost;
	node* tmp;

	/* initalize */
	for (int i = 0; i < Vnum; i++) {
		V[i].e = -1;
		V[i].v = i;
		V[i].flag = false;
		V[i].p = NULL;
	}
	for (int i = 0; i < Enum; i++) {
		E[i].vf = -1; E[i].vr = -1;
		E[i].cost = -1;
		E[i].flag = false;

	}

	for (int i = 0; i < Enum; i++) {
		vf, vr, cost;
		scanf("%d %d %d", &vf, &vr, &cost);

		E[i].vf = vf; E[i].vr = vr; E[i].cost = cost;
		node* n1 = (node*)malloc(sizeof(node));
		node* n2 = (node*)malloc(sizeof(node));
		if (n1 == NULL || n2 == NULL) exit(-1);

		n1->v = vf; n1->e = i; n1->flag = false; n1->p = NULL;
		n2->v = vr; n2->e = i; n2->flag = false; n2->p = NULL;
		if (V[vf].p == NULL) V[vf].p = n2;
		else {
			tmp = V[vf].p;
			n2->p = tmp;
			V[vf].p = n2;
		}
		if (V[vr].p == NULL) V[vr].p = n1;
		else {
			tmp = V[vr].p;
			n1->p = tmp;
			V[vr].p = n1;
		}
	}
}
void free_graph(node* V, int Vnum) {
	for (int i = 0; i < Vnum; i++) {
		node* curr = V[i].p;
		while (curr != NULL) {
			node* next = curr->p;
			free(curr);
			curr = next;
		}
	}
}

/* elementary graph operations */
void DFS(node* V, edge* E, int Vnum, int src) {
	node* w = &V[src];
	V[src].flag = true;

	printf("%2d ", src);
	while (w != NULL) {
		if (V[w->v].flag != true) {
			if (w->e != -1) E[w->e].flag = true;
			DFS(V, E, Vnum, w->v);
		}
		w = w->p;
	}
}
void BFS(node* V, edge* E, int Vnum, int src) {
	int v;
	node* w;
	queue<int>q;
	q.push(src);
	V[src].flag = true;
	while (!q.empty()) {
		v = q.front(); q.pop();
		w = &V[v];
		w->flag = true;

		printf("%2d ", w->v);
		while (w != NULL) {
			if (V[w->v].flag != true) {
				V[w->v].flag = true;
				if (w->e != -1) E[w->e].flag = true;
				q.push(w->v);
			}
			w = w->p;
		}
	}
}
void connected(node* V, edge* E, int Vnum) {
	for (int i = 0; i < Vnum; i++) {
		if (V[i].flag == false) {
			DFS(V, E, Vnum, i);
			printf("\n");
		}
	}
}
void flag_init(node* V, int Vnum, edge* E, int Enum) {
	for (int i = 0; i < Vnum; i++) {
		V[i].flag = false;
	}
	for (int i = 0; i < Enum; i++) {
		E[i].flag = false;
	}
}

/* non cost spanning tree */
void is_SPT(node* V, edge* E, int Vnum, int Enum) {
	int tree_edge = 0;
	for (int i = 0; i < Enum; i++) {
		if (E[i].flag == true) tree_edge++;
	}

	if (tree_edge == Vnum - 1) {
		printf("\n** spanning tree.\n");
	}
	else {
		printf("\n** not a spanning tree.\n");
	}
}

/* biconnected components */
int  min2(int a, int b) {
	if (a > b) return b;
	else return a;
}
void dfnlow(node* V, edge* E, int* dfn, int* low, int* num, int u, int v) {
	node* curr = &V[u];
	int w;
	dfn[u] = *num; low[u] = *num; (*num)++;
	printf("%2d ", u);

	while (curr != NULL) {
		w = curr->v;
		if (dfn[w] < 0) {
			if (curr->e != -1) E[curr->e].flag = true;
			dfnlow(V, E, dfn, low, num, w, u);
			low[u] = min2(low[u], low[w]);
		}
		else if (w != v) {
			low[u] = min2(low[u], dfn[w]);
		}
		curr = curr->p;
	}
}
void is_articul(node* V, edge* E, int Vnum, int* dfn, int* low, int u, int src) {
	if (u == src) {
		/* root node */
		int child = 0;
		node* curr = &V[u];
		while (curr != NULL) {
			if (curr->e != -1 &&
				E[curr->e].flag == true) {
				child++;
			}
			if (child > 1) break;
			curr = curr->p;
		}
		if (child > 1) printf("\n%d is articulation point", u);
		return;
	}
	else {
		/* non root node */
		for (int i = u + 1; i < Vnum; i++) {
			if (low[i] >= dfn[u]) {
				printf("\n%d is articulation point", u);
				return;
			}
		}
	}
}

/* minimum spanning cost tree */
int  find(int* parent, int u) {
	while (parent[u] >= 0) {
		u = parent[u];
	}
	return u;
}
void weighted_union(int* parent, int u, int v) {
	int tmp = parent[u] + parent[v]; // number
	if (parent[u] > parent[v]) {
		parent[u] = v;   // v is a root node
		parent[v] = tmp; // parent[root] = -(number of nodes in tree)
	}
	else {
		parent[v] = u;
		parent[u] = tmp;
	}
}
void heap_push(edge* E, int* heap, int* size, int i) {
	int last = (*size) + 1;
	heap[last] = i; // push in the last index.
	(*size)++;
	up_heapify(E, heap, size, last);
}
int  heap_pop(edge* E, int* heap, int* size) {
	int top = heap[1];
	heap[1] = heap[*size]; // last elem -> first index

	heap[*size] = -1;
	(*size)--;
	down_heapify(E, heap, size, 1);
	return top; // return minimum cost edge index
}
void up_heapify(edge* E, int* heap, int* size, int i) {
	int index = i;
	int parent = index / 2;

	while (parent >= 1) {
		if (E[heap[index]].cost > E[heap[parent]].cost) break;
		swap(&heap[parent], &heap[index]);
		index = parent;
		parent = index / 2;
	}
}
void down_heapify(edge* E, int* heap, int* size, int i) {
	int index = i;
	int left = index * 2;
	int right = left + 1;

	while (left <= *size) {
		if (right <= *size && E[heap[left]].cost > E[heap[right]].cost) left = right;
		if (E[heap[index]].cost < E[heap[left]].cost) break;
		swap(&heap[index], &heap[left]);
		index = left;
		left = index * 2;
		right = left + 1;
	}
}
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void kruskal(node* V, edge* E, int Vnum, int Enum, int* heap, int* size, int* parent) {
	/* initialize heap and parent arr */
	heap[0] = -1;
	int tree_cost = 0;
	for (int i = 0; i < Enum; i++) {
		heap_push(E, heap, size, i);
	}
	for (int i = 0; i < Vnum; i++) {
		parent[i] = -1;
	}

	/* flag spanning tree */
	int TN = 0;
	while ((*size) > 0) {
		int e = heap_pop(E, heap, size);
		if (E[e].flag != 1) {
			int r1 = find(parent, E[e].vf);
			int r2 = find(parent, E[e].vr);
			if (r1 == r2) { continue; }  // if root is the same
			else {
				E[e].flag = true; // in T				
				tree_cost += E[e].cost;
				TN++;
				printf("%d %d %d\n", E[e].vf, E[e].vr, E[e].cost);
				weighted_union(parent, r1, r2);
			}
		}
	}
}