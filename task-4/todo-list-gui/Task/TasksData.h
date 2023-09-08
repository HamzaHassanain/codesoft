#pragma once
#include "Task.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <filesystem>
class TasksData
{
public:
    static void Save(std::vector<Task> tasks)
    {
        std::ofstream file("./Task/tasks.txt");

        file << tasks.size() << std::endl;
        for (auto task : tasks)
        {
            std::replace(task.task.begin(), task.task.end(), ' ', '_');
            file << task.task << " " << task.isDone << std::endl;
        }
        file.close();
    }
    static std::vector<Task> Load()
    {
        std::vector<Task> tasks;
        std::ifstream file("./Task/tasks.txt");
        if (!file.is_open())
            return tasks;
        int size;
        file >> size;
        for (int i = 0; i < size; i++)
        {
            Task task;
            file >> task.task >> task.isDone;
            std::replace(task.task.begin(), task.task.end(), '_', ' ');
            tasks.push_back(task);
        }
        file.close();
        return tasks;
    }
    static void Clear()
    {
        if (std::filesystem::exists("./Task/tasks.txt"))
            std::filesystem::remove("./Task/tasks.txt");
    }
};