#ifndef _CHECK_H_
  #include  <check.h>
#endif
#ifndef _MATH_H_
  #include  <math.h>
#endif
#ifndef _STDIO_H_
  #include  <stdio.h>
#endif
#ifndef _STDLIB_H_
  #include  <stdlib.h>
#endif
#ifndef _LIMITS_H_  // не нужен?
  #include  <limits.h>
#endif
#ifndef _FLOAT_H_
  #include  <float.h>
#endif
#include "s21_math.h"

double max_inf = 1.0 / 0.0;
double min_inf = -1.0 / 0.0;
double max_nan = 0.0 / 0.0;
double min_nan = -0.0 / 0.0;
char str1[50] = {'\0'};
char str2[50] = {'\0'};

    // отклонения на 170000000000000.1
START_TEST(sin_test) {
    snprintf(str1, sizeof(str1), "%.15Lf", s21_sin(s21_MAX_INF));
    snprintf(str2, sizeof(str2), "%.15lf", sin(s21_MAX_INF));
    ck_assert_str_eq(str1, str2);

    ck_assert_ldouble_nan(s21_sin(max_inf));
    ck_assert_ldouble_nan(s21_sin(min_inf));
    ck_assert_ldouble_nan(s21_sin(max_nan));
    ck_assert_ldouble_nan(s21_sin(min_nan));
    ck_assert_ldouble_eq_tol(s21_sin(0.5), sin(0.5), 1e-15);
    ck_assert_ldouble_eq_tol(s21_sin(-0.5), sin(-0.5), 1e-15);
    ck_assert_ldouble_eq_tol(s21_sin(-1), sin(-1), 1e-15);
    ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), 1e-15);
    ck_assert_ldouble_eq_tol(s21_sin(1.1), sin(1.1), 1e-15);
    ck_assert_ldouble_eq_tol(s21_sin(-2.1), sin(-2.1), 1e-15);
    ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 1e-15);
    ck_assert_ldouble_eq_tol(s21_sin(-0), sin(-0), 1e-15);
    ck_assert_ldouble_eq_tol(s21_sin(5.123456789123), sin(5.123456789123), 1e-15);
    ck_assert_ldouble_eq_tol(s21_sin(0.00000004564897), sin(0.00000004564897), 1e-15);
    ck_assert_ldouble_eq_tol(s21_sin(17000000000.1), sin(17000000000.1), 1e-6);
} END_TEST

START_TEST(cos_test) {
    snprintf(str1, sizeof(str1), "%.15Lf", s21_cos(s21_MAX_INF));
    snprintf(str2, sizeof(str2), "%.15lf", cos(s21_MAX_INF));
    ck_assert_str_eq(str1, str2);

    ck_assert_ldouble_nan(s21_cos(max_inf));
    ck_assert_ldouble_nan(s21_cos(min_inf));
    ck_assert_ldouble_nan(s21_cos(max_nan));
    ck_assert_ldouble_nan(s21_cos(min_nan));
    ck_assert_ldouble_eq_tol(s21_cos(0.5), cos(0.5), 1e-15);
    ck_assert_ldouble_eq_tol(s21_cos(-0.5), cos(-0.5), 1e-15);
    ck_assert_ldouble_eq_tol(s21_cos(-1), cos(-1), 1e-15);
    ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), 1e-15);
    ck_assert_ldouble_eq_tol(s21_cos(1.1), cos(1.1), 1e-15);
    ck_assert_ldouble_eq_tol(s21_cos(-2.1), cos(-2.1), 1e-15);
    ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-15);
    ck_assert_ldouble_eq_tol(s21_cos(-0), cos(-0), 1e-15);
    ck_assert_ldouble_eq_tol(s21_cos(5.123456789123), cos(5.123456789123), 1e-15);
    ck_assert_ldouble_eq_tol(s21_cos(0.00000004564897), cos(0.00000004564897), 1e-15);
    ck_assert_ldouble_eq_tol(s21_cos(17000000000.1), cos(17000000000.1), 1e-7);
} END_TEST

START_TEST(tan_test) {
    ck_assert_ldouble_nan(s21_cos(max_inf));
    ck_assert_ldouble_nan(s21_cos(min_inf));
    ck_assert_ldouble_nan(s21_cos(max_nan));
    ck_assert_ldouble_nan(s21_cos(min_nan));
    ck_assert_ldouble_eq_tol(s21_tan(0.5), tan(0.5), 1e-15);
    ck_assert_ldouble_eq_tol(s21_tan(-0.5), tan(-0.5), 1e-15);
    ck_assert_ldouble_eq_tol(s21_tan(-1), tan(-1), 1e-15);
    ck_assert_ldouble_eq_tol(s21_tan(1), tan(1), 1e-15);
    ck_assert_ldouble_eq_tol(s21_tan(1.1), tan(1.1), 1e-15);
    ck_assert_ldouble_eq_tol(s21_tan(-2.1), tan(-2.1), 1e-15);
    ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), 1e-15);
    ck_assert_ldouble_eq_tol(s21_tan(-0), tan(-0), 1e-15);
    ck_assert_ldouble_eq_tol(s21_tan(5.123456789123), tan(5.123456789123), 1e-15);
    ck_assert_ldouble_eq_tol(s21_tan(0.00000004564897), tan(0.00000004564897), 1e-15);
    ck_assert_ldouble_eq_tol(s21_tan(170000000.1), tan(170000000.1), 1e-7);
    
} END_TEST

START_TEST(asin_test) {
    ck_assert_ldouble_nan(s21_asin(max_inf));
    ck_assert_ldouble_nan(s21_asin(min_inf));
    ck_assert_ldouble_nan(s21_asin(max_nan));
    ck_assert_ldouble_nan(s21_asin(min_nan));
    ck_assert_ldouble_eq_tol(s21_asin(0.5), asin(0.5), 1e-8);
    ck_assert_ldouble_eq_tol(s21_asin(-0.5), asin(-0.5), 1e-8);
    ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 1e-15);
    ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-15);
    ck_assert_ldouble_nan(s21_asin(1.1));
    ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), 1e-15);
    ck_assert_ldouble_eq_tol(s21_asin(-0), asin(-0), 1e-15);
    ck_assert_ldouble_eq_tol(s21_asin(0.00000004564897), asin(0.00000004564897), 1e-15);
} END_TEST

START_TEST(acos_test) {
    ck_assert_ldouble_nan(s21_acos(max_inf));
    ck_assert_ldouble_nan(s21_acos(min_inf));
    ck_assert_ldouble_nan(s21_acos(max_nan));
    ck_assert_ldouble_nan(s21_acos(min_nan));
    ck_assert_ldouble_eq_tol(s21_acos(0.5), acos(0.5), 1e-8);
    ck_assert_ldouble_eq_tol(s21_acos(-0.5), acos(-0.5), 1e-8);
    ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), 1e-15);
    ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 1e-15);
    ck_assert_ldouble_nan(s21_acos(1.1));
    ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), 1e-15);
    ck_assert_ldouble_eq_tol(s21_acos(-0), acos(-0), 1e-15);
    ck_assert_ldouble_eq_tol(s21_acos(0.00000004564897), acos(0.00000004564897), 1e-15);
} END_TEST

START_TEST(atan_test) {
    ck_assert_ldouble_nan(s21_atan(max_nan));
    ck_assert_ldouble_nan(s21_atan(min_nan));
    ck_assert_ldouble_eq_tol(s21_atan(min_inf), atan(min_inf), 1e-8);
    ck_assert_ldouble_eq_tol(s21_atan(max_inf), atan(max_inf), 1e-8);
    ck_assert_ldouble_eq_tol(s21_atan(0.5), atan(0.5), 1e-8);
    ck_assert_ldouble_eq_tol(s21_atan(-0.5), atan(-0.5), 1e-8);
    ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 1e-8);
    ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-8);
    ck_assert_ldouble_eq_tol(s21_atan(1.1), atan(1.1), 1e-8);
    ck_assert_ldouble_eq_tol(s21_atan(-2.1), atan(-2.1), 1e-8);
    ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 1e-15);
    ck_assert_ldouble_eq_tol(s21_atan(-0), atan(-0), 1e-15);
    ck_assert_ldouble_eq_tol(s21_atan(5.123456789123), atan(5.123456789123), 1e-15);
    ck_assert_ldouble_eq_tol(s21_atan(0.00000004564897), atan(0.00000004564897), 1e-15);
    ck_assert_ldouble_eq_tol(s21_atan(170000000000000.1), atan(170000000000000.1), 1e-15);
    
} END_TEST

