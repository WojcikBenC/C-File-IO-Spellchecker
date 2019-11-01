#include "spell_lib.h"

/*
Reads the size of the dictionary file, allocates enough space for it in an array, and reads the characters into the array.
Efficiency was not a requirement for this assignment. Returns a filled array.
*/
char** parseDict(char* path) {
	FILE *dict = fopen(path, "r");
	int c = 0;
	int words = 0;
	while (c != EOF) {
		c = getc(dict);
		if (c == 10) words = words + 1;
	}
	char** array = (char**)malloc((words + 1) * sizeof(char*));
	dict = fopen(path, "r");
	for (int i = 0; i < words; i++) {
		c = 0;
		int len = 0;
		while (c != 10 && c != 32 && c != EOF) {
			c = getc(dict);
			len = len + 1;
		}
		array[i] = (char*)malloc((len + 1) * sizeof(char));
	}
	dict = fopen(path, "r");
	for (int i = 0; i < words; i++) {
		c = 0;
		int j = 0;
		while (c != 10 && c != 32 && c != EOF) {
			c = getc(dict);
			array[i][j] = c;
			j = j + 1;
		}
	}
	array[words] = (char*)malloc(sizeof(NULL));
	array[words] = NULL;
	return array;
}

/*
Searches for the given word in the given array. First converts word to lowercase and cuts off when reaching punctuation or a new line, a requirement for the assignment.
Returns 1 if the word is found and 0 if not.
*/
int wordSearch(char* word, char** dict) {
	char* copy = (char*)malloc(strlen(word) * sizeof(char));
	int c = 0;
	for(c = 0; c < strlen(word); c++) {
		if(isalpha(word[c]) == 0) break;
		copy[c] = tolower(word[c]);
	}
	char* n = "\n";
	copy[c] = *n;
	int found = 0;
	int i = 0;
	char* line = "";
	while(line != NULL && found == 0) {
		line = dict[i];
		if(line != NULL && strcmp(copy, line) == 0) found = 1;
		i++;
	}
	free(copy);
	return found;
}

/*
Checks the given file for errors, then prints out where a misspelling was found, another requirement for the assignment.
Returns 0 if the file has an error and 1 if not.
*/
int bad_word(char* word, int line, FILE* OUT) {
	int err = ferror(OUT);
	if(err != 0) {
		perror("There was an error in the file.\n");
		return 0;
	}
	printf("Unknown word %s found in line %d of the input file.\n", word, line);
	return 1;
}
