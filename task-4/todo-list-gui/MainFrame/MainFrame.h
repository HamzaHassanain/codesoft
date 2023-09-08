#pragma once

#include <wx/wx.h>
#include <iostream>
#include "../Task/TasksData.h"

class MainFrame : public wxFrame
{
private:
    // initalization
    void CreateControls();
    void BindEventsHandlers();
    void LoadAndSetTodos();

    // events handlers
    void OnAddButtonClicked(wxCommandEvent &);
    void OnClearButtonClicked(wxCommandEvent &);
    void OnAddTaskFromSubmit(wxCommandEvent &);
    void OnCheckListKeyDown(wxKeyEvent &);
    void OnCheckListCheck(wxCommandEvent &);

    // helpers
    void HandleSpaceKeyOnCheckList();
    std::vector<Task> ParseTasksCheckList();
    void AddTask(wxString);
    void DeleteTask();
    void MoveTask(int);
    void SwapTasks(int, int);

    bool isMoving = false;
    wxPanel *topPanel;
    wxPanel *panel;
    wxPanel *bottomPanel;
    wxStaticText *headlineText;
    wxTextCtrl *inputField;
    wxButton *addButton;
    wxCheckListBox *checkListBox;
    wxButton *clearButton;

public:
    MainFrame(const wxString &title);
};