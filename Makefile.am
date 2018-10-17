AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I m4
CXXFLAGS = -std=c++11 -O2 -Wall

lib_LTLIBRARIES = libminicas.la

include_HEADERS = src/include/mini-cas \
		src/include/number.h \
		src/include/num_q.h \
		src/include/num_z.h \
		src/include/num_zm.h \
		src/include/monomial.h \
		src/include/monomial_comp_class.h \
		src/include/polynomial.h \
		src/include/term.h \
		src/include/symbol.h \
		src/include/template_ops.h \
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
			src/num_q/num_ops.cpp \
			src/num_q/op_atrdiv.cpp \
			src/num_q/op_atrmul.cpp \
			src/num_q/op_atrsub.cpp \
			src/num_q/op_atrsum.cpp \
			src/num_q/opdiv.cpp \
			src/num_q/opmul.cpp \
			src/num_q/opsub.cpp \
			src/num_q/opsum.cpp \
			src/polynomial/attrib.cpp \
			src/polynomial/bool.cpp \
			src/polynomial/coefficient_ops.cpp \
			src/polynomial/degree_ops.cpp \
			src/polynomial/content_and_primitive_part.cpp \
			src/polynomial/io.cpp \
			src/polynomial/monomial_arithmetic_ops.cpp \
			src/polynomial/monomial_bool_ops.cpp \
			src/polynomial/monomial_general_ops.cpp \
			src/polynomial/opdiv.cpp \
			src/polynomial/opmul.cpp \
			src/polynomial/opsub.cpp \
			src/polynomial/opsum.cpp \
			src/polynomial/p_gcd.cpp \
			src/polynomial/subs.cpp \
			src/polynomial/wrappers.cpp

check_PROGRAMS = t_basic t_monomials t_monomial_pow t_grades t_polynomials t_polynomial_derive t_polynomial_eval t_polynomial_div

t_basic_CPPFLAGS = -I./src/include
t_basic_SOURCES = script/basic/t_basic.cpp
t_basic_LDADD = libminicas.la

t_monomials_CPPFLAGS = -I./src/include
t_monomials_SOURCES = script/polynomials/t_monomials.cpp
t_monomials_LDADD = libminicas.la

t_monomial_pow_CPPFLAGS = -I./src/include
t_monomial_pow_SOURCES = script/polynomials/t_monomial_pow.cpp
t_monomial_pow_LDADD = libminicas.la

t_grades_CPPFLAGS = -I./src/include
t_grades_SOURCES = script/polynomials/t_grade.cpp
t_grades_LDADD = libminicas.la

t_polynomials_CPPFLAGS = -I./src/include
t_polynomials_SOURCES = script/polynomials/t_polynomials.cpp
t_polynomials_LDADD = libminicas.la

t_polynomial_derive_CPPFLAGS = -I./src/include
t_polynomial_derive_SOURCES = script/polynomials/t_polynomial_derivative.cpp
t_polynomial_derive_LDADD = libminicas.la

t_polynomial_eval_CPPFLAGS = -I./src/include
t_polynomial_eval_SOURCES = script/polynomials/t_polynomial_eval.cpp
t_polynomial_eval_LDADD = libminicas.la

t_polynomial_div_CPPFLAGS = -I./src/include
t_polynomial_div_SOURCES = script/polynomials/t_polynomial_div.cpp
t_polynomial_div_LDADD = libminicas.la


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
	script/basic/tst/basic_ops13.sh \
	t_monomials \
	t_monomial_pow \
	t_grades \
	t_polynomials \
	t_polynomial_derive \
	t_polynomial_eval \
	t_polynomial_div
	
EXTRA_DIST = $(TESTS) script/basic/in/inp1 script/basic/in/inp2 script/basic/in/inp3 script/basic/in/inp4 script/basic/in/inp5 script/basic/in/inp6 script/basic/in/inp7 script/basic/in/inp8 script/basic/in/inp9 script/basic/in/inp10 script/basic/in/inp11 script/basic/in/inp12 script/basic/in/inp13 script/basic/out/outg1 script/basic/out/outg2 script/basic/out/outg3 script/basic/out/outg4 script/basic/out/outg5 script/basic/out/outg6 script/basic/out/outg7 script/basic/out/outg8 script/basic/out/outg9 script/basic/out/outg10 script/basic/out/outg11 script/basic/out/outg12 script/basic/out/outg13 README.md LICENSE
