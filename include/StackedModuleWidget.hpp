#pragma once

#include <QStackedWidget>

class StackedModuleWidget : public QStackedWidget
{
    Q_OBJECT
public:
    explicit StackedModuleWidget(QWidget* parent = nullptr);
};