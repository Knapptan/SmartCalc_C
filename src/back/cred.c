#include "smart.h"

// credit_sum - сумма займа
// interest_rate - процентная ставка
// credit_time - срок кредита мес
// flagDiff - тип рассчета
// monthly - ежемесячный платеж
// overpayment - переплата
// total - итоговая сумма с переплатой

// аннуитетный тип рассчета
double annuity_calc(double credit_sum, double interest_rate,
                    double credit_time) {
  double res = 0;
  double rate = interest_rate / 1200.0;
  res = credit_sum * rate / (1 - pow(1 + rate, 0 - credit_time));
  res = round(res * 100) / 100;
  return res;
}

// дифференцированный тип рассчета
double diff_calc(double credit_sum, double interest_rate, double credit_time,
                 double *total) {
  double res = 0;
  double start_credit_sum = credit_sum;
  double sd = credit_sum / credit_time;
  int i = 0;
  double first = 0, last = 0;
  double days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  while (start_credit_sum > 0.001) {
    last = sd + (start_credit_sum * (interest_rate / 100.0) * days[i]) / 365.0;
    last = round(last * 100) / 100;
    if (!i) first = last;
    if (i == 11)
      i = 0;
    else
      i++;
    start_credit_sum -= sd;
    *total += last;
  }
  res = (first + last) / 2;
  return res;
}

// логика исполнения
int calculate_credit(double credit_sum, double interest_rate,
                     double credit_time, int flagDiff, double *monthly,
                     double *overpayment, double *total) {
  int error = 0;
  if (!flagDiff) {
    *monthly = annuity_calc(credit_sum, interest_rate, credit_time);
    *total = *monthly * credit_time;
  } else {
    *monthly = diff_calc(credit_sum, interest_rate, credit_time, total);
  }
  *overpayment = *total - credit_sum;

  return error;
}
