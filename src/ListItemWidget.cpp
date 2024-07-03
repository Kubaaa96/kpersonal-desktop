#include "ListItemWidget.hpp"

#include <QVBoxLayout>

ListItemWidget::ListItemWidget(const QString &text, QWidget *parent)
    : QWidget(parent) {

    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);

    label = new QLabel(text, this);
    layout->addWidget(label);

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}
