#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// Function to generate a 4-digit number with unique digits
void generateSecretNumber(char secret[]) {
    bool used[10] = {false};
    int i = 0;

    while (i < 4) {
        int digit = rand() % 10;
        if (!used[digit]) {
            secret[i] = digit + '0';
            used[digit] = true;
            i++;
        }
    }
    secret[4] = '\0';
}

// Function to count bulls and cows
void getBullsAndCows(char guess[], char secret[], int *bulls, int *cows) {
    *bulls = 0;
    *cows = 0;

    for (int i = 0; i < 4; i++) {
        if (guess[i] == secret[i]) {
            (*bulls)++;
        } else {
            for (int j = 0; j < 4; j++) {
                if (guess[i] == secret[j]) {
                    (*cows)++;
                    break;
                }
            }
        }
    }
}

// Check if guess has 4 unique digits
bool isValidGuess(char guess[]) {
    if (strlen(guess) != 4) return false;

    bool used[10] = {false};
    for (int i = 0; i < 4; i++) {
        if (guess[i] < '0' || guess[i] > '9') return false;
        int digit = guess[i] - '0';
        if (used[digit]) return false;
        used[digit] = true;
    }
    return true;
}

int main() {
    char secret[5];
    char guess[10];
    int attempts = 0;
    int bulls, cows;

    srand(time(NULL));
    generateSecretNumber(secret);

    printf("Welcome to Bulls and Cows!\n");
    printf("Guess the 4-digit number with unique digits.\n");

    do {
        printf("Enter your guess: ");
        scanf("%s", guess);

        if (!isValidGuess(guess)) {
            printf("Invalid guess. Please enter 4 unique digits.\n");
            continue;
        }

        attempts++;
        getBullsAndCows(guess, secret, &bulls, &cows);
        printf("Bulls: %d, Cows: %d\n", bulls, cows);

    } while (bulls != 4);

    printf("Congratulations! You guessed the number %s in %d attempts.\n", secret, attempts);
    return 0;
}
