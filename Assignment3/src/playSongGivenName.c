/*
Student Name: Oliver Raczka
Student ID: 1341067
Due Date: March 31, 2025
Course: CIS*2500
I have exclusive control over this submission via my password.
By including this header comment, I certify that:
1) I have read and understood the policy on academic integrity.
2) I have completed Moodle's module on academic integrity.
3) I have achieved at least 80% on the academic integrity quiz
I assert that this work is my own. I have appropriate acknowledged
any and all material that I have used, be it directly quoted or
paraphrased. Furthermore, I certify that this assignment was written
by me in its entirety.
*/
#include "givenA3.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Helper function to convert a string to lowercase
static void toLowerString(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = (char)tolower((unsigned char)str[i]);
    }
}

int playSongGivenName(A3Song *headLL, char givenSongName[MAX_LENGTH]) {
    A3Song *current = headLL;
    char lowerGivenName[MAX_LENGTH];
    char lowerCurrentName[MAX_LENGTH];

    // Convert input name to lowercase
    strcpy(lowerGivenName, givenSongName);
    toLowerString(lowerGivenName);

    // Search the list
    while (current != NULL) {
        // Convert the current song's name to lowercase
        strcpy(lowerCurrentName, current->songName);
        toLowerString(lowerCurrentName);

        if (strcmp(lowerCurrentName, lowerGivenName) == 0) {
            // Found match
            printf("Song ID: %d\n", current->songId);
            printf("Song Name: %s\n", current->songName);
            printf("Notes: ");
            for (int i = 0; i < 21; i++) {
                printf("%s", current->songNotes[i]);
                if (i < 20) {
                    printf(".");
                }
            }
            printf("\n");
            return 1;
        }
        current = current->nextSong;
    }

    return -1; // Not found
}