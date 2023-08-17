#include "smart.h"

// ядро основние исполнение программы
double smart_calc(char *str, double x) {
  double result = 0.0;
  char no_sp_str[256] = {0};
  get_rid_of_spaces(str, no_sp_str);
  if (check_str(no_sp_str)) {
    char str_p_notation[256] = {0};
    parser(no_sp_str, str_p_notation);
    result = calculate(str_p_notation, x);
  } else {
    result = NAN;
  }
  return result;
}

// проверка матиматической записи
int check_str(char *str) {
  int flag_for_point = 0, break_point = 0;
  int result = 1;
  char *alphabet = " .0123456789()+~-*/^%acgilnoqrstxmd";
  if (strlen(str) > 256 || str == NULL || strlen(str) < 1) {
    result = 0;
  } else {
    if (!check_brackets(str)) {
      result = 0;
      break_point = 1;
    }
    for (int i = 0; (str[i] != '\0' || i != (int)strlen(str)) && !break_point;
         i++) {
      if (str[i] == 's') {
        if (!check_sin_sqrt(str, &i, 0)) {
          result = 0;
          break_point = 1;
        }
      } else if (str[i] == 'c') {
        if (!check_cos(str, &i)) {
          result = 0;
          break_point = 1;
        }
      } else if (str[i] == 't') {
        if (!check_tan(str, &i)) {
          result = 0;
          break_point = 1;
        }
      } else if (str[i] == 'l') {
        if (!check_ln_log(str, &i)) {
          result = 0;
          break_point = 1;
        }
      } else if (str[i] == 'a') {
        if (!check_a_group(str, &i, 0)) {
          result = 0;
          break_point = 1;
        }
      } else if (str[i] == 'm') {
        if (!check_mod(str, &i)) {
          result = 0;
          break_point = 1;
        }
        flag_for_point = 0;
      } else if (str[i] == '(') {
        if (!check_brackets_left(str, i)) {
          result = 0;
          break_point = 1;
        }
      } else if (str[i] == ')') {
        if (!check_brackets_right(str, i)) {
          result = 0;
          break_point = 1;
        }
      } else if (str[i] == '-' || str[i] == '+' || str[i] == '*' ||
                 str[i] == '/' || str[i] == '^') {
        flag_for_point = 0;
        if (!check_signs(str, i)) {
          result = 0;
          break_point = 1;
        }
      } else if (str[i] == '.') {
        if (!check_after_point(str, i)) {
          result = 0;
          break_point = 1;
        }
        if (flag_for_point) {
          result = 0;
          break_point = 1;
        }
        flag_for_point = 1;
      } else if (str[i] == 'x') {
        if (!check_x(str, i)) {
          result = 0;
          break_point = 1;
        }
      } else if (strchr(alphabet, str[i]) == NULL &&
                 i != (int)strlen(str) - 1) {
        result = 0;
        break_point = 1;
      }
    }
  }
  return result;
}

// проверка закрития скобок
int check_brackets(char *str) {
  int result = 1, bracket = 0, break_point = 0;
  for (int i = 0; str[i] != '\0' && !break_point; i++) {
    if (bracket < 0) {
      break_point = 1;
    } else if (str[i] == '(')
      bracket++;
    else if (str[i] == ')')
      bracket--;
  }
  if (bracket != 0) result = 0;
  return result;
}

// проверка открытой скобки
int check_brackets_left(char *str, int i) {
  int result = 0;
  if (i == 0 || (str[i + 1] >= '0' && str[i + 1] <= '9') || str[i + 1] == 'x' ||
      check_func(str, i + 1) || str[i + 1] == '-' || str[i + 1] == '+' ||
      str[i + 1] == '(') {
    result = 1;
  }
  return result;
}

// проверка закрытой скобки
int check_brackets_right(char *str, int i) {
  int result = 0;
  if (i != 0 && ((str[i - 1] >= '0' && str[i - 1] <= '9') ||
                 str[i - 1] == 'x' || str[i - 1] == ')')) {
    result = 1;
  }
  return result;
}

// проверка записи синус или корень
int check_sin_sqrt(char *str, int *i, int value) {
  int result = 0, b = 0;
  b = *i + 1;
  if (str[b] == 'i' && str[b + 1] == 'n' && str[b + 2] == '(') {
    result = 1;
    *i = *i + 3;
  } else if (str[b] == 'q' && str[b + 1] == 'r' && str[b + 2] == 't' &&
             str[b + 3] == '(') {
    if (!value) result = 1;
    *i = *i + 4;
  }
  return result;
}

