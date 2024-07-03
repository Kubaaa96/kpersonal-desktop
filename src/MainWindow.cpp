#include "ListItemWidget.hpp"
#include "CustomDelegate.hpp"
#include "MainWindow.hpp"

#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QListWidget>
#include <QMessageBox>
#include <QCloseEvent>

#include "StackedModuleWidget.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    initialize();

    // Central Widget
    auto *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Main Layout
    auto *mainLayout = new QHBoxLayout(centralWidget);

    // Left Panel
    leftPanel = new QWidget(this);
    leftPanel->setFixedWidth(200);
    auto *leftLayout = new QVBoxLayout(leftPanel);

    listWidget = new QListWidget(leftPanel);
    listWidget->setItemDelegate(new CustomDelegate(this));
    listWidget->setFrameShape(QFrame::NoFrame);

    QStringList items = {"Task", "Time", "Flashcards", "Habit", "Wiki", "Project", "Calendar", "Kanban"};
    for (const QString &item : items) {
        auto *listItem = new QListWidgetItem(listWidget);
        auto *itemWidget = new ListItemWidget("Name: " + item, listWidget);
        listItem->setSizeHint(itemWidget->sizeHint());
        listWidget->setItemWidget(listItem, itemWidget);
    }

    connect(listWidget, &QListWidget::itemClicked, this, &MainWindow::onItemClicked);
    leftLayout->addWidget(listWidget);

    // Toggle Button
    toggleButton = new QPushButton("<", this);
    toggleButton->setMaximumWidth(20);
    toggleButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    connect(toggleButton, &QPushButton::clicked, this, &MainWindow::toggleLeftPanel);

    // Add widgets to main layout
    mainLayout->addWidget(leftPanel);
    mainLayout->addWidget(toggleButton);

    stackedModuleWidget = new StackedModuleWidget(this);
    mainLayout->addWidget(stackedModuleWidget);

    // Menu Bar
    QMenuBar *menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    auto *fileMenu = new QMenu("&File", this);
    auto *newAction = new QAction("&New...", this);
    auto *openAction = new QAction("&Open...", this);
    auto *saveAction = new QAction("&Save", this);
    auto *saveAsAction = new QAction("Save &As...", this);
    auto *quitAction = new QAction("&Quit", this);
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAction);

    auto *actionsMenu = new QMenu("&Actions", this);
    auto *exportAction = new QAction("&Export", this);
    auto *statisticsAction = new QAction("&Statistics", this);
    auto *optionsAction = new QAction("&Options", this);
    actionsMenu->addAction(exportAction);
    actionsMenu->addAction(statisticsAction);
    actionsMenu->addAction(optionsAction);

    auto *helpMenu = new QMenu("&Help", this);
    auto *aboutAction = new QAction("&About", this);
    helpMenu->addAction(aboutAction);

    menuBar->addMenu(fileMenu);
    menuBar->addMenu(actionsMenu);
    menuBar->addMenu(helpMenu);

    connect(quitAction, &QAction::triggered, this, &MainWindow::handleCloseAction);


}

MainWindow::~MainWindow() {
}

void MainWindow::toggleLeftPanel() {
    if (leftPanel->isVisible()) {
        leftPanel->hide();
        toggleButton->setText(">");
    } else {
        leftPanel->show();
        toggleButton->setText("<");
    }
}

void MainWindow::debug() {
    qDebug("test");
}

void MainWindow::handleCloseAction() {
    close();
}

void MainWindow::onItemClicked(QListWidgetItem *item) {
    int index = listWidget->row(item);
    if (index >= 0 && index < stackedModuleWidget->count()) {
        stackedModuleWidget->setCurrentIndex(index);
    }
}

void MainWindow::closeEvent(QCloseEvent *event) {
    auto resultButton = QMessageBox::question(
    this, "Exit Confirmation",
    "Are you sure you want to exit?\n",
    QMessageBox::No | QMessageBox::Yes,
    QMessageBox::Yes);
    resultButton == QMessageBox::Yes ? event->accept() : event->ignore();
}

void MainWindow::initialize() {
    resize(960, 540);

    constexpr QSize resNHD{640,360};
    setMinimumSize(resNHD);

    constexpr QSize res4K{3840, 2160};
    setMaximumSize(res4K);
}
