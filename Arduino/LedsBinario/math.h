#ifndef __MATH_H
#define __MATH_H

#define M_PI 3.141592653589793238462643

#define M_SQRT2 1.4142135623730950488016887

#define NAN	__builtin_nan("")

#define INFINITY	__builtin_inf()

#ifndef __ATTR_CONST__
# define __ATTR_CONST__ __attribute__((__const__))
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern double cos(double __x) __ATTR_CONST__;

extern double fabs(double __x) __ATTR_CONST__;
#if 0

static inline double fabs( double __x )
  { double __res;
    __asm__ __volatile__ ("andi %D0,0x7F \n\t"
		: "=d" (__res) : "0" (__x) );
    return __res;
  }
#endif

extern double fmod(double __x, double __y) __ATTR_CONST__;

extern double modf(double __x, double *__iptr);

extern double sin(double __x) __ATTR_CONST__;

extern double sqrt(double __x) __ATTR_CONST__;

extern double tan(double __x) __ATTR_CONST__;

extern double floor(double __x) __ATTR_CONST__;

extern double ceil(double __x) __ATTR_CONST__;

extern double frexp(double __x, int *__pexp);

extern double ldexp(double __x, int __exp) __ATTR_CONST__;

extern double exp(double __x) __ATTR_CONST__;

extern double cosh(double __x) __ATTR_CONST__;

extern double sinh(double __x) __ATTR_CONST__;

extern double tanh(double __x) __ATTR_CONST__;

extern double acos(double __x) __ATTR_CONST__;

extern double asin(double __x) __ATTR_CONST__;

extern double atan(double __x) __ATTR_CONST__;

extern double atan2(double __y, double __x) __ATTR_CONST__;

extern double log(double __x) __ATTR_CONST__;

extern double log10(double __x) __ATTR_CONST__;

extern double pow(double __x, double __y) __ATTR_CONST__;

extern int isnan(double __x) __ATTR_CONST__;

extern int isinf(double __x) __ATTR_CONST__;

extern double square(double __x) __ATTR_CONST__;

__ATTR_CONST__ static inline double copysign (double __x, double __y)
{
    __asm__ (
	"bst	%D2, 7	\n\t"
	"bld	%D0, 7	"
	: "=r" (__x)
	: "0" (__x), "r" (__y) );
    return __x;
}

extern double fdim (double __x, double __y) __ATTR_CONST__;

extern double fma (double __x, double __y, double __z) __ATTR_CONST__;

extern double fmax (double __x, double __y) __ATTR_CONST__;

extern double fmin (double __x, double __y) __ATTR_CONST__;

extern int signbit (double __x) __ATTR_CONST__;

extern double trunc (double __x) __ATTR_CONST__;

__ATTR_CONST__ static inline int isfinite (double __x)
{
    unsigned char __exp;
    __asm__ (
	"mov	%0, %C1		\n\t"
	"lsl	%0		\n\t"
	"mov	%0, %D1		\n\t"
	"rol	%0		"
	: "=r" (__exp)
	: "r" (__x)	);
    return __exp != 0xff;
}

double hypot (double __x, double __y) __ATTR_CONST__;

double round (double __x) __ATTR_CONST__;

long lround (double __x) __ATTR_CONST__;

long lrint (double __x) __ATTR_CONST__;

#ifdef __cplusplus
}
#endif

#endif /* _MATH_H */
