#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

char *card_name(int arg){
	switch(arg){
		case adventurer: return "adventurer";
		case council_room: return "council_room";
		case feast: return "feast";
		case great_hall: return "great_hall";
		case mine: return "mine";
		case remodel: return "remodel";
		case smithy: return "smithy";
		case curse: return "curse";
		case estate: return "estate";
		case duchy: return "duchy";
		case ambassador: return "ambassador";
		case cutpurse: return "cutpurse";
		case embargo: return "embargo";
		case outpost: return "outpost";
		case salvager: return "salvager";
		case sea_hag: return "sea_hag";
		case province: return "province";
		case copper: return "copper";
		case silver: return "silver";
		case gold: return "gold";
		case gardens: return "gardens";
		case village: return "village";
		case baron: return "baron";
		case minion: return "minion";
		case steward: return "steward";
		case tribute: return "tribute";
		case treasure_map: return "treasure_map";
		default: return "";
	}
}

int main (int argc, char** argv) {
  struct gameState G;
  struct gameState *p = &G;

  srand(atoi(argv[1]));
  
  int a[20] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, 
			village, baron, great_hall, minion, steward, tribute, ambassador, 
			cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};
  
  int j[10], k[10];
  
  int i, ii;
  for(i=0; i<10; i++){
	  int loop = 1;
	  while(loop){
		  j[i] = rand()%20;
		  for(ii=0; ii<i; ii++){
			  if(j[ii] == j[i]){
				  loop++;
				  break;
			  }
		  }
		  loop--;
	  }
  }
  
  for(i=0; i<10; i++){
	k[i] = a[j[i]];
  }
  
  for(i=0; i<10; i++){
	  printf("%s ", card_name(k[i]));
	  //printf("%d %s\n", k[i], card_name(k[i]));
  }
  printf("\n");
  
  int players = rand()%3+2;
  printf("Players: %d\n\n", players);

  printf ("Starting game.\n");
  
  initializeGame(players, k, atoi(argv[1]), p);
  
  i = 0;

  while (!isGameOver(p)) {
	
	int active = whoseTurn(p);
	
	printf("Player %d\n", active);
	
	while(p->numActions > 0){
		int playing = rand()%p->handCount[active]+1;
		if(playing == p->handCount[active]){	//Chance to stop playing cards early
			printf("Stop playing cards early\n");
			break;
		}
		else{
			if(playCard(playing, rand()%20, rand()%20, rand()%20, p) != -1){
				printf("Playing %s\n", card_name(handCard(playing,p)));
			}
		}
	}
	
	while(p->numBuys > 0){
		int action = rand()%18;
		
		if(action <= 6){			//Attempting to get a utility card, i.e. silver or province
			if(buyCard(action, p) != -1){
				printf("Buying %s\n", card_name(action));
			}
		}
		else if(action == 17){		//Chance to end turn early
			printf("Stop buying cards early\n");
			break;
		}
		else{						//Attempt to buy one of the randomly selected cards
			if(buyCard(k[action-7], p) != -1){
				printf("Buying %s\n", card_name(k[action-7]));
			}
		}
	}
	
	printf("END_TURN\n\n");
	
	printf("Deck Size: %d\nDiscard Size: %d\n\n", p->deckCount[active], p->discardCount[active]);
	
	endTurn(p);
	
	/*
    if (whoseTurn(p) == 0) {
      if (money >= 8) {
        printf("0: bought province\n"); 
        buyCard(province, p);
      }
      else if (money >= 6) {
        printf("0: bought gold\n"); 
        buyCard(gold, p);
      }
      else if (money >= 3) {
        printf("0: bought silver\n"); 
        buyCard(silver, p);
      }

      printf("0: end turn\n");
      endTurn(p);
    }
	*/
	
      //printf ("Player 0: %d\nPlayer 1: %d\n", scoreFor(0, p), scoreFor(1, p));
	    
  } // end of While

  printf ("Finished game.\n");
  printf ("Player 0: %d\nPlayer 1: %d\n", scoreFor(0, p), scoreFor(1, p));

  return 0;
}

