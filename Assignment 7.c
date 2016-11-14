#include <stdio.h> 

void Palindrome(char Array[], int start, int j, int End, int length, char misfits[], int mcnt);
void parenPrint(int n, int i, int L, int R, int Rcnt, int Lcnt);

void generateAllMatchedParens(int n) {
	int i;
	int j;
	int Rcnt=0; //keep track of how many rights to follow a left with initially
	int L = 0;
	int R = 0;
	for (i = 0; i < n;i++) {
		printf("(");
	}
	for (i = 0; i < n; i++) {
		printf(")");
	}
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("()");
	}
	//Function needs to generate all matched parens as described in the assignment 
	n = 4; //for testing
	i = n;
	while (i > 0) {
		printf("(");
		i--;
		L++;
	}
	Rcnt++;
	for (j = 0; j < Rcnt; j++) {
		printf(")");
	}
}

void generateAllPalindromicDecompositions(char str[]) {
	int End=0;
	int j;
	char misfits[100] = { 0 };
	int mcnt = 0;
	int start;
	int length;
	
	//for (End = 0; str[End] != 0; End++) { ; }
	while (str[End] != 0) {
		End++;				//End will be the length of the string
	}
	j = --End;
	length = j;
	start = 0;
	Palindrome(str, start, j, End, length, misfits, mcnt);
	start = 0;
	getchar();
}
void Palindrome(char Array[], int start, int j, int End, int length, char misfits[], int mcnt) {
	int i;
	int a=1;
	length = j;
	for (i = start; i < j; i++, j--) {
		if (Array[i] != Array[j]) {
			//j--; 
			a = 0;
			break;//make sure it breaks from the for loop
		}
	}
	j = j;
	i = i;
	//orginal end spot
	
	
	//if ((start > End) || (start == End)) {
	if(start > End){
		return;
	}
		/*go again til the loop finds a palindrome, once it finds a palindrome, print the array and then print the palindrome*/
//	if ((a == 0) && ((start + 1) == End)) { printf("%c", Array[start]); }
	if (a == 0) {
		j--; //try this
		Palindrome(Array, start, j, End, length, misfits, mcnt);
		return;
	}
	else if((a==1)&&(start !=j)) {
		printf(" ");
		for (i = start; i <= length; i++) {	//go til length of the ministring being tested
			printf("%c", Array[i]);
		}
		printf(" ");
		/*probably dont need, but keep for now
		start = length + 1;
		j = End;
		Palindrome(Array, start, j, End, length);*/ 
	}
	else if ((a == 1) && (start == j)) { //original a==0
		printf("%c", Array[j]);
		/*misfits[mcnt] = Array[start];
		mcnt++;*/
		j = End; start++;
		Palindrome(Array, start, j, End, length, misfits, mcnt);
		return;
	}
	/*if ((a == 1) && (misfits[0] != 0)) {
		for (i = 0; i < mcnt; i++) {
			printf("%c", misfits[i]);
		}
		printf(" ");
		mcnt = 0;
	}*/
	if(j != End) {
		start = length + 1;
		j = End;
		Palindrome(Array, start, j, End, length, misfits, mcnt); 
		return;
	}
	
}


void parenPrint(int n, int i, int L, int R, int Rcnt, int Lcnt) {
	//int j;
	if (R == n) { return; }
	while ((n - Lcnt) > i) {
		printf("(");
		i++;
	}
	if ((Lcnt) == 0) {
		for (i = 0; i < n; i++) {
			printf(")");
		}
		Lcnt++; parenPrint(n, i, L, R, Rcnt, Lcnt); return;
	}
	i = 0;
	Rcnt = 1;
	while ((n - Rcnt) > i) {
		printf(")");
		i++;
	}


	Rcnt++;
	if (Rcnt < n) {//call a recursive function that prints out right braces}
	}
}
/*
Call recursive function that outputs N-i lefts, then 
*/