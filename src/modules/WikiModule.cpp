#include "modules/WikiModule.hpp"

#include <QVBoxLayout>
#include <QLabel>

WikiModule::WikiModule(QWidget *parent)
    : QWidget(parent)
{
    moduleLabel = new QLabel("Wiki Module", this);
    moduleLabel->setAlignment(Qt::AlignCenter);

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(moduleLabel);
    layout->addStretch();

    setLayout(layout);
}

