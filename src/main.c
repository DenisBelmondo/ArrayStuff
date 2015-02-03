#include <stdio.h>

#define TRUE 1 // False boolean
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
 * next, so on. So the output in this implementation would look like
 * this:
 * 
 * 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
 * 
 * 4 bytes in each int in an array of 5 ints. 4 * 5 = 20. So what you
 * must do to retrieve the amount of bytes in an int without the use
 * of a magic number, is this: sizeof(i[0]) which would get the number
 * of bytes in the first value of the array. Dividing the total sum of
 * bytes in the array which is [number of elements] * 4, you'd have to
 * divide all of that by 4 to get just the number of elements. That's
 * what this is doing.
 *  
 * Furthermore, make sure you make sure the limit of rndPos doesn't
 * exceed the limit of the array because you'll end up with something
 * like: 1, 2, 3, 4, 5, (fucked up number).
 * 
*/

void rndPrint()
{

	for (rndPos = 0; rndPos <= (sizeof(rndTable) / sizeof(rndTable[0]))-1; rndPos++) {
		printf("%d\n", rndTable[rndPos]);
	}

}