START_TEST(exp_test) {
    ck_assert_ldouble_infinite(s21_exp(max_inf));
    ck_assert_ldouble_eq_tol(s21_exp(min_inf), exp(min_inf), 1e-8);
    ck_assert_ldouble_nan(s21_exp(max_nan));
    ck_assert_ldouble_nan(s21_exp(min_nan));
    ck_assert_ldouble_eq_tol(s21_exp(0.5), exp(0.5), 1e-15);
    ck_assert_ldouble_eq_tol(s21_exp(-0.5), exp(-0.5), 1e-15);
    ck_assert_ldouble_eq_tol(s21_exp(-1), exp(-1), 1e-15);
    ck_assert_ldouble_eq_tol(s21_exp(1), exp(1), 1e-15);
    ck_assert_ldouble_eq_tol(s21_exp(1.1), exp(1.1), 1e-15);
    ck_assert_ldouble_eq_tol(s21_exp(-2.1), exp(-2.1), 1e-15);
    ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), 1e-15);
    ck_assert_ldouble_eq_tol(s21_exp(-0), exp(-0), 1e-15);
    ck_assert_ldouble_eq_tol(s21_exp(5.123456789123), exp(5.123456789123), 1e-8);
    ck_assert_ldouble_eq_tol(s21_exp(0.00000004564897), exp(0.00000004564897), 1e-15);
    ck_assert_ldouble_eq_tol(s21_exp(20.1), exp(20.1), 1e-8);
    ck_assert_ldouble_eq_tol(s21_exp(-20.1), exp(-20.1), 1e-8);
} END_TEST

START_TEST(log_test) {
    ck_assert_ldouble_infinite(s21_log(max_inf));
    ck_assert_ldouble_nan(s21_log(min_inf));
    ck_assert_ldouble_nan(s21_log(max_nan));
    ck_assert_ldouble_nan(s21_log(min_nan));
    ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-15);
    ck_assert_ldouble_nan(s21_log(-0.5));
    ck_assert_ldouble_eq_tol(s21_log(1), log(1), 1e-15);
    ck_assert_ldouble_eq_tol(s21_log(1.1), log(1.1), 1e-15);
    ck_assert_ldouble_infinite(s21_log(0));
    ck_assert_ldouble_infinite(s21_log(-0));
    ck_assert_ldouble_eq_tol(s21_log(5.123456789123), log(5.123456789123), 1e-15);
    ck_assert_ldouble_eq_tol(s21_log(0.00000004564897), log(0.00000004564897), 1e-15);
    ck_assert_ldouble_eq_tol(s21_log(170000000000000.1), log(170000000000000.1), 1e-8);
} END_TEST

START_TEST(sqrt_test) {
    ck_assert_ldouble_nan(s21_sqrt(min_inf));
    ck_assert_ldouble_infinite(s21_sqrt(max_inf));
    ck_assert_ldouble_nan(s21_sqrt(max_nan));
    ck_assert_ldouble_nan(s21_sqrt(min_nan));
    ck_assert_ldouble_eq_tol(s21_sqrt(0.5), sqrt(0.5), 1e-15);
    ck_assert_ldouble_nan(s21_sqrt(-0.5));
    ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrt(1), 1e-15);
    ck_assert_ldouble_eq_tol(s21_sqrt(1.1), sqrt(1.1), 1e-15);
    ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), 1e-15);
    ck_assert_ldouble_eq_tol(s21_sqrt(-0), sqrt(-0), 1e-15);
    ck_assert_ldouble_eq_tol(s21_sqrt(5.123456789123), sqrt(5.123456789123), 1e-15);
    ck_assert_ldouble_eq_tol(s21_sqrt(0.00000004564897), sqrt(0.00000004564897), 1e-15);
    ck_assert_ldouble_eq_tol(s21_sqrt(170000000000000.1), sqrt(170000000000000.1), 1e-8);
} END_TEST

START_TEST(pow_test) {
    ck_assert_ldouble_eq(s21_pow(max_inf, max_inf), pow(max_inf, max_inf));
    ck_assert_ldouble_eq_tol(s21_pow(max_inf, min_inf), pow(max_inf, min_inf), 1e-8);
    ck_assert_ldouble_nan(s21_pow(max_inf, max_nan));
    ck_assert_ldouble_nan(s21_pow(max_inf, min_nan));

    ck_assert_ldouble_eq(s21_pow(min_inf, max_inf), pow(min_inf, max_inf));
    ck_assert_ldouble_eq_tol(s21_pow(min_inf, min_inf), pow(min_inf, min_inf), 1e-8);
    ck_assert_ldouble_nan(s21_pow(min_inf, max_nan));
    ck_assert_ldouble_nan(s21_pow(min_inf, min_nan));

    ck_assert_ldouble_nan(s21_pow(max_nan, max_inf));
    ck_assert_ldouble_nan(s21_pow(max_nan, min_inf));
    ck_assert_ldouble_nan(s21_pow(max_nan, max_nan));
    ck_assert_ldouble_nan(s21_pow(max_nan, min_nan));

    ck_assert_ldouble_nan(s21_pow(min_nan, max_inf));
    ck_assert_ldouble_nan(s21_pow(min_nan, min_inf));
    ck_assert_ldouble_nan(s21_pow(min_nan, max_nan));
    ck_assert_ldouble_nan(s21_pow(min_nan, min_nan));

    ck_assert_ldouble_infinite(s21_pow(max_inf, 2.4));
    ck_assert_ldouble_infinite(s21_pow(min_inf, 2.4));
    ck_assert_ldouble_nan(s21_pow(max_nan, 2.4));
    ck_assert_ldouble_nan(s21_pow(min_nan, 2.4));

    ck_assert_ldouble_infinite(s21_pow(2.4, max_inf));
    ck_assert_ldouble_eq_tol(s21_pow(2.4, min_inf), pow(2.4, min_inf), 1e-8);
    ck_assert_ldouble_nan(s21_pow(2.4, max_nan));
    ck_assert_ldouble_nan(s21_pow(2.4, min_nan));

    ck_assert_ldouble_eq_tol(s21_pow(0, 2.4), pow(0, 2.4), 1e-8);
    ck_assert_ldouble_eq_tol(s21_pow(-0, 2.4), pow(-0, 2.4), 1e-8);
    ck_assert_ldouble_eq_tol(s21_pow(2.4, 0), pow(2.4, 0), 1e-8);
    ck_assert_ldouble_eq_tol(s21_pow(2.4, -0), pow(2.4, -0), 1e-8);
    ck_assert_ldouble_eq_tol(s21_pow(2.4, 0.5), pow(2.4, 0.5), 1e-8);
    ck_assert_ldouble_eq_tol(s21_pow(2.4, -0.5), pow(2.4, -0.5), 1e-8);
    ck_assert_ldouble_nan(s21_pow(-2.4, 0.5));
    ck_assert_ldouble_nan(s21_pow(-2.4, -0.5));
    ck_assert_ldouble_nan(s21_pow(-2.4, 2.1));
    ck_assert_ldouble_nan(s21_pow(-2.4, -2.1));
    ck_assert_ldouble_eq_tol(s21_pow(-2.4, 2), pow(-2.4, 2), 1e-8);
    ck_assert_ldouble_eq_tol(s21_pow(2.4, 2), pow(2.4, 2), 1e-8);
    ck_assert_ldouble_eq_tol(s21_pow(-2.4, -1), pow(-2.4, -1), 1e-8);
    ck_assert_ldouble_nan(s21_pow(-2.4, -1.2));
    ck_assert_ldouble_nan(s21_pow(-2.4, -0.4));
    ck_assert_ldouble_eq_tol(s21_pow(2.4, 1), pow(2.4, 1), 1e-8);
    ck_assert_ldouble_eq_tol(s21_pow(2.4, 3), pow(2.4, 3), 1e-8);
    ck_assert_ldouble_eq_tol(s21_pow(2.4, -3), pow(2.4, -3), 1e-8);
    ck_assert_ldouble_eq_tol(s21_pow(666666.4, 1.5), pow(666666.4, 1.5), 1e-6);
    ck_assert_ldouble_eq_tol(s21_pow(666666.4, -1.5), pow(666666.4, -1.5), 1e-8);
    ck_assert_ldouble_eq_tol(s21_pow(3.3, 13.2), pow(3.3, 13.2), 1e-6);
    ck_assert_ldouble_eq_tol(s21_pow(3.3, -24.2), pow(3.3, -24.2), 1e-8);
    ck_assert_ldouble_nan(s21_pow(-3.3, -24.2));
    ck_assert_ldouble_eq_tol(s21_pow(0.0000000005543, 24.2), pow(0.0000000005543, 24.2), 1e-8);
    ck_assert_ldouble_eq_tol(s21_pow(0.0000000005543, 0.00000003), pow(0.0000000005543, 0.00000003), 1e-8);
} END_TEST

