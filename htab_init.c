// ===============     htab_init.c     ===============
// Řešení IJC-DU2, příklad b), 19.04.2022
//
// Autor: 		Michal Novák, FIT
// 				xnovak3g@stud.fit.vutbr.cz
//
// Přeloženo: 	gcc (Ubuntu 9.4.0-1ubuntu1~20.04) 9.4.0

#include "htab.h"
#include "htab_structs.h"
#include <stdlib.h>
#include <stdio.h>

htab_t * htab_init(size_t num){
	htab_t * t = malloc(sizeof(htab_t) + num * sizeof(struct htab_item *));
	if(t == NULL)
		return NULL;
	
	for(size_t i = 0; i<num; i++){
		t->arr_ptr[i] = NULL;
	}

	t->arr_size = num;
	t->size = 0;

	return t;
}
