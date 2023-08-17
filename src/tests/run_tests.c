#include <check.h>
#include <string.h>

#include "../back/smart.h"

START_TEST(test_plus) {
  char str[256] = "1.25+3.45";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(4.700000, res);
}
END_TEST

START_TEST(test_minus) {
  char str[256] = "1.25-3.45";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(-2.200000, res);
}
END_TEST

START_TEST(test_mult) {
  char str[256] = "1.25*3.45";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(4.312500, res);
}
END_TEST

START_TEST(test_mult2) {
  char str[256] = "3*(4+7)";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(33.000000, res);
}
END_TEST

START_TEST(test_div) {
  char str[256] = "1.25/3.45";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(0.362319, res);
}
END_TEST

START_TEST(test_mod) {
  char str[256] = "1.25mod3.45";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(1.250000, res);
}
END_TEST

START_TEST(test_pow) {
  char str[256] = "1.25^3.45";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(2.159432, res);
}
END_TEST

START_TEST(test_brackets) {
  char str[256] = "(5.23+1.25)*(0.25+0.001)";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(1.626480, res);
}
END_TEST

START_TEST(test_sin) {
  char str[256] = "sin((5.23+1.25)*(0.25+0.001))";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(0.998450, res);
}
END_TEST

START_TEST(test_cos) {
  char str[256] = "cos((5.23+1.25)*(0.25+0.001))";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(-0.055655, res);
}
END_TEST

START_TEST(test_tan) {
  char str[256] = "tan((5.23+1.25)*(0.25+0.001))";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(-17.940020, res);
}
END_TEST

START_TEST(test_asin) {
  char str[256] = "asin(7/7.7)";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(1.141097, res);
}
END_TEST

START_TEST(test_acos) {
  char str[256] = "acos(7/7.7)";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(0.429700, res);
}
END_TEST

START_TEST(test_atan) {
  char str[256] = "atan(7/7.7)";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(0.737815, res);
}
END_TEST

START_TEST(test_sqrt) {
  char str[256] = "sqrt(1357-245)";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(33.346664, res);
}
END_TEST

START_TEST(test_ln) {
  char str[256] = "ln(1357-245)";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(7.013915, res);
}
END_TEST

START_TEST(test_log) {
  char str[256] = "log(1357-245)";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(3.046105, res);
}
END_TEST

START_TEST(test_combo) {
  char str[256] = "log(32+1)*7/11*432*(sin(2)*12-45+4)/2";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(-6280.257182, res);
}
END_TEST

START_TEST(test_combo_func) {
  char str[256] = "cos(sin(tan(-0.005)))";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(0.999987, res);
}
END_TEST

START_TEST(test_hard_1) {
  char str[256] = "(5*3+cos(1))+tan(5)+log(10)+asin(0.5)";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(13.683386, res);
}
END_TEST

START_TEST(test_hard_2) {
  char str[256] = "1+2*3-4";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(3.000000, res);
}
END_TEST

START_TEST(test_hard_3) {
  char str[256] = "5*7-3*8";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(11.000000, res);
}
END_TEST

START_TEST(test_hard_4) {
  char str[256] = "2+3*sin(3)";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(2.423360, res);
}
END_TEST

START_TEST(test_hard_5) {
  char str[256] = "5*3+cos(1)+tan(3)+log(7)+asin(0.5)";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(16.766453, res);
}
END_TEST

START_TEST(test_hard_6) {
  char str[256] = "5*3+cos(1)+tan(3)";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(15.397756, res);
}
END_TEST

START_TEST(test_hard_7) {
  char str[256] = "3.98+5.2367364*2";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(14.453473, res);
}
END_TEST

START_TEST(test_hard_8) {
  char str[256] = "(3+5)*2";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(16.000000, res);
}
END_TEST

START_TEST(test_hard_9) {
  char str[256] = "(sin(1)+cos(1))*2*tan(1)+3";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(7.303969, res);
}
END_TEST

START_TEST(test_hard_10) {
  char str[256] = "cos(1)";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(0.540302, res);
}
END_TEST

START_TEST(test_hard_11) {
  char str[256] = "sin(1.78)+cos(1.7)*2*tan(1)+3";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(3.576870, res);
}
END_TEST

START_TEST(test_hard_12) {
  char str[256] = "1+2";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(3.000000, res);
}
END_TEST

