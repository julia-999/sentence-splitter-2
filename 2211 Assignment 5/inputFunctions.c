/* CS2211a 2020 */
/* Assignment number: 5 */
/* Your name: Julia Anantchenko */
/* Your student number: 251097696 */
/* Your UWO User Name: janantch */
/* Date Completed: Dec 1 2020 */

// includes the main header file
#include "headers.h"

// prompts for the line, stores in str
void promptLine(char *str) {

    printf("Enter a line: ");
    gets(str);
    
}

// prompts for a word, stores in str
void promptWord(char *str) {
    
    printf("Enter a word to search: ");
    gets(str);
    
}

// prompts for and returns an int
int promptNum() {
    
    int num;
    printf("Enter the line to delete: ");
    scanf("%d", &num);
    return num;
    
}