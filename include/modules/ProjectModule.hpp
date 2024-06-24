#pragma once

#include <QWidget>

class QLabel;

class ProjectModule : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectModule(QWidget *parent = nullptr);


private:
    QLabel *moduleLabel;
};
