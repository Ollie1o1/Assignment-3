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

int createPlayList(A3Song **headLL, char fileName[MAX_LENGTH]) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        return -1; // File not found
    }

    char line[500];
    int numSongs = 0;

    // Skip header line
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file)) {
        A3Song *newSong = malloc(sizeof(A3Song));
        if (newSong == NULL) {
            fclose(file);
            return numSongs; // Partial load
        }

        // Parse CSV line
        char *token = strtok(line, ",");
        strcpy(newSong->songName, token);

        // Generate songId: strlen(name) + random 1-1000
        newSong->songId = strlen(newSong->songName) + (rand() % 1000 + 1);

        // Parse 21 notes
        for (int i = 0; i < 21; i++) {
            token = strtok(NULL, ",\r\n");
            if (token) {
                strcpy(newSong->songNotes[i], token);
            }
        }

        // Insert at BEGINNING of list
        newSong->nextSong = *headLL;
        *headLL = newSong;
        numSongs++;
    }

    fclose(file);
    return numSongs;
}