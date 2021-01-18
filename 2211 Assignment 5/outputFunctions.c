/* CS2211a 2020 */
/* Assignment number: 5 */
/* Your name: Julia Anantchenko */
/* Your student number: 251097696 */
/* Your UWO User Name: janantch */
/* Date Completed: Dec 1 2020 */

// includes the main header file
#include "headers.h"

// print out each sentence in its entirety in the order it was entered by the user. 
void printSentence(sentence *sPtr) {

    printf("\nThis is all the words printed out on the same line as entered: \n");
    
    // temp node to go through the list
    sentence *currentS = sPtr;
    while (currentS != NULL) {
        word *currentW = currentS->w; // temp node to go through the list
        while (currentW != NULL) {
            for (int i = 0; i < currentW->numChar; i++) {
                printf("%c", currentW->c[i]); // prints each char of the word
            }
            printf(" ");
            currentW = currentW->next; // goes to the next word
        }
        printf("\n");
        currentS = currentS->next; // goes to the next sentence
    }
}

// // finds a word, prints out which line and position the word was found in or states message saying it doesn't exist
void printWordSearch(char *str, sentence *sPtr) {
    
    // variables to track if there is a match
    int match = 0;
    int matchTotal = 0;
    
    // temp node to go through the list
    sentence *currentS = sPtr;
    while (currentS != NULL) {
        word *currentW = currentS->w; // temp node to go through the list
        while (currentW != NULL) {
            
            match = 1;
            
            // goes through the word comparing each char, sets match to 0 if there is a dffference
            for (int i = 0; i < currentW->numChar; i++) {
                
                if (str[i] != currentW->c[i])
                    match = 0;
            }
            
            // if there was no difference, prints the position
            if (match == 1) {
                matchTotal++;
                printf("%s found in line %d position %d\n", str, currentS->line+1, currentW->pos+1);
            }
            
            // moves to the next word
            currentW = currentW->next;
        }
        // moves to the next sentence
        currentS = currentS->next;
    }
    
    // if no matches were made, prints a message
    if (matchTotal == 0)
        printf("%s was not found in this file\n", str);
    
}