#include "htab.h"
#include "htab_structs.h"
// ===============     htab_lookup_add.c     ===============
// Řešení IJC-DU2, příklad b), 19.04.2022
//
// Autor: 		Michal Novák, FIT
// 				xnovak3g@stud.fit.vutbr.cz
//
// Přeloženo: 	gcc (Ubuntu 9.4.0-1ubuntu1~20.04) 9.4.0

#include <stdint.h>
#include <stdio.h>

htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key){
	uint32_t hash = htab_hash_function(key);
	htab_item_t * item = t->arr_ptr[hash%t->arr_size];

	if(item == NULL){
		t->arr_ptr[hash%t->arr_size]=htab_item_init(key);
		t->size++;
		return t->arr_ptr[hash%t->arr_size];
	}

	htab_item_t * prev;
	for(; item != NULL; prev = item, item=item->next){
		if(!strcmp(key, item->data->key)){
			item->data->value++;
			return item->data;
		}
	}
	prev->next=htab_item_init(key);
	t->size++;
	return prev->next;
}
