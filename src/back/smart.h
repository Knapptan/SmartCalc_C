#ifndef _SMART_H
#define _SMART_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// структура для символов
typedef struct Node Node;
struct Node {
  char data;
  Node *next;
};

// структура для цифр
typedef struct Numbers Numbers;
typedef struct Numbers {
  double data;
  Numbers *next;
} Numbers;

// логика исполнения
double smart_calc(char *str, double x);
void get_rid_of_spaces(char *str, char *result);

// проверка
int check_str(char *str);
int check_brackets(char *str);
int check_brackets_left(char *str, int a);
int check_brackets_right(char *str, int a);
int check_sin_sqrt(char *str, int *a, int value);
int check_cos(char *str, int *a);
int check_tan(char *str, int *a);
int check_ln_log(char *str, int *a);
int check_a_group(char *str, int *a, int value);
int check_signs(char *str, int a);
int check_func(char *str, int a);
int check_mod(char *str, int *a);
int check_after_point(char *str, int a);
int check_x(char *str, int a);

// польская
void parser(char *str, char *str_p_notation);
void push(Node **list, char d);
char pop(Node **list);
int priority(char sym);
void simplification(char *str);
int is_digit(char sym);

// решение
double calculate(char *str, double x);
int is_func_op(char sym);
double get_variable(char *str, int *i, double x);
void push_numbers(Numbers **list, double d);
double pop_numbers(Numbers **list);
void arithmetic_simple(Numbers **list, char sym);
void arithmetic(Numbers **list, char sym);

// кредитный
double annuity_calc(double loan, double interest, double term);
double diff_calc(double amount, double interest, double term, double *total);
int calculate_credit(double amount, double interest, double term, int flagDiff,
                     double *monthly, double *overpayment, double *total);

// депозитный
void deposit_calc(double summ, double n, double interest_rate, double tax_rate,
                  int periodicity_payments, int capitalization, int count_add,
                  double add, int count_sub, double sub, double *result,
                  double *tax_with, double *accrued_interest);

#endif