START_TEST(fmod_test) {
    ck_assert_ldouble_nan(s21_fmod(max_inf, max_inf));
    ck_assert_ldouble_nan(s21_fmod(max_inf, min_inf));
    ck_assert_ldouble_nan(s21_fmod(max_inf, max_nan));
    ck_assert_ldouble_nan(s21_fmod(max_inf, min_nan));

    ck_assert_ldouble_nan(s21_fmod(min_inf, max_inf));
    ck_assert_ldouble_nan(s21_fmod(min_inf, min_inf));
    ck_assert_ldouble_nan(s21_fmod(min_inf, max_nan));
    ck_assert_ldouble_nan(s21_fmod(min_inf, min_nan));

    ck_assert_ldouble_nan(s21_fmod(max_nan, max_inf));
    ck_assert_ldouble_nan(s21_fmod(max_nan, min_inf));
    ck_assert_ldouble_nan(s21_fmod(max_nan, max_nan));
    ck_assert_ldouble_nan(s21_fmod(max_nan, min_nan));

    ck_assert_ldouble_nan(s21_fmod(min_nan, max_inf));
    ck_assert_ldouble_nan(s21_fmod(min_nan, min_inf));
    ck_assert_ldouble_nan(s21_fmod(min_nan, max_nan));
    ck_assert_ldouble_nan(s21_fmod(min_nan, min_nan));

    ck_assert_ldouble_nan(s21_fmod(max_inf, 2.4));
    ck_assert_ldouble_nan(s21_fmod(min_inf, 2.4));
    ck_assert_ldouble_nan(s21_fmod(max_nan, 2.4));
    ck_assert_ldouble_nan(s21_fmod(min_nan, 2.4));

    ck_assert_ldouble_eq_tol(s21_fmod(2.4, max_inf), fmod(2.4, max_inf), 1e-8);
    ck_assert_ldouble_eq_tol(s21_fmod(2.4, min_inf), fmod(2.4, min_inf), 1e-8);
    ck_assert_ldouble_nan(s21_fmod(2.4, max_nan));
    ck_assert_ldouble_nan(s21_fmod(2.4, min_nan));

    ck_assert_ldouble_eq_tol(s21_fmod(0, 2.4), fmod(0, 2.4), 1e-8);
    ck_assert_ldouble_eq_tol(s21_fmod(-0, 2.4), fmod(-0, 2.4), 1e-8);
    ck_assert_ldouble_nan(s21_fmod(2.4, 0));
    ck_assert_ldouble_nan(s21_fmod(2.4, -0));
    ck_assert_ldouble_eq_tol(s21_fmod(2.4, 0.5), fmod(2.4, 0.5), 1e-8);
    ck_assert_ldouble_eq_tol(s21_fmod(2.4, -0.5), fmod(2.4, -0.5), 1e-8);
    ck_assert_ldouble_eq_tol(s21_fmod(-2.4, 0.5), fmod(-2.4, 0.5), 1e-8);
    ck_assert_ldouble_eq_tol(s21_fmod(-2.4, -0.5), fmod(-2.4, -0.5), 1e-8);
    ck_assert_ldouble_eq_tol(s21_fmod(666666.4, 1.5), fmod(666666.4, 1.5), 1e-8);
    ck_assert_ldouble_eq_tol(s21_fmod(666666.4, -1.5), fmod(666666.4, -1.5), 1e-8);
    ck_assert_ldouble_eq_tol(s21_fmod(3.3, 24.2), fmod(3.3, 24.2), 1e-8);
    ck_assert_ldouble_eq_tol(s21_fmod(3.3, -24.2), fmod(3.3, -24.2), 1e-8);
    ck_assert_ldouble_eq_tol(s21_fmod(-3.3, -24.2), fmod(-3.3, -24.2), 1e-8);
    ck_assert_ldouble_eq_tol(s21_fmod(0.0000000005543, 24.2), fmod(0.0000000005543, 24.2), 1e-8);
    ck_assert_ldouble_eq_tol(s21_fmod(0.0000000005543, 0.000003), fmod(0.0000000005543, 0.000003), 1e-8);
    
} END_TEST

START_TEST(ceil_test) {
    ck_assert_ldouble_eq(s21_ceil(max_inf), ceil(max_inf));
    ck_assert_ldouble_eq(s21_ceil(min_inf), ceil(min_inf));
    ck_assert_ldouble_nan(s21_floor(max_nan));
    ck_assert_ldouble_nan(s21_floor(min_nan));
    ck_assert_ldouble_eq(s21_ceil(-876554310.23455), ceil(-876554310.23455));
    ck_assert_ldouble_eq(s21_ceil(876554310.23455), ceil(876554310.23455));
    ck_assert_ldouble_eq(s21_ceil(-0.45), ceil(-0.45));
    ck_assert_ldouble_eq(s21_ceil(0.45), ceil(0.45));
    ck_assert_ldouble_eq(s21_ceil(-0.00000000000000045), ceil(-0.00000000000000045));
    
} END_TEST

START_TEST(floor_test) {  // Done
    ck_assert_ldouble_infinite(s21_floor(s21_MAX_INF));
    ck_assert_ldouble_infinite(s21_floor(s21_MIN_INF));
    ck_assert_ldouble_nan(s21_floor(s21_NAN));
    ck_assert_ldouble_eq(s21_floor(s21_MAX_INF), floor(s21_MAX_INF));
    ck_assert_ldouble_eq(s21_floor(s21_MIN_INF), floor(s21_MIN_INF));
    ck_assert_ldouble_eq(s21_floor(0), floor(0));
    ck_assert_ldouble_eq(s21_floor(-0), floor(-0));
    ck_assert_ldouble_eq(s21_floor(-876554310.23455), floor(-876554310.23455));
    ck_assert_ldouble_eq(s21_floor(876554310.23455), floor(876554310.23455));
    ck_assert_ldouble_eq(s21_floor(-0.45), floor(-0.45));
    ck_assert_ldouble_eq(s21_floor(0.45), floor(0.45));
    ck_assert_ldouble_eq(s21_floor(-0.0000000000000000000045), floor(-0.0000000000000000000045));
} END_TEST

START_TEST(abs_test) {
    int inf_max = 1.0 / 0.0;
    int inf_min = -1.0 / 0.0;
    int nan_max = 0.0 / 0.0;
    int nan_min = -0.0 / 0.0;
    ck_assert_int_eq(s21_abs(inf_max), abs(inf_max));
    ck_assert_int_eq(s21_abs(inf_min), abs(inf_min));
    ck_assert_int_eq(s21_abs(nan_max), abs(nan_max));
    ck_assert_int_eq(s21_abs(nan_min), abs(nan_min));
    ck_assert_int_eq(s21_abs(-10), abs(-10));
    ck_assert_int_eq(s21_abs(-0), abs(-0));
} END_TEST

START_TEST(fabs_test) {
    ck_assert_ldouble_infinite(s21_fabs(min_inf));
    ck_assert_ldouble_infinite(s21_fabs(max_inf));
    ck_assert_ldouble_nan(s21_fabs(max_nan));
    ck_assert_ldouble_nan(s21_fabs(min_nan));
    ck_assert_ldouble_eq_tol(s21_fabs(0.5), fabs(0.5), 1e-15);
    ck_assert_ldouble_eq_tol(s21_fabs(-0.5), fabs(-0.5), 1e-15);
    ck_assert_ldouble_eq_tol(s21_fabs(-1.0), fabs(-1.0), 1e-15);
    ck_assert_ldouble_eq_tol(s21_fabs(1.0), fabs(1.0), 1e-15);
    ck_assert_ldouble_eq_tol(s21_fabs(1.1), fabs(1.1), 1e-15);
    ck_assert_ldouble_eq_tol(s21_fabs(-2.1), fabs(-2.1), 1e-15);
    ck_assert_ldouble_eq_tol(s21_fabs(0.0), fabs(0.0), 1e-15);
    ck_assert_ldouble_eq_tol(s21_fabs(-0.0), fabs(-0.0), 1e-15);
    ck_assert_ldouble_eq_tol(s21_fabs(5.123456789123), fabs(5.123456789123), 1e-15);
    ck_assert_ldouble_eq_tol(s21_fabs(0.00000004564897), fabs(0.00000004564897), 1e-15);
    ck_assert_ldouble_eq_tol(s21_fabs(170000000000000.1), fabs(170000000000000.1), 1e-15);
    ck_assert_ldouble_eq_tol(s21_fabs(-5.123456789123), fabs(-5.123456789123), 1e-15);
    ck_assert_ldouble_eq_tol(s21_fabs(-0.00000004564897), fabs(-0.00000004564897), 1e-15);
    ck_assert_ldouble_eq_tol(s21_fabs(-170000000000000.1), fabs(-170000000000000.1), 1e-15);
} END_TEST

int main(void) {
    Suite *suite = suite_create("UNITS");        // test suite - это набор тестовых случаев
    TCase *tcase = tcase_create("TESTS");        // test case — это набор тестовых примеров
    SRunner *srunner = srunner_create(suite);    // Suite runner - это функция, которая берет набор тестов
                                                 // и запускает все тестовые случаи и их тестовые функции
    int val = 0;

    suite_add_tcase(suite, tcase);
    tcase_add_test(tcase, sin_test);
    tcase_add_test(tcase, cos_test);
    tcase_add_test(tcase, tan_test);
    tcase_add_test(tcase, asin_test);
    tcase_add_test(tcase, acos_test);
    tcase_add_test(tcase, atan_test);
    tcase_add_test(tcase, exp_test);
    tcase_add_test(tcase, log_test);
    tcase_add_test(tcase, sqrt_test);
    tcase_add_test(tcase, pow_test);
    tcase_add_test(tcase, fmod_test);
    tcase_add_test(tcase, ceil_test);
    tcase_add_test(tcase, floor_test);
    tcase_add_test(tcase, abs_test);
    tcase_add_test(tcase, fabs_test);

    // Запуск всех наборов тестов (suite - набор). CK_NORMAL - что бы выводить только неудачные тесты.
    srunner_run_all(srunner, CK_NORMAL);
    // Количество проваленных тестов.
    val = srunner_ntests_failed(srunner);
    // Освобождаем память срунеру, при этом suite и tcase освобождать почему то не нужно
    srunner_free(srunner);

    return val == 0 ? 0 : 1;
}

