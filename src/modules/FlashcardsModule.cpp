#include "modules/FlashcardsModule.hpp"

#include <QVBoxLayout>
#include <QLabel>

FlashcardsModule::FlashcardsModule(QWidget *parent)
    : QWidget(parent)
{
    moduleLabel = new QLabel("Flashcards Module", this);
    moduleLabel->setAlignment(Qt::AlignCenter);

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(moduleLabel);
    layout->addStretch();

    setLayout(layout);
}
