#include "./MainFrame.h"

void MainFrame::MoveTask(int offset)
{
    int selctedIndex = checkListBox->GetSelection();
    if (selctedIndex == wxNOT_FOUND)
        checkListBox->SetSelection((offset == -1 ? 0 : checkListBox->GetCount() - 1));
    else
    {

        int newIndex = selctedIndex + offset;
        if (newIndex < 0 || newIndex >= checkListBox->GetCount())
            return;

        if (isMoving)
            SwapTasks(selctedIndex, newIndex);

        checkListBox->SetSelection(newIndex);

        TasksData::Save(ParseTasksCheckList());
    }
}
void MainFrame::SwapTasks(int index1, int index2)
{
    Task td1, td2;
    td1.task = checkListBox->GetString(index1).ToStdString();
    td1.isDone = checkListBox->IsChecked(index1);

    td2.task = checkListBox->GetString(index2).ToStdString();
    td2.isDone = checkListBox->IsChecked(index2);

    checkListBox->SetString(index1, td2.task);
    checkListBox->SetString(index2, td1.task);
    checkListBox->Check(index1, td2.isDone);
    checkListBox->Check(index2, td1.isDone);
}
void MainFrame::AddTask(wxString task)
{
    checkListBox->Insert(task, 0);

    TasksData::Save(ParseTasksCheckList());

    inputField->Clear();
}
void MainFrame::DeleteTask()
{
    int selctedIndex = checkListBox->GetSelection();
    if (selctedIndex == wxNOT_FOUND)
        wxMessageBox("No task selected");
    else
    {
        wxDialog *dialog = new wxMessageDialog(this, "Are you sure you want to delete this task?", "Delete Task",
                                               wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
        int result = dialog->ShowModal();
        if (result == wxID_YES)
        {
            checkListBox->Delete(selctedIndex);
            TasksData::Save(ParseTasksCheckList());
        }
    }
}
std::vector<Task> MainFrame::ParseTasksCheckList()
{
    std::vector<Task> tasks;
    for (int i = 0; i < checkListBox->GetCount(); i++)
    {
        Task task;
        task.task = checkListBox->GetString(i).ToStdString();
        task.isDone = checkListBox->IsChecked(i);
        tasks.push_back(task);
    }
    return tasks;
}

void MainFrame::HandleSpaceKeyOnCheckList()
{
    int selctedIndex = checkListBox->GetSelection();

    if (selctedIndex == wxNOT_FOUND)
        return;

    checkListBox->Check(selctedIndex, !checkListBox->IsChecked(selctedIndex));

    TasksData::Save(ParseTasksCheckList());
}