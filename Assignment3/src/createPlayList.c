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
#include <stdlib.h>
#include <string.h>

int createPlayList(A3Song **headLL, char fileName[MAX_LENGTH]) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        // File not found
        return -1;
    }

    char line[500];
    int numSongs = 0;

    // Skip a header line if the CSV has one
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file)) {
        A3Song *newSong = malloc(sizeof(A3Song));
        if (newSong == NULL) {
            // Partial load if we run out of memory
            fclose(file);
            return numSongs;
        }

        // Parse song name (first token)
        char *token = strtok(line, ",");
        if (token == NULL) {
            free(newSong);
            continue; 
        }
        strcpy(newSong->songName, token);

        // Generate Song ID (basic approach for uniqueness)
        newSong->songId = strlen(newSong->songName) + (rand() % 1000 + 1);

        // Parse the 21 notes from CSV
        for (int i = 0; i < 21; i++) {
            token = strtok(NULL, ",\r\n");
            if (token) {
                strcpy(newSong->songNotes[i], token);
            } else {
                // If fewer than 21 tokens, fill the rest with something, e.g. empty
                strcpy(newSong->songNotes[i], "");
            }
        }

        // Insert newSong at the beginning of the linked list
        newSong->nextSong = *headLL;
        *headLL = newSong;

        numSongs++;
    }

    fclose(file);
    return numSongs;
}