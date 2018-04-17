OBJDIR := ./classes/obj
LIBDIR := ./classes/lib
NUMZDIR := ./classes/num_z
NUMQDIR := ./classes/num_q
POLYDIR := ./classes/polynomial
INCLUDE := ./classes/include

STATIC_LIB := libsymbolib.a
SHARED_LIB := libsymbolib.so

CC := g++
CFLAGS := -O3 -Wall -fPIC
dummy_build_folder := $(shell mkdir -p $(OBJDIR) && mkdir -p $(LIBDIR))

EXECUTABLE := mini-cas
SOURCES := num_z.cpp abs_bool.cpp attrib.cpp bool.cpp io.cpp op_atrdiv.cpp op_atrmod.cpp op_atrmul.cpp op_atrsub.cpp op_atrsum.cpp opdiv.cpp opmod.cpp opmul.cpp oppow.cpp opsub.cpp opsum.cpp private_ops.cpp unary_ops.cpp
OBJECTS := $(SOURCES:.cpp=.o) 

P_OBJ := $(addprefix $(OBJDIR)/, $(OBJECTS))

main: main.cpp $(STATIC_LIB) $(SHARED_LIB)
	$(CC) main.cpp -o $(EXECUTABLE) -I$(INCLUDE) $(LIBDIR)/$(STATIC_LIB) $(CFLAGS)

$(STATIC_LIB) : $(P_OBJ) 
	ar rsv $(LIBDIR)/$@ $^

$(SHARED_LIB) : $(P_OBJ)
	$(CC) -shared -O3 -o $(LIBDIR)/$@ $^

$(OBJDIR)/%.o : $(NUMZDIR)/%.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

clean :
	rm -r $(OBJDIR)
