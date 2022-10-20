#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int chooseOper(int, int, int, int, int, int);
int min(int, int, int);

void Edit_Distance(
	// inputs
	char* SS,                                   // Source string array (main에서 읽어서 제공)
	char* TS,                                   // Edited string array (상동)
	int ins_cost, int del_cost, int sub_cost,   // insertion, deletion, substitution cost
	// outputs
	int** Table,                                // Cost Table Calculated (2d array (|SS| + 1) x (|TS| + 1) will be set)
	char** SR,                                  // Source string ('*' implies insertion of a char to T)
	char** OP,                                  // Operation sequence ('i', 'd', 's', or '.' (nop))
	char** TR,                                  // Edited string ('*' implies deletion of a char from S)
	int* Mem_Allocated                          // allocation한 SR, OP, TR의 크기 합을 저장하여 메인에 전달.
) {
	// initialize Cost Table
	int SN = (int)strlen(SS) + 1; // cosider null string
	int TN = (int)strlen(TS) + 1;
	int ins_cnt = 0;
	int del_cnt = 0;
	
	for (int i = 0; i < SN; i++) {
		Table[i][0] = i * del_cost;
	}
	for (int j = 0; j < TN; j++) {
		Table[0][j] = j * ins_cost;
	}
	for (int i = 1; i < SN; i++) {
		for (int j = 1; j < TN; j++) {
			if (SS[i-1] == TS[j-1]) {
				Table[i][j] = Table[i - 1][j - 1];
			}
			else {
				Table[i][j] = min(Table[i][j - 1] + ins_cost,
					Table[i - 1][j] + del_cost,
					Table[i - 1][j - 1] + sub_cost);
			}			
		}
	}
	
	// backtrace to get SR, OP, TR size
	int i = SN-1;
	int j = TN-1;
	int child = -2; // init
	while (i > 0 && j > 0) {
		if (SS[i - 1] == TS[j - 1]) {
			i--; j--;
			//no need to count
		}			
		else {
			if (i > 0 && j > 0) {
				child = chooseOper(Table[i][j],
					Table[i][j - 1] + ins_cost,
					Table[i - 1][j] + del_cost,
					Table[i - 1][j - 1] + sub_cost, ins_cost, del_cost);
			}
			else if (i > 0 && j <= 0 && Table[i][j] == Table[i - 1][j] + del_cost) {
				child = -1;
			}
			else if (i <= 0 && j > 0 && Table[i][j] == Table[i][j - 1] + ins_cost) {
				child = 1;
			}

			if (child == 1) { ins_cnt++; j--; }
			else if (child == -1) { del_cnt++; i--; }
			else if (child == 0) { i--; j--; }
			else { exit(-1); } //error
		}
	}

	// allocate SR, OP, TR	
	int maxString = ((TN + del_cnt) > (SN + ins_cnt) ? (TN + del_cnt) : (SN + ins_cnt));	
	*SR = new char[maxString];
	*TR = new char[maxString];
	*OP = new char[maxString];
	(*SR)[maxString - 1] = 0;
	(*TR)[maxString - 1] = 0;
	(*OP)[maxString - 1] = 0;
	*Mem_Allocated = maxString * 3;

	// initialize SR, OP, TR
	i = SN - 1;
	j = TN - 1;
	int k = maxString - 2;
	for (k; k >= 0; k--) {
		if (SS[i - 1] == TS[j - 1]) {
			(*OP)[k] = '.';
			(*SR)[k] = SS[i - 1];
			(*TR)[k] = TS[j - 1];
			j--;
			i--;
		}
		else {
			if (i > 0 && j > 0) {
				child = chooseOper(Table[i][j],
					Table[i][j - 1] + ins_cost,
					Table[i - 1][j] + del_cost,
					Table[i - 1][j - 1] + sub_cost, ins_cost, del_cost);
			}
			else if (i > 0 && j <= 0 && Table[i][j] == Table[i-1][j]+del_cost) {
				child = -1;
			}
			else if (i <= 0 && j > 0 && Table[i][j] == Table[i][j - 1] + ins_cost) {
				child = 1;
			}

			if (child == 1) {
				(*OP)[k] = 'i';
				(*SR)[k] = '*';
				(*TR)[k] = TS[j - 1];
				j--;
			}
			else if (child == -1) {
				(*OP)[k] = 'd';
				(*SR)[k] = SS[i - 1];
				(*TR)[k] = '*';
				i--;
			}
			else if (child == 0) {
				(*OP)[k] = 's';
				(*SR)[k] = SS[i - 1];
				(*TR)[k] = TS[j - 1];
				j--;
				i--;
			}
			else { exit(-1); } //error
		}
	}
}

int min(int ins, int del, int sub) {
	int minVal = ins;
	
	if (ins < del) {
		if (sub < ins) {
			minVal = sub;
		}
		else {
			int minVal = ins;
		}
	}
	else {
		if (del < sub) {
			minVal = del;
		}
		else {
			minVal = sub;
		}
	}
	return minVal;
}

int chooseOper(int parent, int ins, int del, int sub, int ins_cost, int del_cost) {
	int rtn = -2;
	if (parent == ins) {
		if (ins == del && ins_cost > del_cost) {
			// choose del
			rtn = -1;
		}
		else {
			// choose ins
			rtn = 1;
		}
	}
	else if (parent == del) {
		rtn = -1;
	}
	else if (parent == sub) {
		rtn = 0;
	}

	return rtn;
}