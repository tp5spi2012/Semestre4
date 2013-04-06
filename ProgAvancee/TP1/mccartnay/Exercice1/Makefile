include Makefile.compilation

#
# Objets
#
fich_obj_prog1=prog1.o 

#
# Tests (executables+objets)
#

BIN = prog1 

prog1 : $(fich_obj_prog1) 
	$(CCLNK) $(CFLAGS) $(LIBMATH) $(fich_obj_prog1) -o prog1 

prog1.o : prog1.c 
	$(CCOBJ) $(CFLAGS) $(LIBMATH) prog1.c -o prog1.o -I./ 



#
# Modules
#

OBJ=

#
# Headers 
#

#
#
#

all : $(BIN) $(OBJ)

clean :
	- rm  *.o
	- rm prog1


tests :


