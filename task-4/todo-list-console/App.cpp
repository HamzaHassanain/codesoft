#include "App.h"
#include "Task.h"
#include "TasksData.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

void App::UI()
{
// check if the sysrem is windows or not
#ifdef _WIN32
    system("cls");
#elif _WIN64
    system("cls");
#else
    system("clear");
#endif

    cout << "Welcome to Todo List Console App" << endl;
    cout << "================================" << endl;

    LoadTasks();
    ListTasks();
    cout << endl;
    cout << "1. Add Task" << endl;
    cout << "2. Check/Uncheck Task" << endl;
    cout << "3. Remove Task" << endl;
    cout << "0. Exit" << endl;

    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        HandleAddTask();
        break;
    case 2:
        HandleToggleTaskDoneState();
        break;
    case 3:
        HandleRemoveTask();
        break;
    case 0:
        Exit();
        return;
    default:
        return UI();
    }
}

void App::Run()
{
    UI();
}

void App::ListTasks()
{
    for (int i = tasks.size() - 1; i >= 0; i--)
    {
        string check = tasks[i].isDone ? "X| " : " | ";
        cout << tasks.size() - i << ". "
             << (check) << tasks[i].task << endl;

        cout << "--------------------------------" << endl;
    }
}

void App::HandleAddTask()
{
    cout << "Enter task: ";
    string task;
    getline(cin >> ws, task);
    AddTask(task);
}
void App::HandleToggleTaskDoneState()
{
    cout << "Enter task index: ";
    int index;
    cin >> index;
    ToggleTaskDoneState(index);
}
void App::HandleRemoveTask()
{
    cout << "Enter task index: ";
    int index;
    cin >> index;
    RemoveTask(index);
}
void App::AddTask(string task)
{
    Task newTask;
    newTask.task = task;
    newTask.isDone = false;
    tasks.push_back(newTask);
    SaveTasks();
    UI();
}
void App::ToggleTaskDoneState(int index)
{
    if (index != -1)
        tasks[index].isDone = !tasks[index].isDone;

    SaveTasks();
    UI();
}
void App::RemoveTask(int index)
{
    index = GetIndex(index, tasks.size());
    if (index != -1)
        tasks.erase(tasks.begin() + index);

    SaveTasks();
    UI();
}
void App::SaveTasks()
{
    TasksData::Save(tasks);
}
void App::LoadTasks()
{
    this->tasks = TasksData::Load();
}
void App::Exit()
{
    cout << "Goodbye!" << endl;
    exit(0);
}
int GetIndex(int index, int size)
{
    if (index > size || index < 1)
    {
        return -1;
    }
    index--;
    index = size - index - 1;
    return index;
}