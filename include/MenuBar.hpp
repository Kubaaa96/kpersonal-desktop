#pragma once

#include <QMenuBar>

class MenuBar : public QMenuBar
{
    Q_OBJECT

public:
    explicit MenuBar(QWidget* parent = nullptr);

    [[nodiscard]] QAction* getQuitAction() const;

private:
    QMenu *fileMenu;
    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *quitAction;

    QMenu *actionsMenu;
    QAction *exportAction;
    QAction *statisticsAction;
    QAction *optionsAction;

    QMenu *helpMenu;
    QAction *aboutAction;
};