#pragma once
#include "Task.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <filesystem>
class TasksData
{
public:
    static void Save(std::vector<Task> tasks)
    {
        std::ofstream file("tasks.txt");

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
        std::ifstream file("tasks.txt");
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
        if (std::filesystem::exists("tasks.txt"))
            std::filesystem::remove("tasks.txt");
    }
};