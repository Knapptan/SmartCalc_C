#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QButtonGroup>
#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>

extern "C" {
#include "../back/smart.h"
}

namespace Ui {
class Deposit_window;
}

class Deposit_window : public QMainWindow {
  Q_OBJECT

 public:
  explicit Deposit_window(QWidget *parent = nullptr);
  ~Deposit_window();

 private slots:
  void on_pushButton_res_clicked();
  void on_clear_Button_clicked();

 private:
  Ui::Deposit_window *ui;
};

#endif  // DEPOSIT_H
