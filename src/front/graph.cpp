#include "graph.h"

#include "ui_graph.h"

Graph::Graph(QWidget *parent) : QWidget(parent), ui(new Ui::Graph) {
  ui->setupUi(this);
  ui->widget->setInteraction(QCP::iRangeZoom, true);
  ui->widget->setInteraction(QCP::iRangeDrag, true);
  ui->widget->replot();
  connect(ui->label_funk, SIGNAL(returnPressed()), this,
          SLOT(on_plot_Button_clicked()));
}

Graph::~Graph() { delete ui; }

void Graph::past_str(QString string_tmp) {
  ui->label_funk->setText(string_tmp);
}

void Graph::on_plot_Button_clicked() {
  double X = 0;
  double result = 0;
  QByteArray funk_str = ui->label_funk->text().toLocal8Bit();

  x.clear();
  y.clear();

  bool val1, val2, val3, val4;
  double x_min = ui->min_edit_x->text().toDouble(&val1);
  double x_max = ui->max_edit_x->text().toDouble(&val2);
  double y_min = ui->min_edit_y->text().toDouble(&val3);
  double y_max = ui->max_edit_y->text().toDouble(&val4);

  if (x_min >= x_max || y_min >= y_max || (val1 + val2 + val3 + val4) != 4 ||
      x_min < -1000000 || x_max > 1000000 || y_min < -1000000 ||
      y_max > 1000000) {
    ui->widget->clearGraphs();
    QMessageBox::critical(this, "Error", "Enter valid values");
    return;
  } else {
    if (check_str(funk_str.data())) {
      if (funk_str.contains('x')) {
        for (double x_value = x_min; x_value < x_max; x_value += 0.1) {
          result = smart_calc(funk_str.data(), x_value);
          x.push_back(x_value);
          y.push_back(result);
        }
      } else {
        for (double x_value = x_min; x_value < x_max; x_value += 0.01) {
          result = smart_calc(funk_str.data(), X);
          x.push_back(x_value);
          y.push_back(result);
        }
      }
      ui->widget->clearGraphs();
      ui->widget->xAxis->setRange(x_min, x_max);
      ui->widget->yAxis->setRange(y_min, y_max);
      ui->widget->addGraph();
      ui->widget->graph(0)->addData(x, y);
      ui->widget->replot();
    } else if (!check_str(funk_str.data())) {
      QMessageBox::critical(this, "Error", "Enter valid function");
    }
  }
}

void Graph::on_stock_Button_clicked() {
  ui->min_edit_x->setText("-10");
  ui->max_edit_x->setText("10");
  ui->min_edit_y->setText("-5");
  ui->max_edit_y->setText("5");
}

void Graph::on_clear_Button_clicked() {
  x.clear();
  y.clear();
  ui->label_funk->setText("");
  ui->widget->clearGraphs();
  ui->widget->xAxis->setRange(-10, 10);
  ui->widget->yAxis->setRange(-5, 5);
  ui->widget->addGraph();
  ui->widget->graph(0)->addData(x, y);
  ui->widget->replot();
}
