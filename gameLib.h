#ifndef _GAMELIB_H
#define _GAMELIB_H

#include<stdlib.h>
#include<stdio.h>

#define MAX_ENTRIES 10
#define MAX_SIZE 100
#define STRIKES 3

typedef struct gameLib
{
    char *artist;
    char *song;
    char *name;
    char year[5];
}Phrase;



int startGame(FILE *fptr, Phrase phrase[]);
void dashIt(char song[], char line[]);
int UserGuess(char Words[], char Letter[], char Capital[]);

#endif