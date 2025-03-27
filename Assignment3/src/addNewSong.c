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
#include "../include/givenA3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool addNewSong(A3Song **headLL, int beginOrEnd) {
    A3Song *newSong = malloc(sizeof(A3Song));
    if (newSong == NULL) {
        return false;
    }

    // Get song name
    printf("Enter song name: ");
    scanf(" %[^\n]", newSong->songName);

    // Generate songId
    newSong->songId = strlen(newSong->songName) + (rand() % 1000 + 1);

    // Generate 21 random notes
    const char *notes[] = {"do", "re", "mi", "fa", "sol", "la", "ti"};
    for (int i = 0; i < 21; i++) {
        int noteIndex = rand() % 7;
        strcpy(newSong->songNotes[i], notes[noteIndex]);
    }

    // Insert at beginning or end
    if (beginOrEnd == 1) {
        newSong->nextSong = *headLL;
        *headLL = newSong;
    } else if (beginOrEnd == 2) {
        newSong->nextSong = NULL;
        if (*headLL == NULL) {
            *headLL = newSong;
        } else {
            A3Song *temp = *headLL;
            while (temp->nextSong != NULL) {
                temp = temp->nextSong;
            }
            temp->nextSong = newSong;
        }
    } else {
        free(newSong);
        return false;
    }

    return true;
}