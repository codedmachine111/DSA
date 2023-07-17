#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

// Function to create a new position
struct node* createPosition(int value) {
    struct node* newPosition = (struct position*)malloc(sizeof(struct node));
    newPosition->value = value;
    newPosition->next = NULL;
    return newPosition;
}

// Function to create a game board
struct node* createGameBoard(int numPositions) {
    struct node* start = NULL;
    struct node* current = NULL;
    
    for (int i = 1; i <= numPositions; i++) {
        struct node* newPosition = createPosition(i);
        
        if (start == NULL) {
            start = newPosition;
            current = start;
        } else {
            current->next = newPosition;
            current = newPosition;
        }
    }
    
    current->next = start;
    return start;
}

// Function to display the game board
void displayGameBoard(struct node* start, int numPositions) {
    if (start == NULL) {
        printf("Game board is empty!\n");
        return;
    }
    
    struct node* current = start;
    printf("Game Board: ");
    for (int i = 1; i <= numPositions; i++) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("Loop back to %d\n", start->value);
}

// Function to simulate player movement on the game board
void playGame(struct node* start, int numPositions, int numPlayers) {
    if (start == NULL) {
        printf("Game board is empty!\n");
        return;
    }
    
    struct node* currentPlayer = start;
    
    printf("Starting the game...\n");
    while (1) {
        for (int i = 1; i <= numPlayers; i++) {
            printf("Player %d's turn: Current position - %d\n", i, currentPlayer->value);
            currentPlayer = currentPlayer->next;
        }
        
        printf("Press 'n' to continue to the next round, 'q' to quit: ");
        char choice;
        scanf(" %c", &choice);
        
        if (choice == 'q') {
            break;
        }
        
        printf("\n");
    }
}

// Main function
int main() {
    int numPositions, numPlayers;
    
    printf("Enter the number of positions on the game board: ");
    scanf("%d", &numPositions);
    
    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);
    
    struct node* start = createGameBoard(numPositions);
    
    displayGameBoard(start, numPositions);
    printf("\n");
    
    playGame(start, numPositions, numPlayers);
    
    return 0;
}
