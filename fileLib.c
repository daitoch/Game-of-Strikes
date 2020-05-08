#include <stdio.h>
#include <stdlib.h>
#include "fileLib.h"
#include <string.h>

FILE * openFile(int argc, char * argv[], char* mode){
    FILE *fptr;
    if (argc >= 2)
    {
         fptr = fopen(argv[1], mode);
    }
    else
    {
        while(fptr == NULL){
        fprintf(stderr, "[!] Failed to open the file\nPlease enter a correct name: ");
        char name[50];
        scanf("%s", name);
        fptr = fopen(name, mode);
        }
    }
    return fptr;
}
int readFile(Phrase phrase[] , FILE *fptr){
    int i = 0;
    char data[100];
    char *token;
    while (fgets(data, 100, fptr) != NULL && i < MAX_ENTRIES){
        
        if (data[0] == '#' || data[0] ==' ' || data[0] == '\n')
        {
            continue;
        }
        
        phrase[i].artist = (char *)malloc(sizeof(char *)*100);
        phrase[i].song = (char *)malloc(sizeof(char *)*100);
        phrase[i].name = (char *)malloc(sizeof(char *)*100);

        if ( phrase[i].artist != NULL && phrase[i].song != NULL && phrase[i].name != NULL)
        {
            token = strtok(data, "|");
            strcpy( phrase[i].artist, token);
            token = strtok(NULL, "|");
            strcpy( phrase[i].song, token);
            token = strtok(NULL, "|");
            strcpy( phrase[i].year, token);
            token = strtok(NULL, "|");
            strcpy( phrase[i].name, token);
        }
        ++i;
        ++record;
    }
    return record;
}
void writeFile(Phrase phrase[], int index, FILE* fptr){
    fseek(fptr, 0, SEEK_SET);
    fseek(fptr, 0, SEEK_END);
    long length = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);
    for (int i = 0; i < record; i++)
    {
        if (i == index)
        {
            continue;
        }
        else
        {
            fprintf(fptr, "%s|", phrase[i].artist);
            fprintf(fptr, "%s|", phrase[i].song);
            fprintf(fptr, "%s|", phrase[i].year);
            fprintf(fptr, "%s", phrase[i].name);
        }
        
    }
    
    while (ftell(fptr) <= length)
    {
        fprintf(fptr, "%s", " ");
    }

    for (int i = 0; i < record; i++)
    {
        free(phrase[i].artist);
        free(phrase[i].song);
        free(phrase[i].name);
    }
    
    fclose(fptr);
    printf("this is fucked");
}