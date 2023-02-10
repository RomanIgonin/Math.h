#include "s21_math.h"

long double s21_sin(double x) {
    long double buff = 0;
    long double res = 0;
    if (x == s21_MAX_INF) res = s21_NAN;
    if (x < (-2 * s21_PI) || x > (2 * s21_PI)) x = s21_fmod(x, 2 * s21_PI);

    buff = x;         // один кусок ряда
    res = buff;       // cумма кусков ряда
    for (int i = 1; s21_fabs(buff) > 1e-18; i++) {
        buff *= -x * x / (2.0 * i) / (2.0 * i + 1.0);
        res += buff;
    }
    return res;
}

long double s21_cos(double x) {
    return s21_sin(s21_PI / 2 - x); 
}

long double s21_tan(double x) {
    long double res = 0;
    if (x == s21_PI / 2) res = 16331239353195370;
    else if (x == -s21_PI / 2) res = -16331239353195370;
    else if (x == 0) res = 0;
    else res = s21_sin(x) / s21_cos(x);
    return res;
}

long double s21_asin(double x) {
    long double num = 1;
    if (s21_fabs(x) < 1e-8) num = 0;
    else if (-1.0 <= x && x <= 1.0 && x != s21_MAX_INF && x != s21_MIN_INF && x == x) 
        num = s21_atan(x / s21_sqrt(1 - x * x));
    else  num = s21_NAN;
    return num;
}

long double s21_acos(double x) {
    return s21_PI / 2.0 - s21_asin(x);
}

long double s21_atan(double x) {
    long double res = 0;
    long double limit = 0;
    int num = 0;
    if (x != x) res = s21_NAN;
    else {
        if (x < 0) {
        x = s21_fabs(x);
        num = 1;
        }
        if (x >= 0 && x < 0.6875) {
            long double buff = x;
            int sign_2 = -1;
            for (int i = 0; i < 20; i++) {
                sign_2 *= -1;
                res += sign_2 * buff / (2 * i + 1);
                buff *= s21_pow(x, 2); 
            }
        }
        if (x <= -2 && x != 0) limit++;
        if (x >= 0.6875 && x < 1.1875) res = s21_atan((x - 1) / (1 + x)) + 0.785398163;
        if (x >= 1.1875 && x < 2.4375) res = s21_atan((x - 1.5) / (1.0 + 1.5 * x)) + 0.982793723;
        if (x >= 2.4375) res = s21_atan(-1 / x) + (s21_PI / 2.0);
        if (num) res *= -1;
        res += limit;
    }
    return res;
}

long double s21_log(double x) {     // Готов
    long double res = 0;
    long double buff = 0;
    long double num = x;
    int i = 0;
    if (x < 0) res = s21_NAN;
    else if (x == 0) res = s21_MIN_INF;
    else if (x == s21_MAX_INF) res = s21_MAX_INF;
    else {
        for (; num > s21_EXP; i++) num /= s21_EXP;

        for (int j = 0; j < 100; j++) {
            buff = res;
            res = buff + 2 * (num - s21_exp(buff)) / (num + s21_exp(buff));
        }
        res += i;
    }
    return res;
}

long double s21_pow(double base, double exp) {  // на числах 666666 точность уезжает из за exp
    long double buff = base;
    long double res;
    res = s21_exp(s21_log(buff) * exp);

    if (exp != exp) {
        if (base == 1) res = 1;
        else res = s21_NAN;
        return res;
    }
    if (base != base) {
        if (exp == 0) res = 1;
        else res = s21_NAN;
        return res;
    }

    if (exp == s21_MIN_INF && base == base) {
        if (base == 1 || base == -1) res = 1;
        else if (-1 < base && base < 1) res = s21_MAX_INF;
        else res = 0;
        return res;
    }
    if (exp == s21_MAX_INF && base == base) {
        if (base == s21_MIN_INF) res = s21_MAX_INF;
        else if (base == 1 || base == -1) res = 1;
        else if (-1 < base && base < 1) res = 0;
        else res = s21_MAX_INF;
        return res;
    }
    if (base == s21_MIN_INF) {
        if (exp == 0) res = 1;
        else if (exp > 0) res = s21_MAX_INF;
        else res = 0;
        return res;
    }
    if (base == 0) {
        if (exp == 0) res = 1;
        else if (exp > 0) res = 0;
        else res = s21_MAX_INF;
        return res;
    }
    if (base < 0 && s21_fmod(exp, 1) != 0) return s21_NAN;
    if (base < 0 && exp == 0) return 1;
    else {
        if (buff < 0) {
            buff = -buff;
            res = s21_exp(s21_log(buff) * exp);
            if (s21_fmod(exp, 2) != 0) res = -res;
        }
    }
    return res; // 2 в 50 степени после запятой не сходится
}

long double s21_exp(double x) { // exp теряет точность на 25 и больше, что влияет на pow
    long double buff = 1;
    long double res = 1;
    int num = 0;
    if (x < 0) {
        x *= -1;
        num = 1;
    }
    for (long double i = 1; s21_fabs(buff) > 1e-20; i++) {
        buff *= x / i;
        res += buff;
        if (res > DBL_MAX) {
            res = s21_MAX_INF;
            break;
        }
    }
    if (num) {
        if (res > DBL_MAX) res = 0;
        else res = 1.0 / res;
    }
    return res;
}

long double s21_sqrt(double x) {
    long double res = 0;
    if (x == 0) res = 0;
    else if (x == s21_MAX_INF) res = s21_MAX_INF;
    else if (x == s21_MIN_INF || x != x || x < 0) res = s21_NAN;
    else {
        res = s21_pow(x, 0.5);
    }
    return res;
}

long double s21_fabs(double x) {
    long double buff = x;
    if (buff < 0) 
        buff *= -1;
    return buff;
}

long double s21_fmod(double x, double y) {
    long double res = 0;
    long long int dif = 0;
    if (x == s21_MAX_INF || x == s21_MIN_INF || y == 0 || s21_fabs(y) < 1e-7) res = s21_NAN;
    else if (x == 0 && y != y) res = s21_NAN;
    else if (y == s21_MAX_INF || y == s21_MIN_INF) res = x;
    else if (s21_fabs(x) < 1e-7) res = 0;
    else {
        dif = x / y;
        res = (long double)x - ((long double)y * dif);
    }
    return res;
}

int s21_abs(int x) {
    if(x < 0) x *= -1;
    return x;
}

long double s21_ceil(double x) {
    long double res = (long long int)x;
    long double buff = x;
    if (x > 0 && (buff - res) != 0) res += 1;
    res = check(x, res);
    return res;
}

long double s21_floor(double x) {
    long double res = (long long int)x;
    long double buff = x;
    if (x < 0 && (buff - res) != 0) res -= 1;
    res = check(x, res);
    return res;
}

long double check(long double x, long double res) {
    long double buff = res;
    if (x == s21_MAX_INF) buff = s21_MAX_INF;
    if (x == s21_MIN_INF) buff = s21_MIN_INF;
    if (x != x) buff = s21_NAN;
    return buff;
}

long double check_2(long double x) { 
    return (x == s21_MAX_INF || x == s21_MIN_INF || x != x);
}

