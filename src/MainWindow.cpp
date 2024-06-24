#include "ListItemWidget.hpp"
#include "CustomDelegate.hpp"
#include "MainWindow.hpp"
#include "modules/CalendarModule.hpp"
#include "modules/FlashcardsModule.hpp"
#include "modules/HabitModule.hpp"
#include "modules/KanbanModule.hpp"
#include "modules/ProjectModule.hpp"
#include "modules/TaskModule.hpp"
#include "modules/TimeModule.hpp"
#include "modules/WikiModule.hpp"



#include <QPushButton>
#include <QHBoxLayout>
#include <QListWidget>
#include <QDialog>

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

    // Right Panel (Stacked Widget)
    stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(new TaskModule(this));
    stackedWidget->addWidget(new TimeModule( this));
    stackedWidget->addWidget(new FlashcardsModule(this));
    stackedWidget->addWidget(new HabitModule(this));
    stackedWidget->addWidget(new WikiModule(this));
    stackedWidget->addWidget(new ProjectModule(this));
    stackedWidget->addWidget(new CalendarModule(this));
    stackedWidget->addWidget(new KanbanModule(this));

    // Add widgets to main layout
    mainLayout->addWidget(leftPanel);
    mainLayout->addWidget(toggleButton);
    mainLayout->addWidget(stackedWidget);

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

    // // Quit Dialog
    auto *quitDialog = new QDialog(this);
    quitDialog->setWindowTitle("Quit");
    quitDialog->setModal(true);
    quitDialog->setLayout(new QVBoxLayout);
    auto *quitLabel = new QLabel("This is a dialog box!", quitDialog);
    quitDialog->layout()->addWidget(quitLabel);
    auto *okButton = new QPushButton("Ok", quitDialog);
    auto *cancelButton = new QPushButton("Cancel", quitDialog);
    quitDialog->layout()->addWidget(okButton);
    quitDialog->layout()->addWidget(cancelButton);
    connect(okButton, &QPushButton::clicked, quitDialog, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, quitDialog, &QDialog::reject);

    connect(quitDialog, &QDialog::accepted, this, []() {
        qDebug() << "Quit dialog accepted";
    });

    connect(quitDialog, &QDialog::rejected, this, []() {
        qDebug() << "Quit dialog rejected";
    });

    connect(quitAction, &QAction::triggered, quitDialog, &QDialog::exec);
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

void MainWindow::onItemClicked(QListWidgetItem *item) {
    int index = listWidget->row(item);
    if (index >= 0 && index < stackedWidget->count()) {
        stackedWidget->setCurrentIndex(index);
    }
}

void MainWindow::initialize() {
    resize(960, 540);

    constexpr QSize resNHD{640,360};
    setMinimumSize(resNHD);

    constexpr QSize res4K{3840, 2160};
    setMaximumSize(res4K);
}