// проверка записи косинуса
int check_cos(char *str, int *i) {
  int result = 0, b = 0;
  b = *i + 1;
  if (str[b] == 'o' && str[b + 1] == 's' && str[b + 2] == '(') {
    result = 1;
    *i = *i + 3;
  }
  return result;
}

// проверка записи тангенса
int check_tan(char *str, int *i) {
  int result = 0, b = 0;
  b = *i + 1;
  if (str[b] == 'a' && str[b + 1] == 'n' && str[b + 2] == '(') {
    result = 1;
    *i = *i + 3;
  }
  return result;
}

// проверка записи логарифма
int check_ln_log(char *str, int *i) {
  int result = 0, b = 0;
  b = *i + 1;
  if (str[b] == 'n' && str[b + 1] == '(') {
    result = 1;
    *i = *i + 2;
  } else if (str[b] == 'o' && str[b + 1] == 'g' && str[b + 2] == '(') {
    result = 1;
    *i = *i + 3;
  }
  return result;
}

// проверка записи с а в начале
int check_a_group(char *str, int *i, int value) {
  int result = 0, b = 0;
  if (value == 0)
    b = *i + 1;
  else
    b = *i;
  if (str[b] == 's') {
    if (check_sin_sqrt(str, &b, 1)) result = 1;
  } else if (str[b] == 'c') {
    if (check_cos(str, &b)) result = 1;
  } else if (str[b] == 't') {
    if (check_tan(str, &b)) result = 1;
  }
  *i = b;
  return result;
}

// проверка записи знаков
int check_signs(char *str, int a) {
  int result = 0;
  if (((str[a + 1] >= '0' && str[a + 1] <= '9') || str[a + 1] == '(' ||
       check_func(str, a + 1) || str[a + 1] == 'x') &&
      ((str[a - 1] == ')' || str[a - 1] == 'x' || str[a - 1] == '(' ||
        (str[a - 1] >= '0' && str[a - 1] <= '9')))) {
    result = 1;
    if (str[a] == '*' || str[a] == '/') {
      if ((str[a - 1] <= '0' && str[a - 1] != ')') ||
          (str[a - 1] >= '9' && str[a - 1] != 'x')) {
        result = 0;
      }
    }
  } else if ((str[a] == '-' || str[a] == '+') && a == 0) {
    result = 1;
  }
  return result;
}

// проверка записи функций
int check_func(char *str, int a) {
  int result = 1;
  if (str[a] == 'a') {
    if (!check_a_group(str, &a, 0)) result = 0;
  } else if (str[a] == 'l') {
    if (!check_ln_log(str, &a)) result = 0;
  } else if (!check_a_group(str, &a, 1)) {
    result = 0;
  }
  return result;
}

// проверка записи мод
int check_mod(char *str, int *i) {
  int result = 0, b = 0;
  b = *i + 1;
  if (str[b] == 'o' && str[b + 1] == 'd' &&
      ((str[b + 2] >= '0' && str[b + 2] <= '9') || str[b + 2] == '(' ||
       str[b + 2] == 'x') &&
      ((str[b - 2] >= '0' && str[b - 2] <= '9') || str[b - 2] == ')' ||
       str[b - 2] == 'x')) {
    result = 1;
    *i = *i + 2;
  }
  return result;
}

// проверка после точки
int check_after_point(char *str, int a) {
  int result = 0;
  if (str[a + 1] >= '0' && str[a + 1] <= '9' && str[a - 1] >= '0' &&
      str[a - 1] <= '9')
    result = 1;
  return result;
}

// проверка икса
int check_x(char *str, int a) {
  int result = 0;
  if ((strchr("m+-*/%^)", str[a + 1]) != NULL) &&
      strchr("m+-*/%^(", str[a - 1]) != NULL) {
    result = 1;
  }

  return result;
}

//                      parser

