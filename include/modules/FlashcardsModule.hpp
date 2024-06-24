#pragma once

#include <QWidget>

class QLabel;

class FlashcardsModule : public QWidget
{
    Q_OBJECT

public:
    explicit FlashcardsModule(QWidget *parent = nullptr);

private:
    QLabel *moduleLabel;
};
