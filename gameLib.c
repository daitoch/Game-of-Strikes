#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "gameLib.h"
#include "fileLib.h"
int startGame(FILE *fptr, Phrase phrase[]){
    int record = readFile(phrase, fptr);
    printf("Welcome to 3 STRIKES -YOU'RE OUT!!!! -the CSE version\n");
    puts("");
	printf("Pick any song from the given menu: \n");
    puts("");
    int i = 0;
    while (i < record)
    {
        printf("%d. %s's song that was released in %s on album %s", i+1, phrase[i].artist, phrase[i].year, phrase[i].name);
        ++i;
    }
    
    int  UserChoice=0;
	while (UserChoice>=i || UserChoice==0)   //we counted the total number of strings in the above loop and assigned to i
	{
		printf("Enter Your Choice: ");
		scanf("%d", &UserChoice);
		getchar();
	}
    return UserChoice;
}
void dashIt(char song[], char line[]){
    int j=0; 
	char A1[]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *occur= NULL;

	strcpy(line, song);
	for (j=0; j< strlen(line);j++)
	{
		line[j]= toupper(line[j]);
	}
	occur= strpbrk(line, A1);
	while (occur!=NULL)
	{
		*occur= '-';
		occur= strpbrk(line, A1);
	}
}

int UserGuess(char Words[], char Letter[], char Capital[])
{
	char Guess;
	char *FindGuess= NULL;
	char UpperPhraseCopy[MAX_SIZE];
	int FoundALetter=0;
	strcpy(UpperPhraseCopy, Capital);
	printf(" %s", Letter);            //i guess?
	printf("\n Guess a random letter of your choice: ");
	scanf(" %c", &Guess);
	getchar();
	Guess= toupper(Guess);
	FindGuess= strchr(UpperPhraseCopy, Guess);
	int Totallength=0;
	
	while(FindGuess!=NULL)
	{
		FoundALetter = 1;
		Totallength= abs(FindGuess - UpperPhraseCopy);
		Letter[Totallength]= Words[Totallength];
		UpperPhraseCopy[Totallength]= '-';
		FindGuess= strchr(UpperPhraseCopy, Guess);
		
	}
	return FoundALetter;
}
