#include "ListItemWidget.hpp"
#include "CustomDelegate.hpp"
#include "MainWindow.hpp"

#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QListWidget>
#include <QMessageBox>
#include <QCloseEvent>

#include "MenuBar.hpp"
#include "StackedModuleWidget.hpp"

void MainWindow::populateLeftPanel() {
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
    listWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(listWidget, &QListWidget::itemClicked, this, &MainWindow::onItemClicked);
    leftLayout->addWidget(listWidget);
}

void MainWindow::addWidgetsToMainLayout(QHBoxLayout *mainLayout) {
    mainLayout->addWidget(leftPanel);
    mainLayout->addWidget(toggleButton);

    stackedModuleWidget = new StackedModuleWidget(this);
    mainLayout->addWidget(stackedModuleWidget);
}

void MainWindow::setupToggleLeftPanelButton() {
    toggleButton = new QPushButton("<", this);
    toggleButton->setMaximumWidth(20);
    toggleButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    connect(toggleButton, &QPushButton::clicked, this, &MainWindow::toggleLeftPanel);
}

void MainWindow::setCustomMenuBar() {
    menuBar = new MenuBar(this);
    setMenuBar(menuBar);
    connect(menuBar->getQuitAction(), &QAction::triggered, this, &MainWindow::handleCloseAction);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    initialize();

    auto *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    populateLeftPanel();

    setupToggleLeftPanelButton();

    auto *mainLayout = new QHBoxLayout(centralWidget);
    addWidgetsToMainLayout(mainLayout);

    setCustomMenuBar();
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
