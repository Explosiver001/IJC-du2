// ===============     io.h     ===============
// Řešení IJC-DU2, příklad b), 19.04.2022
//
// Autor: 		Michal Novák, FIT
// 				xnovak3g@stud.fit.vutbr.cz
//
// Přeloženo: 	gcc (Ubuntu 9.4.0-1ubuntu1~20.04) 9.4.0

#ifndef _IO_H_
#define	_IO_H_

#define ERROR_NUM 1000

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int read_word(char *s, int max, FILE *f);

#endif