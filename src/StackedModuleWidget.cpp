#include "StackedModuleWidget.hpp"

#include "modules/CalendarModule.hpp"
#include "modules/FlashcardsModule.hpp"
#include "modules/HabitModule.hpp"
#include "modules/KanbanModule.hpp"
#include "modules/ProjectModule.hpp"
#include "modules/TaskModule.hpp"
#include "modules/TimeModule.hpp"
#include "modules/WikiModule.hpp"

StackedModuleWidget::StackedModuleWidget(QWidget *parent) : QStackedWidget(parent){
    addWidget(new TaskModule(this));
    addWidget(new TimeModule(this));
    addWidget(new FlashcardsModule(this));
    addWidget(new HabitModule(this));
    addWidget(new WikiModule(this));
    addWidget(new ProjectModule(this));
    addWidget(new CalendarModule(this));
    addWidget(new KanbanModule(this));
}
