/*
 * https://www.aceptaelreto.com/problem/statement.php?id=204
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int 
count_branch(char* buff, int* adornos, int* pos) {
	
	int elm = 0;
	int ad[2] = {0,0};

	*pos = *pos + 1;

	while (elm < 2) {
		if (buff[*pos] == 'Y') {
			if (!count_branch(buff, &ad[elm], pos))
				return 0;
			elm++;
			continue;
		}

		if (buff[*pos] == '*') {
			ad[elm] = 1;
		}

		elm++;
		*pos = *pos + 1;
	}

	*adornos = ad[0] + ad[1];

	if (abs(ad[0] - ad[1]) >= 2)
		return 0;
	
	return 1;

}


int 
main(int argc, char**argv) {

	int adornos;
	int pos;
	char buff[100001];

	while (fgets(buff, 100001, stdin)) {
		
		pos = 0;

		if (buff[0] == '.' || buff[0] == '*') {
			printf("OK\n");
			continue;
		}

		if (count_branch(buff, &adornos, &pos))
			printf("OK\n");
		else
			printf("KO\n");

	}

	return 0;

}