// #include "s21_math.h"

// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include <float.h>
// #include <check.h>

// START_TEST(pow_test_1) {
//     for (double k = -9; k <= 9; k += 1.7) {
//         for (double g = -5; g < 5; g +=1) {
//             long double a = s21_pow(k, g);
//             long double b = pow(k, g);
//             if ((!isnan(a) && !isnan(b)) \
//             && !(a == INFINITY && b == INFINITY) \
//             && !(a == -INFINITY && b == -INFINITY)) {
//                 ck_assert_double_eq_tol(a, b, 1e-6);
//             }
//             a = s21_pow(g, k);
//             b = pow(g, k);
//             if ((!isnan(a) && !isnan(b)) \
//             && !(a == INFINITY && b == INFINITY) \
//             && !(a == -INFINITY && b == -INFINITY)) {
//                 ck_assert_double_eq_tol(a, b, 1e-6);
//             }
//         }
//     }
// }
// END_TEST

// // START_TEST(pow_test_2) {
// //     for (double k = -1e-1; k <= 1; k += 1.1e-1) {
// //         for (double g = -2.55; g < 2; g +=1.1) {
// //             long double a = s21_pow(k, g);
// //             long double b = pow(k, g);
// //                 ck_assert_double_eq_tol(a, b, 1e-6);
// //             a = s21_pow(g, k);
// //             b = pow(g, k);
// //                 ck_assert_double_eq_tol(a, b, 1e-6);
            
// //         }
// //     }
// // }
// // END_TEST

// START_TEST(pow_test_3) {
//     ck_assert_double_eq(pow(1, 0), s21_pow(1, 0));
//     ck_assert_double_eq(pow(-1, 3), s21_pow(-1, 3));
//     ck_assert_double_eq(pow(-1, 4), s21_pow(-1, 4));
//     ck_assert_double_eq(pow(0, 0), s21_pow(0, 0));
//     ck_assert_double_eq(pow(0, -1), s21_pow(0, -1));
//     ck_assert_double_eq(pow(0, 1), s21_pow(0, 1));
//     ck_assert_double_eq(pow(INFINITY, 0), s21_pow(INFINITY, 0));
//     ck_assert_double_eq(pow(INFINITY, -1), s21_pow(INFINITY, -1));
//     ck_assert_double_eq(pow(-1, -INFINITY), s21_pow(-1, -INFINITY));
//     ck_assert_double_eq(pow(0, INFINITY), s21_pow(0, INFINITY));
//     ck_assert_double_nan(s21_pow(0, s21_NAN));
//     ck_assert_double_eq(pow(NAN, 0), s21_pow(s21_NAN, 0));
//     ck_assert_double_nan(s21_pow(s21_NAN, s21_NAN));
//     ck_assert_double_eq(pow(INFINITY, INFINITY), s21_pow(INFINITY, INFINITY));
//     ck_assert_double_eq(pow(INFINITY, -INFINITY), s21_pow(INFINITY, -INFINITY));
//     ck_assert_double_eq(pow(-INFINITY, INFINITY), s21_pow(-INFINITY, INFINITY));
//     ck_assert_double_eq(pow(-INFINITY, -INFINITY), s21_pow(-INFINITY, -INFINITY));
//     ck_assert_double_eq(pow(1, -INFINITY), s21_pow(1, -INFINITY));
//     ck_assert_double_eq(pow(1, NAN), s21_pow(1, s21_NAN));
//     ck_assert_double_nan(s21_pow(s21_NAN, INFINITY));
//     ck_assert_double_nan(s21_pow(INFINITY, s21_NAN));
//     ck_assert_double_nan(s21_pow(s21_NAN, -INFINITY));
//     ck_assert_double_nan(s21_pow(-INFINITY, s21_NAN));
//     ck_assert_double_eq(pow(2, INFINITY), s21_pow(2, INFINITY));
//     ck_assert_double_eq(pow(0.5, INFINITY), s21_pow(0.5, INFINITY));
//     ck_assert_double_eq(pow(-2, INFINITY), s21_pow(-2, INFINITY));
//     ck_assert_double_eq(pow(2, -INFINITY), s21_pow(2, -INFINITY));
//     ck_assert_double_eq(pow(0.5, -INFINITY), s21_pow(0.5, -INFINITY));
//     ck_assert_double_eq(pow(-2, -INFINITY), s21_pow(-2, -INFINITY));
// }
// END_TEST

// START_TEST(log_test_1) {
//     for (double k = 1; k < 100; k += 13.2) {
//         double a = s21_log(k);
//         double b = log(k);
//         ck_assert_double_eq_tol(a, b, 1e-6);
//     }
// }
// END_TEST

// START_TEST(log_test_2) {
//     for (double k = 0.1; k < 4; k += 0.24) {
//         double a = s21_log(k);
//         double b = log(k);
//         ck_assert_double_eq_tol(a, b, 1e-6);
//     }
// }
// END_TEST

// START_TEST(log_test_3) {
//     for (double k = 0.1; k < 10000; k += 123) {
//         double a = s21_log(k);
//         double b = log(k);
//         ck_assert_double_eq_tol(a, b, 1e-6);
//     }
// }
// END_TEST

// START_TEST(log_test_4) {
//     for (double k = 0.000005; k < 1; k *= 5) {
//         double a = s21_log(k);
//         double b = log(k);
//         ck_assert_double_eq_tol(a, b, 1e-6);
//     }
// }
// END_TEST

// START_TEST(log_test_5) {
//     ck_assert_double_nan(s21_log(s21_NAN));
//     ck_assert_double_eq(log(0), s21_log(0));
//     ck_assert_double_nan(s21_log(-3));
//     ck_assert_double_eq(log(INFINITY), s21_log(INFINITY));
//     ck_assert_double_nan(s21_log(-INFINITY));
//     ck_assert_double_eq(log(1), s21_log(1));
//     ck_assert_double_eq(log(M_E), s21_log(M_E));
//     ck_assert_double_eq_tol(log(2), s21_log(2), 1e-6);
// }
// END_TEST

// START_TEST(sin_test_1) {
//     for (int R = 20; R >= -20; R -= 4) {
//         for (double k = 2 * s21_PI; k > -2 * s21_PI; k -= s21_PI / 17) {
//             ck_assert_double_eq_tol(sin(k + R * s21_PI), s21_sin(k + R * s21_PI), 1e-6);
//         }
//     }
// }
// END_TEST

// START_TEST(cos_test_1) {
//     for (int R = 20; R >= -20; R -= 4) {
//         for (double k = 2 * s21_PI; k > -2 * s21_PI; k -= s21_PI / 17) {
//             ck_assert_double_eq_tol(cos(k + R * s21_PI), s21_cos(k + R * s21_PI), 1e-6);
//         }
//     }
// }
// END_TEST

// START_TEST(tan_test_1) {
//     for (int R = 20; R >= -20; R -= 4) {
//         for (double k = 2 * s21_PI; k > -2 * s21_PI; k -= s21_PI / 9) {
//             ck_assert_double_eq_tol(tan(k + R * s21_PI), s21_tan(k + R * s21_PI), 1e-6);
//         }
//     }
// }
// END_TEST

// START_TEST(sin_cos_tan_test) {
//     ck_assert_double_nan(s21_sin(s21_NAN));
//     ck_assert_double_nan(s21_cos(s21_NAN));
//     ck_assert_double_nan(s21_tan(s21_NAN));
//     ck_assert_double_nan(s21_sin(INFINITY));
//     ck_assert_double_nan(s21_cos(INFINITY));
//     ck_assert_double_nan(s21_tan(INFINITY));
//     ck_assert_double_nan(s21_sin(-INFINITY));
//     ck_assert_double_nan(s21_cos(-INFINITY));
//     ck_assert_double_nan(s21_tan(-INFINITY));
//     ck_assert_double_eq_tol(tan(M_PI / 2), s21_tan(s21_PI / 2), 1e-7);
//     ck_assert_double_eq_tol(tan(-M_PI / 2), s21_tan(-s21_PI / 2), 1e-7);
// }
// END_TEST

// START_TEST(exp_test_1) {
//     for (double k = -21; k < 21; k += 1) {
//         double a = s21_exp(k);
//         double b = exp(k);
//         ck_assert_double_eq_tol(a, b, 1e-6);
//     }
// }
// END_TEST

// START_TEST(exp_test_2) {
//     for (double k = -15; k < 15; k += 0.123) {
//         double a = s21_exp(k);
//         double b = exp(k);
//         ck_assert_double_eq_tol(a, b, 1e-6);
//     }
// }
// END_TEST

// START_TEST(exp_test_3) {
//     for (double k = -5; k < 5; k += 0.00573) {
//         double a = s21_exp(k);
//         double b = exp(k);
//         ck_assert_double_eq_tol(a, b, 1e-6);
//     }
// }
// END_TEST

// START_TEST(exp_test_4) {
//     ck_assert_double_nan(s21_exp(s21_NAN));
//     ck_assert_double_eq(exp(INFINITY), s21_exp(INFINITY));
//     ck_assert_double_eq(exp(-INFINITY), s21_exp(-INFINITY));
//     ck_assert_double_eq(exp(0), s21_exp(0));
//     ck_assert_double_eq(exp(1), s21_exp(1));
// }
// END_TEST

