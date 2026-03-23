#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cash = 100;   // global variable

void Play(int bet) {

    char C[3] = {'J', 'Q', 'K'};

    printf("Shuffling...\n");

    srand(time(NULL));

    for (int i = 0; i < 5; i++) {
        int x = rand() % 3;
        int y = rand() % 3;

        char temp = C[x];
        C[x] = C[y];
        C[y] = temp;
    }

    int playersGuess;

    printf("What is the position of the queen (1, 2 or 3)? ");
    scanf("%d", &playersGuess);

    if (C[playersGuess - 1] == 'Q') {
        cash += 3 * bet;
        printf("You Won! Result = \"%c %c %c\" Total cash = %d\n",
               C[0], C[1], C[2], cash);
    }
    else {
        cash -= bet;
        printf("You Lose! Result = \"%c %c %c\" Total cash = %d\n",
               C[0], C[1], C[2], cash);
    }
}

int main() {

    int bet;

    while (cash > 0) {

        printf("What's your bet? $");
        scanf("%d", &bet);

        if (bet == 0 || bet > cash)
            break;

        Play(bet);
    }

    return 0;
}