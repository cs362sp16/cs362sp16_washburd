#include "dominion.h"
#include <stdio.h>

int main() {
  struct gameState g;

  int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
	       outpost,baron,tribute};

  initializeGame(2, k, 5, &g);
  int i = numHandCards(&g);
  
  printf("%d\n",i);

  if(i == 5){
	  printf("Correct number of initial cards\n");
  }
  else{
	  printf("FAILURE: Incorrect number of initial cards\n");
  }
  
  return 0;
}
