#ifndef SPORT_H
#define SPORT_H

#include <QMainWindow>
#include <qglobal.h>
#include <iostream>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class sport; }
QT_END_NAMESPACE

class sport : public QMainWindow
{
    Q_OBJECT

public:
    sport(QWidget *parent = nullptr);
    ~sport();
    QString nomFICHIER;

private slots:

    void on_boutoncalculer_clicked();


    void on_pushButton_clicked();

    void on_nettoyer_clicked();

    void on_QUITTER_clicked();

    void on_RECOMMENCER_clicked();

private:
    Ui::sport *ui;
};
#endif // SPORT_H
