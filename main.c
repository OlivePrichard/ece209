// Read strings from a file.
// Find longest, shortest, first, and last strings.
//
// For ECE 209 students only -- DO NOT SHARE with others


#include <stdio.h>
#include <string.h>
#include <ctype.h>   // ispunct

// declaration -- don't change this 
// see below for definition -- write your code there
int wordInfo(const char * filename, char shortest[], char longest[], char lowest[], char highest[]);

// declaration -- don't write code here
void removePunct(char * string);

int main() {
   char filename[25];
   char shortWord[16] = "";
   char longWord[16] = "";
   char firstWord[16] = "";
   char lastWord[16] = "";
   printf("Filename: ");
   fflush(stdout);
   scanf("%24s", filename);

   int w = wordInfo(filename, shortWord, longWord, firstWord, lastWord);
   if (w == -1) {
      printf("Could not open file: %s\n", filename);
   }
   else {
      printf("File has %d words.\n", w);
      printf("Shortest word: %s\n", shortWord);
      printf("Longest word: %s\n", longWord);
      printf("Alphabetically first: %s\n", firstWord);
      printf("Alphabetically last: %s\n", lastWord);
   }

   return 0;
}

int wordInfo(const char* filename, char *shortest, char *longest, char *lowest, char *highest) {
   // create a local variable large enough to hold one word (see spec for max size)
   // NOTE: suggestion is to read one word at a time, not a line
   // You don't need to store all of the words, just one. Process each word as it is read.

   // Task 1: open file, read one word at a time and count them
   // Task 2: remove punctuation from the end of a word
   // Task 3: find the longest and shortest words
   // Task 4: find the first and last words in alphabetical order

   FILE* file = fopen(filename, "r");
   if (file == NULL) return -1;

   char word[16];
   int wordCount = 0, longestLength, shortestLength;
   while (fscanf(file, "%s", word) != EOF) {
      wordCount++;
      removePunct(word);
      if (wordCount == 1) {
         strcpy(shortest, word);
         strcpy(longest, word);
         longestLength = shortestLength = strlen(word);
         strcpy(lowest, word);
         strcpy(highest, word);
         continue;
      }

      int wordLength = strlen(word);
      if (wordLength < shortestLength) {
         shortestLength = wordLength;
         strcpy(shortest, word);
      }
      else if (wordLength > longestLength) {
         longestLength = wordLength;
         strcpy(longest, word);
      }

      if (strcmp(word, lowest) < 0) strcpy(lowest, word);
      else if (strcmp(word, highest) > 0) strcpy(highest, word);
   }

   fclose(file);
   return wordCount;
}


// definition -- write your code here
void removePunct(char * string) {

   for (char* ptr = string + strlen(string) - 1; ptr >= string && ispunct(*ptr); *ptr-- = 0);
}
