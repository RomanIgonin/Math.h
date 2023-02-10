#ifndef _S_21_MATH_H_
#define _S_21_MATH_H_

#include <stdio.h>
#include <math.h> // delete
#include <stdlib.h>
#include <float.h> // для DBL_MAX

#define s21_NAN 0.0 / 0.0
#define s21_MAX_INF 1.0 / 0.0
#define s21_MIN_INF -1.0 / 0.0
#define s21_PI 3.14159265358979323846264338327950288
#define s21_EXP 2.7182818284590452353602874713526624
#define S21_EPS 1e-7                                    // del
#define S21_INF 1.0 / 0.0                               // del
#define S21_NAN 0.0 / 0.0                               // del

long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);

long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);

long double s21_fmod(double x, double y);      // остаток от деления чисел с плавающей точкой
long double s21_log(double x);                 // вычисляет степень в которую нужно возвести exp
long double s21_pow(double base, double exp);  // возводит число в заданную степень
long double s21_sqrt(double x);                // квадратный корень числа
long double s21_exp(double x);                 // возводит exp в заданную степень

long double s21_ceil(double x);                // округление к большему
long double s21_floor(double x);               // округление к меньшему

long double s21_fabs(double x);                // возвращает число по модулю
int s21_abs(int x);

// дополнительные для вычисления 15 основных из задания
long double check(long double x, long double res); // Проверка на inf, -inf и nan
long double check_2(long double x);

#endif  // _S_21_MATH_H_