START_TEST(test_hard_13) {
  char str[256] = "2^3^2";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(512.000000, res);
}
END_TEST

START_TEST(test_hard_14) {
  char str[256] = "10+(1+3)*(4-5)+5";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(11.000000, res);
}
END_TEST

START_TEST(test_hard_15) {
  char str[256] = "sin(log(5))/log(sin(0.5))";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(-2.015259, res);
}
END_TEST

START_TEST(test_hard_16) {
  char str[256] = "sin(log(5))/sin(0.2)";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(3.238696, res);
}
END_TEST

START_TEST(test_hard_17) {
  char str[256] = "2^10";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(1024.000000, res);
}
END_TEST

START_TEST(test_hard_18) {
  char str[256] = "1+2+x";
  double res = smart_calc(str, 5);
  ck_assert_int_eq(8.000000, res);
}
END_TEST

START_TEST(test_hard_19) {
  char str[256] = "sin(log(x*3+2))/log(sin(x*10-3))";
  double res = smart_calc(str, 5);
  ck_assert_int_eq(-1.038062, res);
}
END_TEST

START_TEST(test_hard_20) {
  char str[256] = "tan(x * 2) + (sin(x ^ 2) - ln(x))";
  double res = smart_calc(str, 5);
  ck_assert_int_eq(-1.093429, res);
}
END_TEST

START_TEST(test_hard_21) {
  char str[256] = "(-1 + 3)";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(2.000000, res);
}
END_TEST

START_TEST(test_hard_22) {
  char str[256] = "(+1) + 3";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(4.000000, res);
}
END_TEST

START_TEST(test_error_1) {
  char str[256] = "(+1) + 3.....";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(isnan(res), 1);
}
END_TEST

START_TEST(test_error_2) {
  char str[256] = "coss()";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(isnan(res), 1);
}
END_TEST

START_TEST(test_error_3) {
  char str[256] = "5**3";
  double res = smart_calc(str, 0);
  ck_assert_int_eq(isnan(res), 1);
}
END_TEST

START_TEST(checker_normal_behavior) {
  {
    int flag;

    char string[256] = "5+5-3";
    flag = check_str(string);

    ck_assert_int_eq(flag, 1);
  }
}
END_TEST

START_TEST(checker_check_alphabet_err) {
  {
    int flag;

    char string[256] = "§";
    flag = check_str(string);

    ck_assert_int_eq(flag, 0);
  }
}

START_TEST(checker_check_brace_err) {
  {
    int flag;

    char string[256] = "(.";
    flag = check_str(string);

    ck_assert_int_eq(flag, 0);
  }

  {
    int flag;

    char string[256] = ".)";
    flag = check_str(string);

    ck_assert_int_eq(flag, 0);
  }
}

START_TEST(checker_check_signs_err) {
  // Wrong signs
  {
    int flag;

    char string[256] = "+*";
    flag = check_str(string);

    ck_assert_int_eq(flag, 0);
  }
}

START_TEST(checker_check_func_err) {
  // Wrong func call
  {
    int flag;

    char string[256] = "foo()";
    flag = check_str(string);

    ck_assert_int_eq(flag, 0);
  }

  {
    int flag;

    char string[256] = "sssssss(x)";
    flag = check_str(string);

    ck_assert_int_eq(flag, 0);
  }

  // Good func call
  {
    int flag;

    char string[256] = "sin(x)";
    flag = check_str(string);

    ck_assert_int_eq(flag, 1);
  }
}

START_TEST(checker_check_digit_err) {
  // Wrong digits
  {
    int flag;

    char string[256] = "5x";
    flag = check_str(string);

    ck_assert_int_eq(flag, 0);
  }

  {
    int flag;

    char string[256] = "x5";
    flag = check_str(string);

    ck_assert_int_eq(flag, 0);
  }

  // Double two or more dots
  {
    int flag;

    char string[256] = "5..3";
    flag = check_str(string);

    ck_assert_int_eq(flag, 0);
  }

  {
    int flag;

    char string[256] = "5.3.4";
    flag = check_str(string);

    ck_assert_int_eq(flag, 0);
  }
}

START_TEST(checker_check_delete_spaces_normal) {
  // Delete spaces
  {
    char string[256] = "5 + 5 - 3";
    char output[256] = {};
    get_rid_of_spaces(string, output);

    ck_assert_str_eq(output, "5+5-3");
  }

  {
    char string[256] = "3+(-5)";
    simplification(string);

    ck_assert_str_eq(string, "3+(~5)");
  }
}

