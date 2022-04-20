// ===============     htab_hash_function.c     ===============
// Řešení IJC-DU2, příklad b), 19.04.2022
//
// Autor: 		Michal Novák, FIT
// 				xnovak3g@stud.fit.vutbr.cz
//
// Přeloženo: 	gcc (Ubuntu 9.4.0-1ubuntu1~20.04) 9.4.0

#include <stddef.h>
#include <stdint.h>

size_t htab_hash_function(const char *str) {
	uint32_t h=0;     // musí mít 32 bitů
	const unsigned char *p;
	for(p=(const unsigned char*)str; *p!='\0'; p++)
		h = 65599*h + *p;
	return h;
}