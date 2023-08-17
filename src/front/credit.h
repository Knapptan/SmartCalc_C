#ifndef CREDIT_H
#define CREDIT_H

#include <QButtonGroup>
#include <QDialog>
#include <QMessageBox>

extern "C" {
#include "../back/smart.h"
}

namespace Ui {
class Credit;
}

class Credit : public QDialog {
  Q_OBJECT

 public:
  explicit Credit(QWidget *parent = nullptr);
  ~Credit();

 private slots:
  void on_clear_Button_clicked();
  void on_calculate_Button_clicked();

 private:
  Ui::Credit *ui;
  QButtonGroup *termButtons;
  QButtonGroup *typeButtons;
};

#endif  // CREDIT_H
