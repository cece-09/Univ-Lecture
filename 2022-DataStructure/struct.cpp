#include <stdio.h>
#include <stdlib.h>

/* vertex and edge strct */
typedef struct _vertex {
	int  fp, rp;
	bool flag;
}vertex;
typedef struct _edge {
	int  fp, rp;
	int  vf, vr;
	int  cost;
	bool flag;
}edge;
typedef struct _node {
	int i;
	struct _node *p;
}node;

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
class stk {
private:
	node* ST;
public:
	void push(node* p) {
		p->p = ST;
		ST = p;
	}
	node* pop() {
		node* p = ST;
		if (ST->p == NULL) ST = NULL;
		else ST = ST->p;

		return p;
	}
	node* top() {
		return ST;
	}
	bool empty() {
		if (ST == NULL)
			return true;
		else
			return false;
	}
};
class que {
private:
	node* QF;
	node* QR;
public:
	void enq(node* p) {
		if (QF == NULL) {
			p->p = NULL;
			QF = p;
		}
		else {
			QR->p = p;
			QR = p;
		}
	}
	node* deq() {
		QF = QF->p;
		return QF;
	}
	bool empty() {
		if (QF == NULL) return true;
		else return false;
	}
};
stk ST;
que Q;

/* min cost edge heap operations */
class minimum_cost_edge_heap {
private:
	edge* E;
	int* heap;
	int* size;
	int index;
public:
	void push(edge* E, int* heap, int* size, int index);
	int  pop(edge* E, int* heap, int* size);
	void up_heapify(edge* E, int* heap, int* size, int index);
	void down_heapify(edge* E, int* heap, int* size, int index);
};
void minimum_cost_edge_heap::push(edge* E, int* heap, int* size, int i) {
	int last = (*size) + 1;
	heap[last] = i; // push in the last index.
	(*size)++;
	up_heapify(E, heap, size, last);
}
int  minimum_cost_edge_heap::pop(edge* E, int* heap, int* size) {
	int top = heap[1];
	heap[1] = heap[*size]; // last elem -> first index

	heap[*size] = -1;
	(*size)--;
	down_heapify(E, heap, size, 1);
	return top; // return minimum cost edge index
}
void minimum_cost_edge_heap::up_heapify(edge* E, int* heap, int* size, int i) {
	int index = i;
	int parent = index / 2;

	while (parent >= 1) {
		if (E[heap[index]].cost > E[heap[parent]].cost) break;
		swap(&heap[parent], &heap[index]);
		index = parent;
		parent = index / 2;
	}
}
void minimum_cost_edge_heap::down_heapify(edge* E, int* heap, int* size, int i) {
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

/* DFS/BFS operation */
class graph_search {
private:
	vertex* V;
	edge* E;
	int Vnum;
	int Enum;
	int src;
public:
	void DFS_SPT(vertex* V, edge* E, int Vnum, int Enum, int src);
	void BFS_SPT(vertex* V, edge* E, int Vnum, int Enum, int src);	
	void print_SPT(vertex* V, edge* E, int Vnum, int Enum);
	void connected();
};
void graph_search::DFS_SPT(vertex* V, edge* E, int Vnum, int Enum, int src) {
	node* n;
	n->i = src; n->p = NULL;
	ST.push(n);
	while (!ST.empty()) {
		node* v;
		v = ST.pop();
		/* get adj */
		int e = V[v->i].fp;
		while (e != -1 && E[e].flag == false) {
			if (V[E[e].vr].flag == false) {
				node u;
				u.i = E[e].vr;
				u.p = NULL;
				ST.push(&u);
				V[u.i].flag = true;
			}			
			e = E[e].fp;
		}
		e = V[v->i].rp;
		while (e != -1 && E[e].flag == false) {
			if (V[E[e].vf].flag == false) {
				node u;
				u.i = E[e].vf;
				u.p = NULL;
				ST.push(&u);
				V[u.i].flag = true;
			}
			e = E[e].rp;
		}
	}
}
void graph_search::BFS_SPT(vertex* V, edge* E, int Vnum, int Enum, int src) {
	node* n;
	n->i = src; n->p = NULL;
	Q.enq(n);
	while (!Q.empty()) {
		n = Q.deq();
		int e = V[n->i].fp;
		while (e != -1) {
			if (V[E[e].vr].flag == false) {
				node u;
				u.i = E[e].vr;
				u.p = NULL;
				Q.enq(&u);
				V[u.i].flag = true;
			}
		}
		e = V[n->i].fp;
		while (e != -1) {
			if (V[E[e].vf].flag == false) {
				node u;
				u.i = E[e].vf;
				u.p = NULL;
				Q.enq(&u);
				V[u.i].flag = true;
			}
		}
	}
}
void graph_search::print_SPT(vertex* V, edge* E, int Vnum, int Enum) {
	for (int i = 0; i < Enum; i++) {
		if (E[i].flag == true) {
			printf("e%d (%d, %d)\n", i, E[i].vf, E[i].vr);
		}		
	}
}

