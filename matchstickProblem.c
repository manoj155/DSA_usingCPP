// Write a C program for a matchstick game played between the computer and a user. Your program should ensure that 
// the computer always wins. Rules for the game are 
// 1) There are 21 matchstick, 
// 2) The computer asks the  player to pick 1, 2, 3, or 4 matchsticks. 
// 3) After the person picks, the computer does it picking. 
// 4) Whoever is forced to pick up the last matchstick lose the game.

#include<stdio.h>

int main() {
    int totalMatchstick = 21;
    int flag = 0; //user input karega intially user==0 computer==1
    int userInput; // to get input from user
    int compInput; //for computer input

    while(totalMatchstick) //jab tak totalMatchstick 0 nehi hoga while chalta rahega
    {
        if(totalMatchstick==1 && flag==0) // jab matchstick = 1 aur user ko next input karna hai
        {
            printf("User lost!");
            break;
        }
        
        if(flag==0) //user ko input karna hai
        {
            //taking user input
            printf("Please input a number between 1-4: ");
            scanf("%d", &userInput);
            while(userInput<1 || userInput>4) {
                printf("Incorrect input! Please input a number between 1-4: ");
                scanf("%d", &userInput);
            }
            printf("User Input: %d\n",userInput);
            totalMatchstick = totalMatchstick - userInput;
            flag = 1;
        }
        else //computer ko input karna hai
        {
            compInput = 5 - userInput;
            printf("Computer Input: %d\n",compInput);
            totalMatchstick = totalMatchstick - (compInput);
            flag = 0;
        }
    }

    return 0;
}