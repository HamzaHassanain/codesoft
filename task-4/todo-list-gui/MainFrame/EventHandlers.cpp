#include "./MainFrame.h"

void MainFrame::OnAddButtonClicked(wxCommandEvent &event)
{
    AddTask(inputField->GetValue());
}
void MainFrame::OnAddTaskFromSubmit(wxCommandEvent &event)
{
    AddTask(inputField->GetValue());
}

void MainFrame::OnCheckListKeyDown(wxKeyEvent &event)
{
    std::cout << event.GetKeyCode() << std::endl;
    if (event.GetKeyCode() == WXK_DELETE)
        DeleteTask();
    if (event.GetKeyCode() == WXK_UP)
        MoveTask(-1);
    if (event.GetKeyCode() == WXK_DOWN)
        MoveTask(1);
    if (event.GetKeyCode() == WXK_SPACE)
        HandleSpaceKeyOnCheckList();
    if (event.GetKeyCode() == WXK_ESCAPE)
        checkListBox->SetSelection(wxNOT_FOUND);
    if (event.GetKeyCode() == WXK_CONTROL)
    {
        if (checkListBox->GetSelection() != wxNOT_FOUND)
            isMoving = !isMoving;
    }
}
void MainFrame::OnCheckListCheck(wxCommandEvent &event)
{
    int selctedIndex = checkListBox->GetSelection();
    if (selctedIndex == wxNOT_FOUND)
        return;

    Task task;
    task.task = checkListBox->GetString(selctedIndex).ToStdString();
    task.isDone = checkListBox->IsChecked(selctedIndex);

    TasksData::Save(ParseTasksCheckList());
}
void MainFrame::OnClearButtonClicked(wxCommandEvent &event)
{
    wxDialog *dialog = new wxMessageDialog(this, "Are you sure you want to clear the list?", "Clear List",
                                           wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);

    int result = dialog->ShowModal();
    if (result == wxID_YES)
        checkListBox->Clear();

    TasksData::Clear();

    wxDELETE(dialog);
}
void MainFrame::LoadAndSetTodos()
{
    std::vector<Task> todos = TasksData::Load();
    for (auto todo : todos)
    {
        wxString task = todo.task;
        checkListBox->Append(task);
        if (todo.isDone)
            checkListBox->Check(checkListBox->GetCount() - 1);
    }
}
