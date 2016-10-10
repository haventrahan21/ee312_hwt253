#include <stdio.h>
#include <string.h>
#define BEGIN_FCN {
#define END_FCN }
int wait(char str[], int i, FILE * fp)																			//8
{
	i++;
	if (str[i] == '/') {	//denotes "//" comments just get new line because these comments end with a newline
							//fgets(str, 201, fp);
		return 1;
	}
	else if (str[i] == '*') {
		i++;
		while ((str[i] != '*') && (str[i+1] != '/')) {
			i++;
		if (str[i] == '\n') { fgets(str, 201, fp);  //if the comment extends over multiple lines, get the new one
		i = 0;				//reset i
			}
		}
		i++;
		return 1;
		}
	else i--;

}
int wait1(char str[], int i, FILE * fp)																			//8
{
	i++;
	if (str[i] == '/') {	//denotes "//" comments just get new line because these comments end with a newline
							//fgets(str, 201, fp);
		return 1;
	}
	else if (str[i] == '*') {
		i++;
		while ((str[i] != '*') && (str[i + 1] != '/')) {
			i++;
			if (str[i] == '\n') {
				fgets(str, 201, fp);  //if the comment extends over multiple lines, get the new one
				i = 0;				//reset i
			}
		}
		return 1;
	}
	else i--;

}
void fixName(char strl);

int isFunction(const char str[], int count[], FILE * fp)  //test for the BEGIN_FCN					//9
{ 
	int i = 0;
	char Begin[] = "BEGIN_FCN";
	while (str[i] != '\n') {
		if (str[i] == '\0') { return -1; }
		i++;
	}
	/*if (str[i] == '#') { return 0; }
	if ((str[i] == '/') && (str[i+1] == '*')) {
		while ((str[i] != '*') && (str[i + 1] != '/')) {
			i++;
			if (str[i] == '\n') {
				fgets(str, 201, fp);  //if the comment extends over multiple lines, get the new one
				i = 0;				//reset i
			}
		}
	}
		if (str[0] == '{') { count[0]; return 1; }
		i++;
	*/
		for (i = 0; i < 9; i++) {
	if (str[i] != Begin[i]) { 
		return 0; }
	}
	return 1;
}
int isEnd(const char str[], int count[], FILE * fp) //test for the BEGIN_FCN							//7
{  
	int i = 0;
	int x = 0;
	while (str[i] != '\n') {
		if (str[i] == '\0') { return -1; }
		i++;
	}
	char End[] = "END_FCN";
	char BEGIN[] = "BEGIN_FCN";
	i = 0;
	while (str[i] == BEGIN[i]) {
		i++;
	}
	if (i == 9) {
		printf("incomplete function\n");
		return 1;
	}
	for (i = 0; i < 7; i++) {
	if (str[i] != End[i]) { return 0; }
	}
	
	/*while (str[i] != '\n')  {
		if (str[i] == '/') {
		x = wait1(str, i, fp);
		if (x == 1) {
			break; }
		}
		if (str[i] == '{') { count[0]++; }
		if (str[i] == '}') { count[0]--; }
		if (str[i + 1] == '\0') {
			return -1; }
		if (count[0] == 0) { return 1; }
		i++;
	}*/
	return 1;
}
int lineCounter(char str[], FILE * fp)													//9
{
	int i = 0;
	int number = 0;
	int x = 0;
	while (str[i] != '\n')  {	//check the string for semicolons, temrinate when newline character reached
		if (str[i] == '\0') { break; }
		if (str[i] == '"') { 
			while (str[i] != '"') {
				i++; }
		}
		if (str[i] == ';') {
			number++;
		}
		if (str[i] == '/') { x = wait(str, i, fp); } // call wait to determine if the / started a comment and wait til the comment ends
		if (x == 1) { return number; } //this means wait encountered // comments or /* */

		else i++;
	}
	return number;
}


int main(void)																					//47
{
	FILE *fp;
	char str[200];
	char strl[200];
	int i=0;
	int x;
	char name[100];
	int test = 0;
	int lines = 0;
	int cnt[1] = { 0 };
	int j = 0; //keep track of the funciton struct #
	struct functions {
		char functionName[32];
		int LineNum;
	};
	struct functions list[20];
	//create an array of structs to store function names and lines

	printf("Enter the name of a file\n");
	gets(name);				//read the input of the user directly into the file pointer
	fp = fopen(name, "r");   //fopen(name, "r");
	if (fp == NULL) {
		printf("ERROR: could not open file\n");
		printf("failure");
	}

	printf("success");
	getchar();

	while (str[i]!='\0') {
		if (str[0] == '/') { wait(str, i, fp); i = 0; }
		while (test == 0) {		//check a new line until find BEGIN_FCN
			strcpy(strl, str);
			fgets(str, 201, fp);
			test = isFunction(str, cnt, fp);
		}
		if (test == -1) { break; }
		fixName(strl);
		strcpy(list[j].functionName, strl); //once a function is found, store it in the list
		test = 0;
		printf("%s", list[j].functionName);
		getchar();
		fgets(str, 201, fp);
		while (test == 0) {
			lines += lineCounter(str, fp); //add up the number of lines until END_FCN
			test = isEnd(str, cnt, fp);
			fgets(str, 201, fp);
		}
		list[j].LineNum = lines;
		printf("%d", list[j].LineNum);
		getchar();
		j++;
		cnt[0] = 0;
		lines = 0;
		if (test == -1) { break; } //if isEnd encounter eof break
		test = 0;
	}
	printf("Function Name \t# Lines of Code\n");
	for (i = 0; i < j; i++) {
		printf("%s", list[i].functionName);
		printf("\t\t %d\n", list[i].LineNum);
	}
	x = 0;
	for (i = 0; i < j; i++) {
		x += list[i].LineNum;
	}
	printf("\n");
	printf("Total Functions: %d\n", j);
	printf("Total Lines of Code: %d", x);
	fclose(fp);
	while (1);
	return 0;
}
void fixName(char strl[])															//9
{
	int i = 0;
	int offset;
	while (strl[i] != ' ') { //search for space inter void/int and funciton name
		i++; 
	}
	i++;
	offset = i;
	while (strl[i] != '(') {	//stop when encounter ( denoting parameters
		strl[i - offset] = strl[i];
		i++;
	}
	i = i - offset;
	strl[i] = NULL;

}