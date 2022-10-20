#define _CRT_NO_SECURE_WARNING
#include <stdio.h>
#include <stdlib.h>

/* These are the pseudo code
* ----------------------------
* void fast_transpose(term a[], term b[]) {
	// b is set to the transpose of a
	int row_terms[MAX_COL], starting_pos[MAX_COL];
	int i, j, num_cols = a[0].col, num_terms = a[0].value;
	b[0].row = num_cols; b[0].col = a[0].row;
	b[0].value = num_terms;
	if (num_terms > 0) { // non-zero matrix
		for (i = 0; i < num_cols; i++) row_terms[i] = 0;
		for (i = 1; i <= num_terms; i++) row_terms[a[i].col]++;
		starting_pos[0] = 1;
		for (i = 1; i < num_cols; i++)
			starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];
		for (i = 1; i <= num_terms; i++) {
			j = starting_pos[a[i].col]++;
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
		}
	}
}
*/