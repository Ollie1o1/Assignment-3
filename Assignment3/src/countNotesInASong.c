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
#include <string.h>

int countNotesInASong(A3Song *headLL, int givenSongId, char whichNote[4]) {
    A3Song *current = headLL;
    while (current != NULL) {
        if (current->songId == givenSongId) {
            // Found the song
            int count = 0;
            for (int i = 0; i < 21; i++) {
                if (strcmp(current->songNotes[i], whichNote) == 0) {
                    count++;
                }
            }
            return count;
        }
        current = current->nextSong;
    }
    // If we never found a matching song ID, return -1
    return -1;
}