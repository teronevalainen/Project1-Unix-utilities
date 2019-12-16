/* Tero Nevalainen */
/*My-cat.c*/
/*Lähteet: https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm
           man sivut*/

#include <stdio.h>
#include <stdlib.h>
int cat(char *);

int main(int argc, char *argv[]) {
  int i;
  if (argc <= 1) {							//Jos syöte <=1 ohjelman lopetus
    return(1);
  }
  for (i=1; i<argc; i++) {					//Syötteet cat funktioon 
    cat(argv[i]);
  }
  return(0);
}
int cat(char *argv) {
  char x[100];
  int koko = 100;
  FILE *fp;
  if ((fp = fopen(argv, "r")) == NULL) {	//Tiedoston avaus ja virheen tarkistus
    printf("My-cat: Cannot open file\n");
    exit(1);
  }
  while (fgets(x, koko, fp)) {				//Tulostus 
  	printf("%s", x);
  }
  fclose(fp);
  return(0);
}
