#include "dominion.h"
#include "interface.h"
#include <stdio.h>

int main() {
  struct gameState g;

  int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
	       outpost,baron,tribute};

  initializeGame(2, k, 5, &g);
  
  addCardToHand(0, 7, &g);
  playCard(5, 0, 0, 0, &g);

  int i = numHandCards(&g);
  
  printf("%d\n", i);
  
  if(i == 7){
	  printf("Correct Adventurer behaviour\n");
  }
  else{
	  printf("FAILURE: Incorrect Adventurer behaviour\n");
  }
  
  return 0;
}
