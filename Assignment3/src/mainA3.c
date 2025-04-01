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

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
 #include <time.h>
 #include "givenA3.h" 
 
 // Helper function to safely read an integer from input.
 // Returns 1 if an integer was successfully read, 0 if not.
 int readIntSafely(int *outValue) {
     int ret = scanf("%d", outValue);
     if (ret == 1) {
         return 1; // success
     }
     // Failed to read an integer -> clear the bad input
     fflush(stdin);
     return 0;
 }
 
 // Prints the recurring menu
 void printMenu(void) {
     printf("======================================================\n");
     printf("1. Create a new playlist\n");
     printf("2. Add a new song to an existing playlist\n");
     printf("3. Play all songs in the given playlist\n");
     printf("4. Play a song from the playlist, given its id\n");
     printf("5. Play a song from the playlist, given its name\n");
     printf("6. Count the number of occurrences of a note in a given song\n");
     printf("7. Delete a song from the playlist, given its id\n");
     printf("8. Delete the entire playlist\n");
     printf("9. Exit\n");
     printf("======================================================\n");
     printf("Enter your choice: ");
 }
 
 int main(int argc, char *argv[]) {
     // Seed random for ID and note generation
     srand((unsigned int) time(NULL));
 
     // Linked list head
     A3Song *headLL = NULL;
 
     // If user doesn't pass CSV in argv[1], we can still run,
     // but option #1 won't load anything.
     // e.g., ./bin/musicalLL musicalNotes.csv
 
     int keepRunning = 1;
     int choice = 0;
 
     while (keepRunning) {
         printMenu();
 
         // Validate integer input
         if (!readIntSafely(&choice)) {
             printf("\nInvalid Type!!\n\n");
             continue; // Show the menu again
         }
 
         // Now choice is an integer. Check if 1..9
         if (choice < 1 || choice > 9) {
             printf("\nInvalid Choice!!\n\n");
             continue; // Show the menu again
         }
 
         switch (choice) {
             case 1: {
                 // Create a new playlist using argv[1] automatically
                 if (argc < 2) {
                     // No CSV file provided in command line
                     printf("\nNo CSV file specified at runtime!\n");
                     printf("Run as: ./bin/musicalLL <filename.csv>\n\n");
                 } else {
                     // Load from argv[1]
                     int loaded = createPlayList(&headLL, argv[1]);
                     if (loaded == -1) {
                         printf("\nFile not found!!\n\n");
                     } else {
                         printf("\nNumber of songs in the playlist: %d\n\n", loaded);
                     }
                 }
                 break;
             }
 
             case 2: {
                 // Add a new song
                 int beginOrEnd;
                 printf("Enter the value for beginOrEnd: ");
                 if (!readIntSafely(&beginOrEnd)) {
                     printf("\nInvalid Type!!\n\n");
                     break;
                 }
                 bool success = addNewSong(&headLL, beginOrEnd);
                 if (!success) {
                     // Possibly invalid beginOrEnd or memory fail
                     if (beginOrEnd != 1 && beginOrEnd != 2) {
                         printf("\nInvalid beginOrEnd value passed!!\n\n");
                     } else {
                         printf("\nCould not add new song (memory error)!!\n\n");
                     }
                 } else {
                     if (beginOrEnd == 1) {
                         printf("\nSong added at the beginning!\n\n");
                     } else {
                         printf("\nSong added at the end!\n\n");
                     }
                 }
                 break;
             }
 
             case 3: {
                 // Play entire playlist
                 if (headLL == NULL) {
                     printf("\nNo songs in the playlist!\n\n");
                 } else {
                     playPlayList(headLL);
                 }
                 break;
             }
 
             case 4: {
                 // Play a song by ID
                 int givenId;
                 printf("Enter the id of the song you want to play: ");
                 if (!readIntSafely(&givenId)) {
                     printf("\nInvalid Type!!\n\n");
                     break;
                 }
                 int result = playSongGivenId(headLL, givenId);
                 if (result == -1) {
                     printf("\nNo song found!!\n\n");
                 }
                 break;
             }
 
             case 5: {
                 // Play a song by name
                 char givenName[MAX_LENGTH];
                 printf("Enter the name of the song you want to play: ");
                 scanf(" %[^\n]", givenName); // reads a line
 
                 int result = playSongGivenName(headLL, givenName);
                 if (result == -1) {
                     printf("\nNo song found!!\n\n");
                 }
                 break;
             }
 
             case 6: {
                 // Count occurrences of a note in a given song
                 int givenId;
                 printf("Enter the id of the song you want to count the notes in: ");
                 if (!readIntSafely(&givenId)) {
                     printf("\nInvalid Type!!\n\n");
                     break;
                 }
                 char whichNote[4];
                 printf("Enter the note you want to count: ");
                 scanf(" %3s", whichNote);
 
                 int count = countNotesInASong(headLL, givenId, whichNote);
                 if (count == -1) {
                     printf("\nSong not found!!\n\n");
                 } else {
                     printf("\nNumber of times the note appears: %d\n\n", count);
                 }
                 break;
             }
 
             case 7: {
                 // Delete a song by ID
                 int givenId;
                 printf("Enter the id of the song you want to delete: ");
                 if (!readIntSafely(&givenId)) {
                     printf("\nInvalid Type!!\n\n");
                     break;
                 }
                 int result = deleteASongGivenId(&headLL, givenId);
                 if (result == -1) {
                     printf("\nSong not found!!\n\n");
                 } else {
                     printf("\nSong Deleted!!\n\n");
                 }
                 break;
             }
 
             case 8: {
                 // Delete the entire playlist
                 printf("\nDeleting Playlist ♫♫♫\n\n");
                 deletePlayList(&headLL);
                 break;
             }
 
             case 9: {
                 // Exit
                 printf("\n♫ Exiting the program ♫\n\n");
                 // free everything just to be safe
                 deletePlayList(&headLL);
                 // exit the loop
                 return 0;
             }
         }
     }
 
     // If for some reason the loop exits, we do final cleanup
     deletePlayList(&headLL);
     return 0;
 }
 