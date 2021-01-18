/* CS2211a 2020 */
/* Assignment number: 5 */
/* Your name: Julia Anantchenko */
/* Your student number: 251097696 */
/* Your UWO User Name: janantch */
/* Date Completed: Dec 1 2020 */

// includes the main header file
#include "headers.h"

// runs each step of the program
int main(void) {

    char str[1000]; // string for the input
    
    // linked list
    linkedList list;
    list.first = NULL;
    list.numSentence = 0;

    list.first = storeLines(&str, list.first, &(list.numSentence)); // gets input and stores the lines

    printSentence(list.first); // prints the sentences one per line
    
    findWord(&str, list.first); // prompts for a word and finds it in the stored sentences
    
    deleteLine(list.first, &(list.numSentence)); // frees the memory

    return 0;
}

