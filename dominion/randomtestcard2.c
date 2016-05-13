#include "dominion.h"
#include "interface.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	
	srand(atoi(argv[0]));
	
	struct gameState g;
	
	int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
		outpost,baron,tribute};
	
	int tests, i, handCount, deckCount, numActions, player;
	
	tests = 2048;  //Number of loops through
	player = 0;
	
	for(i=0; i<tests; i++){
		initializeGame(2, k, 5, &g);
		
		g.handCount[player] = rand()%50;
		g.deckCount[player] = rand()%50;
		g.numActions = rand()%50;
		
		handCount = g.handCount[player];
		deckCount = g.deckCount[player];
		numActions = g.numActions;
		
		addCardToHand(player, 14, &g);
		playCard(handCount, 0, 0, 0, &g);
		
	}
	
	return 0;
	
}

