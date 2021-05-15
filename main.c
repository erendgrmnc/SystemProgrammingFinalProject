#include <stdio.h>
#include <string.h>
#include "./libfdr/fields.h"
#include "./libfdr/jval.h"
#include "./libfdr/jrb.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

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

 JRB b;
 JRB bn;
 JRB rnode;

main(argc, argv)
int argc;
char **argv;
{
  IS is;
  //True ise encrypt False ise Decryption işlemi yapılır.
  int isEncryptOrDecrypt = 0;
  int i;
  
  b = make_jrb();


  if (argc != 4) {
    fprintf(stderr, "Eksik parametre girildi\n");
    exit(1);
  }

  if(strcmp(argv[1],"-d") == 0){

    isEncryptOrDecrypt = 0;
  }
  else if(strcmp(argv[1],"-e") == 0){

    isEncryptOrDecrypt = 1;
  }
  else{
    perror("Yanlis Komut Girildi !");
    exit(1);
  }

  is = new_inputstruct(strdup(argv[2]));

  if (is == NULL) {
    perror("dosya bulunamadi !");
    exit(1);
  }

  Jval dataKey[5000];
  Jval dataVal[5000];
  Jval txtData[5000];
  int dataCounter = 0;

int txtWordCounter = 0;

   while(get_line(is) >= 0) {
     for (i = 0; i < is->NF; i++) {
      txtData[txtWordCounter].s = strdup(is->fields[i]);
      txtWordCounter++;
    }
  }
  is = NULL,
  is = new_inputstruct(".kilit");

  while(get_line(is) >= 0) {
    for (i = 0; i < is->NF; i++) {
      if(i != (is->NF - 1) || i != 0){
         
          RemoveChars(is->fields[i],',');
          RemoveChars(is->fields[i],'"');
          RemoveChars(is->fields[i],':');
          
          if(i % 2 == 0){
            dataKey[dataCounter].s = strdup(is->fields[i] + '\0');
          }
          else{
            dataVal[dataCounter].s = strdup(is->fields[i]);
          }
          
          if(i % 2 == 1){

            int control = 0;
            int counter = 0;

            if(isEncryptOrDecrypt == 1)
            {
              jrb_insert_str(b,strdup(dataKey[dataCounter].s),new_jval_s(strdup(dataVal[dataCounter].s)));
            }
            else
            {
               jrb_insert_str(b,strdup(dataVal[dataCounter].s),new_jval_s(strdup(dataKey[dataCounter].s)));
            }

            dataCounter++;
          }
         
      }
    
    }
  }

  jettison_inputstruct(is);
  exit(0);
}