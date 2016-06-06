#include "dominion.h"
#include "interface.h"
#include <stdio.h>

int main(int argc, char** argv) {
  struct gameState g;

  int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
	       outpost,baron,tribute};

  int seed;
  if(argc == 1){
	  seed = atoi(argv[1]);
  }
  else{
	  seed = 42;
  }
  
  initializeGame(2, k, seed, &g);
  
  addCardToHand(0, 13, &g);
  playCard(5, 0, 0, 0, &g);

  int i = numHandCards(&g);
  
  printf("%d\n", i);
  
  if(i == 8){
	  printf("Correct Smithy card draw\n");
  }
  else{
	  printf("FAILURE: Incorrect Smithy card draw\n");
  }
  
  return 0;
}
