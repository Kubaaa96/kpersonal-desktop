#pragma once


#include <QLabel>

class ListItemWidget : public QWidget {
    Q_OBJECT

public:
    explicit ListItemWidget(const QString &text, QWidget *parent = nullptr);

private:
    QLabel *label;
    QLabel *label1;
};
