#include "../libfdr/jval.h"

typedef union {
    char** keys;
    int* values;
} Jval;

void parseJSON(char** key, int* value);