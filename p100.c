/*
 * https://www.aceptaelreto.com/problem/statement.php?id=100
 */

#include <stdio.h>
#include <stdlib.h>

int order(const void* a, const void* b);
int kaprekar_constant(int val);

int 
main(int argc, char**argv) {
	int it, r_it, val;

	scanf("%d", &r_it);

	for (it=0; it<r_it; ++it) {
		scanf("%d", &val);
		printf("%d\n", kaprekar_constant(val));
	}

	return 0;
}

int
kaprekar_constant(int val) {
	char max_val[5], min_val[5];
	int i, num = 0;

	min_val[4] = '\0';
	
	while (val != 6174) {
		sprintf(max_val, "%04d", val);
		qsort(max_val, 4, sizeof(char), order);
		
		for (i=0; i<4; ++i)
			min_val[i] = max_val[3-i];

		val = atoi(max_val) - atoi(min_val);
		if (val == 0)
			return 8;

		++num;
	}

	return num;
}

int 
order(const void* a, const void* b) {
	if (*((char*)a) > *((char*)b))
		return -1;
	else
		return 1;
}
