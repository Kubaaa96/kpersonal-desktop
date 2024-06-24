#include "modules/CalendarModule.hpp"

#include <QVBoxLayout>
#include <QLabel>


CalendarModule::CalendarModule(QWidget *parent)
    : QWidget(parent)
{
    moduleLabel = new QLabel("Calendar Module", this);
    moduleLabel->setAlignment(Qt::AlignCenter);

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(moduleLabel);
    layout->addStretch();

    setLayout(layout);
}
