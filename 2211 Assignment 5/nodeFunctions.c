/* CS2211a 2020 */
/* Assignment number: 5 */
/* Your name: Julia Anantchenko */
/* Your student number: 251097696 */
/* Your UWO User Name: janantch */
/* Date Completed: Dec 1 2020 */

// includes the main header file
#include "headers.h"

// creates a word node with specified data
word *newWord(char* cPtr, int numC, int position) {
    word* temp = (word*)malloc(sizeof(word)); // allocates memory
    temp->c = cPtr;
    temp->numChar = numC;
    temp->pos = position;
    temp->next = NULL;
    return temp; // returns the word just created
}

// creates a sentence node with the specified data
sentence *newSentence(word* wPtr, int lineNum, int wordCount) {
    sentence* temp = (sentence*)malloc(sizeof(sentence)); // allocates memory
    temp->w = wPtr;
    temp->line = lineNum;
    temp->numWords = wordCount;
    temp->next = NULL;
    return temp; // returns the word just created
}

// inserts a word at the end of the list
word *insertWord(word* first, char* cPtr, int numC) {

    // if there are no words, this is set to be the first
    if (first == NULL) {
        return newWord(cPtr, numC, 0);
    }

    // loops through until the end, keeping track of the position
    word *current = first;
    int position = 1;
    while (current->next != NULL) {
        current = current->next;
        position++;
    }
    current->next = newWord(cPtr, numC, position); // sets the next node to be the new node
    return first; // returns the first node
}

// inserts a sentence at the end of the list
sentence *insertSentence(sentence* first, word* wPtr, int lineNum, int wordCount) {

    // if there are no sentences, this is set to be the first
    if (first == NULL) {
        return newSentence(wPtr, 0, wordCount);
    }

    // loops through until the end, keeping track of the position
    word *current = first;
    int position = 1;
    while (current->next != NULL) {
        current = current->next;
        position++;
    }
    current->next = newSentence(wPtr, position, wordCount); // sets the next node to the new node
    return first; // returns the first node
}

// deletes a line from the list
sentence *deleteSentence(sentence* first, int l) {
    
    sentence *current = first;
    l = l-1;
    
    // if it's the first node, sets the new first node to be the second
    if (l == 0)
        return current->next;

    // otherwise finds the place of the node to be deleted    
    for (int i = 1; i < l; i++) {
        current = current->next;
    }
    
    // sets the one before to point to the one after
    current->next = current->next->next;
    updateLine(first); // updates the values
    return first;
        
}

// updates the position numbers for the sentence linked list
void updateLine(sentence* first) {
    
    if (first == NULL) {
        return;
    }

    // goes through the list, counts and updates all the positions
    sentence *current = first;
    int position = 0;
    while (current->next != NULL) {
        current->line = position;
        current = current->next;
        position++;
    }
    
}

// clears the sentence memory
void clearSentence(sentence *sPtr) {
    
    sentence *currentS = sPtr;
    
    // returns if null
    if (currentS == NULL)
        return;

    // recursively clears the space    
    clearSentence(currentS->next);
    clearWord(currentS->w);
    
    // frees the space
    free(currentS);

}

// clears the word memory
void clearWord(word *wPtr) {
    
    word *currentW = wPtr;
    
    // returns if null
    if (currentW == NULL)
        return;

    // recursively clears the space    
    clearWord(currentW->next);
    
    // frees the space
    free(currentW);
}