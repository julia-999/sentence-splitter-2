/* CS2211a 2020 */
/* Assignment number: 5 */
/* Your name: Julia Anantchenko */
/* Your student number: 251097696 */
/* Your UWO User Name: janantch */
/* Date Completed: Dec 1 2020 */

// if undefined, defines
#ifndef dH
#define dH

// word structure used for word related data
typedef struct wordStruct {
    char *c;
    int numChar;
    int pos;
    struct wordStruct* next;
} word;

// sentence structure used for storing sentence related data
typedef struct sentenceStruct {
    word *w;
    int line;
    int numWords;
    struct sentenceStruct* next;
} sentence;

// linked list control stucture
typedef struct lStruct {
    sentence *first;
    int numSentence;
} linkedList;

#endif // dH