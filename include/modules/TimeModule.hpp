#pragma once

#include <QWidget>

class QLabel;

class TimeModule : public QWidget
{
    Q_OBJECT

public:
    explicit TimeModule(QWidget *parent = nullptr);

private:
    QLabel *moduleLabel;
};
