OBJDIR := ./classes/obj
LIBDIR := ./classes/lib
NUMZDIR := ./classes/num_z
NUMZMDIR:= ./classes/num_zm
NUMQDIR := ./classes/num_q
POLYDIR := ./classes/polynomial
INCLUDE := ./classes/include

STATIC_LIB := libmini-cas.a
SHARED_LIB := libmini-cas.so

CC := g++ -std=c++11
CFLAGS := -g -O3 -Wall
dummy_build_folder := $(shell mkdir -p $(OBJDIR) && mkdir -p $(LIBDIR))

EXECUTABLE := mini-cas

NUMZ_SRC := num_z.cpp abs_bool.cpp attrib.cpp base.cpp bool.cpp io.cpp op_atrdiv.cpp op_atrmod.cpp op_atrmul.cpp op_atrsub.cpp op_atrsum.cpp opdiv.cpp opmod.cpp opmul.cpp opsub.cpp opsum.cpp private_ops.cpp unary_ops.cpp

SOURCES := $(NUMZ_SRC)

S_OBJECTS := $(SOURCES:.cpp=.o) 
D_OBJECTS := $(SOURCES:.cpp=.lo)

S_OBJ := $(addprefix $(OBJDIR)/, $(S_OBJECTS))
D_OBJ := $(addprefix $(OBJDIR)/, $(D_OBJECTS))

main: main.cpp $(STATIC_LIB) $(SHARED_LIB)
	$(CC) main.cpp -static -o $(EXECUTABLE) -I$(INCLUDE) -L$(LIBDIR) -lmini-cas $(CFLAGS)

$(STATIC_LIB) : $(S_OBJ) 
	ar rsv $(LIBDIR)/$@ $^

$(SHARED_LIB) : $(D_OBJ)
	$(CC) -shared -O3 -o $(LIBDIR)/$@ $^

$(OBJDIR)/%.o : $(NUMZDIR)/%.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

$(OBJDIR)/%.lo : $(NUMZDIR)/%.cpp
	$(CC) -c $< -o $@ $(CFLAGS) -fPIC

	
clean :
	rm -r $(OBJDIR)
