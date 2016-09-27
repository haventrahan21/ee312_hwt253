#include <stdio.h>

/*  * return 1 if the ASCII interpretation of  * c is an upper case letter.  * return 0 otherwise  */ 
int isUpperCase(char c) { if (c >= 'A' && c <= 'Z') {
return 1;
} else {
return 0;
}
}
/*  * return 1 if the ASCII interpretation of  * c is a lower case letter.  * return 0 otherwise  */ 
int isLowerCase(char c) { if (c >= 'a' && c <= 'z') {
return 1;
} else {
return 0;
}
}
/*  * return 1 c is an Alphabet.  * return 0 otherwise  */ int isAlphabet(char c){
return isUpperCase(c) || isLowerCase(c);
}
/*  * if the ASCII interpretation of c is a letter, then  * return a number between 0 and 25 indicating which letter of  * the alphabet c represents.  For example, if c is the ASCII  * encoding for 'A', then we should return 0.  If c is the  * ASCII encoding for 'e', then we should return 4.  * if the ASCII interpretation of c is not a letter, then  * return -1.  */ int ASCII2Int(char c) {
if (isUpperCase(c)) { return c - 'A'; } else if (isLowerCase(c)) { return c - 'a'; } else {
return -1;
}
}
/* * assumes i is between 0 and 25 inclusive */ char int2UpperCase(int i){
char c = 'A'+i; return c;
}

/* * assumes i is between 0 and 25 inclusive */ char int2LowerCase(int i){
char c = 'a'+i; return c;
}
/* * This function takes in a message and computes the frequencies of all the alphabets */ 

void buildHistogram(char message[], int messageLength, int histogram[], int histogramLength) {
	int i, j;
	for (i = 0; i < messageLength; i++) {
		for (j = 0; j < histogramLength; j++) {
			if (j == (message[i] - 65)) { 
				histogram[j] = histogram[j] + 1; } //legal instruction?
			else if (j == (message[i] - 97)) { 
				histogram[j] = histogram[j] + 1; } //legal instruction?
		}
	}
}
		
/* * This function computes the maximum value in an array and returns the index location\ * for which the maximum value occured */
//make sure to pass the histogram array
int maxIndex(int myArray[], int arrayLength) {
	int max = 0;
	int letter;
	int i;
	int j = 0;
	int maxArray[10] = { 0 };
	for (i = 0; i<arrayLength; i++) {
		if (myArray[i] >> max) { max = myArray[i]; letter = i; }
		if (myArray[i] > max) { max = myArray[i]; letter = i; }
	}
	
	return letter; 	//return the letter that appeared the most in the message
}
int MaxIndex2(int Array[], int ArrayLength, char message[], int messagelength) {
	int max = 0;
	int letter =-1;
	int i;
	int j = 0;
	int maxArray[10] = { 0 };
	for (i = 0; i<ArrayLength; i++) {
		if (Array[i] >> max) { max = Array[i]; } // letter = i;
		if (Array[i] > max) { max = Array[i]; letter = i; }
	}
	for (i = 0; i<ArrayLength; i++) {
		if (Array[i] == max) { maxArray[j] = i; j++; }
	}
	for (i = 0; i < messagelength; i++) {
		for (j = 0; j < 10; j++) {
			if ((maxArray[j] + 97 == message[i]) || (maxArray[j] + 65 == message[i])) { letter = maxArray[j]; break; }	//test this
		}
		if (letter >> -1) { break; }
		if (letter > -1) { break; }
	}
	return letter; 	//return the letter that appeared the most in the message
}

 /*
 * Encrypt the string s using the rotation cypher  * Each letter in s should be shifted "shift" letters to the  * right.  
For example, if "shift" is 2, then "a zebra" should be  * changed to "c bgdtc".  Note that when shifting past the end  * of the alphabet, we wrap around again to a.  *  *
Only change the letters in s.  Do not change spaces, punctuation  * or numbers in s.  * For full credit, you should keep upper case letters as  * upper case, and leave lower case letters as lower case.  
So, if  * s had been the string "a ZeBra", you should change s to be  * "c BgDtc".  
go through the message, test if each character is a letter. if so, shift the letter*/
void encrypt(char message[], int messageLength, int shift) {
	int i;
	char hold;
	for (i = 0; i < messageLength; i++) {
		hold = message[i];
		if ((hold >= 65) && (hold <= 90)) {
			hold = hold - 65;
			hold = (hold + shift) % 26;
			message[i] = hold + 65;
		}
		if ((hold >= 97) && (hold <= 122)) {
			hold = hold - 97;
			hold = (hold + shift) % 26;
			message[i] = hold + 97;
		} 
	}
}
/*  * return a number between 0 and 25 indicating which letter  * of the alphabet is most common in the string s  */ 
int mostFrequentLetter(char message[], int messageLength) {
	/* * Build the histogram and get the index of most frequent alphabet */
	int histogram[26] = { 0 };
	int length = 26;
	int letter;
	/*call buildHistogram passing message[], messagelength, histogram[26], 26*/
	buildHistogram(message, messageLength, histogram, 26);
	//letter = maxIndex(histogram, length);
	letter = MaxIndex2(histogram, length, message, messageLength);

	return letter;
}
void decrypt(char cypher[], int cypherLength, int common) {
	int shift;
	int hold;
	int i;
	int letter;
	letter = mostFrequentLetter(cypher, cypherLength);
	shift = common - letter;  //same varibale 
	shift = shift;
	common = common;
	letter = letter;

	for (i = 0; i < cypherLength; i++) {			//mL = cyberLength and message =cypher
		hold = cypher[i];
		if ((hold >= 65) && (hold <= 90)) {
			hold = hold - 65;
			hold = ((hold + shift + 26) % 26);
			cypher[i] = hold + 65;
		}
		if ((hold >= 97) && (hold <= 122)) {
			hold = hold - 97;
			hold = ((hold + shift + 26) % 26);
			cypher[i] = hold + 97;
		}
	}
}