#ifndef STATS_H
#define STATS_H

#include <QDialog>
#include <vector>


class QLabel;
class QPushButton;
class QProgressBar;
class QGroupBox;
class QSpacerItem;


class Stats : public QDialog
{
    Q_OBJECT
private:
    void setItems();
    void setConnect();
    void layItems();

    //Buttons
    QPushButton* btHome;
    QPushButton* btExit;

    //Int for the number of answers
    int maxAns;

    //Vectors for progress bars
    std::vector<QProgressBar*> pbars_Q1;
    std::vector<QProgressBar*> pbars_Q2;
    std::vector<QProgressBar*> pbars_Q3;
    std::vector<QProgressBar*> pbars_Q4;
    std::vector<QProgressBar*> pbars_Q5;


    //Groupboxes
    QGroupBox* mkGrp_Q1();
    QGroupBox* mkGrp_Q2();
    QGroupBox* mkGrp_Q3();
    QGroupBox* mkGrp_Q4();
    QGroupBox* mkGrp_Q5();

    //Spacers
    QSpacerItem* spBtns;

public:
    Stats(QWidget* parent=0);

public slots:
    void updateMax();
    void goExit();
    void goHome();

signals:
    void toExit();
    void toHome();

};

#endif // STATS_H
