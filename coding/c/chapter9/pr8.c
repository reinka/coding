#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>


int roll_dice(void);
bool play_game(void);

int main(void)
{

   bool play;
   int win = 0, lose = 0;
   char ch = 'y';

   while(ch != 'n' && ch != 'N'){
	play = play_game();

   	if(play){
	   printf("You win!\n");
	   win++;
   	}
  	 else{
	   printf("You lose!\n");
	   lose++;
  	 }

   	printf("Play again (y/n)? ");
  	scanf(" %c", &ch);
   }

   printf("Wins: %d   Losses: %d\n", win, lose);

   return 0;     
}

int roll_dice(void)
{
   int dice_1, dice_2;
  
   dice_1 = (rand() % 6 ) + 1;
   dice_2 = (rand() % 6 ) + 1;

   return dice_1 + dice_2;
}

bool play_game(void)
{
   int sum, point;
   
   srand((unsigned) time(NULL));
   
   sum = roll_dice();
   printf("You rolled: %d\n", sum);
   if(sum == 7 || sum == 11)
	return true;
   else if( sum == 2 || sum == 3 || sum == 12)
	return false;
   else{
	point = sum;
	printf("Your point is %d\n", point);
	for(;;){
	   sum = roll_dice();
	   printf("You rolled: %d\n", sum);
	   if(sum == point){
		return true;
	   }
	   else if( sum == 7) {
		return false;
	   }
	}
	
	return false;
   }
}
