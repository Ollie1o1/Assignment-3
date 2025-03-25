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
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

#define MAX_LENGTH 25
#define NOTE_LENGTH 4

struct Song
{

   int songId;         // this is auto-generated by the program
                       // must be unique for each song in the playList
   char songName[MAX_LENGTH];       // name of the song
   char songNotes[21][NOTE_LENGTH]; // every song in this playlist has 21 notes
   struct Song *nextSong;
};
typedef struct Song A3Song;

/*
create a play list using data given in the file named "musicalNotes.csv"
 */
int createPlayList(A3Song **headLL, char fileName[MAX_LENGTH]);

/*
add a new song to the start of the given linked list if beginOrEnd is 1; add it to the end of the given LL if beginOrEnd is 2
 return True for success and False if it fails for any reason
 */
bool addNewSong(A3Song **headLL, int beginOrEnd);

/*
Play all songs in the playlist,
each song separated by a newline;
each note in a song separated by a .
for example, Do.Re.Mi. and so on
 */
void playPlayList(A3Song *headLL);

/* 
Play a song, given its id givenSongId;
each note in a song must be separated by a dot (.)
for example, Do.Re.Mi. and so on

Return -1 if song not found; 1 if found
 */
int playSongGivenId(A3Song *headLL, int givenSongId);

/* 
Play a song, given its name givenSongName;
each note in the song must be separated by a dot (.)
for example, Do.Re.Mi. and so on

Return -1 if song not found; 1 if found
 */
int playSongGivenName(A3Song *headLL,
                      char givenSongName[MAX_LENGTH]);

/* 
Count and return the number of times a given note appears in the song identified by givenSongId;

 Return -1 if song not found;
 */
int countNotesInASong(A3Song *headLL, int givenSongId, char whichNote[4]); 

/*
 Remove every song from the playlist
 */
void deletePlayList(A3Song **headLL);

/*
 Remove the song identified by givenSongId;

 Return -1 if song doesn't exist
 */
int deleteASongGivenId(A3Song **headLL, int givenSongId);

// Helpers
void printPlayList(A3Song *headLL);
