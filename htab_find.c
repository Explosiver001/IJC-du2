// ===============     htab_find.c     ===============
// Řešení IJC-DU2, příklad b), 19.04.2022
//
// Autor: 		Michal Novák, FIT
// 				xnovak3g@stud.fit.vutbr.cz
//
// Přeloženo: 	gcc (Ubuntu 9.4.0-1ubuntu1~20.04) 9.4.0

#include "htab.h"
#include "htab_structs.h"
#include <stdint.h>

htab_pair_t * htab_find(htab_t * t, htab_key_t key){
	uint32_t hash = htab_hash_function(key);
	

	for(htab_item_t * item = t->arr_ptr[hash%t->arr_size]; item!=NULL; item=item->next){
		if(!strcmp(item->data->key, key))
			return item->data;
	}
	
	return NULL;
}


