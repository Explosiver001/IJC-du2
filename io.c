// ===============     io.c     ===============
// Řešení IJC-DU2, příklad b), 19.04.2022
//
// Autor: 		Michal Novák, FIT
// 				xnovak3g@stud.fit.vutbr.cz
//
// Přeloženo: 	gcc (Ubuntu 9.4.0-1ubuntu1~20.04) 9.4.0

#include "io.h"

int read_word(char *s, int max, FILE *f){

	if(f==NULL){
		printf("ERROR");
	}
	
	for(int i = 0; i<max; i++){
		s[i]=0;
	}

	//clear white space
	int c;
	while((c=fgetc(f))!=EOF && isspace(c));

	if(c == EOF)
		return EOF;

	if(max == 0){
		return 0;
	}

	bool tooLong = false;
	int ret=1;
	
	s[0]=c;

	while((c=fgetc(f)) != EOF && !isspace(c)){
		if(ret<=max-1){
			s[ret] = c;
			s[++ret] = 0;
		}
		else{
			tooLong = true;
		}
	}

	if(tooLong){
		return ret+ERROR_NUM;
	}

	else{
		return ret;
	}
}