// START_TEST(asin_test_1) {
//     for (float k = -1; k <= 1; k += 0.1) {
//         double a = s21_asin(k);
//         double b = asin(k);
//         ck_assert_double_eq_tol(a, b, 1e-7);
//     }
//     ck_assert_double_eq_tol(asin(1), s21_asin(1), 1e-7);
// }
// END_TEST

// START_TEST(asin_test_2) {
//     for (float k = -1; k <= 1; k += 0.0771) {
//         double a = s21_asin(k);
//         double b = asin(k);
//         ck_assert_double_eq_tol(a, b, 1e-7);
//     }
// }
// END_TEST

// START_TEST(acos_test_1) {
//     for (float k = -1; k <= 1; k += 0.1) {
//         double a = s21_acos(k);
//         double b = acos(k);
//         ck_assert_double_eq_tol(a, b, 1e-7);
//     }
// }
// END_TEST

// START_TEST(acos_test_2) {
//     for (float k = -1; k <= 1; k += 0.0305) {
//         double a = s21_acos(k);
//         double b = acos(k);
//         ck_assert_double_eq_tol(a, b, 1e-7);
//     }
// }
// END_TEST

// START_TEST(atan_test_1) {
//     for (float k = -10; k <= 10; k += 4) {
//         double a = s21_atan(k);
//         double b = atan(k);
//         ck_assert_double_eq_tol(a, b, 1e-7);
//     }
// }
// END_TEST

// START_TEST(sqrt_test_1) {
//     for (double k = 0; k < 21; k += 3) {
//         double a = s21_sqrt(k);
//         double b = sqrt(k);
//         ck_assert_double_eq_tol(a, b, 1e-6);
//     }
// }
// END_TEST

// START_TEST(sqrt_test_2) {
//     ck_assert_double_nan(s21_sqrt(s21_NAN));
//     ck_assert_double_nan(sqrt(NAN));
//     ck_assert_double_eq(s21_sqrt(INFINITY), sqrt(INFINITY));
//     ck_assert_double_nan(s21_sqrt(-INFINITY));
//     ck_assert_double_nan(sqrt(-INFINITY));
//     ck_assert_double_nan(s21_sqrt(-5));
//     ck_assert_double_nan(sqrt(-5));
//     ck_assert_double_eq_tol(s21_sqrt(1000), sqrt(1000), 1e-7);
// }
// END_TEST

// START_TEST(atan_test_2) {
//     double a = 12;
//     ck_assert_double_eq_tol(atan(a), s21_atan(a), 1e-7);
//     a = 0.4;
//     ck_assert_double_eq_tol(atan(a), s21_atan(a), 1e-7);
//     a = -0.333;
//     ck_assert_double_eq_tol(atan(a), s21_atan(a), 1e-7);
//     a = 55;
//     ck_assert_double_eq_tol(atan(a), s21_atan(a), 1e-7);
//     a = 13.54;
//     ck_assert_double_eq_tol(atan(a), s21_atan(a), 1e-7);
//     a = M_E;
//     ck_assert_double_eq_tol(atan(a), s21_atan(a), 1e-7);
// }
// END_TEST

// START_TEST(asin_acos_atan_test) {
//     ck_assert_double_nan(s21_asin(s21_NAN));
//     ck_assert_double_nan(s21_acos(s21_NAN));
//     ck_assert_double_nan(s21_atan(s21_NAN));
//     ck_assert_double_nan(s21_asin(INFINITY));
//     ck_assert_double_nan(s21_acos(INFINITY));
//     ck_assert_double_eq(atan(INFINITY), s21_atan(INFINITY));
//     ck_assert_double_nan(s21_asin(-INFINITY));
//     ck_assert_double_nan(s21_acos(-INFINITY));
//     ck_assert_double_eq(atan(-INFINITY), atan(-INFINITY));
//     ck_assert_double_nan(s21_asin(5));
//     ck_assert_double_nan(s21_acos(6));
//     ck_assert_double_nan(s21_asin(-8));
//     ck_assert_double_nan(s21_acos(-4));
// }
// END_TEST

// START_TEST(abs_test) {
//     ck_assert_double_eq(abs(-7), s21_abs(-7));
//     ck_assert_double_eq(abs(-98), s21_abs(-98));
//     ck_assert_double_eq(abs(123), s21_abs(123));
//     ck_assert_double_eq(abs(10009), s21_abs(10009));
//     ck_assert_double_eq(abs(-10009), s21_abs(-10009));
// }
// END_TEST

// START_TEST(fabs_test) {
//     ck_assert_double_eq(fabs(INFINITY), s21_fabs(INFINITY));
//     ck_assert_double_eq(fabs(-INFINITY), s21_fabs(-INFINITY));
//     ck_assert_double_nan(fabs(NAN));
//     ck_assert_double_nan(s21_fabs(s21_NAN));
//     ck_assert_double_eq(fabs(-7.0), s21_fabs(-7.0));
//     ck_assert_double_eq(fabs(-98.1), s21_fabs(-98.1));
//     ck_assert_double_eq(fabs(123.02), s21_fabs(123.02));
//     ck_assert_double_eq(fabs(10009.0), s21_fabs(10009.0));
//     ck_assert_double_eq(fabs(-10009.555), s21_fabs(-10009.555));
//     ck_assert_double_eq(fabs(-0.10009), s21_fabs(-0.10009));
//     ck_assert_double_eq(fabs(-1e23), s21_fabs(-1e23));
// }
// END_TEST

// START_TEST(floor_test) {
//     ck_assert_double_eq(floor(INFINITY), s21_floor(INFINITY));
//     ck_assert_double_eq(floor(-INFINITY), s21_floor(-INFINITY));
//     ck_assert_double_nan(floor(NAN));
//     ck_assert_double_nan(s21_floor(s21_NAN));
//     ck_assert_double_eq(floor(-7.0), s21_floor(-7.0));
//     ck_assert_double_eq(floor(-98.1), s21_floor(-98.1));
//     ck_assert_double_eq(floor(123.02), s21_floor(123.02));
//     ck_assert_double_eq(floor(10009.00123), s21_floor(10009.00123));
//     ck_assert_double_eq(floor(-10009.555), s21_floor(-10009.555));
//     ck_assert_double_eq(floor(-0.10009), s21_floor(-0.10009));
//     ck_assert_double_eq(floor(-1e-23), s21_floor(-1e-23));
//     ck_assert_double_eq(floor(100091234.5), s21_floor(100091234.5));
// }
// END_TEST

// START_TEST(ceil_test) {
//     ck_assert_double_eq(ceil(INFINITY), s21_ceil(INFINITY));
//     ck_assert_double_eq(ceil(-INFINITY), s21_ceil(-INFINITY));
//     ck_assert_double_nan(ceil(NAN));
//     ck_assert_double_nan(s21_ceil(s21_NAN));
//     ck_assert_double_eq(ceil(-7.0), s21_ceil(-7.0));
//     ck_assert_double_eq(ceil(-98.1), s21_ceil(-98.1));
//     ck_assert_double_eq(ceil(123.02), s21_ceil(123.02));
//     ck_assert_double_eq(ceil(10009.00123), s21_ceil(10009.00123));
//     ck_assert_double_eq(ceil(-10009.555), s21_ceil(-10009.555));
//     ck_assert_double_eq(ceil(-0.10009), s21_ceil(-0.10009));
//     ck_assert_double_eq(ceil(-1e-23), s21_ceil(-1e-23));
// }
// END_TEST

// START_TEST(fmod_test_1) {
//     ck_assert_double_nan(fmod(1, 0));
//     ck_assert_double_nan(s21_fmod(1, 0));
//     ck_assert_double_eq(fmod(0, -1), s21_fmod(0, -1));
//     ck_assert_double_eq(fmod(0, 1), s21_fmod(0, 1));
//     ck_assert_double_nan(fmod(INFINITY, -1));
//     ck_assert_double_nan(s21_fmod(INFINITY, -1));
//     ck_assert_double_eq(fmod(-1, -INFINITY), s21_fmod(-1, -INFINITY));
//     ck_assert_double_eq(fmod(0, INFINITY), s21_fmod(0, INFINITY));
//     ck_assert_double_nan(s21_fmod(0, s21_NAN));
//     ck_assert_double_nan(fmod(0, NAN));
//     ck_assert_double_nan(s21_fmod(s21_NAN, s21_NAN));
//     ck_assert_double_nan(fmod(NAN, NAN));
//     ck_assert_double_nan(s21_fmod(s21_NAN, INFINITY));
//     ck_assert_double_nan(s21_fmod(INFINITY, s21_NAN));
//     ck_assert_double_nan(s21_fmod(s21_NAN, -INFINITY));
//     ck_assert_double_nan(s21_fmod(-INFINITY, s21_NAN));
//     ck_assert_double_nan(fmod(NAN, INFINITY));
//     ck_assert_double_nan(fmod(INFINITY, NAN));
//     ck_assert_double_nan(fmod(NAN, -INFINITY));
//     ck_assert_double_nan(fmod(-INFINITY, NAN));
// }
// END_TEST

