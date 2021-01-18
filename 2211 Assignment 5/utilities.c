/* CS2211a 2020 */
/* Assignment number: 5 */
/* Your name: Julia Anantchenko */
/* Your student number: 251097696 */
/* Your UWO User Name: janantch */
/* Date Completed: Dec 1 2020 */

// includes the main header file
#include "headers.h"

// goes through a sentence, creating and returning a word pointer with the required information
word * storeWords(char str[], int *numW) {

    // creates a word pointer
    word* wPtr = NULL;

    // splits the string into words based on whitespace
    char *splitPtr = strtok(str, " ");

    // loops while there are words 
    while (splitPtr != NULL) {

        // creates a char pointer and allocates memory
        char* cPtr;
        cPtr = (char*) calloc ((strlen(splitPtr)+1), sizeof(char));

        // adds each char of the string to the char pointer
        for (int i = 0; i < strlen(splitPtr); i++) {
            cPtr[i] = splitPtr[i];
        }
        
        // increases word counter
        (*numW)++;
        
        // gets the length of the word
        int length = strlen(splitPtr);

        // inserts the word into the list
        wPtr = insertWord(wPtr, cPtr, length);

        // moves onto the next word
        splitPtr = strtok(NULL, " ");

    }

    // returns the word pointer
    return wPtr;

}

// stores the lines entered by a user as a sentence
sentence* storeLines(char *str, sentence *sPtr, int *numSentence) {

    // loops while the input is not blank
    do {

        // prompts the user
        promptLine(str);
        
        // breaks if nothing was entered
        if (str[0] == '\0')
            break;

        // puts the words into a linked list to make a sentence   
        int numW = 0;
        word *wordPtr = storeWords(str, &numW);

        // inserts the sentence into the list and updates sentence counter
        sPtr = insertSentence(sPtr, wordPtr, *numSentence, numW);
        (*numSentence)++;

    } while (str[0] != '\0');

    return sPtr;

}

// // finds a word entered by the user in the sentence
void findWord(char *str, sentence *sPtr) {

    // loops while the input is not blank
    do {

        // prompts the user
        printf("\n");
        promptWord(str);
        
        // returns if nothing was entered
        if (str[0] == '\0')
            return;
        
        // prints the results
        printWordSearch(str, sPtr);

    } while (str[0] != '\0');
    
}

void deleteLine(sentence *sPtr, int *numSentence) {
    
    int line = 0;
    
    // loops while the input is not blank
    do {

        // prompts the user
        printf("\n");
        line = 0;
        line = promptNum();
        
        // checks if it is in bounds
        if (line > *numSentence) {
            printf("Invalid value, try again.\n");
        }
        else if (line > 0) {
            
            // deletes the sentence
            sPtr = deleteSentence(sPtr, line);

            // updates counter
            (*numSentence)--;
            
            // prints the results
            printSentence(sPtr);
        }

    } while (line != 0);
    
}