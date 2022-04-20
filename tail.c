// ===============     tail.c     ===============
// Řešení IJC-DU2, příklad a), 19.04.2022
//
// Autor: 		Michal Novák, FIT
// 				xnovak3g@stud.fit.vutbr.cz
//
// Přeloženo: 	gcc (Ubuntu 9.4.0-1ubuntu1~20.04) 9.4.0


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include "linked_list.h"

int main (int argc, char *argv[]) {
	long max_lines = 10; 
	bool stdinput = true;
	FILE *input=stdin;
	if(argc > 1){
		if(argc == 2){
			if (!strcmp("-n", argv[1])){
				fprintf(stderr, "Je pouzit prepinac -n a neni zadano cislo!\n");
				return 1;
			}
			else{
				if((input=fopen(argv[1], "r"))==NULL){
					fprintf(stderr, "Soubor \"%s\" nelze otevrit!\n", argv[1]);
					return 1;
				}
				stdinput=false;
			}
		}
		if(argc>=3 && argc<=4){
			char * endptr;
			long temp = strtoll(argv[2], &endptr, 10);
			if(endptr[0]!='\0'){
				fprintf(stderr, "Cislo je ve spatnem tvaru!\n");
				return 1;
			}
			if (strcmp("-n", argv[1])){
				fprintf(stderr, "Neni pouzit prepinac -n!\n");
				return 1;
			}
			max_lines=temp;
			if(argc==4){
				if((input=fopen(argv[3], "r"))==NULL){
					fprintf(stderr, "Soubor \"%s\" nelze otevrit!\n", argv[3]);
					return 1;
				}
				stdinput=false;
			}
		}
		if(argc>4){
				fprintf(stderr, "Spoustejte ve formatu:\n\ttail soubor\n\ttail <soubor\n\ttail -n <cislo> soubor\n\ttail -n <cislo> <soubor\n");
				return 1;
		}
	}
	Element_t * head = NULL;

	if(max_lines<0){
		fprintf(stderr, "Pocet radku musi byt kladne cele cislo\n");
		return 1;
	}
	if(max_lines==0){
		return 0;
	}

	for(unsigned count = 1; true; count++){
		char line[MAX_CHARS] = {0};
		int c;
		bool error = false;

		for(int i = 0; (c=fgetc(input))!='\n' && c!=EOF; i++){
			if(i<MAX_CHARS-1)
				line[i] = c;
			else 
				error = true;
		}	

		if(c == EOF)
			break;
			

		if(error)
			fprintf(stderr, "Radek c. %u je prilis dlouhy!\n", count);

		if((head = insert(head, line, max_lines))==NULL){
				fprintf(stderr, "Chyba alokace pameti!\n");
				return 1;
			}
	}

	//Vypis poslednich N radku
	for(Element_t * temp = head; temp != NULL; temp=temp->next){
		printf("%s\n", temp->line);
	}

	
	list_dtor(head);
	if(!stdinput){
		fclose(input);
	}

	return 0;
}