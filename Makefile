main : main.o bigint.o abs_bool.o bool.o op_atrdiv.o op_atrmod.o op_atrmul.o op_atrsub.o op_atrsum.o opdiv.o opmod.o opmul.o oppow.o opsub.o opsum.o attrib.o io.o
	g++ -o res main.o bigint.o abs_bool.o bool.o op_atrdiv.o op_atrmod.o op_atrmul.o op_atrsub.o op_atrsum.o opdiv.o opmod.o opmul.o oppow.o opsub.o opsum.o attrib.o io.o
main.o : main.cpp
	g++ -g -c -O3 main.cpp
bigint.o : ./classes/bigint/bigint.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/bigint.cpp
abs_bool.o : ./classes/bigint/abs_bool.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/abs_bool.cpp
bool.o : ./classes/bigint/bool.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/bool.cpp
op_atrdiv.o : ./classes/bigint/op_atrdiv.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/op_atrdiv.cpp
op_atrmod.o : ./classes/bigint/op_atrmod.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/op_atrmod.cpp
op_atrmul.o : ./classes/bigint/op_atrmul.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/op_atrmul.cpp
op_atrsub.o : ./classes/bigint/op_atrsub.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/op_atrsub.cpp
op_atrsum.o : ./classes/bigint/op_atrsum.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/op_atrsum.cpp
opdiv.o : ./classes/bigint/opdiv.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/opdiv.cpp
opmod.o : ./classes/bigint/opmod.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/opmod.cpp
opmul.o : ./classes/bigint/opmul.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/opmul.cpp
oppow.o : ./classes/bigint/oppow.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/oppow.cpp
opsub.o : ./classes/bigint/opsub.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/opsub.cpp
opsum.o : ./classes/bigint/opsum.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/opsum.cpp
attrib.o : ./classes/bigint/attrib.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/attrib.cpp
io.o : ./classes/bigint/io.cpp ./classes/bigint/bigint.h
	g++ -g -c -O3 ./classes/bigint/io.cpp
clean :
	rm *.o
