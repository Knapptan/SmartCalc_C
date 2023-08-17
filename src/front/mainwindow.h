#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include "credit.h"
#include "deposit_window.h"
#include "graph.h"

extern "C" {
#include "../back/smart.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  QByteArray text;
  QString tmp_str;
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void input_button_clicked();
  void clear_clicked();
  void on_graph_Button_clicked();
  void on_equal_Button_clicked();
  void on_credit_Button_clicked();

  void on_deposit_Button_clicked();

 signals:
  void signal_to_past_str(QString string_tmp);

 private:
  Ui::MainWindow *ui;
  Graph graph;
  Credit credit;
  Deposit_window deposit_window;
};
#endif  // MAINWINDOW_H
