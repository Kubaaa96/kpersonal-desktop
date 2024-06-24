#pragma once

#include <QWidget>

class QLabel;

class CalendarModule : public QWidget
{
    Q_OBJECT

public:
    explicit CalendarModule(QWidget *parent = nullptr);

private:
    QLabel *moduleLabel;
};
