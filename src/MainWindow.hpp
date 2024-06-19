#pragma once

#include <QMainWindow>
#include <QStackedWidget>
#include <QListWidget>
#include <QPushButton>
#include <QMenuBar>


class MainWindow final : public QMainWindow {
    Q_OBJECT

public:


    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    private slots:
        void toggleLeftPanel();
    void onItemClicked(QListWidgetItem *item);

private:
    QWidget *leftPanel;
    QListWidget *listWidget;
    QWidget *rightPanel;
    QStackedWidget *stackedWidget;
    QPushButton *toggleButton;

    void initialize();
};
