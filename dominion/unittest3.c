#include "dominion.h"
#include <stdio.h>

int main() {
  struct gameState g;

  int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
	       outpost,baron,tribute};

  initializeGame(2, k, 5, &g);
  int i = whoseTurn(&g);

  if(i == 0){
	  printf("Correct initial player\n");
  }
  else{
	  printf("FAILURE: Incorrect initial player\n");
  }
  
  return 0;
}
