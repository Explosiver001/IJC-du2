// ===============     htab_resize.c     ===============
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

void htab_resize(htab_t **t, size_t newn){

	htab_t * new = htab_init(newn);
	if(new == NULL)
		return;
	
	for(size_t i = 0; i < (*t)->arr_size; i++){
		for(htab_item_t * item = (*t)->arr_ptr[i]; item!=NULL;){
			htab_item_t * next = item->next;
			uint32_t hash = htab_hash_function(item->data->key);
			item->next = NULL;
			if(new->arr_ptr[hash%newn] == NULL){
				new->arr_ptr[hash%newn] = item;
				new->arr_ptr[hash%newn]->next = NULL;
			}
			else{
				for(htab_item_t * tmp = new->arr_ptr[hash%newn]; ; tmp=tmp->next){
					if(tmp->next == NULL){
						
						tmp->next = item;
						tmp->next->next = NULL;
						break;
					}
				}
			}
			item = next;
		} 	
	}
	
	free(*t);

	*t=new;
}