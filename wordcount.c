// ===============     wordcount.c     ===============
// Řešení IJC-DU2, příklad b), 19.04.2022
//
// Autor: 		Michal Novák, FIT
// 				xnovak3g@stud.fit.vutbr.cz
//
// Přeloženo: 	gcc (Ubuntu 9.4.0-1ubuntu1~20.04) 9.4.0

#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "io.h"

#define MAX_CHARS 127

void print_pair(htab_pair_t * data){
	printf("%s\t%d\n", data->key, data->value);
}

int main (int argc, char *argv[]) {	
	htab_t *t = htab_init(1000);

	char word[MAX_CHARS] = {0};
	int code;
	bool error = false;
	while((code = read_word(&word, MAX_CHARS, stdin)) != EOF){
		if(code>1000 && !error){
			fprintf(stderr, "Slovo bylo delsi nez maximalni mozna delka <%d> a bylo zkraceno! Tato zprava se nebude opakovat.\n", MAX_CHARS);
			error=true;
		}
		htab_lookup_add(t, word);
		
		if(htab_bucket_count(t) > htab_size(t));
			htab_resize(&t, htab_size(t)+500);
	}

	htab_for_each(t, &print_pair);

	htab_free(t);

	return 0;
}