START_TEST(test_deposit_1) {
  double res = 0, UN = 0, NP = 0;
  deposit_calc(30000, 12, 10.17, 1, 2, 2, 0, 0, 0, 0, &res, &UN, &NP);
  ck_assert_int_eq(33009.2, res);
}
END_TEST

START_TEST(test_deposit_2) {
  double res = 0, UN = 0, NP = 0;
  deposit_calc(30000, 12, 10.17, 1, 2, 1, 0, 0, 0, 0, &res, &UN, &NP);
  ck_assert_int_eq(33151.48, res);
}
END_TEST

START_TEST(test_deposit_3) {
  double res = 0, UN = 0, NP = 0;
  deposit_calc(30000, 12, 10.17, 1, 1, 1, 0, 0, 0, 0, &res, &UN, &NP);
  ck_assert_int_eq(33009.2, res);
}
END_TEST

START_TEST(test_deposit_4) {
  double res = 0, UN = 0, NP = 0;
  deposit_calc(30000, 12, 10.17, 0, 1, 1, 0, 0, 0, 0, &res, &UN, &NP);
  ck_assert_int_eq(33009.2, res);
}
END_TEST

START_TEST(test_deposit_5) {
  double res = 0, UN = 0, NP = 0;
  deposit_calc(30000, 12, 10.17, 0, 1, 1, 1, 1000, 1, 500, &res, &UN, &NP);
  ck_assert_int_eq(39335.2, res);
}
END_TEST

START_TEST(test_deposit_6) {
  double res = 0, UN = 0, NP = 0;
  deposit_calc(850000, 12, 10.17, 0, 1, 1, 0, 0, 0, 0, &res, &UN, &NP);
  ck_assert_int_eq(935260.8, res);
}
END_TEST

START_TEST(test_deposit_7) {
  double res = 0, UN = 0, NP = 0;
  deposit_calc(30000, 12, 10.17, 1, 2, 2, 1, 1000, 0, 0, &res, &UN, &NP);
  ck_assert_int_eq(45661.20, res);
}
END_TEST

START_TEST(test_deposit_8) {
  double res = 0, UN = 0, NP = 0;
  deposit_calc(30000, 12, 10.17, 1, 2, 2, 0, 0, 1, 500, &res, &UN, &NP);
  ck_assert_int_eq(26683.20, res);
}
END_TEST

START_TEST(test_deposit_9) {
  double res = 0, UN = 0, NP = 0;
  deposit_calc(30000, 12, 10.17, 1, 2, 2, 1, 1000, 1, 500, &res, &UN, &NP);
  ck_assert_int_eq(39335.20, res);
}
END_TEST

START_TEST(test_deposit_10) {
  double res = 0, UN = 0, NP = 0;
  deposit_calc(30000, 12, 10.17, 1, 2, 1, 1, 1000, 0, 0, &res, &UN, &NP);
  ck_assert_int_eq(45823.9, res);
}
END_TEST

START_TEST(test_deposit_11) {
  double res = 0, UN = 0, NP = 0;
  deposit_calc(30000, 12, 10.17, 1, 2, 1, 1, 1000, 1, 500, &res, &UN, &NP);
  ck_assert_int_eq(39487.7, res);
}
END_TEST

START_TEST(test_deposit_12) {
  double res = 0, UN = 0, NP = 0;
  deposit_calc(30000, 12, 10.17, 1, 2, 1, 0, 0, 1, 500, &res, &UN, &NP);
  ck_assert_int_eq(26815, res);
}
END_TEST

START_TEST(test_deposit_13) {
  double res = 0, UN = 0, NP = 0;
  deposit_calc(30000, 12, 10.17, 1, 1, 1, 1, 1000, 0, 0, &res, &UN, &NP);
  ck_assert_int_eq(45661.2, res);
}
END_TEST

START_TEST(test_deposit_14) {
  double res = 0, UN = 0, NP = 0;
  deposit_calc(30000, 12, 10.17, 1, 1, 1, 0, 0, 1, 500, &res, &UN, &NP);
  ck_assert_int_eq(26683.2, res);
}
END_TEST

