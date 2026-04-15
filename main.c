#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int game(char you, char computer)
{
    if (you == computer)
        return -1;

    if (you == 's') {
        if (computer == 'p') return 0;
        else return 1;
    }

    if (you == 'p') {
        if (computer == 'z') return 0;
        else return 1;
    }

    if (you == 'z') {
        if (computer == 's') return 0;
        else return 1;
    }
}

int main()
{
    char name[20];
    char you, computer;
    int result, n;
    int user_score = 0, comp_score = 0;

    printf("\n===== RPS SHOWDOWN =====\n");
    printf("Enter your game name \n");
    scanf("%s", name);

    printf("\nHI!%s Welcome To The RPS SHOWDOWN \n",name);
    printf("Game will be played for 3 rounds.\n");

    srand(time(NULL));


    for (int round = 1; round <= 3; round++)
    {
        printf("\n--- Round %d ---\n", round);

        while (1)
        {
            printf("%s, enter your choice \n(s=STONE, p=PAPER, z=SCISSOR):\n ", name);
            scanf(" %c", &you);

            if (you == 's' || you == 'p' || you == 'z')
                break;
            else
                printf("Invalid input! Try again.\n");
        }

 
        n = rand() % 3;
        if (n == 0) computer = 's';
        else if (n == 1) computer = 'p';
        else computer = 'z';

        // Game result
        result = game(you, computer);

        if (result == -1)
            printf("Draw!\n");
        else if (result == 1) {
            printf("%s wins this round!\n", name);
            user_score++;
        }
        else {
            printf("Computer wons this round!\n");
            comp_score++;
        }

        printf("%s: %c  | Computer: %c\n", name, you, computer);
        printf("Score -> %s: %d | Computer: %d\n", name, user_score, comp_score);
    }

    printf("\n=== FINAL RESULT ===\n");

    if (user_score > comp_score)
        printf("🎉 %s wins the game!\n", name);
    else if (comp_score > user_score)
        printf("😢 Computer wins the game!\n");
    else
        printf("It's a Draw!\n");

    return 0;
}
