// ECE 209, Fall 2025 -- Program 2
// functions to implement Wordle game

#include "wordle.h"
#include "random.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ****** DO THIS *******
// Declare a global variable to hold the words in the dictionary.
// You may assume that no dictionary file will have more than 10,000 words.
// Your variable must be an array of some sort, and the order of the words
// must be exactly the same as the order in the dictionary file.
char* dictionary = NULL;

// ****** DO THIS *******
// Declare a global variable to hold the number of words in the dictionary.
// This will only be used by functions in this file.
int dictLen = 0;



// Function: loadDictionary
// load all words from a dictionary file and store into the dictionary (see the .c file for info)

// all words are guaranteed to be exactly 5 characters long
// (no need for checking or protecting against errors)

// parameter is a string that gives the NAME of the file to be loaded
// the return value is the number of words read from the file and stored in the dictionary
// if the file cannot be opened, return 0

int loadDictionary(const char *fname) {
    FILE* file = fopen(fname, "r");
    if (!file) return 0;
    dictLen = 0;
    dictionary = (char*)malloc(sizeof(char)*10000*6);
    char* word = dictionary;
    while (EOF != fscanf(file, "%s ", dictionary + 6 * dictLen)) dictLen++;
    return dictLen;
}

// Function: getRandomWord
// select a random word from the dictionary

// There is no parameter.  You must use the getRandom function from the random.h file,
// and you must call it in such a way that any word in the dictionary may be selected.

// The return value is a pointer to the selected word.

const char * getRandomWord() {
    return dictionary + 6 * getRandom(dictLen);
}

// Function: getWordByIndex
// return a specified word from the dictionary
// (This function will only be used to test whether you have read and stored the words correctly.
// It is not called in the main function.)

// The parameter is an unsigned integer, specifying an index into the dictionary.
// The dictionary words must be indexed in the same order as they appear in the file.

// The return value is a pointer to the selected word.
const char * getWordByIndex(unsigned int index) {
    return dictionary + 6 * index;
}

// Function: findGuess
// search for a specified word in the dictionary

// Parameter is a string. (You should not make any assumptions about the size or nature of the string.)
// If the string appears in the dictionary, return true; otherwise, return false.

bool findGuess(const char *guess) {
    for (int i = 0; i < dictLen; i++) { // simple linear search
        if (strcmp(guess, dictionary + 6 * i) == 0) return true;
    }
    return false;
}

// Function: checkGuess
// compare the guess to the solution, and return string showing exact and misplaced matches

// The first two parameters are the guess string and the solution string.  You may assume that
// both the guess and the solution are exactly 5 characters long.

// The third parameter points to an array where you must create the matching string.
// Exact matches are indicated by * (asterisk).
// Misplaced matches are indicated by | (vertical bar).
// Non-matching characters are indicated - (hyphen).
// Do not assume anything about the array, except that it will be large enough to hold a 5-character string.
// See the specification document for more details on the matching process.

// The return value is the number of exact matches.

int checkGuess(const char *guess, const char *soln, char *outcome) {
    char mutSol[6] = ""; // copy the solution and remove letters to handle double yellow logic
    strcpy(mutSol, soln);
    strcpy(outcome, "-----"); // put all gray in the outcome and only handle green and yellow
    int greens = 0;
    for (int i = 0; i < 5; i++) { // first pass detects greens
        if (guess[i] == soln[i]) {
            outcome[i] = '*';
            mutSol[i] = ' '; // remove letter once it is referenced in the feedback
            greens++;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (guess[i] == soln[i]) continue;
        char* ptr = strchr(mutSol, guess[i]);
        if (!ptr) continue;
        // at this point we know the letter is in the word but not in the same place
        // the letter is yellow, but we remove it from the solution to handle double yellows
        // ex:
        // solution = meter
        // guess    = eerie
        // feedback = |*|--
        // note how all 3 Es get different colors

        outcome[i] = '|';
        *ptr = ' '; // remove used up letter
    }
    return greens;
}
