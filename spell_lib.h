#ifndef SPELL_LIB_H
#define SPELL_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char** parseDict(char* path);
int wordSearch(char* word, char** dict);
int bad_word(char* word, int line, FILE* out);

#endif
