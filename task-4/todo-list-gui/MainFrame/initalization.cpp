#include "./MainFrame.h"
MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title)
{
    CreateControls();
    LoadAndSetTodos();
    BindEventsHandlers();
}

void MainFrame::CreateControls()
{

    wxFont headLineFont(wxFontInfo(wxSize(0, 36)).Bold());
    wxFont mainFont(wxFontInfo(wxSize(0, 24)).Bold());

    topPanel = new wxPanel(this);
    wxPanel *inputPanel = new wxPanel(this);
    panel = new wxPanel(this);
    bottomPanel = new wxPanel(this);

    topPanel->SetBackgroundColour(*wxRED);

    panel->SetFont(mainFont);
    inputPanel->SetFont(mainFont);

    // make size strech to fit

    headlineText =
        new wxStaticText(topPanel, wxID_ANY, "To Do List", wxDefaultPosition, wxSize(800, 200), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    headlineText->SetFont(headLineFont);
    // headlineText->SetBackgroundColour(*wxRED);

    inputField = new wxTextCtrl(inputPanel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
    addButton = new wxButton(inputPanel, wxID_ANY, "Add");

    checkListBox = new wxCheckListBox(panel, wxID_ANY, wxDefaultPosition);
    clearButton = new wxButton(bottomPanel, wxID_ANY, "Clear", wxDefaultPosition);

    wxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    wxSizer *topPanelSizer = new wxBoxSizer(wxHORIZONTAL);
    wxSizer *inputPanelSizer = new wxBoxSizer(wxHORIZONTAL);
    wxSizer *checkListSizer = new wxBoxSizer(wxHORIZONTAL);
    wxSizer *bottomPanelSizer = new wxBoxSizer(wxHORIZONTAL);

    topPanel->SetSizerAndFit(topPanelSizer);
    inputPanel->SetSizerAndFit(inputPanelSizer);
    panel->SetSizerAndFit(checkListSizer);
    bottomPanel->SetSizerAndFit(bottomPanelSizer);
    this->SetSizerAndFit(sizer);

    topPanelSizer->Add(headlineText, 1, wxEXPAND | wxTOP, 10);

    inputPanelSizer->Add(inputField, 5, wxEXPAND | wxALL, 5);
    inputPanelSizer->Add(addButton, 1, wxEXPAND | wxALL, 5);

    checkListSizer->Add(checkListBox, 1, wxEXPAND | wxALL, 5);

    bottomPanelSizer->Add(clearButton, 1, wxEXPAND | wxALL, 5);

    sizer->Add(topPanel, 1, wxEXPAND);
    sizer->Add(inputPanel, 1, wxEXPAND);
    sizer->Add(panel, 6, wxEXPAND);
    sizer->Add(bottomPanel, 1, wxEXPAND);
}

void MainFrame::BindEventsHandlers()
{

    checkListBox->Bind(wxEVT_KEY_DOWN, &MainFrame::OnCheckListKeyDown, this);
    checkListBox->Bind(wxEVT_CHECKLISTBOX, &MainFrame::OnCheckListCheck, this);

    addButton->Bind(wxEVT_BUTTON, &MainFrame::OnAddButtonClicked, this);
    clearButton->Bind(wxEVT_BUTTON, &MainFrame::OnClearButtonClicked, this);
    inputField->Bind(wxEVT_TEXT_ENTER, &MainFrame::OnAddTaskFromSubmit, this);
}
