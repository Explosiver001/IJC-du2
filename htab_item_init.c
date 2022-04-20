// ===============     htab_item_init.c     ===============
// Řešení IJC-DU2, příklad b), 19.04.2022
//
// Autor: 		Michal Novák, FIT
// 				xnovak3g@stud.fit.vutbr.cz
//
// Přeloženo: 	gcc (Ubuntu 9.4.0-1ubuntu1~20.04) 9.4.0

#include "htab.h"
#include "htab_structs.h"
#include <stdlib.h>

htab_item_t * htab_item_init(htab_key_t key){
	htab_item_t * item = malloc(sizeof(htab_item_t));
	if(item == NULL)
		return NULL;

	item->data = malloc(sizeof(htab_pair_t));
	if(item->data == NULL)
		return NULL;

	item->data->key=malloc(sizeof(char)*strlen(key));
	if(item->data->key == NULL)
		return NULL;

	strcpy(item->data->key, key);
	item->data->value=1;

	item->next=NULL;

	return item;
}