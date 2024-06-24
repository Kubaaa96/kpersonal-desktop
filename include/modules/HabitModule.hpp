#pragma once

#include <QWidget>

class QLabel;

class HabitModule : public QWidget
{
    Q_OBJECT

public:
    explicit HabitModule(QWidget *parent = nullptr);

private:
    QLabel *moduleLabel;
};
