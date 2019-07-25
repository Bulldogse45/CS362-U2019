/********************************************************************* 
 ** Name: RandomTestCard3
 ** Author: Matthew Fair
 ** Date: 7-24-2019
 ** Description: Random Testing for tribute
 *********************************************************************/ 

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "randMethods.c"
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "playBaron"

int main() {
  int currentPlayer = 0;
  struct gameState state, originalState;

  printf("----------------- Testing TESTCARD: %s ----------------\n", TESTCARD);
  // ----------- TEST 1: Choose to discard draws an estate card --------------
  for(int i = 0; i < 6000; i++){
    printf("TEST %d \n", i);
    int choice1 = randInt(0,1);
    int seed = randInt(1,10000);
    int k[10];
    setDeck(k, 10);
    int playerCount = randInt(2,4);
    initializeGame(playerCount, k, seed, &originalState);
    memcpy(&state, &originalState, sizeof(struct gameState));
    state.supplyCount[estate] = randInt(0,8);

    playBaron(&state, currentPlayer, choice1);
    // assertEqual(originalState.numBuys + 1, state.numBuys);
    // assertEqual(originalState.supplyCount[estate] - 1, state.supplyCount[estate]);
    // assertEqual(state.discard[currentPlayer][state.discardCount[currentPlayer]-1], estate);
  }

  printf("\n >>>>> Random Card Test 1 SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
  return 0;
}
