#pragma once

#include <QLabel>
#include <QPushButton>

class TaskModule : public QWidget
{
    Q_OBJECT

public:
    explicit TaskModule(QWidget *parent = nullptr);

    private slots:
        void onFloatingButtonClicked();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    QLabel *moduleLabel;
    QPushButton *floatingButton;
};
