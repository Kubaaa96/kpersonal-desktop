#include "modules/HabitModule.hpp"

#include <QVBoxLayout>
#include <QLabel>

HabitModule::HabitModule(QWidget *parent)
    : QWidget(parent)
{
    moduleLabel = new QLabel("Habit Module", this);
    moduleLabel->setAlignment(Qt::AlignCenter);

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(moduleLabel);
    layout->addStretch();

    setLayout(layout);
}
