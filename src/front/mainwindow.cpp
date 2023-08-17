#include "mainwindow.h"

#include <QtDebug>
#include <QtWidgets>

#include "credit.h"
#include "graph.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  //    QIcon icon_graph(":/resources/icons/graph.png");
  //    ui->graph_Button->setIcon(icon_graph);
  //    ui->graph_Button->setChecked(false);
  connect(ui->zero_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->one_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->two_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->tree_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->four_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->five_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->six_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->seven_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->eight_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->nine_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->plus_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->minus_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->mult_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->divide_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->dot_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->open_br_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->close_br_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->x_Button, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->mod_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->exp_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->sin_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->asin_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->cos_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->acos_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->tan_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->atan_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->ln_Button, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->log_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->sqrt_Button, SIGNAL(clicked()), this,
          SLOT(input_button_clicked()));
  connect(ui->clear_Button, SIGNAL(clicked()), this, SLOT(clear_clicked()));
  connect(ui->key_input, SIGNAL(returnPressed()), this,
          SLOT(on_equal_Button_clicked()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::input_button_clicked() {
  QPushButton *button = (QPushButton *)sender();
  QByteArray btn_text = button->text().toLocal8Bit();
  const char *c_str = btn_text.data();

  if (strpbrk(c_str, "0123456789x+-()^.*")) {
    ui->key_input->setText(ui->key_input->text() + button->text());
  } else if (strpbrk(c_str, "√")) {
    ui->key_input->setText(ui->key_input->text() + "sqrt(");
  } else if (strpbrk(c_str, "÷")) {
    ui->key_input->setText(ui->key_input->text() + "/");
  } else if (strpbrk(c_str, "%")) {
    ui->key_input->setText(ui->key_input->text() + " mod ");
  } else {
    ui->key_input->setText(ui->key_input->text() + button->text() + "(");
  }
}

void MainWindow::clear_clicked() {
  ui->key_input->setText("");
  ui->result->setText("");
  ui->x_input->setText("0");
}

void MainWindow::on_graph_Button_clicked() {
  QString tmp_str = ui->key_input->text();
  connect(this, &MainWindow ::signal_to_past_str, &graph, &Graph::past_str);
  emit signal_to_past_str(tmp_str);
  graph.show();
}

void MainWindow::on_credit_Button_clicked() { credit.show(); }

void MainWindow::on_equal_Button_clicked() {
  text = ui->key_input->text().toLocal8Bit();
  bool is_number = true;
  char *c_str = text.data();
  double result = 0;
  QString tmp_x = ui->x_input->text();
  double x = 0.0;
  x = tmp_x.toDouble(&is_number);
  if (is_number) {
    result = smart_calc(c_str, x);
    if (isnan(result)) {
      QMessageBox::critical(this, "Error", "Enter valid function");
      ui->result->setText("");
    } else {
      QString resString = QString::number(result, 'f', 7);
      ui->result->setText(resString);
    }
  } else {
    QMessageBox::critical(this, "Error", "Enter valid X");
    ui->result->setText("");
  }
}

void MainWindow::on_deposit_Button_clicked() { deposit_window.show(); }
