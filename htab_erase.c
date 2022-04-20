// ===============     htab_erase.c     ===============
// Řešení IJC-DU2, příklad b), 19.04.2022
//
// Autor: 		Michal Novák, FIT
// 				xnovak3g@stud.fit.vutbr.cz
//
// Přeloženo: 	gcc (Ubuntu 9.4.0-1ubuntu1~20.04) 9.4.0

#include "htab.h"
#include "htab_structs.h"
#include <stdlib.h>
#include <stdint.h>

bool htab_erase(htab_t * t, htab_key_t key){
	uint32_t hash = htab_hash_function(key);

	htab_item_t * prev = NULL;
	htab_item_t * item;

	for(item = t->arr_ptr[hash%t->arr_size]; item!=NULL; prev = item, item = item->next){
		if(!strcmp(item->data->key, key)){
			if(prev == NULL)
				t->arr_ptr[hash%t->arr_size] = NULL;
			else
				prev->next = item->next;
			
			free(item->data->key);
			free(item->data);
			free(item);

			t->size--;

			return true;
		}
	}

	return false;
}