// START_TEST(fmod_test_2) {
//     for (double a = -1500; a < 1500; a += 123) {
//         for (double b = -12; b < 12; b += 1.25) {
//         ck_assert_double_eq(fmod(a, b), s21_fmod(a, b));
//         ck_assert_double_eq(fmod(b, a), s21_fmod(b, a));
//         }
//     }
// }
// END_TEST

// int main(void) {
//     TCase *tcase_core = tcase_create("Core");
//     Suite *suite = suite_create("UNITS");
//     SRunner *srunner = srunner_create(suite);
//     int val = 0;

//     tcase_add_test(tcase_core, pow_test_1);
//     // tcase_add_test(tcase_core, pow_test_2);
//     tcase_add_test(tcase_core, pow_test_3);
//     tcase_add_test(tcase_core, log_test_1);
//     tcase_add_test(tcase_core, log_test_2);
//     tcase_add_test(tcase_core, log_test_3);
//     tcase_add_test(tcase_core, log_test_4);
//     tcase_add_test(tcase_core, log_test_5);
//     tcase_add_test(tcase_core, sin_test_1);
//     tcase_add_test(tcase_core, cos_test_1);
//     tcase_add_test(tcase_core, tan_test_1);
//     tcase_add_test(tcase_core, sin_cos_tan_test);
//     tcase_add_test(tcase_core, exp_test_1);
//     tcase_add_test(tcase_core, exp_test_2);
//     tcase_add_test(tcase_core, exp_test_3);
//     tcase_add_test(tcase_core, exp_test_4);
//     tcase_add_test(tcase_core, asin_test_1);
//     tcase_add_test(tcase_core, asin_test_2);
//     tcase_add_test(tcase_core, acos_test_1);
//     tcase_add_test(tcase_core, acos_test_2);
//     tcase_add_test(tcase_core, atan_test_1);
//     tcase_add_test(tcase_core, atan_test_2);
//     tcase_add_test(tcase_core, asin_acos_atan_test);
//     tcase_add_test(tcase_core, sqrt_test_1);
//     tcase_add_test(tcase_core, sqrt_test_2);
//     tcase_add_test(tcase_core, abs_test);
//     tcase_add_test(tcase_core, fabs_test);
//     tcase_add_test(tcase_core, floor_test);
//     tcase_add_test(tcase_core, ceil_test);
//     tcase_add_test(tcase_core, fmod_test_1);
//     tcase_add_test(tcase_core, fmod_test_2);

//     suite_add_tcase(suite, tcase_core);

// // Запуск всех наборов тестов (suite - набор). CK_NORMAL - что бы выводить только неудачные тесты.
//     srunner_run_all(srunner, CK_NORMAL);
// //     // Количество проваленных тестов.
//     val = srunner_ntests_failed(srunner);
// //     // Освобождаем память срунеру, при этом suite и tcase освобождать почему то не нужно
//     srunner_free(srunner);

//     return val == 0 ? 0 : 1;
// }

// int main(void) {
//     Suite *suite = s21_string_suite();
//     SRunner *suite_runner = srunner_create(suite);
//     srunner_run_all(suite_runner, CK_VERBOSE);
//     int failed_count = srunner_ntests_failed(suite_runner);
//     srunner_free(suite_runner);
//     return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
// }


// #include "s21_math.h"

// #include <check.h>
// #include <math.h>
// #include <stdio.h>
// #include <stdlib.h>

// double my_inf = 1.0 / 0.0;
// double my_min_inf = -1.0 / 0.0;
// double my_nan = 0.0 / 0.0;
// double min_nan = -0.0 / 0.0;
// double zero = 0;
// double min_zero = -0;
// double small_num = 1;
// double min_small_num = -1;
// double num = 100;
// double min_num = -100;
// double big_num = 666666;
// double min_big_num = -666666;
// double zf = 0.5;
// double mzf = -0.5;
// double tf = 2.5;
// double mtf = -2.5;
// double big_float = 1234.456789;
// double min_big_float = -1234.456789;
// double small = 0.0000001;
// double min_small = -0.0000001;
// double long_double = 0.3425443513423432432432;
// double min_long_double = -0.3425443513423432432432;
// int flag = 0;
// double x;
// double y;
// char str1[100] = {'\0'};
// char str2[100] = {'\0'};

// START_TEST(abs_test) {
//   int my_inf = 1.0 / 0.0;
//   int my_min_inf = -1.0 / 0.0;
//   int my_nan = 0.0 / 0.0;
//   int min_nan = -0.0 / 0.0;
//   int zero = 0;
//   int min_zero = -0;
//   int small_num = 1;
//   int min_small_num = -1;
//   int num = 100;
//   int min_num = -100;
//   int big_num = 666666;
//   int min_big_num = -666666;
//   ck_assert_int_eq(s21_abs(my_inf), abs(my_inf));
//   ck_assert_int_eq(s21_abs(my_min_inf), abs(my_min_inf));
//   ck_assert_int_eq(s21_abs(my_nan), abs(my_nan));
//   ck_assert_int_eq(s21_abs(min_nan), abs(min_nan));
//   ck_assert_int_eq(s21_abs(zero), abs(zero));
//   ck_assert_int_eq(s21_abs(min_zero), abs(min_zero));
//   ck_assert_int_eq(s21_abs(big_num), abs(big_num));
//   ck_assert_int_eq(s21_abs(min_big_num), abs(min_big_num));
//   ck_assert_int_eq(s21_abs(num), abs(num));
//   ck_assert_int_eq(s21_abs(min_num), abs(min_num));
//   ck_assert_int_eq(s21_abs(small_num), abs(small_num));
//   ck_assert_int_eq(s21_abs(min_small_num), abs(min_small_num));
// }
// END_TEST

// START_TEST(fabs_test) {
//   if (s21_fabs(my_inf) == fabs(my_inf)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_fabs(my_min_inf) == fabs(my_min_inf)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   ck_assert_int_eq(s21_fabs(my_nan), fabs(my_nan));
//   ck_assert_int_eq(s21_fabs(min_nan), fabs(min_nan));
//   ck_assert_int_eq(s21_fabs(zero), fabs(zero));
//   ck_assert_int_eq(s21_fabs(min_zero), fabs(min_zero));
//   if (s21_fabs(small_num) == fabs(small_num)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_fabs(min_small_num) == fabs(min_small_num)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_fabs(num) == fabs(num)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_fabs(min_num) == fabs(min_num)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_fabs(big_num) == fabs(big_num)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_fabs(min_big_num) == fabs(min_big_num)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_fabs(zf) == fabs(zf)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_fabs(mzf) == fabs(mzf)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_fabs(tf) == fabs(tf)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_fabs(mtf) == fabs(mtf)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_fabs(big_float) == fabs(big_float)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_fabs(min_big_float) == fabs(min_big_float)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_fabs(small) == fabs(small)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_fabs(min_small) == fabs(min_small)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_fabs(long_double) == fabs(long_double)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_fabs(min_long_double) == fabs(min_long_double)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
// }
// END_TEST

// START_TEST(floor_test) {
//   if (s21_floor(my_inf) == floor(my_inf)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_floor(my_min_inf) == floor(my_min_inf)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   ck_assert_int_eq(s21_floor(my_nan), floor(my_nan));
//   ck_assert_int_eq(s21_floor(min_nan), floor(min_nan));
//   ck_assert_int_eq(s21_floor(zero), floor(zero));
//   ck_assert_int_eq(s21_floor(min_zero), floor(min_zero));
//   if (s21_floor(small_num) == floor(small_num)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_floor(min_small_num) == floor(min_small_num)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_floor(num) == floor(num)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_floor(min_num) == floor(min_num)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_floor(big_num) == floor(big_num)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_floor(min_big_num) == floor(min_big_num)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_floor(zf) == floor(zf)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_floor(mzf) == floor(mzf)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_floor(tf) == floor(tf)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_floor(mtf) == floor(mtf)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_floor(big_float) == floor(big_float)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_floor(min_big_float) == floor(min_big_float)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_floor(small) == floor(small)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_floor(min_small) == floor(min_small)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_floor(long_double) == floor(long_double)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_floor(min_long_double) == floor(min_long_double)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
// }
// END_TEST

// START_TEST(ceil_test) {
//   if (s21_ceil(my_inf) == ceil(my_inf)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_ceil(my_min_inf) == ceil(my_min_inf)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   ck_assert_int_eq(s21_ceil(my_nan), ceil(my_nan));
//   ck_assert_int_eq(s21_ceil(min_nan), ceil(min_nan));
//   ck_assert_int_eq(s21_ceil(zero), ceil(zero));
//   ck_assert_int_eq(s21_ceil(min_zero), ceil(min_zero));
//   if (s21_ceil(small_num) == ceil(small_num)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_ceil(min_small_num) == ceil(min_small_num)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_ceil(num) == ceil(num)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_ceil(min_num) == ceil(min_num)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_ceil(big_num) == ceil(big_num)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_ceil(min_big_num) == ceil(min_big_num)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_ceil(zf) == ceil(zf)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_ceil(mzf) == ceil(mzf)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_ceil(tf) == ceil(tf)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_ceil(mtf) == ceil(mtf)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_ceil(big_float) == ceil(big_float)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_ceil(min_big_float) == ceil(min_big_float)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_ceil(small) == ceil(small)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_ceil(min_small) == ceil(min_small)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_ceil(long_double) == ceil(long_double)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_ceil(min_long_double) == ceil(min_long_double)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
// }
// END_TEST

