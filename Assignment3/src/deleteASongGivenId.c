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
#include <stdlib.h>

int deleteASongGivenId(A3Song **headLL, int givenSongId) {
    A3Song *current = *headLL;
    A3Song *prev = NULL;

    while (current != NULL) {
        if (current->songId == givenSongId) {
            // Found the song to delete
            if (prev == NULL) {
                // Deleting the head
                *headLL = current->nextSong;
            } else {
                // Deleting from the middle or end
                prev->nextSong = current->nextSong;
            }
            free(current);
            return 1;
        }
        prev = current;
        current = current->nextSong;
    }
    // Not found
    return -1;
}