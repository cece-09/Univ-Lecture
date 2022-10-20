#include "Graph_adj_array.h"

void Read_Graph_adj_array (int Vnum, vertex V[], int Enum, edge E[]) {
	
	// initialize the vertex and edge
	for (int i = 0; i < Vnum; i++) {
		V[i].name = i;
		V[i].f_hd = -1;
		V[i].r_hd = -1;
	}
	for (int i = 0; i < Enum; i++) {
		E[i].cost = 1;
		E[i].name = i;
		E[i].fp   = -1;
		E[i].rp   = -1;
	}

	int k = 0;
	while (k < Enum) {
		int i, j, cost;
		scanf_s("%d %d %d", &i, &j, &cost);

		E[k].vf = i;
		E[k].vr = j;

		if (V[i].f_hd == -1) {
			V[i].f_hd = k;
		}
		else {
			E[k].fp   = V[i].f_hd;
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

int DFS_Tree_adj_array(
	int     src,   // source node index
	int     Vnum,  // number of vertices
	vertex *V,     // vertex structure array (starting index 0)
	int     Enum,  // number of edges
	edge   *E      // edge structure array (starting index 0) 
) { 
	// visit src node
	V[src].flag = true;
	// if there is no adj node, return
	if (V[src].f_hd == -1 && V[src].r_hd == -1) {
		return 0;
	}

	int Tree_cost = 0;
	int direction = 0;   // front or rear
	int Eindex, Vindex;  // incident edge index and adj vertex index

	if (V[src].f_hd != -1) {
		direction = 1; // front
		Eindex = V[src].f_hd;
		Vindex = E[Eindex].vr;
	}
	else {
		direction = 0; // rear
		Eindex = V[src].r_hd;
		Vindex = E[Eindex].vf;
	}
	
	// find the adj vertex
	while (Eindex != -1) {
		// for one adj vertex, check if flag is false
		if (V[Vindex].flag == false) {
			// if so, count += Tree_cost and do DFS
			E[Eindex].flag = true;
			Tree_cost += E[Eindex].cost;
			Tree_cost += DFS_Tree_adj_array(Vindex, Vnum, V, Enum, E);
		}
		// next adj node
		if (direction == 1) {
			Eindex = E[Eindex].fp;
			Vindex = E[Eindex].vr;
		}
		else {
			Eindex = E[Eindex].rp;
			Vindex = E[Eindex].vf;
		}
	}

	return Tree_cost;
}
