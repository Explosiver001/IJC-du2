// ===============     htab_for_each.c     ===============
// Řešení IJC-DU2, příklad b), 19.04.2022
//
// Autor: 		Michal Novák, FIT
// 				xnovak3g@stud.fit.vutbr.cz
//
// Přeloženo: 	gcc (Ubuntu 9.4.0-1ubuntu1~20.04) 9.4.0

#include "htab.h"
#include "htab_structs.h"

void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data)){
	htab_item_t * item;

	for(size_t i = 0; i<t->arr_size; i++){
		for(item=t->arr_ptr[i]; item!=NULL; item=item->next){
			(*f)(item->data);
		}
	}
}