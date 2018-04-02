OBJDIR := ./classes/obj
dummy_build_folder := $(shell mkdir -p $(OBJDIR))

main : main.o bigint.o abs_bool.o bool.o op_atrdiv.o op_atrmod.o op_atrmul.o op_atrsub.o op_atrsum.o opdiv.o opmod.o opmul.o oppow.o opsub.o opsum.o attrib.o io.o
	g++ -o mini-cas $(OBJDIR)/main.o $(OBJDIR)/bigint.o $(OBJDIR)/abs_bool.o $(OBJDIR)/bool.o $(OBJDIR)/op_atrdiv.o $(OBJDIR)/op_atrmod.o $(OBJDIR)/op_atrmul.o $(OBJDIR)/op_atrsub.o $(OBJDIR)/op_atrsum.o $(OBJDIR)/opdiv.o $(OBJDIR)/opmod.o $(OBJDIR)/opmul.o $(OBJDIR)/oppow.o $(OBJDIR)/opsub.o $(OBJDIR)/opsum.o $(OBJDIR)/attrib.o $(OBJDIR)/io.o
main.o : main.cpp
	g++ -g -c -O3 main.cpp -o $(OBJDIR)/main.o
bigint.o : ./classes/bigint/bigint.cpp ./classes/bigint/bigint.h 
	g++ -g -c -O3 ./classes/bigint/bigint.cpp -o $(OBJDIR)/bigint.o
abs_bool.o : ./classes/bigint/abs_bool.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/abs_bool.cpp -o $(OBJDIR)/abs_bool.o
bool.o : ./classes/bigint/bool.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/bool.cpp -o $(OBJDIR)/bool.o
op_atrdiv.o : ./classes/bigint/op_atrdiv.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/op_atrdiv.cpp -o $(OBJDIR)/op_atrdiv.o
op_atrmod.o : ./classes/bigint/op_atrmod.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/op_atrmod.cpp -o $(OBJDIR)/op_atrmod.o
op_atrmul.o : ./classes/bigint/op_atrmul.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/op_atrmul.cpp -o $(OBJDIR)/op_atrmul.o
op_atrsub.o : ./classes/bigint/op_atrsub.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/op_atrsub.cpp -o $(OBJDIR)/op_atrsub.o
op_atrsum.o : ./classes/bigint/op_atrsum.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/op_atrsum.cpp -o $(OBJDIR)/op_atrsum.o
opdiv.o : ./classes/bigint/opdiv.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/opdiv.cpp -o $(OBJDIR)/opdiv.o
opmod.o : ./classes/bigint/opmod.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/opmod.cpp -o $(OBJDIR)/opmod.o
opmul.o : ./classes/bigint/opmul.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/opmul.cpp -o $(OBJDIR)/opmul.o
oppow.o : ./classes/bigint/oppow.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/oppow.cpp -o $(OBJDIR)/oppow.o
opsub.o : ./classes/bigint/opsub.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/opsub.cpp -o $(OBJDIR)/opsub.o
opsum.o : ./classes/bigint/opsum.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/opsum.cpp -o $(OBJDIR)/opsum.o
attrib.o : ./classes/bigint/attrib.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/attrib.cpp -o $(OBJDIR)/attrib.o
io.o : ./classes/bigint/io.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/io.cpp -o $(OBJDIR)/io.o
clean :
	rm -r $(OBJDIR)
