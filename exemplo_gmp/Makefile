SRCDIR := .
OBJDIR := ./obj
CC := gcc
GMPPATH:= /home/arthur/local
INCLUDE:= -I. -I$(GMPPATH)/include
CFLAGS := -O3 -Wall
LDFLAGS:= -L$(GMPPATH)/lib
LIBS   := -lgmp
dummy_build_folder := $(shell mkdir -p $(OBJDIR))

EXECUTABLE := teste_gmp 
SOURCES := main.c
OBJECTS := $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))

all : $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) -o $(EXECUTABLE) $(OBJECTS) $(CFLAGS) $(INCLUDE) $(LDFLAGS) $(LIBS)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -c $< -o $@ $(INCLUDE) $(CFLAGS)

clean :
	rm -r $(OBJDIR)
