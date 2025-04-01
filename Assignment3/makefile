# Copyright 2025 daman
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
#     https://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.


# There are two makefiles in this one
# One is for test cases and the other is for the main code
# The test cases makefile is active (line #23-#41)
# The main code makefile is commented out (line #44-#68)



#################################
# 1. Compiler & Flags
#################################
CC = gcc
CFLAGS = -Wall -std=c99 -w -Iinclude

#################################
# 2. MAIN BUILD
#################################

# We manually list the .c files for the main program:
MAIN_SRCS = src/mainA3.c src/playPlayList.c src/deleteASongGivenId.c \
            src/deletePlayList.c src/playSongGivenId.c \
            src/playSongGivenName.c src/addNewSong.c src/createPlayList.c \
            src/countNotesInASong.c

MAIN_OBJS = $(MAIN_SRCS:.c=.o)

#comment the following 41,43,44 lines to run the test cases
all: bin/musicalLL

bin/musicalLL: bin $(MAIN_OBJS)
	$(CC) $(CFLAGS) -o bin/musicalLL $(MAIN_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bin:
	if not exist bin mkdir bin

#################################
# 3. HARNESS BUILD
#################################
# The harness includes the .c files from src internally, so we do NOT compile them again.
# We only compile the harness .c files themselves.

test: bin bin/test

bin/test: TestCode.o unity.o TestCodeRunner.o
	$(CC) $(CFLAGS) -o bin/test TestCode.o unity.o TestCodeRunner.o -lm

TestCode.o: harness/TestCode.c harness/unity.h harness/CodeUnderTest.h
	$(CC) $(CFLAGS) -c harness/TestCode.c

unity.o: harness/unity.c harness/unity.h
	$(CC) $(CFLAGS) -c harness/unity.c

TestCodeRunner.o: harness/TestCodeRunner.c harness/unity.h
	$(CC) $(CFLAGS) -c harness/TestCodeRunner.c

#################################
# 4. CLEAN
#################################
clean:
	del /Q *.o 2>NUL
	del /Q src\\*.o 2>NUL
	del /Q bin\\* 2>NUL
