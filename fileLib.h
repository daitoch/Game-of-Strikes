#include "gameLib.h"
#include <stdlib.h>

int record;

FILE * openFile(int argc, char* argv[], char *mode);
int readFile(Phrase phrase[], FILE *fptr);
void writeFile(Phrase phrase[], int index, FILE* fptr);