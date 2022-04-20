// ===============     linked_list.c     ===============
// Řešení IJC-DU2, příklad a), 19.04.2022
//
// Autor: 		Michal Novák, FIT
// 				xnovak3g@stud.fit.vutbr.cz
//
// Přeloženo: 	gcc (Ubuntu 9.4.0-1ubuntu1~20.04) 9.4.0

#include "linked_list.h"

Element_t * element_ctor (char * line){
	Element_t *temp = (Element_t *)malloc(sizeof(Element_t));
	if(temp == NULL){
		return NULL;
	}
	temp->line=malloc(sizeof(char)*strlen(line));
	strcpy(temp->line, line);
	temp->next=NULL;
	return temp;
}

Element_t * remove_first (Element_t * list){
	Element_t * temp = list->next;
	temp->size=list->size;
	free(list->line);
	free(list);
	return temp;
}

Element_t * insert(Element_t * list, char * line, unsigned max_size){
	if(list==NULL){
		Element_t * temp = element_ctor(line);
		if(temp==NULL){
			return NULL;
		}
		temp->size = 1;
		return temp;
	}
	else{
		Element_t *temp=list;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=element_ctor(line);
		if(temp->next==NULL)
			return NULL;
		else{
			if(max_size>list->size){
				list->size++;
				return list;
			}
			else{
				return remove_first(list);
			}
		}
		
	}
}

void list_dtor(Element_t * list){
	for(Element_t * temp = list; temp != NULL;){
		Element_t *next = temp->next;
		free(temp->line);
		free(temp);
		temp=next;
	}
}
