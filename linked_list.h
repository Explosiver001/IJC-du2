// ===============     linked_list.h     ===============
// Řešení IJC-DU2, příklad a), 19.04.2022
//
// Autor: 		Michal Novák, FIT
// 				xnovak3g@stud.fit.vutbr.cz
//
// Přeloženo: 	gcc (Ubuntu 9.4.0-1ubuntu1~20.04) 9.4.0


#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 4095

typedef struct element Element_t;
struct element {
	char * line;
	Element_t * next;
	unsigned size;
};

Element_t * element_ctor (char * line);

Element_t * remove_first (Element_t * list);

Element_t * insert(Element_t * list, char * line, unsigned max_size);

void list_dtor(Element_t * list);

#endif