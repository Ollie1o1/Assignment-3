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
#include "include/givenA3.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    A3Song *playlist = NULL;
    int choice;
    char fileName[MAX_LENGTH];
    char songName[MAX_LENGTH];
    char note[NOTE_LENGTH];
    int songId, count, result;
    
    srand(time(NULL)); // Seed random number generator

    do {
        printf("\n=========== musicalLL Menu ===========\n");
        printf("1. Create a new playlist\n");
        printf("2. Add a new song\n");
        printf("3. Play all songs\n");
        printf("4. Play song by ID\n");
        printf("5. Play song by name\n");
        printf("6. Count notes in song\n");
        printf("7. Delete song by ID\n");
        printf("8. Delete entire playlist\n");
        printf("9. Exit\n");
        printf("=====================================\n");
        printf("Enter your choice (1-9): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Create playlist
                printf("Enter CSV filename: ");
                scanf("%s", fileName);
                result = createPlayList(&playlist, fileName);
                if(result == -1) {
                    printf("Error: Could not open file!\n");
                } else {
                    printf("Successfully loaded %d songs!\n", result);
                }
                break;

            case 2: // Add new song
                printf("Add to (1) beginning or (2) end: ");
                scanf("%d", &result);
                if(addNewSong(&playlist, result)) {
                    printf("Song added successfully!\n");
                } else {
                    printf("Failed to add song!\n");
                }
                break;

            case 3: // Play all songs
                playPlayList(playlist);
                break;

            case 4: // Play song by ID
                printf("Enter song ID: ");
                scanf("%d", &songId);
                if(playSongGivenId(playlist, songId) == -1) {
                    printf("Song not found!\n");
                }
                break;

            case 5: // Play song by name
                printf("Enter song name: ");
                scanf("%s", songName);
                if(playSongGivenName(playlist, songName) == -1) {
                    printf("Song not found!\n");
                }
                break;

            case 6: // Count notes
                printf("Enter song ID: ");
                scanf("%d", &songId);
                printf("Enter note to count: ");
                scanf("%s", note);
                count = countNotesInASong(playlist, songId, note);
                if(count == -1) {
                    printf("Song not found!\n");
                } else {
                    printf("Note '%s' appears %d times\n", note, count);
                }
                break;

            case 7: // Delete song by ID
                printf("Enter song ID to delete: ");
                scanf("%d", &songId);
                if(deleteASongGivenId(&playlist, songId) == -1) {
                    printf("Song not found!\n");
                } else {
                    printf("Song deleted!\n");
                }
                break;

            case 8: // Delete entire playlist
                deletePlayList(&playlist);
                printf("Playlist cleared!\n");
                break;

            case 9: // Exit
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please enter 1-9.\n");
        }
    } while(choice != 9);
    // Final cleanup
    deletePlayList(&playlist);
    return 0;
}