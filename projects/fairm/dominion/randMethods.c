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