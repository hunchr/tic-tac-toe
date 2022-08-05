#include <stdio.h>

// Board
char b[9] = {
    '-', '-', '-',
    '-', '-', '-',
    '-', '-', '-'
};

// Player
int p = 'X';

char nextTurn() {
    int choice;

    // Get choice
    printf("\nPlayer %c, what will you do? (1-9)> ", p);
    scanf("%i", &choice);

    // Validate choice
    while (b[choice-1] != '-') {
        printf("You cannot do this, try again! (1-9)> ");
        scanf("%i", &choice);
    }

    b[choice-1] = p;

    // Print board
    printf("\n");
    for (int i=1; i<10; i++) {
        printf(i % 3 == 0 ? "%c\n" : "%c", b[i-1]);
    }

    // Check if player won
    if (
        // Horizontal
        b[0] == p && b[1] == p && b[2] == p ||
        b[3] == p && b[4] == p && b[5] == p ||
        b[6] == p && b[7] == p && b[8] == p ||
        // Vertical
        b[0] == p && b[3] == p && b[6] == p ||
        b[1] == p && b[4] == p && b[7] == p ||
        b[2] == p && b[5] == p && b[8] == p ||
        // Diagonal
        b[0] == p && b[4] == p && b[8] == p ||
        b[2] == p && b[4] == p && b[6] == p
    ) {
        // Print winner and exit game
        printf("\nCongrats, Player %c, you won!\n", p);
        return 0;
    }
    else {
        // Change player
        p = p == 'X' ? 'O' : 'X';
        return 1;
    }
}

int main() {
    int turns = 0;

    while (nextTurn()) {
        if (++turns == 9) {
            printf("\nWell played, it's a draw!\n");
            return 0;
        }
    }
    return 0;
}
