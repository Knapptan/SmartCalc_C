#ifndef GRAPH_H
#define GRAPH_H

#include <QObject>
#include <QVector>
#include <QWidget>
extern "C" {
#include "../back/smart.h"
}

namespace Ui {
class Graph;
}

class Graph : public QWidget {
  Q_OBJECT

 public:
  explicit Graph(QWidget *parent = nullptr);
  ~Graph();
  QString string;
  QVector<double> x, y;

 private slots:
  void on_plot_Button_clicked();

  void on_stock_Button_clicked();

  void on_clear_Button_clicked();

 private:
  Ui::Graph *ui;
  double xBegin, xEnd, h, X;
  int N;

 public slots:
  void past_str(QString string_tmp);
};

#endif  // GRAPH_H
