#include "dominion.h"
#include <stdio.h>

int main() {
  struct gameState g;

  int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
	       outpost,baron,tribute};

  initializeGame(2, k, 5, &g);
  int i = supplyCount(3,&g);

  if(i > 0){
	  printf("Card count works\n");
  }
  else{
	  printf("FAILURE: Card count not finding cards\n");
  }
  return 0;
}
