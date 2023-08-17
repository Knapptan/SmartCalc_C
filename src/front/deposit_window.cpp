#include "deposit_window.h"

#include "ui_deposit_window.h"

Deposit_window::Deposit_window(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Deposit_window) {
  ui->setupUi(this);
}

Deposit_window::~Deposit_window() { delete ui; }

void Deposit_window::on_pushButton_res_clicked() {
  bool check_summ = 0, check_interest = 0, check_n = 0, check_add = 0,
       check_sub = 0, check_tax = 0;
  double result = 0, tax_with = 0, accrued_interest = 0;
  double summ = ui->line_summ->text().toDouble(&check_summ);
  double interest_rate =
      ui->line_interest_rate->text().toDouble(&check_interest);
  double n = ui->line_n->text().toDouble(&check_n);
  double add = ui->line_add->text().toDouble(&check_add);
  double sub = ui->line_sub->text().toDouble(&check_sub);
  double tax_rate = ui->line_tax->text().toDouble(&check_tax);
  int periodicity_payments = 0, capitalization = 0, count_add = 0,
      count_sub = 0;
  if ((check_summ + check_interest + check_n + check_add + check_sub +
       check_tax) != 6 ||
      tax_rate > 100 || tax_rate < 0 || interest_rate > 100 ||
      interest_rate < 0 || summ < 0 || n < 0 || add < 0 || sub < 0) {
    QMessageBox::critical(this, "Error", "Enter valid values");
  } else {
    if (ui->radioButton_periodicity_payments_on->isChecked()) {
      periodicity_payments = 1;
    } else {
      periodicity_payments = 2;
    }
    if (ui->checkBox_capitalization->isChecked()) {
      capitalization = 1;
    } else {
      capitalization = 2;
    }
    if (ui->checkBox_add->isChecked()) {
      count_add = 1;
    } else {
      count_add = 0;
    }
    if (ui->checkBox_sub->isChecked()) {
      count_sub = 1;
    } else {
      count_sub = 0;
    }
    deposit_calc(summ, n, interest_rate, tax_rate, periodicity_payments,
                 capitalization, count_add, add, count_sub, sub, &result,
                 &tax_with, &accrued_interest);

    ui->label_res->setText(QString::number(result, 'f', 7));
    ui->label_tax->setText(QString::number(tax_with, 'f', 7));
    ui->label_accrued_interest->setText(
        QString::number(accrued_interest, 'f', 7));
  }
}

void Deposit_window::on_clear_Button_clicked() {
  ui->label_res->setText("0");
  ui->label_tax->setText("0");
  ui->label_accrued_interest->setText("0");
  ui->line_summ->setText("0");
  ui->line_add->setText("0");
  ui->line_sub->setText("0");
  ui->line_n->setText("0");
  ui->line_interest_rate->setText("0");
  ui->line_tax->setText("0");
  ui->checkBox_add->setChecked(false);
  ui->checkBox_sub->setChecked(false);
  ui->checkBox_capitalization->setChecked(false);
  ui->radioButton_periodicity_payments->setChecked(true);
}
