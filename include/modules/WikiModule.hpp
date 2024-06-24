#pragma once

#include <QWidget>

class QLabel;

class WikiModule : public QWidget
{
    Q_OBJECT

public:
    explicit WikiModule(QWidget *parent = nullptr);

private:
    QLabel *moduleLabel;
};
