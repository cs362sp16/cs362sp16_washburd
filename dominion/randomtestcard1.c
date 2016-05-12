#include "dominion.h"
#include "interface.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	
	struct gameState g;
	
	int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
		outpost,baron,tribute};
	
	int tests, i, handCount, deckCount, player;
	
	tests = 2048;  //Number of loops through
	player = 0;
	
	for(i=0; i<tests; i++){
		initializeGame(2, k, 5, &g);
		
		g.handCount[player] = rand()%500;
		g.deckCount[player] = rand()%500;
		
		handCount = g.handCount[player];
		deckCount = g.deckCount[player];
		
		addCardToHand(player, 13, &g);
		playCard(handCount, 0, 0, 0, &g);
		
		if(g.handCount[player] == handCount+3){
			printf("%d\n", i);
		}
		
		if(g.deckCount[player] == deckCount-3){
			printf("%d\n", i);
		}
		
	}
	
	return 0;
	
}