// логика записи в стек (парсер)
void parser(char *str, char *str_p_notation) {
  simplification(str);
  struct Node *stack = NULL;
  int i_pn = 0, flag = 0, break_flag = 0;
  for (int i = 0; str[i] != '\0' && !break_flag; i++) {
    if (is_digit(str[i])) {
      str_p_notation[i_pn] = str[i];
      i_pn++;
      if (!is_digit(str[i + 1])) {
        str_p_notation[i_pn] = ' ';
        i_pn++;
      }
    } else if (str[i] == '(' || strchr("sctlqSCTML", str[i]) != NULL) {
      push(&stack, str[i]);
    } else if (str[i] == ')') {
      int flag_for_right_br = 0;
      if (stack->data == '(') {
        flag_for_right_br = 1;
      }
      while (stack->data != '(') {
        flag_for_right_br = 1;
        str_p_notation[i_pn] = pop(&stack);
        i_pn++;
        str_p_notation[i_pn] = ' ';
        i_pn++;
      }
      if (!flag_for_right_br) {
        str_p_notation = NULL;
        flag = 1;
        break_flag = 1;
      }
      pop(&stack);
      if (strchr("sctlqSCTML", str[i])) {
        str_p_notation[i_pn] = pop(&stack);
        i_pn++;
        str_p_notation[i_pn] = ' ';
        i_pn++;
      }
    } else {
      while (stack != NULL && (priority(stack->data) >= priority(str[i]) &&
                               stack->data != '^')) {
        str_p_notation[i_pn] = pop(&stack);
        i_pn++;
        str_p_notation[i_pn] = ' ';
        i_pn++;
      }
      push(&stack, str[i]);
    }
  }
  int f = 0;
  while (stack != NULL && !flag) {
    if (stack->data == '(' && stack->data == ')' && f == 0) {
      str_p_notation = NULL;
      break_flag = 1;
    } else {
      f = 1;
      str_p_notation[i_pn] = pop(&stack);
      i_pn++;
    }
  }
}

// положить в стек
void push(Node **stack, char d) {
  Node *p = calloc(1, sizeof(Node));
  p->data = d;
  p->next = *stack;
  *stack = p;
}

// взять из стека
char pop(Node **stack) {
  Node *p = *stack;
  char result = p->data;
  *stack = p->next;
  free(p);
  return result;
}

// приоритет операций
int priority(char sym) {
  int result = -1;
  if (sym == '+' || sym == '-')
    result = 1;
  else if (sym == '*' || sym == '/' || sym == 'M')
    result = 2;
  else if (sym == '^')
    result = 3;
  else if (sym == 's' || sym == 'c' || sym == 't' || sym == 'S' || sym == 'C' ||
           sym == 'T' || sym == 'q' || sym == 'L' || sym == 'l')
    result = 4;
  return result;
}

// упрощение названий функций
// sin = 's'; asin = 'S'; cos = 'c'; acos = 'C'; tan = 't'; atan = 'T';
// sqrt = 'q'; mod = 'M'; ln = 'l'; log = 'L'; (-) = '~'; (+) = ' ';
void simplification(char *str) {
  char result[1000] = {0};
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == 's') {
      if (str[i + 1] == 'i') {
        str[i] = 's';
        str[i + 1] = ' ';
        str[i + 2] = ' ';
      } else {
        str[i] = 'q';
        str[i + 1] = ' ';
        str[i + 2] = ' ';
        str[i + 3] = ' ';
      }
    } else if (str[i] == 'c') {
      str[i] = 'c';
      str[i + 1] = ' ';
      str[i + 2] = ' ';
    } else if (str[i] == 't') {
      str[i] = 't';
      str[i + 1] = ' ';
      str[i + 2] = ' ';
    } else if (str[i] == 'a') {
      if (str[i + 1] == 's') {
        str[i] = 'S';
        str[i + 1] = ' ';
        str[i + 2] = ' ';
        str[i + 3] = ' ';
      } else if (str[i + 1] == 'c') {
        str[i] = 'C';
        str[i + 1] = ' ';
        str[i + 2] = ' ';
        str[i + 3] = ' ';
      } else if (str[i + 1] == 't') {
        str[i] = 'T';
        str[i + 1] = ' ';
        str[i + 2] = ' ';
        str[i + 3] = ' ';
      }
    } else if (str[i] == 'l') {
      if (str[i + 1] == 'n') {
        str[i] = 'l';
        str[i + 1] = ' ';
      } else {
        str[i] = 'L';
        str[i + 1] = ' ';
        str[i + 2] = ' ';
      }
    } else if (str[i] == '-' && (str[i - 1] == '(' || i == 0)) {
      str[i] = '~';
    } else if (str[i] == '+' && (str[i - 1] == '(' || i == 0)) {
      str[i] = ' ';
    } else if (str[i] == 'm') {
      str[i] = 'M';
      str[i + 1] = ' ';
      str[i + 2] = ' ';
    }
  }
  get_rid_of_spaces(str, result);
  strcpy(str, result);
}

