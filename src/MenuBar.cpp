#include "MenuBar.hpp"

MenuBar::MenuBar(QWidget *parent) {
    fileMenu = new QMenu("&File", this);
    newAction = new QAction("&New...", this);
    openAction = new QAction("&Open...", this);
    saveAction = new QAction("&Save", this);
    saveAsAction = new QAction("Save &As...", this);
    quitAction = new QAction("&Quit", this);
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAction);

    actionsMenu = new QMenu("&Actions", this);
    exportAction = new QAction("&Export", this);
    statisticsAction = new QAction("&Statistics", this);
    optionsAction = new QAction("&Options", this);
    actionsMenu->addAction(exportAction);
    actionsMenu->addAction(statisticsAction);
    actionsMenu->addAction(optionsAction);

    helpMenu = new QMenu("&Help", this);
    aboutAction = new QAction("&About", this);
    helpMenu->addAction(aboutAction);
    addMenu(fileMenu);
    addMenu(actionsMenu);
    addMenu(helpMenu);

}

QAction * MenuBar::getQuitAction() const {
    return quitAction;
}
