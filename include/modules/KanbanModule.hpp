#pragma once

#include <QWidget>

class QLabel;

class KanbanModule : public QWidget
{
    Q_OBJECT

public:
    explicit KanbanModule(QWidget *parent = nullptr);

private:
    QLabel *moduleLabel;

};
