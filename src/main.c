#include <stdio.h>

#define TRUE 1
#define FALSE 0

const int rndTable[5] = { 1, 2, 3, 4, 5 }; // const is read-only
int rndPos = 0;

void rndPrint(); // Prototype

int main()
{

	char c;
	
	while (TRUE) {
	
		printf("Print rndTable? (Y/N): ");
		scanf(" %c", &c); /* Remember to put a space before the 
							specifier so it doesn't count the newline
							as an inputted value */
		switch (c) {
			case 'Y':
			case 'y':
				rndPrint();
				break;
			case 'N':
			case 'n':
				printf("See ya!\n");
				return 0;
				break;
			default:
				printf("Please enter a valid character\n");
				break;
		}
	
	}

	return 0;

}

/*
 *
 * Getting the size of an array:
 * 
 * sizeof() returns the size of a variable _in byets_ to you.
 * ints are 4 bytes long so without doing the sizeof(i) / sizeof(i[0])
 * calculation, it will return the 4 bytes of each value in the table.
 * To clarify, you have 5 values in i, so you declared it like the
 * following:
 * 
 * i[5] = { ... }
 * 
 * What sizeof() would do is get all bytes from the first value, and
 * spit 'em out. Then it'd go to the next value, spit 'em out, then the
 * next, so on.
 *  
*/

void rndPrint()
{

	for (rndPos = 0; rndPos <= sizeof(rndTable) / sizeof(rndTable[0]); rndPos++) {
		printf("%d\n", rndPos);
	}

}
