/* CS2211a 2020 */
/* Assignment number: 5 */
/* Your name: Julia Anantchenko */
/* Your student number: 251097696 */
/* Your UWO User Name: janantch */
/* Date Completed: Dec 1 2020 */

// if undefined, defines
#ifndef mH
#define mH

// includes some c library header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// includes the definitions header
#include "definitions.h"

// the functions in other c files:

void promptLine(char*);
void promptWord(char*);
int promptNum();

void printSentence(sentence*);
void printWordSearch(char*, sentence*);

word * storeWords(char[], int*);
sentence* storeLines(char*, sentence*, int*);
void findWord(char*, sentence*);
void deleteLine(sentence*, int*);

word *newWord(char*, int, int);
sentence *newSentence(word*, int, int);
word *insertWord(word*, char*, int);
sentence *insertSentence(sentence*, word*, int, int);
sentence *deleteSentence(sentence*, int);
void updateLine(sentence*);
void clearSentence(sentence*);
void clearWord(word*);

#endif // mH