// ===============     htab_clear.c     ===============
// Řešení IJC-DU2, příklad b), 19.04.2022
//
// Autor: 		Michal Novák, FIT
// 				xnovak3g@stud.fit.vutbr.cz
//
// Přeloženo: 	gcc (Ubuntu 9.4.0-1ubuntu1~20.04) 9.4.0

#include "htab.h"
#include "htab_structs.h"
#include <stdlib.h>


void htab_clear(htab_t * t){
	for(size_t i = 0; i<t->arr_size; i++){
		for(htab_item_t * item = t->arr_ptr[i]; item != NULL; item = t->arr_ptr[i]){
			t->arr_ptr[i]=item->next;
			free(item->data->key);
			free(item->data);
			free(item);
		}
	}
}