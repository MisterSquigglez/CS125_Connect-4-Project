/****************************************************************************
* File:   Project.c
* Author:   Priyanshu Kumar and Rashel Calderon-Sanchez
* Purpose:  This program allows two people to play Connect 4.
* Version:  1.0 Feb 27, 2020 added win conditions
*               1.1 March 5, 2020 added input arguements
*               1.2 March 10, 2020 added character arrays
*               1.3 March 20, 2020 integrated various parts of the code
*               1.4 March 22, 2020 cleaned up code and added comments        
* Resources: Learned how to input characters in the middle of a string via
*                https://stackoverflow.com/questions/14042047/copy-specific-characters-from-a-string-to-another-string
*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main(){

    char array[6][24];
    char inputcolchar[100];
    char o[7] = "[o][x]";
    int inputcol, turn = 0, x = 0, x1, x2, x3;
    int arrayint[6][7], color, a, b, tie = 1;
    int y1shift = 0, y2shift = 0, y3shift = 0, y4shift = 0, y5shift = 0, y6shift = 0, y7shift = 0;

/*****************************************************************************
Game Setup: Creates a character array to create a display for the game
            Creates an integer array to keep track of which spot contains an x or an o
            Integer array is used to determine if someone has won or not
*****************************************************************************/

    for (x = 0; x < 6; x++){
        strcpy(array[x],"[ ][ ][ ][ ][ ][ ][ ]");
   }
    for (x = 0; x < 6; x++){
        for (x1 = 0; x1 < 7; x1++){
            arrayint[x][x1] = 0;
       }
   }

//Print empty Connect 4 board

    for (x = 0; x < 6; x++){
        printf("%s",array[x]);
        printf("\n");

   }
        printf("\n");
