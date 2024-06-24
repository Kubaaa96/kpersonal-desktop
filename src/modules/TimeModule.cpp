#include "modules/TimeModule.hpp"

#include <QVBoxLayout>
#include <QLabel>

TimeModule::TimeModule(QWidget *parent)
    : QWidget(parent)
{
    moduleLabel = new QLabel("Time Module", this);
    moduleLabel->setAlignment(Qt::AlignCenter);

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(moduleLabel);
    layout->addStretch();

    setLayout(layout);
}