// убираем пробелы
void get_rid_of_spaces(char *str, char *result) {
  int i = 0, j = 0;
  while (str[i] != '\0') {
    if (str[i] != ' ') {
      result[j] = str[i];
      j++;
    }
    i++;
  }
  result[j] = '\0';
}

// проверка на цифру
int is_digit(char sym) {
  int result = 0;
  if ((sym >= '0' && sym <= '9') || sym == '.' || sym == 'x' || sym == '~')
    result = 1;
  return result;
}

//                  calculate

// логика рассчетов
double calculate(char *str, double x) {
  double result = 0.0;
  if (str != NULL) {
    struct Numbers *stack = NULL;
    for (int i = 0; str[i] != '\0'; i++) {
      double num1 = 0, num2 = 0;
      int flag = 0;
      while (!is_func_op(str[i])) {
        if (!flag) {
          if (str[i] != ' ') {
            num1 = get_variable(str, &i, x);
            flag = 1;
            push_numbers(&stack, num1);
          }
        } else {
          if (str[i] != ' ') {
            num2 = get_variable(str, &i, x);
            push_numbers(&stack, num2);
          }
        }
        if (str[i] == ' ') i++;
      }
      if (str[i] == '\0') break;
      if (strchr("M+-*/%^", str[i]) != NULL)
        arithmetic_simple(&stack, str[i]);
      else if (strchr("sctlqSCTML", str[i]) != NULL)
        arithmetic(&stack, str[i]);
    }
    result = pop_numbers(&stack);
  }
  return result;
}

//проверка на функцию/оператор
int is_func_op(char sym) {
  int result = 0;
  if (strchr("sctlqSCTML+-*/%^", sym) != NULL) {
    result = 1;
  }
  return result;
}

// преобразует строку в число
double get_variable(char *str, int *i, double x) {
  char num[100] = {0};
  double n = 0;
  int j = 0;
  int a = *i;
  double sign = 1;
  if (str[a] == '~') {
    sign = -1;
    a++;
  }
  if (str[a] == 'x') {
    n = x;
    a = a + 1;
  } else {
    while (str[a] != ' ') {
      num[j] = str[a];
      j++;
      a++;
    }
    n = atof(num) * sign;
  }
  *i = a;
  return n;
}

// положить в стек цифру
void push_numbers(Numbers **stack, double d) {
  Numbers *p = calloc(1, sizeof(Numbers));
  p->data = d;
  p->next = *stack;
  *stack = p;
}

// достать из стека цифру
double pop_numbers(Numbers **stack) {
  Numbers *p = *stack;
  double result = p->data;
  *stack = p->next;
  free(p);
  return result;
}

// простые арифметические действия
void arithmetic_simple(Numbers **stack, char sym) {
  double result = 0.0;
  double num1 = pop_numbers(stack), num2 = pop_numbers(stack);
  switch (sym) {
    case '+':
      result = num1 + num2;
      break;
    case '-':
      result = num2 - num1;
      break;
    case '*':
      result = num1 * num2;
      break;
    case '/':
      result = num2 / num1;
      break;
    case '%':
    case 'M':
      result = fmod(num2, num1);
      break;
    case '^':
      result = pow(num2, num1);
      break;
  }
  push_numbers(stack, result);
}

// арифметика с функциями
void arithmetic(Numbers **stack, char sym) {
  double result = 0.0;
  double num = pop_numbers(stack);

  if (sym == 'c') {
    result = cos(num);
  } else if (sym == 's') {
    result = sin(num);
  } else if (sym == 't') {
    result = tan(num);
  } else if (sym == 'C') {
    result = acos(num);
  } else if (sym == 'S') {
    result = asin(num);
  } else if (sym == 'T') {
    result = atan(num);
  } else if (sym == 'q') {
    if (num >= 0) {
      result = sqrt(num);
    } else {
      result = NAN;
    }
  } else if (sym == 'l') {
    result = log(num);
  } else if (sym == 'L') {
    result = log10(num);
  }

  push_numbers(stack, result);
}