// START_TEST(exp_test) {
//   if (s21_exp(my_inf) == exp(my_inf)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_exp(my_min_inf) == exp(my_min_inf)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   ck_assert_int_eq(s21_exp(my_nan), exp(my_nan));
//   ck_assert_int_eq(s21_exp(min_nan), exp(min_nan));
//   ck_assert_int_eq(s21_exp(zero), exp(zero));
//   ck_assert_int_eq(s21_exp(min_zero), exp(min_zero));
//   x = s21_exp(small_num);
//   y = exp(small_num);
//   if (x == y) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   x = s21_exp(min_small_num);
//   y = exp(min_small_num);
//   if (x == y) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;

//   x = s21_exp(big_num);
//   y = exp(big_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_exp(min_big_num);
//   y = exp(min_big_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_exp(zf);
//   y = exp(zf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_exp(mzf);
//   y = exp(mzf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_exp(tf);
//   y = exp(tf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_exp(mtf);
//   y = exp(mtf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_exp(big_float);
//   y = exp(big_float);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_exp(min_big_float);
//   y = exp(min_big_float);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_exp(small);
//   y = exp(small);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_exp(min_small);
//   y = exp(min_small);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_exp(long_double);
//   y = exp(long_double);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_exp(min_long_double);
//   y = exp(min_long_double);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(pow_test) {
//   if (s21_pow(my_inf, 2) == pow(my_inf, 2)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   if (s21_pow(my_min_inf, 2) == pow(my_min_inf, 2)) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   x = s21_pow(my_nan, 2);
//   y = pow(my_nan, 2);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_pow(min_nan, 2);
//   y = pow(min_nan, 2);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_pow(zero, 2);
//   y = pow(zero, 2);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_pow(min_zero, 2);
//   y = pow(min_zero, 2);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_pow(small_num, 2);
//   y = pow(small_num, 2);
//   if (x == y) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   x = s21_pow(min_small_num, 2);
//   y = pow(min_small_num, 2);
//   if (x == y) flag = 1;
//   ck_assert_int_eq(flag, 1);
//   flag = 0;
//   x = s21_pow(num, 2);
//   y = pow(num, 2);
//   snprintf(str1, sizeof(str1), "%16.6lf", x);
//   snprintf(str2, sizeof(str1), "%16.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_pow(min_num, 2);
//   y = pow(min_num, 2);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_pow(big_num, 2.1);
//   y = pow(big_num, 2.1);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_pow(min_big_num, 2);
//   y = pow(min_big_num, 2);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_pow(zf, 2);
//   y = pow(zf, 2);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_pow(mzf, 2);
//   y = pow(mzf, 2);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_pow(tf, 2);
//   y = pow(tf, 2);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_pow(mtf, 2);
//   y = pow(mtf, 2);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_pow(big_float, 2);
//   y = pow(big_float, 2);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_pow(min_big_float, 2);
//   y = pow(min_big_float, 2);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_pow(small, 2);
//   y = pow(small, 2);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_pow(min_small, 2);
//   y = pow(min_small, 2);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_pow(long_double, 2);
//   y = pow(long_double, 2);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_pow(min_long_double, 2);
//   y = pow(min_long_double, 2);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(sqrt_test) {
//   x = s21_sqrt(my_inf);
//   y = sqrt(my_inf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sqrt(my_min_inf);
//   y = sqrt(my_min_inf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(s21_sqrt(my_nan), sqrt(my_nan));
//   ck_assert_int_eq(s21_sqrt(min_nan), sqrt(min_nan));
//   ck_assert_int_eq(s21_sqrt(zero), sqrt(zero));
//   ck_assert_int_eq(s21_sqrt(min_zero), sqrt(min_zero));
//   x = s21_sqrt(small_num);
//   y = sqrt(small_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sqrt(min_small_num);
//   y = sqrt(min_small_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sqrt(num);
//   y = sqrt(num);
//   snprintf(str1, sizeof(str1), "%16.6lf", x);
//   snprintf(str2, sizeof(str1), "%16.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sqrt(min_num);
//   y = sqrt(min_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sqrt(big_num);
//   y = sqrt(big_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sqrt(min_big_num);
//   y = sqrt(min_big_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sqrt(zf);
//   y = sqrt(zf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sqrt(mzf);
//   y = sqrt(mzf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sqrt(tf);
//   y = sqrt(tf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sqrt(mtf);
//   y = sqrt(mtf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sqrt(big_float);
//   y = sqrt(big_float);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sqrt(min_big_float);
//   y = sqrt(min_big_float);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sqrt(small);
//   y = sqrt(small);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sqrt(min_small);
//   y = sqrt(min_small);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sqrt(long_double);
//   y = sqrt(long_double);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sqrt(min_long_double);
//   y = sqrt(min_long_double);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(fmod_test) {
//   x = s21_fmod(my_inf, 3);
//   y = fmod(my_inf, 3);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(my_min_inf, 3);
//   y = fmod(my_min_inf, 3);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(my_nan, 3);
//   y = fmod(my_nan, 3);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(min_nan, 3);
//   y = fmod(min_nan, 3);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(zero, 3);
//   y = fmod(zero, 3);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(min_zero, 3);
//   y = fmod(min_zero, 3);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(small_num, 3);
//   y = fmod(small_num, 3);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(min_small_num, 3);
//   y = fmod(min_small_num, 3);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(num, 3);
//   y = fmod(num, 3);
//   snprintf(str1, sizeof(str1), "%16.6lf", x);
//   snprintf(str2, sizeof(str1), "%16.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(min_num, 3);
//   y = fmod(min_num, 3);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(big_num, 3);
//   y = fmod(big_num, 3);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(min_big_num, 3);
//   y = fmod(min_big_num, 3);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(zf, 3);
//   y = fmod(zf, 3);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(mzf, 3);
//   y = fmod(mzf, 3);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(tf, 3);
//   y = fmod(tf, 3);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(mtf, 3);
//   y = fmod(mtf, 3);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(big_float, 3);
//   y = fmod(big_float, 3);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(min_big_float, 3);
//   y = fmod(min_big_float, 3);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(small, 3);
//   y = fmod(small, 3);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(min_small, 3);
//   y = fmod(min_small, 3);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(long_double, 3);
//   y = fmod(long_double, 3);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(min_long_double, 3);
//   y = fmod(min_long_double, 3);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);

