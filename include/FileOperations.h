#include "../libfdr/fields.h"

typedef struct inputstruct {
  char** keys;
  int values;
} IS; 

void fileReader(char* fileName);

void fileWriter(char* fileName);