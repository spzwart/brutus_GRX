###################################################################
# Adjust path to mpreal.h file
LOCAL	= /home/spz
MPRLIB  = $(LOCAL)/src/mpreal
MPRDIR  = $(LOCAL)/src/mpreal
###################################################################
LIB     = ./lib/
MPLIB   = ./mplib/

DIRTIM  = $(LIB)Timer/

DIRDH   = $(LIB)Data_Handler/

DIRRAN  = $(LIB)Random/
DIRTOO  = $(LIB)Tools/
DIRDIA  = $(LIB)Diagnostics/
DIRINIT = $(LIB)Initializer/

DIRPRO  = $(LIB)Products/
DIRDEL  = $(MPLIB)Delta/
###################################################################
COMP = g++
#COMP = $(DIRMPI)mpicxx
CFLAGS = -O3 -std=c++11
CC  = $(COMP) $(CFLAGS) -c
CO  = $(COMP) $(CFLAGS) -o
###################################################################
EXE = brutus_GRX
EXEREV = brutus_GRX_rev
all: $(EXE) $(EXEREV)
###################################################################
brutus_GRX: brutus_GRX.o Brutus.o Bulirsch_Stoer.o Cluster.o Acceleration.o Star.o Delta.o Products.o Initializer.o Diagnostics.o Tools.o Random.o mtrand.o Data_Handler.o Timer.o  
	$(CO) brutus_GRX brutus_GRX.o Brutus.o Bulirsch_Stoer.o Cluster.o Acceleration.o Star.o Delta.o Products.o Initializer.o Diagnostics.o Tools.o Random.o mtrand.o Data_Handler.o Timer.o  -lmpfr -lgmp
###################################################################
brutus_GRX_rev: brutus_GRX_rev.o Brutus.o Bulirsch_Stoer.o Cluster.o Acceleration.o Star.o Delta.o Products.o Initializer.o Diagnostics.o Tools.o Random.o mtrand.o Data_Handler.o Timer.o  
	$(CO) brutus_GRX_rev brutus_GRX_rev.o Brutus.o Bulirsch_Stoer.o Cluster.o Acceleration.o Star.o Delta.o Products.o Initializer.o Diagnostics.o Tools.o Random.o mtrand.o Data_Handler.o Timer.o  -lmpfr -lgmp
###################################################################
brutus_GRX.o: brutus_GRX.cpp Brutus.o Bulirsch_Stoer.o Cluster.o Acceleration.o Star.o Delta.o Products.o Initializer.o Diagnostics.o Tools.o Random.o mtrand.o Data_Handler.o Timer.o  
	$(CC) brutus_GRX.cpp -I$(MPRDIR) -I$(DIRTIM) -I$(DIRDH) -I$(DIRRAN) -I$(DIRDIA) -I$(DIRINIT) -I$(DIRPRO) -I$(DIRDEL) -I$(DIRTOO)
###################################################################
brutus_GRX_rev.o: brutus_GRX_rev.cpp Brutus.o Bulirsch_Stoer.o Cluster.o Acceleration.o Star.o Delta.o Products.o Initializer.o Diagnostics.o Tools.o Random.o mtrand.o Data_Handler.o Timer.o  
	$(CC) brutus_GRX_rev.cpp -I$(MPRDIR) -I$(DIRTIM) -I$(DIRDH) -I$(DIRRAN) -I$(DIRDIA) -I$(DIRINIT) -I$(DIRPRO) -I$(DIRDEL) -I$(DIRTOO)
###################################################################
Brutus.o: Brutus.h Brutus.cpp Bulirsch_Stoer.o Cluster.o Acceleration.o Star.o Timer.o
	$(CC) Brutus.cpp -I$(MPRDIR) -I$(DIRTIM)

Bulirsch_Stoer.o: Bulirsch_Stoer.h Bulirsch_Stoer.cpp Cluster.o Acceleration.o Star.o Timer.o
	$(CC) Bulirsch_Stoer.cpp -I$(MPRDIR) -I$(DIRTIM)
Cluster.o: Cluster.h Cluster.cpp Acceleration.o Star.o 
	$(CC) Cluster.cpp -I$(DIRINIT) -I$(MPRDIR)
Acceleration.o: Acceleration.h Acceleration.cpp Star.o
	$(CC) Acceleration.cpp -I$(MPRDIR) 
Star.o: Star.h Star.cpp 
	$(CC) Star.cpp -I$(MPRDIR)

Delta.o: $(DIRDEL)Delta.h $(DIRDEL)Delta.cpp
	$(CC) $(DIRDEL)Delta.cpp -I$(MPRDIR)

Initializer.o: $(DIRINIT)Initializer.h $(DIRINIT)Initializer.cpp Data_Handler.o mtrand.o Random.o Tools.o Diagnostics.o Products.o
	$(CC) $(DIRINIT)Initializer.cpp -I$(DIRDH) -I$(DIRRAN) -I$(DIRDIA) -I$(DIRPRO) -I$(DIRTOO) -I$(MPRDIR)

Products.o: $(DIRPRO)Products.h $(DIRPRO)Products.cpp
	$(CC) $(DIRPRO)Products.cpp -I$(MPRDIR)
Diagnostics.o: $(DIRDIA)Diagnostics.h $(DIRDIA)Diagnostics.cpp Tools.o
	$(CC) $(DIRDIA)Diagnostics.cpp -I$(DIRTOO)
Tools.o: $(DIRTOO)Tools.h $(DIRTOO)Tools.cpp
	$(CC) $(DIRTOO)Tools.cpp
Random.o: $(DIRRAN)Random.h $(DIRRAN)Random.cpp mtrand.o
	$(CC) $(DIRRAN)Random.cpp
mtrand.o: $(DIRRAN)mtrand.h $(DIRRAN)mtrand.cpp
	$(CC) $(DIRRAN)mtrand.cpp

Data_Handler.o: $(DIRDH)Data_Handler.h $(DIRDH)Data_Handler.cpp
	$(CC) $(DIRDH)Data_Handler.cpp

Timer.o: $(DIRTIM)Timer.h $(DIRTIM)Timer.cpp
	$(CC) $(DIRTIM)Timer.cpp
###################################################################
clean:
	rm -f *~
	rm -f *.o
	rm -f -r ccache
	rm -f .fuse*
	rm -f brutus_GRX brutus_GRX_rev
	rm -f outfile.log outfile.diag energies.out
