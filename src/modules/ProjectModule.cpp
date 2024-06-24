#include "modules/ProjectModule.hpp"

#include <QVBoxLayout>
#include <QLabel>

ProjectModule::ProjectModule(QWidget *parent)
    : QWidget(parent)
{
    moduleLabel = new QLabel("Project Module", this);
    moduleLabel->setAlignment(Qt::AlignCenter);

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(moduleLabel);
    layout->addStretch();

    setLayout(layout);
}

