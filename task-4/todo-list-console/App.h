#pragma once
#include <vector>
#include <string>
#include "Task.h"

class App
{
    std::vector<Task> tasks;
    void UI();
    void ListTasks();

    void HandleAddTask();
    void HandleToggleTaskDoneState();
    void HandleRemoveTask();

    void AddTask(std::string);
    void ToggleTaskDoneState(int index);
    void RemoveTask(int index);

    void Exit();
    void SaveTasks();
    void LoadTasks();

public:
    void Run();
};

int GetIndex(int, int);