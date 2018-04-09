OBJDIR := ./classes/obj
BNTDIR := ./classes/num_z
CC := g++
CFLAGS := -O3 -Wall
dummy_build_folder := $(shell mkdir -p $(OBJDIR))


EXECUTABLE := mini-cas
SOURCES := num_z.cpp abs_bool.cpp bool.cpp op_atrdiv.cpp op_atrmod.cpp op_atrmul.cpp op_atrsub.cpp op_atrsum.cpp opdiv.cpp opmod.cpp opmul.cpp oppow.cpp opsub.cpp opsum.cpp attrib.cpp io.cpp
OBJECTS := $(SOURCES:.cpp=.o) 

P_OBJ := $(addprefix $(OBJDIR)/, $(OBJECTS))

main: $(OBJDIR)/main.o $(P_OBJ) 
	$(CC) -o $(EXECUTABLE) $(OBJDIR)/main.o $(P_OBJ) $(CFLAGS)

$(OBJDIR)/main.o : main.cpp
	$(CC) -c main.cpp -o $(OBJDIR)/main.o $(CFLAGS)

$(OBJDIR)/%.o : $(BNTDIR)/%.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

clean :
	rm -r $(OBJDIR)
