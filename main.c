#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "gameLib.h"
#include "fileLib.h"

int main(int argc, char *argv[])
{
    char letter[MAX_SIZE], line[MAX_SIZE], Capital[MAX_SIZE];
    char *Line;
    int takeout = 0, chosen;

    puts("");
    Phrase phrase[MAX_ENTRIES];
    FILE *fptr = openFile(argc, argv, "r+");
    chosen = startGame(fptr, phrase);
    dashIt(phrase[chosen-1].song, line);

    for(int i=0; i< strlen(phrase[chosen-1].song); i++)
	{
		Capital[i]= toupper(*(phrase[chosen-1].song+i));
	}
    
    puts("");
    printf("Here's the phrase you need to guess \n");

    UserGuess(phrase[chosen-1].song, line, Capital);

    do
	{
		int FinalResults= UserGuess(phrase[chosen-1].song, line, Capital);	
		Line = strchr(line, '-');
	
		if (FinalResults==0)
		{
			takeout++;	

			printf("\n Strike! %d\n", takeout);

		}
	}while(Line != NULL && takeout < STRIKES);
	
	if (takeout >=STRIKES)
	{
		printf("Total of %d Strikes!! That means: YOU ARE OUT!!\n", STRIKES);
		printf("**GAME OVER!!**");
	}else{
		printf("Correct! You Found it!!\n");
		printf("\nThe Pharse is: \n");
		printf("%s", phrase[chosen-1].song);	
		printf("\n WINNER!!!");
        writeFile(phrase, chosen-1, fptr);
		
	}

    puts("");
    return 0;
}
