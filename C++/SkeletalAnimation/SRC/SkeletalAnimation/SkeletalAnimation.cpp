#include "SkeletalAnimation.h"

wxIMPLEMENT_APP(SkeletalAnimation);

bool SkeletalAnimation::OnInit()
{
	wxFrame *main_frame = new GUIMainFrame();
	main_frame->Show(true);
	SetTopWindow(main_frame);
	return true;
}
