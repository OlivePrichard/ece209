// ECE 209, Fall 2025 - Program 2
// Wordle game

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "random.h"
#include "wordle.h"

// User interface for ECE 209 Wordle game
int main(void) {

    // get name of dictionary file from user
    char filename[21];  // name must be 20 chars or less
    printf("Dictionary file: "); fflush(stdout);
    scanf("%20s", filename);

    int wordCount = 0;     // number of words in the dictionary
    bool playGame = true;   // flag to control game play loop

    wordCount = loadDictionary(filename);
    if (!wordCount) {
        printf("Could not open file: %s\n", filename);
        return 0;
    }
    printf("There are %d words in the dictionary.\n", wordCount);

    // seed the random number generator -- this just happens once
    // each time you use the same seed, you will get the same sequence of words
    unsigned int seed = 10000;
    while ((seed < 1000) || (seed > 9999)) {
        printf("Enter any number between 1000 and 9999: ");  fflush(stdout);
        scanf("%u", &seed);
    }
    seedRandom(seed * seed);


    const unsigned int numTries = 6;   // user gets this many attempts to guess the word

    while (playGame) {
        const char * soln = getRandomWord();

        // error checking -- nothing stored by function into string
        if (!soln || soln[0] == '\0') {
            printf("Unable to choose word from dictionary\n");
            break;
        }

        bool wordleWin = false;    // flag to signal correct Wordle guess
        char guess[6] = "";
        char outcome[6] = "";
        unsigned int guessCount = 0;
        char option[2] = "";   // Y or N for play again
        while (!wordleWin && (guessCount < numTries)) {
            printf("Guess %d: ", guessCount+1); fflush(stdout);
            scanf("%5s", guess);
            if (findGuess(guess)) {
                printf("Result:  "); fflush(stdout);
                int score = checkGuess(guess, soln, outcome);
                printf("%s\n", outcome);
                if (score == 5) wordleWin = true;
                ++guessCount;
                printf("\n");
            }
            else {
                // if word is not in the dictionary, it's not a valid guess
                printf("This word is not in my dictionary -- try again.\n\n");
                // this also handles the case where the guess is not 5 characters
            }
            // in case user typed more than 5 characters, remove the extras
            // read and ignore characters until a linefeed is found
            while (fgetc(stdin) != '\n');
        }
        if (wordleWin) {
            printf("Congratulations! You solved it in %d tries.\n", guessCount);
        }
        else {
            printf("\nSorry, you are out of tries.  The solution is %s.\n", soln);
        }
        while (1) {
            printf("\nDo you want to play again?  (y or n)\n"); fflush(stdout);
            scanf("%1s", option);
            if ((option[0] == 'n') || (option[0] == 'N')) {
                playGame = false;
                break;
            }
            else if ((option[0] == 'y') || (option[0] == 'Y')) {
                break;
            }
        }

    }
    return 0;
}