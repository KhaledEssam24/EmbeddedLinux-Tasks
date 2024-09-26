#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_FB_clicked();
    void on_YT_clicked();
    void on_LIN_clicked();
    void on_GPT_clicked();
    void on_Enter_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
