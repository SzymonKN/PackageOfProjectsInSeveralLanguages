#include "MainFrame.h"

MainFrame::MainFrame() : wxFrame(NULL, wxID_ANY, "Animacja szkieletu", wxDefaultPosition, wxSize(910, 749))
{
	setUpUi();
}

MainFrame::~MainFrame()
{
	m_pnlSkeleton->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrame::WxPanel_Repaint), NULL, this);
}

void MainFrame::onExit(wxCommandEvent & event)
{
	Close(true);
}

/* code generated with wxFormBuilder */
void MainFrame::setUpUi()
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bsContainer = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bsUi = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* bsRotation = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* bsMovement = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bsBody = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* bsArms = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* bsLegs = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bsRotationX = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* bsRotationY = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* bsRotationZ = new wxBoxSizer(wxVERTICAL);

	// skeletal animation panel
	m_pnlSkeleton = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	m_pnlSkeleton->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

	bsContainer->Add(m_pnlSkeleton, 1, wxEXPAND | wxALL, 5);

	// ui
	bsUi->Add(0, 5, 0, wxEXPAND, 5);

	// -- rotation
	wxStaticText* stRotationTitle = new wxStaticText(this, wxID_ANY, wxT("Rotacja"), wxDefaultPosition, wxDefaultSize, 0);
	stRotationTitle->Wrap(-1);
	stRotationTitle->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), 70, 90, 92, true, wxEmptyString));

	bsUi->Add(stRotationTitle, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	// ---- OX
	wxStaticLine* sl12 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bsRotationX->Add(sl12, 0, wxEXPAND | wxALL, 5);

	wxStaticText* stRotationX = new wxStaticText(this, wxID_ANY, wxT("OX"), wxDefaultPosition, wxDefaultSize, 0);
	stRotationX->Wrap(-1);
	stRotationX->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString));

	bsRotationX->Add(stRotationX, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 0);
	bsRotationX->Add(0, 5, 0, 0, 0);

	m_sldRotationX = new wxSlider(this, wxID_ANY, 180, 0, 360, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bsRotationX->Add(m_sldRotationX, 0, wxALIGN_CENTER_HORIZONTAL, 0);

	bsRotation->Add(bsRotationX, 1, 0, 5);

	// ---- OY
	wxStaticLine* sl121 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bsRotationY->Add(sl121, 0, wxEXPAND | wxALL, 5);

	wxStaticText* stRotationY = new wxStaticText(this, wxID_ANY, wxT("OY"), wxDefaultPosition, wxDefaultSize, 0);
	stRotationY->Wrap(-1);
	stRotationY->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString));

	bsRotationY->Add(stRotationY, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 0);
	bsRotationY->Add(0, 5, 0, 0, 0);

	m_sldRotationY = new wxSlider(this, wxID_ANY, 180, 0, 360, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bsRotationY->Add(m_sldRotationY, 0, wxALIGN_CENTER_HORIZONTAL, 0);

	bsRotation->Add(bsRotationY, 1, 0, 5);

	// ---- OZ
	wxStaticLine* sl122 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bsRotationZ->Add(sl122, 0, wxEXPAND | wxALL, 5);

	wxStaticText* stRotationZ = new wxStaticText(this, wxID_ANY, wxT("OZ"), wxDefaultPosition, wxDefaultSize, 0);
	stRotationZ->Wrap(-1);
	stRotationZ->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString));

	bsRotationZ->Add(stRotationZ, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 0);
	bsRotationZ->Add(0, 5, 0, 0, 0);

	m_sldRotationZ = new wxSlider(this, wxID_ANY, 180, 0, 360, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bsRotationZ->Add(m_sldRotationZ, 0, wxALIGN_CENTER_HORIZONTAL, 0);

	bsRotation->Add(bsRotationZ, 1, 0, 5);
	bsUi->Add(bsRotation, 0, wxEXPAND, 5);

	// -- movement
	wxStaticText* stMovementTitle = new wxStaticText(this, wxID_ANY, wxT("Poruszanie"), wxDefaultPosition, wxDefaultSize, 0);
	stMovementTitle->Wrap(-1);
	stMovementTitle->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), 70, 90, 92, true, wxEmptyString));
	bsUi->Add(0, 35, 0, wxEXPAND, 5);
	bsUi->Add(stMovementTitle, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	// ---- body
	wxStaticLine* sl1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bsBody->Add(sl1, 0, wxEXPAND | wxALL, 5);

	wxStaticText* stHead = new wxStaticText(this, wxID_ANY, wxT("G\u0142owa"), wxDefaultPosition, wxDefaultSize, 0);
	stHead->Wrap(-1);
	stHead->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString));

	bsBody->Add(stHead, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 0);
	bsBody->Add(0, 11, 1, wxEXPAND, 5);

	m_sldHeadX = new wxSlider(this, wxID_ANY, 0, -50, 50, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bsBody->Add(m_sldHeadX, 0, wxALIGN_CENTER_HORIZONTAL, 0);

	m_sldHeadY = new wxSlider(this, wxID_ANY, 0, -50, 50, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bsBody->Add(m_sldHeadY, 0, wxALIGN_CENTER_HORIZONTAL, 0);

	m_sldHeadZ = new wxSlider(this, wxID_ANY, 0, -50, 50, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bsBody->Add(m_sldHeadZ, 0, wxALIGN_CENTER_HORIZONTAL, 0);

	wxStaticLine* sl2 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bsBody->Add(sl2, 0, wxALL | wxEXPAND, 5);

	wxStaticText* stShoulder = new wxStaticText(this, wxID_ANY, wxT("Bark"), wxDefaultPosition, wxDefaultSize, 0);
	stShoulder->Wrap(-1);
	stShoulder->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString));

	bsBody->Add(stShoulder, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 0);

	wxString m_chShoulderChoices[] = { wxT("lewy"), wxT("prawy") };
	int m_chShoulderNChoices = sizeof(m_chShoulderChoices) / sizeof(wxString);
	m_chShoulder = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxSize(-1, 25), m_chShoulderNChoices, m_chShoulderChoices, 0);
	m_chShoulder->SetSelection(0);
	m_chShoulder->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString));

	bsBody->Add(m_chShoulder, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	m_sldShoulderX = new wxSlider(this, wxID_ANY, 0, -50, 50, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bsBody->Add(m_sldShoulderX, 0, wxALIGN_CENTER_HORIZONTAL, 0);

	m_sldShoulderY = new wxSlider(this, wxID_ANY, 0, -50, 50, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bsBody->Add(m_sldShoulderY, 0, wxALIGN_CENTER_HORIZONTAL, 0);

	wxStaticLine* sl3 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bsBody->Add(sl3, 0, wxEXPAND | wxALL, 5);

	wxStaticText* stBelly = new wxStaticText(this, wxID_ANY, wxT("Brzuch"), wxDefaultPosition, wxDefaultSize, 0);
	stBelly->Wrap(-1);
	stBelly->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString));

	bsBody->Add(stBelly, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 0);

	bsBody->Add(0, 0, 1, wxEXPAND, 5);

	m_sldBellyX = new wxSlider(this, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bsBody->Add(m_sldBellyX, 0, wxALIGN_CENTER_HORIZONTAL, 0);

	m_sldBellyY = new wxSlider(this, wxID_ANY, 0, -50, 50, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bsBody->Add(m_sldBellyY, 0, wxALIGN_CENTER_HORIZONTAL, 0);

	wxStaticLine* sl4 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);

	bsBody->Add(sl4, 0, wxEXPAND | wxALL, 5);

	wxStaticText* stHip = new wxStaticText(this, wxID_ANY, wxT("Biodro"), wxDefaultPosition, wxDefaultSize, 0);
	stHip->Wrap(-1);
	stHip->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString));

	bsBody->Add(stHip, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 0);

	wxString m_chHipChoices[] = { wxT("lewe"), wxT("prawe") };
	int m_chHipNChoices = sizeof(m_chHipChoices) / sizeof(wxString);
	m_chHip = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxSize(-1, 25), m_chHipNChoices, m_chHipChoices, 0);
	m_chHip->SetSelection(0);
	m_chHip->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString));

	bsBody->Add(m_chHip, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	m_sldHipX = new wxSlider(this, wxID_ANY, 0, 0, 70, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bsBody->Add(m_sldHipX, 0, wxALIGN_CENTER_HORIZONTAL, 0);
	;
	m_sldHipY = new wxSlider(this, wxID_ANY, 0, 0, 70, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bsBody->Add(m_sldHipY, 0, wxALIGN_CENTER_HORIZONTAL, 0);

	wxStaticLine* sl5 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bsBody->Add(sl5, 0, wxEXPAND | wxALL, 5);

	bsMovement->Add(bsBody, 1, wxALIGN_CENTER_HORIZONTAL, 5);

	// ---- arms
	wxStaticLine* sl6 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bsArms->Add(sl6, 0, wxEXPAND | wxALL, 5);

	wxStaticText* stForearm = new wxStaticText(this, wxID_ANY, wxT("Rami\u0119"), wxDefaultPosition, wxDefaultSize, 0);
	stForearm->Wrap(-1);
	stForearm->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString));

	bsArms->Add(stForearm, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 0);

	wxString m_chForearmChoices[] = { wxT("lewe"), wxT("prawe") };
	int m_chForearmNChoices = sizeof(m_chForearmChoices) / sizeof(wxString);
	m_chForearm = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxSize(-1, 25), m_chForearmNChoices, m_chForearmChoices, 0);
	m_chForearm->SetSelection(0);
	m_chForearm->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString));

	bsArms->Add(m_chForearm, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	m_sldForearmX = new wxSlider(this, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bsArms->Add(m_sldForearmX, 0, wxALIGN_CENTER_HORIZONTAL, 0);

	m_sldForearmY = new wxSlider(this, wxID_ANY, 0, -30, 60, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bsArms->Add(m_sldForearmY, 0, wxALIGN_CENTER_HORIZONTAL, 0);

	wxStaticLine* sl7 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bsArms->Add(sl7, 0, wxEXPAND | wxALL, 5);

	wxStaticText* stHand = new wxStaticText(this, wxID_ANY, wxT("Przedrami\u0119"), wxDefaultPosition, wxDefaultSize, 0);
	stHand->Wrap(-1);
	stHand->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString));

	bsArms->Add(stHand, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 0);

	wxString m_chHandChoices[] = { wxT("lewa"), wxT("prawa") };
	int m_chHandNChoices = sizeof(m_chHandChoices) / sizeof(wxString);
	m_chHand = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxSize(-1, 25), m_chHandNChoices, m_chHandChoices, 0);
	m_chHand->SetSelection(0);
	m_chHand->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString));

	bsArms->Add(m_chHand, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	m_sldHandX = new wxSlider(this, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bsArms->Add(m_sldHandX, 0, wxALIGN_CENTER_HORIZONTAL, 0);

	bsArms->Add(0, 24, 0, wxEXPAND, 5);

	wxStaticLine* sl8 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bsArms->Add(sl8, 0, wxEXPAND | wxALL, 5);

	bsMovement->Add(bsArms, 1, wxEXPAND, 5);

	// ---- legs
	wxStaticLine* sl9 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bsLegs->Add(sl9, 0, wxEXPAND | wxALL, 5);

	wxStaticText* stThigh = new wxStaticText(this, wxID_ANY, wxT("Udo"), wxDefaultPosition, wxDefaultSize, 0);
	stThigh->Wrap(-1);
	stThigh->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString));

	bsLegs->Add(stThigh, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 0);

	wxString m_chThighChoices[] = { wxT("lewe"), wxT("prawe") };
	int m_chThighNChoices = sizeof(m_chThighChoices) / sizeof(wxString);
	m_chThigh = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxSize(-1, 25), m_chThighNChoices, m_chThighChoices, 0);
	m_chThigh->SetSelection(0);
	m_chThigh->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString));

	bsLegs->Add(m_chThigh, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	m_sldThighX = new wxSlider(this, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bsLegs->Add(m_sldThighX, 0, wxALIGN_CENTER_HORIZONTAL, 0);

	bsLegs->Add(0, 24, 0, wxEXPAND, 5);

	wxStaticLine* sl10 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bsLegs->Add(sl10, 0, wxEXPAND | wxALL, 5);

	wxStaticText* stCalf = new wxStaticText(this, wxID_ANY, wxT("\u0141ydka"), wxDefaultPosition, wxDefaultSize, 0);
	stCalf->Wrap(-1);
	stCalf->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString));

	bsLegs->Add(stCalf, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 0);

	wxString m_chCalfChoices[] = { wxT("lewa"), wxT("prawa") };
	int m_chCalfNChoices = sizeof(m_chCalfChoices) / sizeof(wxString);
	m_chCalf = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxSize(-1, 25), m_chCalfNChoices, m_chCalfChoices, 0);
	m_chCalf->SetSelection(0);
	m_chCalf->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString));

	bsLegs->Add(m_chCalf, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	m_sldCalfX = new wxSlider(this, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bsLegs->Add(m_sldCalfX, 0, wxALIGN_CENTER_HORIZONTAL, 0);

	bsLegs->Add(0, 24, 0, wxEXPAND, 5);

	wxStaticLine* sl11 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bsLegs->Add(sl11, 0, wxEXPAND | wxALL, 5);

	bsMovement->Add(bsLegs, 1, wxEXPAND, 5);

	bsUi->Add(bsMovement, 1, wxEXPAND, 5);

	bsContainer->Add(bsUi, 1, wxALIGN_CENTER_HORIZONTAL, 5);

	this->SetSizer(bsContainer);
	this->Layout();

	this->Centre(wxBOTH);

	m_pnlSkeleton->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrame::WxPanel_Repaint), NULL, this);
}
void MainFrame::WxPanel_Repaint(wxUpdateUIEvent& event)
{ 
	event.Skip();
}