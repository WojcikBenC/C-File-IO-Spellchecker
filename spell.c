#include "spell.h"

/*
Prompts for input for the paths of the two input files, validates them, then calls methods to parse the dictionary
into an array, search the input file for word matches, and print out where spelling errors occur.
*/
int main() {
	FILE *inp = NULL;
	char input = ' ';
	while (inp == NULL) {
		printf("Enter the name of the input file: ");
		scanf("%s", &input);
		inp = fopen(&input, "r");
	}
	FILE *dict = NULL;
	char dictionary = ' ';
	while (dict == NULL) {
		printf("Enter the name of the dictionary file: ");
		scanf("%s", &dictionary);
		dict = fopen(&dictionary, "r");
	}
	char** array = parseDict(&dictionary);
	char word[46];
	int s = 1;
	int i = 1;
	while(fgets(word, 46, inp) != NULL) {
		strtok(word, " ,.-!@#$^&*_+<>?");
		s = wordSearch(word, array);
		if(s == 0) bad_word(word, i, inp);
		i++;
	}
	free(array);
	return 0;
}