//   x = s21_fmod(my_inf, 2.5);
//   y = fmod(my_inf, 2.5);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(my_min_inf, 2.5);
//   y = fmod(my_min_inf, 2.5);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(my_nan, 2.5);
//   y = fmod(my_nan, 2.5);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(min_nan, 2.5);
//   y = fmod(min_nan, 2.5);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(zero, 2.5);
//   y = fmod(zero, 2.5);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(min_zero, 2.5);
//   y = fmod(min_zero, 2.5);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(small_num, 2.5);
//   y = fmod(small_num, 2.5);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(min_small_num, 2.5);
//   y = fmod(min_small_num, 2.5);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(num, 2.5);
//   y = fmod(num, 2.5);
//   snprintf(str1, sizeof(str1), "%16.6lf", x);
//   snprintf(str2, sizeof(str1), "%16.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(min_num, 2.5);
//   y = fmod(min_num, 2.5);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(big_num, 2.5);
//   y = fmod(big_num, 2.5);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(min_big_num, 2.5);
//   y = fmod(min_big_num, 2.5);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(zf, 2.5);
//   y = fmod(zf, 2.5);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(mzf, 2.5);
//   y = fmod(mzf, 2.5);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(tf, 2.5);
//   y = fmod(tf, 2.5);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(mtf, 2.5);
//   y = fmod(mtf, 2.5);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(big_float, 2.5);
//   y = fmod(big_float, 2.5);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(min_big_float, 2.5);
//   y = fmod(min_big_float, 2.5);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(small, 2.5);
//   y = fmod(small, 2.5);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(min_small, 2.5);
//   y = fmod(min_small, 2.5);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(long_double, 2.5);
//   y = fmod(long_double, 2.5);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_fmod(min_long_double, 2.5);
//   y = fmod(min_long_double, 2.5);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(log_test) {
//   x = s21_log(my_inf);
//   y = log(my_inf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_log(my_min_inf);
//   y = log(my_min_inf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_log(my_nan);
//   y = log(my_nan);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_log(min_nan);
//   y = log(min_nan);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_log(zero);
//   y = log(zero);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_log(min_zero);
//   y = log(min_zero);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_log(small_num);
//   y = log(small_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_log(min_small_num);
//   y = log(min_small_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_log(num);
//   y = log(num);
//   snprintf(str1, sizeof(str1), "%16.6lf", x);
//   snprintf(str2, sizeof(str1), "%16.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_log(min_num);
//   y = log(min_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_log(big_num);
//   y = log(big_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_log(min_big_num);
//   y = log(min_big_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_log(zf);
//   y = log(zf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_log(mzf);
//   y = log(mzf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_log(tf);
//   y = log(tf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_log(mtf);
//   y = log(mtf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_log(big_float);
//   y = log(big_float);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_log(min_big_float);
//   y = log(min_big_float);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_log(small);
//   y = log(small);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_log(min_small);
//   y = log(min_small);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_log(long_double);
//   y = log(long_double);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_log(min_long_double);
//   y = log(min_long_double);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(sin_test) {
//   x = s21_sin(my_inf);
//   y = sin(my_inf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sin(my_min_inf);
//   y = sin(my_min_inf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sin(my_nan);
//   y = sin(my_nan);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sin(min_nan);
//   y = sin(min_nan);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sin(zero);
//   y = sin(zero);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sin(min_zero);
//   y = sin(min_zero);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sin(small_num);
//   y = sin(small_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sin(min_small_num);
//   y = sin(min_small_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sin(num);
//   y = sin(num);
//   snprintf(str1, sizeof(str1), "%16.6lf", x);
//   snprintf(str2, sizeof(str1), "%16.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sin(min_num);
//   y = sin(min_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sin(big_num);
//   y = sin(big_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sin(min_big_num);
//   y = sin(min_big_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sin(zf);
//   y = sin(zf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sin(mzf);
//   y = sin(mzf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sin(tf);
//   y = sin(tf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sin(mtf);
//   y = sin(mtf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sin(big_float);
//   y = sin(big_float);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sin(min_big_float);
//   y = sin(min_big_float);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sin(small);
//   y = sin(small);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sin(min_small);
//   y = sin(min_small);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sin(long_double);
//   y = sin(long_double);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_sin(min_long_double);
//   y = sin(min_long_double);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(cos_test) {
//   x = s21_cos(my_inf);
//   y = cos(my_inf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_cos(my_min_inf);
//   y = cos(my_min_inf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_cos(my_nan);
//   y = cos(my_nan);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_cos(min_nan);
//   y = cos(min_nan);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_cos(zero);
//   y = cos(zero);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_cos(min_zero);
//   y = cos(min_zero);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_cos(small_num);
//   y = cos(small_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_cos(min_small_num);
//   y = cos(min_small_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_cos(num);
//   y = cos(num);
//   snprintf(str1, sizeof(str1), "%16.6lf", x);
//   snprintf(str2, sizeof(str1), "%16.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_cos(min_num);
//   y = cos(min_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_cos(zf);
//   y = cos(zf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_cos(mzf);
//   y = cos(mzf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_cos(tf);
//   y = cos(tf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_cos(mtf);
//   y = cos(mtf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_cos(big_float);
//   y = cos(big_float);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_cos(min_big_float);
//   y = cos(min_big_float);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_cos(small);
//   y = cos(small);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_cos(min_small);
//   y = cos(min_small);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_cos(long_double);
//   y = cos(long_double);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_cos(min_long_double);
//   y = cos(min_long_double);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(tan_test) {
//   x = s21_tan(my_inf);
//   y = tan(my_inf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_tan(my_min_inf);
//   y = tan(my_min_inf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_tan(my_nan);
//   y = tan(my_nan);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_tan(min_nan);
//   y = tan(min_nan);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_tan(zero);
//   y = tan(zero);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_tan(min_zero);
//   y = tan(min_zero);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_tan(small_num);
//   y = tan(small_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_tan(min_small_num);
//   y = tan(min_small_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_tan(num);
//   y = tan(num);
//   snprintf(str1, sizeof(str1), "%16.6lf", x);
//   snprintf(str2, sizeof(str1), "%16.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_tan(min_num);
//   y = tan(min_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_tan(zf);
//   y = tan(zf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_tan(mzf);
//   y = tan(mzf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_tan(tf);
//   y = tan(tf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_tan(mtf);
//   y = tan(mtf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_tan(big_float);
//   y = tan(big_float);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_tan(min_big_float);
//   y = tan(min_big_float);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_tan(small);
//   y = tan(small);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_tan(min_small);
//   y = tan(min_small);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_tan(long_double);
//   y = tan(long_double);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_tan(min_long_double);
//   y = tan(min_long_double);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(asin_test) {
//   x = s21_asin(my_inf);
//   y = asin(my_inf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_asin(my_min_inf);
//   y = asin(my_min_inf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_asin(my_nan);
//   y = asin(my_nan);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_asin(min_nan);
//   y = asin(min_nan);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_asin(zero);
//   y = asin(zero);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_asin(min_zero);
//   y = asin(min_zero);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_asin(small_num);
//   y = asin(small_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_asin(min_small_num);
//   y = asin(min_small_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_asin(num);
//   y = asin(num);
//   snprintf(str1, sizeof(str1), "%16.6lf", x);
//   snprintf(str2, sizeof(str1), "%16.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_asin(min_num);
//   y = asin(min_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_asin(big_num);
//   y = asin(big_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_asin(min_big_num);
//   y = asin(min_big_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_asin(zf);
//   y = asin(zf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_asin(mzf);
//   y = asin(mzf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_asin(tf);
//   y = asin(tf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_asin(mtf);
//   y = asin(mtf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_asin(big_float);
//   y = asin(big_float);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_asin(min_big_float);
//   y = asin(min_big_float);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_asin(small);
//   y = asin(small);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_asin(min_small);
//   y = asin(min_small);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_asin(long_double);
//   y = asin(long_double);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_asin(min_long_double);
//   y = asin(min_long_double);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(atan_test) {
//   x = s21_atan(my_inf);
//   y = atan(my_inf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_atan(my_min_inf);
//   y = atan(my_min_inf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_atan(my_nan);
//   y = atan(my_nan);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_atan(min_nan);
//   y = atan(min_nan);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_atan(zero);
//   y = atan(zero);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_atan(min_zero);
//   y = atan(min_zero);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_atan(small_num);
//   y = atan(small_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_atan(min_small_num);
//   y = atan(min_small_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_atan(num);
//   y = atan(num);
//   snprintf(str1, sizeof(str1), "%16.6lf", x);
//   snprintf(str2, sizeof(str1), "%16.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_atan(min_num);
//   y = atan(min_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_atan(big_num);
//   y = atan(big_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_atan(min_big_num);
//   y = atan(min_big_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_atan(zf);
//   y = atan(zf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_atan(mzf);
//   y = atan(mzf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_atan(tf);
//   y = atan(tf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_atan(mtf);
//   y = atan(mtf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_atan(big_float);
//   y = atan(big_float);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_atan(min_big_float);
//   y = atan(min_big_float);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_atan(small);
//   y = atan(small);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_atan(min_small);
//   y = atan(min_small);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_atan(long_double);
//   y = atan(long_double);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_atan(min_long_double);
//   y = atan(min_long_double);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(acos_test) {
//   x = s21_acos(my_inf);
//   y = acos(my_inf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_acos(my_min_inf);
//   y = acos(my_min_inf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_acos(my_nan);
//   y = acos(my_nan);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_acos(min_nan);
//   y = acos(min_nan);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_acos(zero);
//   y = acos(zero);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_acos(min_zero);
//   y = acos(min_zero);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_acos(small_num);
//   y = acos(small_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_acos(min_small_num);
//   y = acos(min_small_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_acos(num);
//   y = acos(num);
//   snprintf(str1, sizeof(str1), "%16.6lf", x);
//   snprintf(str2, sizeof(str1), "%16.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_acos(min_num);
//   y = acos(min_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_acos(big_num);
//   y = acos(big_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_acos(min_big_num);
//   y = acos(min_big_num);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_acos(zf);
//   y = acos(zf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_acos(mzf);
//   y = acos(mzf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_acos(tf);
//   y = acos(tf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_acos(mtf);
//   y = acos(mtf);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_acos(big_float);
//   y = acos(big_float);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_acos(min_big_float);
//   y = acos(min_big_float);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_acos(small);
//   y = acos(small);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_acos(min_small);
//   y = acos(min_small);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_acos(long_double);
//   y = acos(long_double);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
//   x = s21_acos(min_long_double);
//   y = acos(min_long_double);
//   snprintf(str1, sizeof(str1), "%.6lf", x);
//   snprintf(str2, sizeof(str1), "%.6lf", y);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// int main(void) {
//   Suite *s1 = suite_create("Core");
//   TCase *tc1_1 = tcase_create("Core");
//   SRunner *sr = srunner_create(s1);
//   int nf;

//   suite_add_tcase(s1, tc1_1);
//   tcase_add_test(tc1_1, abs_test);
//   tcase_add_test(tc1_1, fabs_test);
//   tcase_add_test(tc1_1, floor_test);
//   tcase_add_test(tc1_1, ceil_test);
//   tcase_add_test(tc1_1, exp_test);
//   tcase_add_test(tc1_1, pow_test);
//   tcase_add_test(tc1_1, sqrt_test);
//   tcase_add_test(tc1_1, fmod_test);
//   tcase_add_test(tc1_1, log_test);
//   tcase_add_test(tc1_1, sin_test);
//   tcase_add_test(tc1_1, cos_test);
//   tcase_add_test(tc1_1, tan_test);
//   tcase_add_test(tc1_1, asin_test);
//   tcase_add_test(tc1_1, atan_test);
//   tcase_add_test(tc1_1, acos_test);

//   srunner_run_all(sr, CK_ENV);
//   nf = srunner_ntests_failed(sr);
//   srunner_free(sr);

//   return nf == 0 ? 0 : 1;
// }
