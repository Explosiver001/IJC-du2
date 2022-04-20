# ===============     Makefile     ===============
# Řešení IJC-DU2, 19.04.2022
#
# Autor: 		Michal Novák, FIT
# 				xnovak3g@stud.fit.vutbr.cz
#

CC = gcc
CC2 = g++
CFLAGS = -w -std=c11 -pedantic -Wall -Wextra
CPPFLAGS = -std=c++17 -pedantic -Wall 

OBJECT_FILES = htab_hash_function.o htab_init.o htab_item_init.o htab_size.o htab_bucket_size.o htab_find.o htab_lookup_add.o htab_erase.o htab_resize.o htab_for_each.o htab_clear.o htab_free.o

all: tail wordcount wordcount-dynamic clean


tail: tail.c linked_list.h linked_list.c
	@$(CC) $(CFLAGS) tail.c linked_list.c -o tail

wordcount: wordcount.c libhtab.a io.o io.h
	@$(CC) $(CFLAGS) -static wordcount.c libhtab.a io.o -o wordcount

wordcount-dynamic: wordcount.c libhtab.so io.o io.h
	@$(CC) $(CFLAGS) wordcount.c libhtab.so io.o -o wordcount-dynamic
	@ export LD_LIBRARY_PATH="."

#spusti wordcount-dynamic 
run: wordcount-dynamic libhtab.so io.o io.h
	@ LD_LIBRARY_PATH="." ./wordcount-dynamic

comp: wordcount.cc 
	@$(CC2) $(CPPFLAGS) wordcount.cc -o wordcount-cpp


#FUNKCE

io.o: io.c io.h
	@$(CC) $(CFLAGS) -fPIC -c io.c

htab_hash_function.o: htab_hash_function.c htab.h htab_structs.h
	@$(CC) $(CFLAGS) -fPIC -c htab_hash_function.c

htab_init.o: htab_init.c htab.h htab_structs.h
	@$(CC) $(CFLAGS) -fPIC -c htab_init.c

htab_item_init.o: htab_item_init.c htab.h htab_structs.h 
	@$(CC) $(CFLAGS) -fPIC -c htab_item_init.c

htab_size.o: htab_size.c htab.h htab_structs.h
	@$(CC) $(CFLAGS) -fPIC -c htab_size.c

htab_find.o: htab_find.c htab.h htab_structs.h
	@$(CC) $(CFLAGS) -fPIC -c htab_find.c

htab_lookup_add.o: htab_lookup_add.c htab.h htab_structs.h
	@$(CC) $(CFLAGS) -fPIC -c htab_lookup_add.c

htab_erase.o: htab_erase.c htab.h htab_structs.h
	@$(CC) $(CFLAGS) -fPIC -c htab_erase.c

htab_bucket_size.o: htab_bucket_size.c htab.h htab_structs.h
	@$(CC) $(CFLAGS) -fPIC -c htab_bucket_size.c

htab_resize.o: htab_resize.c htab.h htab_structs.h
	@$(CC) $(CFLAGS) -fPIC -c htab_resize.c

htab_for_each.o: htab_for_each.c htab.h htab_structs.h
	@$(CC) $(CFLAGS) -fPIC -c htab_for_each.c

htab_clear.o: htab_clear.c htab.h htab_structs.h
	@$(CC) $(CFLAGS) -fPIC -c htab_clear.c

htab_free.o: htab_free.c htab.h htab_structs.h
	@$(CC) $(CFLAGS) -fPIC -c htab_free.c

#KNIHOVNY

libhtab.a: $(OBJECT_FILES)
	@ar rcs libhtab.a $(OBJECT_FILES)

libhtab.so: $(OBJECT_FILES)
	@$(CC) $(CFLAGS) -fPIC -shared $(OBJECT_FILES) -o libhtab.so


#POMOCNE

clean:
	@rm *.o

zip: *.c *.cc *.h Makefile
	zip xnovak3g.zip *.c *.cc *.h Makefile
