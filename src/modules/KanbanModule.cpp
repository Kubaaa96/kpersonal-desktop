#include "modules/KanbanModule.hpp"

#include <QVBoxLayout>
#include <QLabel>

KanbanModule::KanbanModule(QWidget *parent)
    : QWidget(parent)
{
    moduleLabel = new QLabel("Kanban Module", this);
    moduleLabel->setAlignment(Qt::AlignCenter);

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(moduleLabel);
    layout->addStretch();

    setLayout(layout);
}

