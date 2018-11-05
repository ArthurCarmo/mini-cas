/*
 * Forward declarations of some useful functions
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#ifndef __EXTERN_DECL_
#define __EXTERN_DECL_

extern function sqrt(int);
extern function sqrt(const Number &);
extern function sqrt(const monomial &);
extern function sqrt(const polynomial &);
extern function sqrt(const function &);
extern function sqrt(const term &);
extern function sqrt(const Expr &);

extern function exp(int);
extern function exp(const Number &);
extern function exp(const monomial &);
extern function exp(const polynomial &);
extern function exp(const function &);
extern function exp(const term &);
extern function exp(const Expr &);

extern function sin(int);
extern function sin(const Number &);
extern function sin(const monomial &);
extern function sin(const polynomial &);
extern function sin(const function &);
extern function sin(const term &);
extern function sin(const Expr &);

extern function cos(int);
extern function cos(const Number &);
extern function cos(const monomial &);
extern function cos(const polynomial &);
extern function cos(const function &);
extern function cos(const term &);
extern function cos(const Expr &);

extern function tg(int);
extern function tg(const Number &);
extern function tg(const monomial &);
extern function tg(const polynomial &);
extern function tg(const function &);
extern function tg(const term &);
extern function tg(const Expr &);

#endif
