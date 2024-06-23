#pragma once

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class ListItemWidget : public QWidget {
    Q_OBJECT

public:
    explicit ListItemWidget(const QString &text, QWidget *parent = nullptr);

private:
    QLabel *label;
    QLabel *label1;
};
