#include "modules/TaskModule.hpp"

#include <QVBoxLayout>

TaskModule::TaskModule(QWidget *parent)
    : QWidget(parent)
{
    moduleLabel = new QLabel("Task Module", this);
    moduleLabel->setAlignment(Qt::AlignCenter);

    floatingButton = new QPushButton("+", this);

    QFont font = floatingButton->font();
    font.setPointSize(23);
    floatingButton->setFont(font);

    floatingButton->setFixedSize(40, 40);
    floatingButton->setStyleSheet(
        "QPushButton { border-radius: 10px; background-color: #ffffff; color: black; text-align: center; }"
    );
    connect(floatingButton, &QPushButton::clicked, this, &TaskModule::onFloatingButtonClicked);

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(moduleLabel);
    layout->addStretch();

    setLayout(layout);
}


void TaskModule::onFloatingButtonClicked()
{
    qDebug() << "Debug";
}

void TaskModule::resizeEvent(QResizeEvent *event)
{
    floatingButton->move(width() - floatingButton->width() - 20, height() - floatingButton->height() - 20);
    QWidget::resizeEvent(event);
}