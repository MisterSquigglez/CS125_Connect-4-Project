//Win Conditions Code will be written here
 
int color, x, y, array[6][7], tie = 1

//blue = 1
//red = 2
//Vertical Wins
for (color = 1; color <= 2; color++){
    for (x = 0 ; x <= 6 ; x++){
      for (y = 5; y >= 3; y--){
        if (array[x][y] == color, array [x][y-1] == color, array [x][y-2] == color, array [x][y-3] == color){
          if(color == 1){
            printf("Blue Wins!");
            tie = 0;
         }
          if(color == 2){
            printf("Red Wins!");
            tie = 0;
         }
       }
     }
   }
}

//Horizontal Wins
for (color = 1; color <= 2; color++){
    for (x = 0 ; x <= 3 ; x++){
      for (y = 5; y >= 0; y--){
        if (array[x][y] == color, array [x+1][y] == color, array [x+2][y] == color, array [x+3][y] == color){
          if(color == 1){
            printf("Blue Wins!");
            tie = 0;
         }
          if(color == 2){
            printf("Red Wins!");
            tie = 0;
         }
       }
     }
   }
}

//Forward Slash Diagonal Wins
for (color = 1; color <= 2; color++){
    for (x = 0 ; x <= 3 ; x++){
      for (y = 5; y >= 3; y--){
        if (array[x][y] == color, array [x+1][y-1] == color, array [x+2][y-2] == color, array [x+3][y-3] == color){
          if(color == 1){
            printf("Blue Wins!");
            tie = 0;
         }
          if(color == 2){
            printf("Red Wins!");
            tie = 0;
         }
       }
     }
   }
}

//Backward Slash Diagonal Wins
for (color = 1; color <= 2; color++){
    for (x = 3 ; x >= 0 ; x--){
      for (y = 5; y >= 3; y--){
        if (array[x+3][y] == color, array [x+2][y-1] == color, array [x+1][y-2] == color, array [x+0][y-3] == color){
          if(color == 1){
            printf("Blue Wins!");
            tie = 0;
         }
          if(color == 2){
            printf("Red Wins!");
            tie = 0;
         }
       }
     }
   }
}

if (tie = 1){
  printf("Tie!");
}

