#include "Graph_adj_list.h"
#include <queue>

extern void errorExit(const char *s);

SLList2 pool;
unsigned long UsedMemoryForArray = 0;

void Read_Graph_adj_list(int Vnum, vertex *V, int Enum, edge *E) {
	// initialize vertex array
	for (int i = 0; i < Vnum; i++) {
		V[i].name = i;
		V[i].flag = false;
	}

	int k = 0;
	while (k < Enum) {
		int i, j, cost;
		scanf_s("%d %d %d\n", &i, &j, &cost);

		// edge array
		E[k].cost = cost;
		E[k].name = k;
		E[k].flag = false;
		E[k].vf   = i;
		E[k].vr   = j;

		// push edge index to adjacent list
		SLL* adj_list_i = pool.allocSLL();
		SLL* adj_list_j = pool.allocSLL();
		adj_list_i->i = k;
		adj_list_j->i = k;

		V[i].S.push(adj_list_i);  
		V[j].S.push(adj_list_j);

		k++;
	}
}

void Free_Graph_adj_list(int Vnum, vertex *V) {
	// V �迭�� adjacency list�� ���Ҹ� pop()�� ����Ͽ�
	// ���  pool�� �ǵ��� �ش�
	int k;

	for (k = 0; k < Vnum; k++) {
		while (V[k].S.empty() == false) {
			pool.freeSLL(V[k].S.pop());
		}
	}
}

int BFS_Tree_adj_list(
	int     src,   // source node index
	int     Vnum,  // number of vertices
	vertex *V,     // vertex structure array (starting index 0)
	int     Enum,  // number of edges
	edge   *E     // edge structure array (starting index 0)
) {
	int Tree_cost = 0;

	// queue for BFS
	using namespace std;
	queue<int> q;

	// put src node to queue and set the flag true(visited)
	q.push(src);
	V[src].flag = true;

	while (q.empty() != true) {
		int i = q.front();
		q.pop();
		SLL* curr = V[i].S.top(); // search SLL

		// search adj list
		while (true) {
			int adj = E[curr->i].vr == i ? E[curr->i].vf : E[curr->i].vr;
			// push the vertex to queue and set the flag true(visited)
			if (V[adj].flag == false) {
				q.push(adj);
				V[adj].flag = true;

				// set the BFS tree edge's flag true
				E[curr->i].flag = true;
				Tree_cost += E[curr->i].cost;
			}
			if (curr->p == NULL)
				break;
			curr = curr->p; // next linked list
		}

	}
	return Tree_cost;
}

// SLL management functions
// �Ʒ� �Լ����� CSW3010_04_CPrg&DS.pdf��
//   �����Ͽ� �� �Լ����� ä�� ����.
// ���ø� �ʿ��ϹǷ� ť�� ��� �Լ��� �Ʒ� �Լ� ����Ʈ�� ����

// stack member fuctions
void sllStack2::push(SLL *p) {
	// insert p to the top of stack ST
	p->p = ST;
	ST = p;
}

SLL *sllStack2::pop(void) {
	// remove and return p at the top of ST
	SLL* p = ST;
	if (ST->p == NULL)
		ST = NULL;
	else
		ST = ST->p;
	return p;
}

SLL *sllStack2::top(void) {
	// return p at the top of ST
	return ST;
}

bool sllStack2::empty(void) {
	// return true if empty
	if (ST == NULL)
		return true;
	else
		return false;
}

// SLList2 member functions
SLL *SLList2::allocSLL(void) {		// allocate a SLL element
	SLL *p;
	if (SLL_pool == NULL) {
		p = (SLL*)malloc(sizeof(SLL));
		if (p == NULL) {
			errorExit("Memory allocation error(allocSLL)");
			exit(-1);
		}
		UsedMemoryForSLLs += sizeof(SLL);
		p->i = NONE;
	}
	else {
		p = SLL_pool;
		SLL_pool = p->p;
	}
	p->p = NULL;
	++SLL_cnt;
	return(p);
}

void SLList2::freeSLL(SLL *p) {		// free *p (move it to SLL_pool)
	if (p->i == NONE) {
		errorExit("This is already freed(freeSLL).");
	}
	p->i = NONE;
	p->p = SLL_pool;
	SLL_pool = p;
	--SLL_cnt;
}

void SLList2::freeSLL_pool(void) {	// clear SLL_pool
	SLL *p = SLL_pool;
	while (p != NULL) {
		SLL_pool = p->p;
		free(p);
		UsedMemoryForSLLs -= sizeof(SLL);
		p = SLL_pool;
	}
	if (SLL_cnt != 0) {
		errorExit("Non-zero SLL_cnt after cleanup.");
	}
}