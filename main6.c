#include <stdlib.h> 
#include <assert.h>
#include <stdio.h>

#define MEM_SIZE 10000

void init_heap(char slab[]);
char *my_malloc(char slab[], int numbytes);
void my_free(char slab[], char *p);

int main() {

	char *p[500] = { 0 };
	int i;
	int j;
	int PInd=0;
	int NB;
	char slab[MEM_SIZE] = { 0 }; // Memory that's being used   
	init_heap(slab);
	//I added this while loop as a way to control the program, if its not helpful for you feel free to remove it
	while (1) {
		printf("please enter a 1 for my_malloc or 2 for my_free then hit enter\n");
		scanf("%d", &i);
		if (i == 1) {
			printf("enter a number of bytes to be allocated\n");
			scanf("%d", &NB);
			p[PInd] = my_malloc(slab, NB);
			PInd++;
		}
		else if (i == 2) {
			printf("enter the pointer number (1 through 500) you would like to have freed\n");
			scanf("%d", &PInd);
			if (p[PInd] == 0) printf("sorry, invalid pointer\n");
			else {
				my_free(slab, p[PInd]);
				PInd = 0;
			}
		}
		else printf("invalid command\n");

		
	}
	
}