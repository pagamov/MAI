#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "sort.h"

int pass = 1;
char q;
int number;

int main (int argc, char * argv[]) {
	Queue * Q = createQueue(10);
	printf("\na to add\nd to delete\n0 to delete all\n1 to get pop\n2 to push\n3 for sort\ns to see\nq for exit\n\n");
	while (pass) {
		scanf("%c", &q);
		switch (q) {
			case ('a'):
				addQueue(Q);
				break;
			case ('d'):
				deleteElemQueue(Q);
				break;
			case ('0'):
				deleteQueue(Q);
				break;
			case ('1'):
				printf("%d\n", popQueue(Q));
				break;
			case ('2'):
				printf("write: ");
		    scanf("%d", &number);
				pushQueue(Q, number);
				break;
			case ('3'):
				Q = qSortQueue(Q);
				break;
			case ('s'):
				printQueue(Q);
				printf(" count: %d\n", getCountQueue(Q));
				break;
			case ('q'):
				free(Q);
				pass = 0;
				break;
		}
	}
	return 0;
}
