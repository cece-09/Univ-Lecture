#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _vertex vertex;
typedef struct _edge   edge;


/* functions */
void kruskal(FILE*, vertex*, int, edge*, int, int*, int*, int*);
void heap_push(edge*, int*, int*, int);
void up_heapify(edge*, int*, int*, int);
void down_heapify(edge*, int*, int*, int);
int  heap_pop(edge*, int*, int*);
void swap(int*, int*);
int  find(int*, int);
void weighted_union(int*, int, int);
void read_graph(FILE*, vertex*, edge*, int, int);


int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("usage: ./fp1 input_filename\n");
		exit(-1);
	}
	const char* filename = argv[1];

	/* variables */
	vertex* V; int Vnum;
	edge* E;   int Enum;
	int tmp = 0;
	int* edge_heap;
	int* heap_size = &tmp;
	int* parent;
	clock_t start, end; double exetime;

	/* file open */
	FILE* fp_r = fopen(filename, "r");
	if (fp_r == NULL) {
		printf("The input file does not exist.\n");
		exit(-1);
	}
	FILE* fp_w = fopen("fp1_result.txt", "w");
	if (fp_w == NULL) exit(-1);

	/* create arrays */
	fscanf(fp_r, "%d", &Vnum);
	fscanf(fp_r, "%d", &Enum);
	V = (vertex*)malloc(sizeof(vertex) * Vnum);
	E = (edge*)malloc(sizeof(edge) * Enum);
	edge_heap = (int*)malloc(sizeof(int) * (Enum + 1));
	parent = (int*)malloc(sizeof(int) * Vnum);
	if (V == NULL || E == NULL || edge_heap == NULL || parent == NULL) { exit(-1); }

	/* read graph */
	read_graph(fp_r, V, E, Vnum, Enum);

	start = clock();

	/* kruskal */
	kruskal(fp_w, V, Vnum, E, Enum, edge_heap, heap_size, parent);

	/* print execute time */
	end = clock();
	exetime = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("output written to fp1_result.txt\n");
	printf("running time : %.6f seconds\n", exetime);

	/* dealloc */
	free(V);
	free(E);
	free(edge_heap);
	free(parent);
	fclose(fp_r);
	fclose(fp_w);
	return 0;
}

/* kruskal */
void kruskal(FILE* fp, vertex*V, int Vnum, edge*E, int Enum, int*heap, int* size, int* parent) {
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
	while((*size) > 0) {
		int e = heap_pop(E, heap, size);
		if (E[e].flag != 1) {
			int r1 = find(parent, E[e].vf);
			int r2 = find(parent, E[e].vr);
			if (r1 == r2) { continue; }  // if root is the same
			else {
				E[e].flag = 1; // in T				
				tree_cost += E[e].cost;
				TN++;
				fprintf(fp, "%d %d %d\n", E[e].vf, E[e].vr, E[e].cost);
				weighted_union(parent, r1, r2);
			}
		}
	}	

	fprintf(fp, "%d\n", tree_cost);
	if (TN == (Vnum - 1)) { // if number of edges in SPT == Vnum - 1
		fprintf(fp, "CONNECTED\n");
	}
	else {
		fprintf(fp, "DISCONNECTED\n");
	}
}

/* union and find */
int find(int* parent, int u) {
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



/* read graph from text */
void read_graph(FILE* fp, vertex* V, edge* E, int Vnum, int Enum) {
	for (int i = 0; i < Vnum; i++) { // initialize V
		V[i].fp = -1;
	}
	int i = 0;
	while (!feof(fp)) {
		int v1, v2, cost;
		fscanf(fp, "%d %d %d", &v1, &v2, &cost);
		E[i].vf = v1;
		E[i].vr = v2;
		E[i].cost = cost;
		E[i].fp = -1;

		int e1 = V[v1].fp;
		int e2 = V[v2].fp;

		if (e1 != -1) {
			E[i].fp = e1;
			V[v1].fp = i;
		}
		else V[v1].fp = e1;

		if (e2 != -1) {
			E[i].fp = e2;
			V[v2].fp = i;
		}
		else V[v2].fp = e2;

		i++;
	}
}