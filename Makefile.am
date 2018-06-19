AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I m4
CXXFLAGS = -std=c++11 -O3 -Wall

lib_LTLIBRARIES = libminicas.la

include_HEADERS = src/include/mini-cas.h \
		src/include/num_q.h \
		src/include/num_z.h \
		src/include/full_zm.h \
		src/include/polynomial.h \
		src/include/signatures.h

libminicas_la_SOURCES = src/num_z/num_z.cpp \
			src/num_z/abs_bool.cpp \
			src/num_z/attrib.cpp \
			src/num_z/base.cpp \
			src/num_z/bool.cpp \
			src/num_z/io.cpp \
			src/num_z/num_ops.cpp \
			src/num_z/op_atrdiv.cpp \
			src/num_z/op_atrmod.cpp \
			src/num_z/op_atrmul.cpp \
			src/num_z/op_atrsub.cpp \
			src/num_z/op_atrsum.cpp \
			src/num_z/opdiv.cpp \
			src/num_z/opmod.cpp \
			src/num_z/opmul.cpp \
			src/num_z/opsub.cpp \
			src/num_z/opsum.cpp \
			src/num_z/private_ops.cpp \
			src/num_z/unary_ops.cpp \
			src/num_q/num_q.cpp \
			src/num_q/attrib.cpp \
			src/num_q/bool.cpp \
			src/num_q/io.cpp \
			src/num_q/op_atrdiv.cpp \
			src/num_q/op_atrmul.cpp \
			src/num_q/op_atrsub.cpp \
			src/num_q/op_atrsum.cpp \
			src/num_q/opdiv.cpp \
			src/num_q/opmul.cpp \
			src/num_q/opsub.cpp \
			src/num_q/opsum.cpp

check_PROGRAMS = t_basic

t_basic_CPPFLAGS = -I./src/include
t_basic_SOURCES = script/basic/t_basic.cpp
t_basic_LDADD = libminicas.la

TESTS = script/basic/tst/basic_ops1.sh \
	script/basic/tst/basic_ops2.sh \
	script/basic/tst/basic_ops3.sh \
	script/basic/tst/basic_ops4.sh \
	script/basic/tst/basic_ops5.sh \
	script/basic/tst/basic_ops6.sh \
	script/basic/tst/basic_ops7.sh \
	script/basic/tst/basic_ops8.sh \
	script/basic/tst/basic_ops9.sh \
	script/basic/tst/basic_ops10.sh \
	script/basic/tst/basic_ops11.sh \
	script/basic/tst/basic_ops12.sh \
	script/basic/tst/basic_ops13.sh
	
EXTRA_DIST = $(TESTS) script/basic/in/inp1 script/basic/in/inp2 script/basic/in/inp3 script/basic/in/inp4 script/basic/in/inp5 script/basic/in/inp6 script/basic/in/inp7 script/basic/in/inp8 script/basic/in/inp9 script/basic/in/inp10 script/basic/in/inp11 script/basic/in/inp12 script/basic/in/inp13 script/basic/out/outg1 script/basic/out/outg2 script/basic/out/outg3 script/basic/out/outg4 script/basic/out/outg5 script/basic/out/outg6 script/basic/out/outg7 script/basic/out/outg8 script/basic/out/outg9 script/basic/out/outg10 script/basic/out/outg11 script/basic/out/outg12 script/basic/out/outg13
