/********************************************************************* 
 ** Name: RandomMethods:
 ** Author: Matthew Fair
 ** Date: 7-23-2019
 ** Description: Random methods
 *********************************************************************/ 
#include <stdio.h> 
#include <stdlib.h> 
#include<time.h> 
  
int randInt(int min, int max)
{ 
  return (rand() % (max - min+ 1)) + min; 
} 

int randCard(int *cards, int cardCount)
{ 
  return cards[randInt(0, cardCount)];
}

void setDeck(int *cards, int cardsNeeded){
    int uniqCheck;
    for(int i=10-cardsNeeded; i<10; i++){
        do {
            uniqCheck = 1;
            int newCard = rand()%27;
            for(int j=0; j<i; j++){
                if(cards[j] == newCard){
                   uniqCheck = 0;
                }
           }
           cards[i] = newCard;
        } while(uniqCheck == 0);
    }
}

void assertNotEqual(int a, int b){
  if(a == b)
    printf("\n >>>>> Failure: %d = %d <<<<<\n\n", a, b);
}

void assertEqual(int a, int b){
  if(a != b)
    printf("\n >>>>> Failure: %d != %d <<<<<\n\n", a, b);
}