/*******************************************************************************
Actual Game: Various while and if loops detect input to a corresponding column
             Turn only progresses to the next player if a valid input is recived
             
             For loops prints the Connect 4 board at the end of every turn  

             A spot in the integer array is set to 1 (O player) or 2 (X player) depending on what spot the user has placed their chip in 
*******************************************************************************/
    while (turn < 43){
        if (turn%2 == 0){
            x2 = 0;
            x3 = 1;
            printf("\nPlayer 1. It is your turn\n");
       }
        else if (turn%2 == 1){
            x2 = 3;
            x3 = 2;
            printf("\nPlayer 2. It is your turn\n");
       }           

        printf("Enter a column: ");
        fgets(inputcolchar, 100, stdin);
        inputcol=atoi(inputcolchar);

        if (inputcol >= 1 && inputcol <= 7){
            while ((y1shift == 6 && inputcol == 1) || (y2shift == 6 && inputcol == 2) || (y3shift == 6 && inputcol == 3) || (y4shift == 6 && inputcol == 4) || (y5shift == 6 && inputcol == 5) || (y6shift == 6 && inputcol == 6) || (y7shift == 6 && inputcol == 7) && (inputcol < 1 && inputcol > 7)){
                printf("Column %d is full. Try another column.\n", inputcol);
                fgets(inputcolchar, 100, stdin);
                inputcol=atoi(inputcolchar);
                if (inputcol == 0){
                    printf("\nInvalid Input.\n");
               }
           }

                if (inputcol == 1){
                    strncpy(array[5-y1shift],&o[x2],3);
                    arrayint[5-y1shift][0] = x3;
                    y1shift = y1shift + 1;
               }
                else if (inputcol == 2){
                    strncpy(&array[5-y2shift][3],&o[x2],3);
                    arrayint[5-y2shift][1] = x3;
                    y2shift = y2shift + 1;
               }
                else if (inputcol == 3){
                    strncpy(&array[5-y3shift][6],&o[x2],3);
                    arrayint[5-y3shift][2] = x3;
                    y3shift = y3shift + 1;
               }
                else if (inputcol == 4){
                    strncpy(&array[5-y4shift][9],&o[x2],3);
                    arrayint[5-y4shift][3] = x3;
                    y4shift = y4shift + 1;
               }
                else if (inputcol == 5){
                    strncpy(&array[5-y5shift][12],&o[x2],3);
                    arrayint[5-y5shift][4] = x3;
                    y5shift = y5shift + 1;
               }
                else if (inputcol == 6){
                    strncpy(&array[5-y6shift][15],&o[x2],3);
                    arrayint[5-y6shift][5] = x3;
                    y6shift = y6shift + 1;
               }
                else if (inputcol == 7){
                    strncpy(&array[5-y7shift][18],&o[x2],3);
                    arrayint[5-y7shift][6] = x3;
                    y7shift = y7shift + 1;
               }

            printf("\n");
            for (x = 0; x < 6; x++){
                printf("%s",array[x]);
                printf("\n");
           }
            if (inputcol > 0 && inputcol < 8){
                turn++;
           }
       }

        else{
            printf("Invalid Input. Try again\n");
       }

/******************************************************************************
Win Conditions: After every turn, the integer array goes through various for loops to see if someone has won
                If a winner is found, the game exits via various break commands or it keeps on going until the game is a tie
******************************************************************************/

//Vertical Wins
        for (color = 1; color < 3; color++){
            for (a = 3 ; a <= 5 ; a++){
              for (b = 6; b >= 0; b--){
                if (arrayint[a][b] == color && arrayint [a-1][b] == color && arrayint [a-2][b] == color && arrayint [a-3][b] == color){
                  if(color == 1){
                    printf("\e[1;34mO Wins!\n");
                    tie = 0;
                    break;
                 }
                  if(color == 2){
                    printf("\e[1;31mX Wins!\n");
                    tie = 0;
                    break;
                 }
               }
             }
           }
        }

//Horizontal Wins
        for (color = 1; color < 3; color++){
            for (a = 0 ; a <= 5 ; a++){
              for (b = 3; b >= 0; b--){
                if (arrayint[a][b] == color && arrayint [a][b+1] == color && arrayint [a][b+2] == color && arrayint [a][b+3] == color){
                  if(color == 1){
                    printf("\e[1;34mO Wins!\n");
                    tie = 0;
                    break;
                 }
                  if(color == 2){
                    printf("\e[1;31mX Wins!\n");
                    tie = 0;
                    break;
                 }
               }
             }
           }
        }

//Forward Slash Diagonal Wins
        for (color = 1; color < 3; color++){
            for (a = 0 ; a <= 2 ; a++){
              for (b = 6; b >= 3; b--){
                if (arrayint[a][b] == color && arrayint [a+1][b-1] == color && arrayint [a+2][b-2] == color && arrayint [a+3][b-3] == color){
                  if(color == 1){
                    printf("\e[1;34mO Wins!\n");
                    tie = 0;
                    break;
                 }
                  if(color == 2){
                    printf("\e[1;31mX Wins!\n");
                    tie = 0;
                    break;
                 }
               }
             }
           }
        }

//Backward Slash Diagonal Wins
        for (color = 1; color < 3; color++){
            for (a = 2 ; a >= 0 ; a--){
              for (b = 6; b >= 3; b--){
                if (arrayint[a+3][b] == color && arrayint [a+2][b-1] == color && arrayint [a+1][b-2] == color && arrayint [a+0][b-3] == color){
                  if(color == 1){
                    printf("\e[1;34mO Wins!\n");
                    tie = 0;
                    break;
                 }
                  if(color == 2){
                    printf("\e[1;31mX Wins!\n");
                    tie = 0;
                    break;
                 }
               }
             }
           }
        }

//Check if a win or tie has occured
        if(tie == 1 && turn == 42){
          printf("\e[1;32mTie!\n");
          break;
       }
        else if(tie == 0){
            break;
       }

   }
    return 0;
}

