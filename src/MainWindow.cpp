#include "MainWindow.hpp"
#include "ListItemWidget.hpp"
#include "CustomDelegate.hpp"

#include <QPushButton>
#include <QHBoxLayout>
#include <QListWidget>

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

    QStringList items = {"Task", "Time", "Flashcards", "Habit", "Wiki", "Project", "Timeline", "Calendar", "Kanban", "List"};
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
    stackedWidget->addWidget(new QLabel("Task Module", this));
    stackedWidget->addWidget(new QLabel("Time Module", this));
    stackedWidget->addWidget(new QLabel("Flashcards Module", this));
    stackedWidget->addWidget(new QLabel("Habit Module", this));
    stackedWidget->addWidget(new QLabel("Wiki Module", this));
    stackedWidget->addWidget(new QLabel("Project Module", this));
    stackedWidget->addWidget(new QLabel("Timeline Module", this));
    stackedWidget->addWidget(new QLabel("Calendar Module", this));
    stackedWidget->addWidget(new QLabel("Kanban Module", this));
    stackedWidget->addWidget(new QLabel("List Module", this));

    // Add widgets to main layout
    mainLayout->addWidget(leftPanel);
    mainLayout->addWidget(toggleButton);
    mainLayout->addWidget(stackedWidget);

    // Menu Bar
    QMenuBar *menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    QMenu *fileMenu = new QMenu("&File", this);
    QAction *newAction = new QAction("&New...", this);
    QAction *openAction = new QAction("&Open...", this);
    QAction *saveAction = new QAction("&Save", this);
    QAction *saveAsAction = new QAction("Save &As...", this);
    QAction *quitAction = new QAction("&Quit", this);
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAction);

    QMenu *actionsMenu = new QMenu("&Actions", this);
    QAction *exportAction = new QAction("&Export", this);
    QAction *statisticsAction = new QAction("&Statistics", this);
    QAction *optionsAction = new QAction("&Options", this);
    actionsMenu->addAction(exportAction);
    actionsMenu->addAction(statisticsAction);
    actionsMenu->addAction(optionsAction);

    QMenu *helpMenu = new QMenu("&Help", this);
    QAction *aboutAction = new QAction("&About", this);
    helpMenu->addAction(aboutAction);

    menuBar->addMenu(fileMenu);
    menuBar->addMenu(actionsMenu);
    menuBar->addMenu(helpMenu);

    // // Quit Dialog
    // QDialog *quitDialog = new QDialog(this);
    // quitDialog->setWindowTitle("Quit");
    // quitDialog->setModal(true);
    // quitDialog->setLayout(new QVBoxLayout);
    // QLabel *quitLabel = new QLabel("This is a dialog box!", quitDialog);
    // quitDialog->layout()->addWidget(quitLabel);
    // QPushButton *okButton = new QPushButton("Ok", quitDialog);
    // QPushButton *cancelButton = new QPushButton("Cancel", quitDialog);
    // quitDialog->layout()->addWidget(okButton);
    // quitDialog->layout()->addWidget(cancelButton);
    // connect(okButton, &QPushButton::clicked, quitDialog, &QDialog::accept);
    // connect(cancelButton, &QPushButton::clicked, quitDialog, &QDialog::reject);
    //
    // connect(quitAction, &QAction::triggered, quitDialog, &QDialog::exec);
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