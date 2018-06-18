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
