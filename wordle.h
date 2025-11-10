// ECE 209, Fall 2025 - Program 2

#ifndef WORDLE_H
#define WORDLE_H

#include <stdbool.h>

// Function: loadDictionary
// load all words from a dictionary file and store into the dictionary (see the .c file for info)

// all words are guaranteed to be exactly 5 characters long
// (no need for checking or protecting against errors)

// parameter is a string that gives the NAME of the file to be loaded
// the return value is the number of words read from the file and stored in the dictionary
// if the file cannot be opened, return 0

int loadDictionary(const char *fname);

// Function: getRandomWord
// select a random word from the dictionary

// There is no parameter.  You must use the getRandom function from the random.h file,
// and you must call it in such a way that any word in the dictionary may be selected.

// The return value is a pointer to the selected word.

const char * getRandomWord();

// Function: getWordByIndex
// return a specified word from the dictionary
// (This function will only be used to test whether you have read and stored the words correctly.
// It is not called in the main function.)

// The parameter is an unsigned integer, specifying an index into the dictionary.
// The dictionary words must be indexed in the same order as they appear in the file.

// The return value is a pointer to the selected word.
const char * getWordByIndex(unsigned int index);

// Function: findGuess
// search for a specified word in the dictionary

// Parameter is a string. (You should not make any assumptions about the size or nature of the string.)
// If the string appears in the dictionary, return true; otherwise, return false.

bool findGuess(const char *guess);

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

int checkGuess(const char *guess, const char *soln, char *outcome);


#endif //WORDLE_H