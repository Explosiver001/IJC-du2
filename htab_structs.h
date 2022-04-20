// ===============     htab_structs.h     ===============
// Řešení IJC-DU2, příklad b), 19.04.2022
//
// Autor: 		Michal Novák, FIT
// 				xnovak3g@stud.fit.vutbr.cz
//
// Přeloženo: 	gcc (Ubuntu 9.4.0-1ubuntu1~20.04) 9.4.0

#ifndef _HTAB_STRUCTS_H_
#define	_HTAB_STRUCTS_H_

#include "htab.h"

struct htab_item;
typedef struct htab_item htab_item_t;

htab_item_t * htab_item_init(htab_key_t key);

struct htab_item{
	htab_item_t * next;
	htab_pair_t * data;     
};

struct htab{
	size_t size;
	size_t arr_size;
	htab_item_t * arr_ptr[];
};

#endif