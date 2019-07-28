/********************************************************************* 
 ** Name: RandomTestCard3
 ** Author: Matthew Fair
 ** Date: 7-23-2019
 ** Description: Random Testing for minion
 *********************************************************************/ 
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "randMethods.c"
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Minion"
void assertEqual(int, int);

int main() {
  int currentPlayer = 0;
  struct gameState state, originalState;

  printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
  // ----------- TEST 1: choice1--------------
  for(int i = 0; i < 10000; i++){
    int choice1 = randInt(0,1);
    int choice2 = randInt(0,1);
    int seed = randInt(1,10000);
    int k[10];
    setDeck(k, 10);
    int playerCount = randInt(2,4);
    initializeGame(playerCount, k, seed, &originalState);
    memcpy(&state, &originalState, sizeof(struct gameState));
    int handPos = randInt(0,state.handCount[currentPlayer]);

    playMinion(&state, currentPlayer, choice1, choice2, handPos);

    assertEqual(originalState.numActions + 1, state.numActions);
    if(choice1 ==1)
      assertEqual(originalState.coins + 2, state.coins);
  }

  printf("\n >>>>> Unit Test 1 SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

  return 0;
}