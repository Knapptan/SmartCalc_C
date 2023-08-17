#include "credit.h"

#include "ui_credit.h"

Credit::Credit(QWidget *parent) : QDialog(parent), ui(new Ui::Credit) {
  ui->setupUi(this);

  termButtons = new QButtonGroup(this);
  termButtons->addButton(ui->Button_Months);
  termButtons->addButton(ui->Button_Years);

  typeButtons = new QButtonGroup(this);
  typeButtons->addButton(ui->radio_annuity);
  typeButtons->addButton(ui->radio_differentiated);

  ui->radio_annuity->setChecked(true);
  ui->Button_Months->setChecked(true);
}

Credit::~Credit() { delete ui; }

void Credit::on_clear_Button_clicked() {
  ui->label_overpayment->setText("0.0");
  ui->label_payment_per_mounth->setText("0.0");
  ui->label_total_payout->setText("0.0");
  ui->lineEdit_credit_term->setText("0");
  ui->lineEdit_interest_rate->setText("0");
  ui->lineEdit_loan_amount->setText("0");
  ui->radio_annuity->setChecked(true);
  ui->Button_Months->setChecked(true);
}

void Credit::on_calculate_Button_clicked() {
  int flag_diff = 0;
  if (ui->radio_differentiated->isChecked()) {
    flag_diff = 1;
  }
  bool val1, val2, val3;
  double amount = ui->lineEdit_loan_amount->text().toDouble(&val1);
  double term = ui->lineEdit_credit_term->text().toDouble(&val2);
  double interest = ui->lineEdit_interest_rate->text().toDouble(&val3);
  int valid = val1 + val2 + val3;
  if (amount > 0 && term > 0 && interest > 0) {
    valid++;
  }
  if (valid != 4) {
    QMessageBox::critical(this, "Error", "Enter valid values");
  } else {
    if (ui->Button_Years->isChecked()) {
      term *= 12;
    }

    double monthly = 0;
    double overpayment = 0;
    double total = 0;
    int error = 0;
    error = calculate_credit(amount, interest, term, flag_diff, &monthly,
                             &overpayment, &total);
    if (error) {
      QMessageBox::critical(this, "Error", "Enter valid values");
    }
    QString strMonthly = "";
    if (flag_diff) strMonthly += "≈";
    strMonthly += QString::number(monthly, 'f', 2);

    ui->label_payment_per_mounth->setText(strMonthly);
    QString strOver = QString::number(overpayment, 'f', 2);
    ui->label_overpayment->setText(strOver);
    QString strTotal = QString::number(total, 'f', 2);
    ui->label_total_payout->setText(strTotal);
  }
}
