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
#include <assert.h>
#include "rngs.h"
#include "randMethods.c"
#include <stdlib.h>

#define TESTCARD "Tribute"

int main() {
  int currentPlayer = 0;
  int nextPlayer = 1;
  int tributeRevealedCards[2] = {-1, -1};
  struct gameState state, originalState;

  // initialize a game state and player cards

  printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
  // ----------- TEST 1:  --------------

  for(int i = 0; i < 3000; i++){
    int seed = randInt(1,10000);
    int k[10];
    setDeck(k, 10);
    int playerCount = randInt(2,4);
    initializeGame(playerCount, k, seed, &originalState);
    memcpy(&state, &originalState, sizeof(struct gameState));

    printf("TEST %d: \n", i);
    state.deckCount[nextPlayer] = randInt(0,2);
    state.discardCount[nextPlayer] = randInt(0,2);
    for(int i = 0; i < state.deckCount[nextPlayer]; i++){
      state.deck[nextPlayer][i] = randCard(k, 10); // gold
    }
    for(int j = 0; j < state.discardCount[nextPlayer]; j++){
      state.discard[nextPlayer][j] = randCard(k, 10); //duchy
    }
    playTribute(&state, currentPlayer, nextPlayer, tributeRevealedCards);
    if(state.deckCount[nextPlayer] + state.discardCount[nextPlayer] > 1){
      assertNotEqual(-1, tributeRevealedCards[0]);
      assertNotEqual(-1, tributeRevealedCards[1]);
    } else if(state.deckCount[nextPlayer] + state.discardCount[nextPlayer] == 1){
      assertNotEqual(-1, tributeRevealedCards[0]);
      assertEqual(-1, tributeRevealedCards[1]);
    }
    // assertEqual(originalState.deckCount[nextPlayer] - 2, state.deckCount[nextPlayer]); 
    // assertEqual(originalState.coins + 2, state.coins); 
    // assertEqual(originalState.handCount[currentPlayer] + 2, state.handCount[currentPlayer]); 
  }
 
  printf("\n >>>>> Random Test SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
  return 0;
}