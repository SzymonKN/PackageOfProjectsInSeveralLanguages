#pragma once
#include <wx/wx.h>
#include <wx/statline.h>

class MainFrame: public wxFrame
{
public:
	MainFrame();
	~MainFrame();

protected:
	void setUpUi();

	/* events */
	void onExit(wxCommandEvent& event);
	virtual void WxPanel_Repaint(wxUpdateUIEvent& event);

	wxPanel* m_pnlSkeleton;
	wxSlider* m_sldRotationX;
	wxSlider* m_sldRotationY;
	wxSlider* m_sldRotationZ;
	wxSlider* m_sldHeadX;
	wxSlider* m_sldHeadY;
	wxSlider* m_sldHeadZ;
	wxChoice* m_chShoulder;
	wxSlider* m_sldShoulderX;
	wxSlider* m_sldShoulderY;
	wxSlider* m_sldBellyX;
	wxSlider* m_sldBellyY;
	wxChoice* m_chHip;
	wxSlider* m_sldHipX;
	wxSlider* m_sldHipY;
	wxChoice* m_chForearm;
	wxSlider* m_sldForearmX;
	wxSlider* m_sldForearmY;
	wxChoice* m_chHand;
	wxSlider* m_sldHandX;
	wxChoice* m_chThigh;
	wxSlider* m_sldThighX;
	wxChoice* m_chCalf;
	wxSlider* m_sldCalfX;
};
