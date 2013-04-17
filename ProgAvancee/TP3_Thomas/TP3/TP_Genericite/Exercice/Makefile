include Makefile.compilation

#
# Objets
#

fich_obj_test_individu=test_individu.o individu.o
fich_obj_test_fraction=test_fraction.o fraction.o
fich_obj_test_mystring=test_mystring.o mystring.o
fich_obj_test_liste=test_liste.o liste.o individu.o fraction.o mystring.o


#
# Tests (executables+objets)
#

BIN = test_individu test_fraction test_mystring test_liste 

test_individu : $(fich_obj_test_individu) 
	$(CCLNK) $(CFLAGS) $(LIBMATH) $(fich_obj_test_individu) -o test_individu 

test_individu.o : test_individu.c 
	$(CCOBJ) $(CFLAGS) $(LIBMATH) test_individu.c -o test_individu.o -I./ 

test_fraction : $(fich_obj_test_fraction) 
	$(CCLNK) $(CFLAGS) $(LIBMATH) $(fich_obj_test_fraction) -o test_fraction 

test_fraction.o : test_fraction.c 
	$(CCOBJ) $(CFLAGS) $(LIBMATH) test_fraction.c -o test_fraction.o -I./ 

test_mystring : $(fich_obj_test_mystring) 
	$(CCLNK) $(CFLAGS) $(LIBMATH) $(fich_obj_test_mystring) -o test_mystring 

test_mystring.o : test_mystring.c 
	$(CCOBJ) $(CFLAGS) $(LIBMATH) test_mystring.c -o test_mystring.o -I./ 

test_liste : $(fich_obj_test_liste) 
	$(CCLNK) $(CFLAGS) $(LIBMATH) $(fich_obj_test_liste) -o test_liste 

test_liste.o : test_liste.c 
	$(CCOBJ) $(CFLAGS) $(LIBMATH) test_liste.c -o test_liste.o -I./ 

#
# Modules
#

OBJ= individu.o fraction.o mystring.o liste.o

individu.o : individu.c individu.h
	$(CCOBJ) $(CFLAGS) $(LIBMATH) individu.c -o individu.o -I./

fraction.o : fraction.c fraction.h 
	$(CCOBJ) $(CFLAGS) $(LIBMATH) fraction.c -o fraction.o -I./

mystring.o : mystring.c mystring.h 
	$(CCOBJ) $(CFLAGS) $(LIBMATH) mystring.c -o mystring.o -I./

liste.o : liste.c liste.h 
	$(CCOBJ) $(CFLAGS) $(LIBMATH) liste.c -o liste.o -I./


#
# Headers 
#

liste.h : commun.h
	touch liste.h

#
#
#

all : $(BIN) $(OBJ)

clean :
	- rm  *.o
	- rm test_individu
	- rm test_fraction
	- rm test_mystring
	- rm test_liste

tests : 
	./test_individu
	./test_fraction
	./test_mystring
	./test_liste

