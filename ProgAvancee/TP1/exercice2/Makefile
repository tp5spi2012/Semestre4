include Makefile.compilation 

#
# Objets
#

fich_obj_test_obj1=test_obj1.o obj1.o
fich_obj_test_obj1s=test_obj1s.o obj1s.o obj1.o

fich_obj_test_obj2=test_obj2.o obj2.o obj1s.o obj1.o
fich_obj_test_obj2s=test_obj2s.o obj2s.o obj2.o obj1s.o obj1.o

fich_obj_prog2=prog2.o obj2s.o obj2.o obj1s.o obj1.o

#
# Tests (executables+objets)
#

BIN = test_obj1 test_obj1s test_obj2 test_obj2s prog2

test_obj1 : $(fich_obj_test_obj1) 
	$(CCLNK) $(CFLAGS) $(LIBMATH) $(fich_obj_test_obj1) -o test_obj1 

test_obj1.o : test_obj1.c obj1.h
	$(CCOBJ) $(CFLAGS) $(LIBMATH) test_obj1.c -o test_obj1.o -I./ 

test_obj1s : $(fich_obj_test_obj1s) 
	$(CCLNK) $(CFLAGS) $(LIBMATH) $(fich_obj_test_obj1s) -o test_obj1s 

test_obj1s.o : test_obj1s.c obj1.h
	$(CCOBJ) $(CFLAGS) $(LIBMATH) test_obj1s.c -o test_obj1s.o -I./ 

test_obj2 : $(fich_obj_test_obj2) 
	$(CCLNK) $(CFLAGS) $(LIBMATH) $(fich_obj_test_obj2) -o test_obj2 

test_obj2.o : test_obj2.c obj1.h
	$(CCOBJ) $(CFLAGS) $(LIBMATH) test_obj2.c -o test_obj2.o -I./ 

test_obj2s : $(fich_obj_test_obj2s) 
	$(CCLNK) $(CFLAGS) $(LIBMATH) $(fich_obj_test_obj2s) -o test_obj2s 

test_obj2s.o : test_obj2s.c obj1.h
	$(CCOBJ) $(CFLAGS) $(LIBMATH) test_obj2s.c -o test_obj2s.o -I./ 

prog2 : $(fich_obj_prog2) 
	$(CCLNK) $(CFLAGS) $(LIBMATH) $(fich_obj_prog2) -o prog2 

prog2.o : prog2.c obj1s.h
	$(CCOBJ) $(CFLAGS) $(LIBMATH) prog2.c -o prog2.o -I./ 


#
# Modules(objets)
#

OBJ = obj1.o obj1s.o obj2.o obj2s.o

obj1.o : obj1.c obj1.h 
	$(CCOBJ) $(CFLAGS) $(LIBMATH) obj1.c -o obj1.o -I./

obj1s.o : obj1s.c obj1s.h 
	$(CCOBJ) $(CFLAGS) $(LIBMATH) obj1s.c -o obj1s.o -I./

obj2.o : obj2.c obj2.h 
	$(CCOBJ) $(CFLAGS) $(LIBMATH) obj2.c -o obj2.o -I./

obj2s.o : obj2s.c obj2s.h 
	$(CCOBJ) $(CFLAGS) $(LIBMATH) obj2s.c -o obj2s.o -I./

#
# Headers
#

obj1.h : commun.h
	touch obj1.h

obj1s.h : obj1.h 
	touch obj1s.h

obj2.h : obj1s.h
	touch obj2.h

obj2s.h : obj1.h 
	touch obj2s.h

#
#
#

all : $(BIN) $(OBJ)

clean :
	- rm  *.o
	- rm test_obj1
	- rm test_obj1s
	- rm test_obj2
	- rm test_obj2s
	- rm prog2

tests :
	./test_obj1
	./test_obj1s
	./test_obj2
	./test_obj2s
