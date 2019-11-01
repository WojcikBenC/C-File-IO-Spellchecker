spell.o: spell.c
	gcc -c spell.c

spell_lib.o: spell_lib.c
	gcc -c spell_lib.c

out: spell.o spell_lib.o
	gcc -o out spell.o spell_lib.o

clean: spell.o spell_lib.o
	rm spell.o
	rm spell_lib.o