START_TEST(test_credit_1) {
  double x = 0, y = 0, total = 0;
  calculate_credit(300000, 5, 10, 0, &x, &y, &total);
  ck_assert_int_eq(306917.90, total);
}
END_TEST

START_TEST(test_credit_2) {
  double x = 0, y = 0, total = 0;
  calculate_credit(300000, 5, 10, 1, &x, &y, &total);
  ck_assert_int_eq(306838.36, total);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, test_plus);
  tcase_add_test(tc1_1, test_minus);
  tcase_add_test(tc1_1, test_mult);
  tcase_add_test(tc1_1, test_mult2);
  tcase_add_test(tc1_1, test_div);
  tcase_add_test(tc1_1, test_mod);
  tcase_add_test(tc1_1, test_pow);
  tcase_add_test(tc1_1, test_brackets);
  tcase_add_test(tc1_1, test_sin);
  tcase_add_test(tc1_1, test_cos);
  tcase_add_test(tc1_1, test_tan);
  tcase_add_test(tc1_1, test_asin);
  tcase_add_test(tc1_1, test_acos);
  tcase_add_test(tc1_1, test_atan);
  tcase_add_test(tc1_1, test_sqrt);
  tcase_add_test(tc1_1, test_ln);
  tcase_add_test(tc1_1, test_log);
  tcase_add_test(tc1_1, test_combo);
  tcase_add_test(tc1_1, test_combo_func);
  tcase_add_test(tc1_1, test_hard_1);
  tcase_add_test(tc1_1, test_hard_2);
  tcase_add_test(tc1_1, test_hard_3);
  tcase_add_test(tc1_1, test_hard_4);
  tcase_add_test(tc1_1, test_hard_5);
  tcase_add_test(tc1_1, test_hard_6);
  tcase_add_test(tc1_1, test_hard_7);
  tcase_add_test(tc1_1, test_hard_8);
  tcase_add_test(tc1_1, test_hard_9);
  tcase_add_test(tc1_1, test_hard_10);
  tcase_add_test(tc1_1, test_hard_11);
  tcase_add_test(tc1_1, test_hard_12);
  tcase_add_test(tc1_1, test_hard_13);
  tcase_add_test(tc1_1, test_hard_14);
  tcase_add_test(tc1_1, test_hard_15);
  tcase_add_test(tc1_1, test_hard_16);
  tcase_add_test(tc1_1, test_hard_17);
  tcase_add_test(tc1_1, test_hard_18);
  tcase_add_test(tc1_1, test_hard_19);
  tcase_add_test(tc1_1, test_hard_20);
  tcase_add_test(tc1_1, test_hard_21);
  tcase_add_test(tc1_1, test_hard_22);
  tcase_add_test(tc1_1, test_error_1);
  tcase_add_test(tc1_1, test_error_2);
  tcase_add_test(tc1_1, test_error_3);
  tcase_add_test(tc1_1, checker_normal_behavior);
  tcase_add_test(tc1_1, checker_check_alphabet_err);
  tcase_add_test(tc1_1, checker_check_brace_err);
  tcase_add_test(tc1_1, checker_check_signs_err);
  tcase_add_test(tc1_1, checker_check_func_err);
  tcase_add_test(tc1_1, checker_check_digit_err);
  tcase_add_test(tc1_1, checker_check_delete_spaces_normal);
  tcase_add_test(tc1_1, test_deposit_1);
  tcase_add_test(tc1_1, test_deposit_2);
  tcase_add_test(tc1_1, test_deposit_3);
  tcase_add_test(tc1_1, test_deposit_4);
  tcase_add_test(tc1_1, test_deposit_5);
  tcase_add_test(tc1_1, test_deposit_6);
  tcase_add_test(tc1_1, test_deposit_7);
  tcase_add_test(tc1_1, test_deposit_8);
  tcase_add_test(tc1_1, test_deposit_9);
  tcase_add_test(tc1_1, test_deposit_10);
  tcase_add_test(tc1_1, test_deposit_11);
  tcase_add_test(tc1_1, test_deposit_12);
  tcase_add_test(tc1_1, test_deposit_13);
  tcase_add_test(tc1_1, test_deposit_14);
  tcase_add_test(tc1_1, test_credit_1);
  tcase_add_test(tc1_1, test_credit_2);

  srunner_run_all(sr, CK_ENV);
  srunner_ntests_failed(sr);
  srunner_free(sr);

  return (0);
}