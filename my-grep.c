/* Tero Nevalainen */
/* My-grep */
/* LÄhteet: https://www.tutorialspoint.com/c_standard_library/c_function_strstr.htm man-sivut*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int grep(char *, char *);

int main(int argc, char *argv[]) {
  int i;
  char str[100];
  if (argc <= 1) {								//Liian vähän syötteitä
    printf("my-grep: searchterm [file ...]\n"); 
    exit(1);
  } 
  for (i=2; i<argc; i++) {						//Oikeanlainen syöte
    grep(argv[1], argv[i]);						//grep funktiolle syöte ja tiedostonimet
  }
  if (argc == 2) {								//Standard inputista luku, strstr vertaa-
    while(fgets(str, 100, stdin) != NULL) {		//syötteitä keskenään ja printtaa jos samoja
      if (strstr(str, argv[1])) {
		printf("%s", str);
      } 
    }
    return(0);
  } 
  return(0); 
}

int grep(char *syote, char *argv) {
  FILE *fp;
  if ((fp = fopen(argv, "r")) == NULL) {		//Tiedoston avaus/olemassaolon tarkistus
    printf("My-grep: Cannot open file\n");
    exit(1);
  }
  size_t koko = 0;
  char *rivi = NULL;
  while(getline(&rivi, &koko, fp) != -1) {		//Rivien luku ja merkkijonojen vertaus
    if  (strstr(rivi, syote)) {
      printf("%s", rivi);
    }
  }
  fclose(fp);
  return(0);
}
