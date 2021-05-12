#include <stdio.h>
#include "./libfdr/fields.h"
void RemoveChars(char *s, char c)
{
    int writer = 0, reader = 0;

    while (s[reader])
    {
        if (s[reader]!=c) 
        {   
            s[writer++] = s[reader];
        }

        reader++;       
    }

    s[writer]=0;
}

main(argc, argv)
int argc;
char **argv;
{
  IS is;
  int i;

  if (argc != 2) {
    fprintf(stderr, "usage: printwords filename\n");
    exit(1);
  }
 
  is = new_inputstruct(argv[1]);
  if (is == NULL) {
    perror(argv[1]);
    exit(1);
  }

  while(get_line(is) >= 0) {
    for (i = 0; i < is->NF; i++) {
      if(i != (is->NF - 1) || i != 0){
         
          RemoveChars(is->fields[i],',');
          RemoveChars(is->fields[i],'"');
          RemoveChars(is->fields[i],':');
         
      
       printf("%d: %d %s\n", is->line,i, is->fields[i]);
      }
    }
  }

  jettison_inputstruct(is);
  exit(0);
}