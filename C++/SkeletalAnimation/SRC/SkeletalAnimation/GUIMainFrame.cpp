#include "GUIMainFrame.h"

GUIMainFrame::GUIMainFrame(): MainFrame()
{
	MoveHeadX(x_head_matrix);
	MoveHeadY(y_head_matrix);
	MoveHeadZ(z_head_matrix);

	MoveShoulderX(x_left_shoulder_matrix);
	MoveShoulderX(x_right_shoulder_matrix);
	MoveShoulderY(y_left_shoulder_matrix);
	MoveShoulderY(y_right_shoulder_matrix);

	MoveForearmX(x_left_forearm_matrix);
	MoveForearmY(y_left_forearm_matrix);

	MoveForearmX(x_right_forearm_matrix);
	MoveForearmY(y_right_forearm_matrix);

	MoveHand(left_hand_matrix);
	MoveHand(right_hand_matrix);

	MoveBellyX(x_belly_matrix);
	MoveBellyY(y_belly_matrix);

	MoveHipX(x_left_hip_matrix);
	MoveHipY(y_left_hip_matrix);
	MoveHipX(x_right_hip_matrix);
	MoveHipY(y_right_hip_matrix);

	MoveThigh(left_thigh_matrix);
	MoveThigh(right_thigh_matrix);

	MoveCalf(left_calf_matrix);
	MoveCalf(right_calf_matrix);
}

void GUIMainFrame::WxPanel_Repaint(wxUpdateUIEvent& event)
{
	DrawSkeleton();
}

void GUIMainFrame::Normalization(Vector4& vector)
{
	vector.data[0] /= vector.data[3];
	vector.data[1] /= vector.data[3];
	vector.data[2] /= vector.data[3];
}

void GUIMainFrame::Projection(Matrix4& matrix)
{
	Matrix4 View;
	View.data[0][0] = 1.0;
	View.data[1][1] = 1.0;
	View.data[3][2] = 1.0 / 2.0;

	Matrix4 Panel_Size;
	wxSize panelSize = m_pnlSkeleton->GetSize();
	Panel_Size.data[0][0] = panelSize.GetWidth() / 2.0;
	Panel_Size.data[0][3] = Panel_Size.data[0][0];
	Panel_Size.data[1][1] = -panelSize.GetHeight() / 2.0;
	Panel_Size.data[1][3] = -Panel_Size.data[1][1];

	matrix = Panel_Size * View;
}

void GUIMainFrame::Transformation(Matrix4& matrix)
{
	double alpha;

	Matrix4 RotateX;
	alpha = m_sldRotationX->GetValue() * acos(-1) / 180;
	RotateX.data[0][0] = 1.0;
	RotateX.data[1][1] = cos(alpha);
	RotateX.data[1][2] = sin(alpha);
	RotateX.data[2][1] = -sin(alpha);
	RotateX.data[2][2] = cos(alpha);

	Matrix4 RotateY;
	alpha = m_sldRotationY->GetValue() * acos(-1) / 180;
	RotateY.data[0][0] = cos(alpha);
	RotateY.data[0][2] = -sin(alpha);
	RotateY.data[1][1] = 1.0;
	RotateY.data[2][0] = sin(alpha);
	RotateY.data[2][2] = cos(alpha);

	Matrix4 RotateZ;
	alpha = m_sldRotationZ->GetValue() * acos(-1) / 180;
	RotateZ.data[0][0] = cos(alpha);
	RotateZ.data[0][1] = sin(alpha);
	RotateZ.data[1][0] = -sin(alpha);
	RotateZ.data[1][1] = cos(alpha);
	RotateZ.data[2][2] = 1.0;

	matrix = RotateX * RotateY * RotateZ;
}

void GUIMainFrame::MoveHand(Matrix4& matrix)
{
	double alpha = -1 * m_sldHandX->GetValue() * acos(-1) / 110;
	matrix.data[0][0] = 1.0;
	matrix.data[1][1] = cos(alpha);
	matrix.data[1][2] = sin(alpha);
	matrix.data[2][1] = -sin(alpha);
	matrix.data[2][2] = cos(alpha);
}

void GUIMainFrame::MoveForearmX(Matrix4& matrix)
{
	double alpha;
	if (m_chForearm->GetSelection() == 0)
		alpha = -1 * m_sldForearmX->GetValue() * acos(-1) / 110;
	else
		alpha = 1 * m_sldForearmX->GetValue() * acos(-1) / 110;
	matrix.data[0][0] = cos(alpha);
	matrix.data[0][1] = sin(alpha);
	matrix.data[1][0] = -sin(alpha);
	matrix.data[1][1] = cos(alpha);
	matrix.data[2][2] = 1.0;
}

void GUIMainFrame::MoveForearmY(Matrix4& matrix)
{
	double alpha = -1 * m_sldForearmY->GetValue() * acos(-1) / 60;
	matrix.data[0][0] = 1.0;
	matrix.data[1][1] = cos(alpha);
	matrix.data[1][2] = sin(alpha);
	matrix.data[2][1] = -sin(alpha);
	matrix.data[2][2] = cos(alpha);
}

void GUIMainFrame::MoveHeadX(Matrix4& matrix)
{
	double alpha = 1 * m_sldHeadX->GetValue() * acos(-1) / 90;
	matrix.data[0][0] = 1.0;
	matrix.data[1][1] = cos(alpha);
	matrix.data[1][2] = sin(alpha);
	matrix.data[2][1] = -sin(alpha);
	matrix.data[2][2] = cos(alpha);
}

void GUIMainFrame::MoveHeadY(Matrix4& matrix)
{
	double alpha = 1 * m_sldHeadY->GetValue() * acos(-1) / 100;
	matrix.data[0][0] = cos(alpha);
	matrix.data[0][2] = -sin(alpha);
	matrix.data[1][1] = 1.0;
	matrix.data[2][0] = sin(alpha);
	matrix.data[2][2] = cos(alpha);
}

void GUIMainFrame::MoveHeadZ(Matrix4& matrix)
{
	double alpha = 1 * m_sldHeadZ->GetValue() * acos(-1) / 100;
	matrix.data[0][0] = cos(alpha);
	matrix.data[0][1] = sin(alpha);
	matrix.data[1][0] = -sin(alpha);
	matrix.data[1][1] = cos(alpha);
	matrix.data[2][2] = 1.0;
}

void GUIMainFrame::MoveShoulderX(Matrix4& matrix)
{
	double alpha = 1 * m_sldShoulderX->GetValue() * acos(-1) / 270;
	matrix.data[0][0] = cos(alpha);
	matrix.data[0][1] = sin(alpha);
	matrix.data[1][0] = -sin(alpha);
	matrix.data[1][1] = cos(alpha);
	matrix.data[2][2] = 1.0;
}

void GUIMainFrame::MoveShoulderY(Matrix4& matrix)
{
	double alpha = 1 * m_sldShoulderY->GetValue() * acos(-1) / 300;
	matrix.data[0][0] = cos(alpha);
	matrix.data[0][2] = -sin(alpha);
	matrix.data[1][1] = 1.0;
	matrix.data[2][0] = sin(alpha);
	matrix.data[2][2] = cos(alpha);
}

void GUIMainFrame::MoveBellyX(Matrix4& matrix)
{
	double alpha = 1 * m_sldBellyX->GetValue() * acos(-1) / 180;
	matrix.data[0][0] = 1.0;
	matrix.data[1][1] = cos(alpha);
	matrix.data[1][2] = sin(alpha);
	matrix.data[2][1] = -sin(alpha);
	matrix.data[2][2] = cos(alpha);
}

void GUIMainFrame::MoveBellyY(Matrix4& matrix)
{
	double alpha = 1 * m_sldBellyY->GetValue() * acos(-1) / 140;
	matrix.data[0][0] = cos(alpha);
	matrix.data[0][1] = sin(alpha);
	matrix.data[1][0] = -sin(alpha);
	matrix.data[1][1] = cos(alpha);
	matrix.data[2][2] = 1.0;
}

void GUIMainFrame::MoveHipX(Matrix4& matrix)
{
	double alpha;
	if (m_chHip->GetSelection() == 0)
		alpha = m_sldHipX->GetValue() * acos(-1) / 200;
	else
		alpha = -1 * m_sldHipX->GetValue() * acos(-1) / 200;
	matrix.data[0][0] = cos(alpha);
	matrix.data[0][2] = -sin(alpha);
	matrix.data[1][1] = 1.0;
	matrix.data[2][0] = sin(alpha);
	matrix.data[2][2] = cos(alpha);
}

void GUIMainFrame::MoveHipY(Matrix4& matrix)
{
	double alpha;
	if (m_chHip->GetSelection() == 0)
		alpha = -1 * m_sldHipY->GetValue() * acos(-1) / 200;
	else
		alpha = m_sldHipY->GetValue() * acos(-1) / 200;
	matrix.data[0][0] = cos(alpha);
	matrix.data[0][1] = sin(alpha);
	matrix.data[1][0] = -sin(alpha);
	matrix.data[1][1] = cos(alpha);
	matrix.data[2][2] = 1.0;
}

void GUIMainFrame::MoveThigh(Matrix4& matrix)
{
	double alpha = -1 * m_sldThighX->GetValue() * acos(-1) / 200;
	matrix.data[0][0] = 1.0;
	matrix.data[1][1] = cos(alpha);
	matrix.data[1][2] = sin(alpha);
	matrix.data[2][1] = -sin(alpha);
	matrix.data[2][2] = cos(alpha);
}

void GUIMainFrame::MoveCalf(Matrix4& matrix)
{
	double alpha = 1 * m_sldCalfX->GetValue() * acos(-1) / 200;
	matrix.data[0][0] = 1.0;
	matrix.data[1][1] = cos(alpha);
	matrix.data[1][2] = sin(alpha);
	matrix.data[2][1] = -sin(alpha);
	matrix.data[2][2] = cos(alpha);
}

void GUIMainFrame::DrawSkeleton()
{
	wxClientDC dc(m_pnlSkeleton);
	wxBufferedDC buffer(&dc);
	buffer.SetBackground(*wxWHITE_BRUSH);
	buffer.Clear();
	buffer.SetPen(wxPen(wxColor(0, 0, 0)));

	wxSize size = m_pnlSkeleton->GetSize();

	Segment position[15][12];

	if (m_chHand->GetSelection() == 0)
		MoveHand(left_hand_matrix);
	else
		MoveHand(right_hand_matrix);

	if (m_chForearm->GetSelection() == 0)
	{
		MoveForearmX(x_left_forearm_matrix);
		MoveForearmY(y_left_forearm_matrix);
	}
	else
	{
		MoveForearmX(x_right_forearm_matrix);
		MoveForearmY(y_right_forearm_matrix);
	}

	if (m_chHip->GetSelection() == 0)
	{
		MoveHipX(x_left_hip_matrix);
		MoveHipY(y_left_hip_matrix);
	}
	else
	{
		MoveHipX(x_right_hip_matrix);
		MoveHipY(y_right_hip_matrix);
	}

	MoveHeadX(x_head_matrix);
	MoveHeadY(y_head_matrix);
	MoveHeadZ(z_head_matrix);
	MoveBellyX(x_belly_matrix);
	MoveBellyY(y_belly_matrix);

	if (m_chThigh->GetSelection() == 0)
		MoveThigh(left_thigh_matrix);
	else
		MoveThigh(right_thigh_matrix);

	if (m_chCalf->GetSelection() == 0)
		MoveCalf(left_calf_matrix);
	else
		MoveCalf(right_calf_matrix);

	if (m_chShoulder->GetSelection() == 0)
	{
		MoveShoulderX(x_left_shoulder_matrix);
		MoveShoulderY(y_left_shoulder_matrix);
	}
	else
	{
		MoveShoulderX(x_right_shoulder_matrix);
		MoveShoulderY(y_right_shoulder_matrix);
	}
		
	for (int i = 0; i < 12; ++i)
	{
		position[0][i] = skeleton.head->lines[i];
		position[1][i] = skeleton.left_shoulder->lines[i];
		position[2][i] = skeleton.right_shoulder->lines[i];
		position[3][i] = skeleton.left_forearm->lines[i];
		position[4][i] = skeleton.right_forearm->lines[i];
		position[5][i] = skeleton.left_arm->lines[i];
		position[6][i] = skeleton.right_arm->lines[i];
		position[7][i] = skeleton.chest->lines[i];
		position[8][i] = skeleton.stomach->lines[i];
		position[9][i] = skeleton.left_hip->lines[i];
		position[10][i] = skeleton.right_hip->lines[i];
		position[11][i] = skeleton.left_thigh->lines[i];
		position[12][i] = skeleton.right_thigh->lines[i];
		position[13][i] = skeleton.left_calf->lines[i];
		position[14][i] = skeleton.right_calf->lines[i];
	}

	Matrix4 projection;
	Matrix4 transformation;
	Projection(projection);
	Transformation(transformation);

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			Vector4 Point1, Point2;
			Point1.Set(position[i][j].begin->x, position[i][j].begin->y, position[i][j].begin->z);
			Point2.Set(position[i][j].end->x, position[i][j].end->y, position[i][j].end->z);

			//G³owa
			if (i == 0)
			{
				if (m_sldHeadX->GetValue() < 0)
				{
					Point1.Set(Point1.GetX(), Point1.GetY() - 0.7, Point1.GetZ() - 0.4);
					Point2.Set(Point2.GetX(), Point2.GetY() - 0.7, Point2.GetZ() - 0.4);
					Point2 = x_head_matrix * Point2;
					Point1 = x_head_matrix * Point1;
					Point1.Set(Point1.GetX(), Point1.GetY() + 0.7, Point1.GetZ() + 0.4);
					Point2.Set(Point2.GetX(), Point2.GetY() + 0.7, Point2.GetZ() + 0.4);
				}
				else
				{
					Point1.Set(Point1.GetX(), Point1.GetY() - 0.7, Point1.GetZ());
					Point2.Set(Point2.GetX(), Point2.GetY() - 0.7, Point2.GetZ());
					Point2 = x_head_matrix * Point2;
					Point1 = x_head_matrix * Point1;
					Point1.Set(Point1.GetX(), Point1.GetY() + 0.7, Point1.GetZ());
					Point2.Set(Point2.GetX(), Point2.GetY() + 0.7, Point2.GetZ());
				}

				Point1.Set(Point1.GetX(), Point1.GetY() - 0.7, Point1.GetZ() - 0.2);
				Point2.Set(Point2.GetX(), Point2.GetY() - 0.7, Point2.GetZ() - 0.2);
				Point2 = y_head_matrix * Point2;
				Point1 = y_head_matrix * Point1;
				Point1.Set(Point1.GetX(), Point1.GetY() + 0.7, Point1.GetZ() + 0.2);
				Point2.Set(Point2.GetX(), Point2.GetY() + 0.7, Point2.GetZ() + 0.2);

				if (m_sldHeadZ->GetValue() < 0)
				{
					Point1.Set(Point1.GetX() + 0.1, Point1.GetY() - 0.7, Point1.GetZ());
					Point2.Set(Point2.GetX() + 0.1, Point2.GetY() - 0.7, Point2.GetZ());
					Point2 = z_head_matrix * Point2;
					Point1 = z_head_matrix * Point1;
					Point1.Set(Point1.GetX() - 0.1, Point1.GetY() + 0.7, Point1.GetZ());
					Point2.Set(Point2.GetX() - 0.1, Point2.GetY() + 0.7, Point2.GetZ());
				}
				else
				{
					Point1.Set(Point1.GetX() - 0.1, Point1.GetY() - 0.7, Point1.GetZ());
					Point2.Set(Point2.GetX() - 0.1, Point2.GetY() - 0.7, Point2.GetZ());
					Point2 = z_head_matrix * Point2;
					Point1 = z_head_matrix * Point1;
					Point1.Set(Point1.GetX() + 0.1, Point1.GetY() + 0.7, Point1.GetZ());
					Point2.Set(Point2.GetX() + 0.1, Point2.GetY() + 0.7, Point2.GetZ());
				}

				//pochylenie brzuch
				Point1.Set(Point1.GetX(), Point1.GetY() - 0.05, Point1.GetZ() - 0.2);
				Point2.Set(Point2.GetX(), Point2.GetY() - 0.05, Point2.GetZ() - 0.2);
				Point2 = x_belly_matrix * Point2;
				Point1 = x_belly_matrix * Point1;
				Point1.Set(Point1.GetX(), Point1.GetY() + 0.05, Point1.GetZ() + 0.2);
				Point2.Set(Point2.GetX(), Point2.GetY() + 0.05, Point2.GetZ() + 0.2);

				Point1.Set(Point1.GetX(), Point1.GetY() - 0.05, Point1.GetZ());
				Point2.Set(Point2.GetX(), Point2.GetY() - 0.05, Point2.GetZ());
				Point2 = y_belly_matrix * Point2;
				Point1 = y_belly_matrix * Point1;
				Point1.Set(Point1.GetX(), Point1.GetY() + 0.05, Point1.GetZ());
				Point2.Set(Point2.GetX(), Point2.GetY() + 0.05, Point2.GetZ());
			}

			//Lewe ramie
			if (i == 1)
			{
				Point1.Set(Point1.GetX() - 0.1, Point1.GetY() - 0.6, Point1.GetZ());
				Point2.Set(Point2.GetX() - 0.1, Point2.GetY() - 0.6, Point2.GetZ());
				Point2 = x_left_shoulder_matrix * Point2;
				Point1 = x_left_shoulder_matrix * Point1;
				Point1.Set(Point1.GetX() + 0.1, Point1.GetY() + 0.6, Point1.GetZ());
				Point2.Set(Point2.GetX() + 0.1, Point2.GetY() + 0.6, Point2.GetZ());

				Point1.Set(Point1.GetX() - 0.1, Point1.GetY(), Point1.GetZ()-0.2);
				Point2.Set(Point2.GetX() - 0.1, Point2.GetY(), Point2.GetZ()-0.2);
				Point2 = y_left_shoulder_matrix * Point2;
				Point1 = y_left_shoulder_matrix * Point1;
				Point1.Set(Point1.GetX() + 0.1, Point1.GetY(), Point1.GetZ()+0.2);
				Point2.Set(Point2.GetX() + 0.1, Point2.GetY(), Point2.GetZ()+0.2);

				//pochylenie brzuch
				Point1.Set(Point1.GetX(), Point1.GetY() - 0.05, Point1.GetZ() - 0.2);
				Point2.Set(Point2.GetX(), Point2.GetY() - 0.05, Point2.GetZ() - 0.2);
				Point2 = x_belly_matrix * Point2;
				Point1 = x_belly_matrix * Point1;
				Point1.Set(Point1.GetX(), Point1.GetY() + 0.05, Point1.GetZ() + 0.2);
				Point2.Set(Point2.GetX(), Point2.GetY() + 0.05, Point2.GetZ() + 0.2);

				Point1.Set(Point1.GetX(), Point1.GetY() - 0.05, Point1.GetZ());
				Point2.Set(Point2.GetX(), Point2.GetY() - 0.05, Point2.GetZ());
				Point2 = y_belly_matrix * Point2;
				Point1 = y_belly_matrix * Point1;
				Point1.Set(Point1.GetX(), Point1.GetY() + 0.05, Point1.GetZ());
				Point2.Set(Point2.GetX(), Point2.GetY() + 0.05, Point2.GetZ());
			}


			//Prawe ramie
			if (i == 2)
			{
				Point1.Set(Point1.GetX() + 0.1, Point1.GetY() - 0.6, Point1.GetZ());
				Point2.Set(Point2.GetX() + 0.1, Point2.GetY() - 0.6, Point2.GetZ());
				Point2 = x_right_shoulder_matrix * Point2;
				Point1 = x_right_shoulder_matrix * Point1;
				Point1.Set(Point1.GetX() - 0.1, Point1.GetY() + 0.6, Point1.GetZ());
				Point2.Set(Point2.GetX() - 0.1, Point2.GetY() + 0.6, Point2.GetZ());

				Point1.Set(Point1.GetX() + 0.1, Point1.GetY(), Point1.GetZ() - 0.2);
				Point2.Set(Point2.GetX() + 0.1, Point2.GetY(), Point2.GetZ() - 0.2);
				Point2 = y_right_shoulder_matrix * Point2;
				Point1 = y_right_shoulder_matrix * Point1;
				Point1.Set(Point1.GetX() - 0.1, Point1.GetY(), Point1.GetZ() + 0.2);
				Point2.Set(Point2.GetX() - 0.1, Point2.GetY(), Point2.GetZ() + 0.2);

				//pochylenie brzuch
				Point1.Set(Point1.GetX(), Point1.GetY() - 0.05, Point1.GetZ() - 0.2);
				Point2.Set(Point2.GetX(), Point2.GetY() - 0.05, Point2.GetZ() - 0.2);
				Point2 = x_belly_matrix * Point2;
				Point1 = x_belly_matrix * Point1;
				Point1.Set(Point1.GetX(), Point1.GetY() + 0.05, Point1.GetZ() + 0.2);
				Point2.Set(Point2.GetX(), Point2.GetY() + 0.05, Point2.GetZ() + 0.2);

				Point1.Set(Point1.GetX(), Point1.GetY() - 0.05, Point1.GetZ());
				Point2.Set(Point2.GetX(), Point2.GetY() - 0.05, Point2.GetZ());
				Point2 = y_belly_matrix * Point2;
				Point1 = y_belly_matrix * Point1;
				Point1.Set(Point1.GetX(), Point1.GetY() + 0.05, Point1.GetZ());
				Point2.Set(Point2.GetX(), Point2.GetY() + 0.05, Point2.GetZ());
			}
			//Lewe przedramie
			if (i == 3)
			{
				Point1.Set(Point1.GetX() - 0.6, Point1.GetY() - 0.5, Point1.GetZ());
				Point2.Set(Point2.GetX() - 0.6, Point2.GetY() - 0.5, Point2.GetZ());
				Point2 = x_left_forearm_matrix * Point2;
				Point1 = x_left_forearm_matrix * Point1;
				Point1.Set(Point1.GetX() + 0.6, Point1.GetY() + 0.5, Point1.GetZ());
				Point2.Set(Point2.GetX() + 0.6, Point2.GetY() + 0.5, Point2.GetZ());

				if (m_sldForearmY->GetValue() < 0)
				{
					Point1.Set(Point1.GetX() - 0.6, Point1.GetY() - 0.5, Point1.GetZ() - 0.4);
					Point2.Set(Point2.GetX() - 0.6, Point2.GetY() - 0.5, Point2.GetZ() - 0.4);
					Point2 = y_left_forearm_matrix * Point2;
					Point1 = y_left_forearm_matrix * Point1;
					Point1.Set(Point1.GetX() + 0.6, Point1.GetY() + 0.5, Point1.GetZ() + 0.4);
					Point2.Set(Point2.GetX() + 0.6, Point2.GetY() + 0.5, Point2.GetZ() + 0.4);
				}
				else
				{
					Point1.Set(Point1.GetX() - 0.6, Point1.GetY() - 0.5, Point1.GetZ());
					Point2.Set(Point2.GetX() - 0.6, Point2.GetY() - 0.5, Point2.GetZ());
					Point2 = y_left_forearm_matrix * Point2;
					Point1 = y_left_forearm_matrix * Point1;
					Point1.Set(Point1.GetX() + 0.6, Point1.GetY() + 0.5, Point1.GetZ());
					Point2.Set(Point2.GetX() + 0.6, Point2.GetY() + 0.5, Point2.GetZ());
				}

				Point1.Set(Point1.GetX() - 0.1, Point1.GetY() - 0.6, Point1.GetZ());
				Point2.Set(Point2.GetX() - 0.1, Point2.GetY() - 0.6, Point2.GetZ());
				Point2 = x_left_shoulder_matrix * Point2;
				Point1 = x_left_shoulder_matrix * Point1;
				Point1.Set(Point1.GetX() + 0.1, Point1.GetY() + 0.6, Point1.GetZ());
				Point2.Set(Point2.GetX() + 0.1, Point2.GetY() + 0.6, Point2.GetZ());

				Point1.Set(Point1.GetX() - 0.1, Point1.GetY(), Point1.GetZ() - 0.2);
				Point2.Set(Point2.GetX() - 0.1, Point2.GetY(), Point2.GetZ() - 0.2);
				Point2 = y_left_shoulder_matrix * Point2;
				Point1 = y_left_shoulder_matrix * Point1;
				Point1.Set(Point1.GetX() + 0.1, Point1.GetY(), Point1.GetZ() + 0.2);
				Point2.Set(Point2.GetX() + 0.1, Point2.GetY(), Point2.GetZ() + 0.2);

				//pochylenie brzuch
				Point1.Set(Point1.GetX(), Point1.GetY() - 0.05, Point1.GetZ() - 0.2);
				Point2.Set(Point2.GetX(), Point2.GetY() - 0.05, Point2.GetZ() - 0.2);
				Point2 = x_belly_matrix * Point2;
				Point1 = x_belly_matrix * Point1;
				Point1.Set(Point1.GetX(), Point1.GetY() + 0.05, Point1.GetZ() + 0.2);
				Point2.Set(Point2.GetX(), Point2.GetY() + 0.05, Point2.GetZ() + 0.2);

				Point1.Set(Point1.GetX(), Point1.GetY() - 0.05, Point1.GetZ());
				Point2.Set(Point2.GetX(), Point2.GetY() - 0.05, Point2.GetZ());
				Point2 = y_belly_matrix * Point2;
				Point1 = y_belly_matrix * Point1;
				Point1.Set(Point1.GetX(), Point1.GetY() + 0.05, Point1.GetZ());
				Point2.Set(Point2.GetX(), Point2.GetY() + 0.05, Point2.GetZ());
			}
			//Prawe przedramie
			if (i == 4)
			{
				Point1.Set(Point1.GetX() + 0.6, Point1.GetY() - 0.5, Point1.GetZ());
				Point2.Set(Point2.GetX() + 0.6, Point2.GetY() - 0.5, Point2.GetZ());
				Point2 = x_right_forearm_matrix * Point2;
				Point1 = x_right_forearm_matrix * Point1;
				Point1.Set(Point1.GetX() - 0.6, Point1.GetY() + 0.5, Point1.GetZ());
				Point2.Set(Point2.GetX() - 0.6, Point2.GetY() + 0.5, Point2.GetZ());

				if (m_sldForearmY->GetValue() < 0)
				{
					Point1.Set(Point1.GetX() + 0.6, Point1.GetY() - 0.5, Point1.GetZ() - 0.4);
					Point2.Set(Point2.GetX() + 0.6, Point2.GetY() - 0.5, Point2.GetZ() - 0.4);
					Point2 = y_right_forearm_matrix * Point2;
					Point1 = y_right_forearm_matrix * Point1;
					Point1.Set(Point1.GetX() - 0.6, Point1.GetY() + 0.5, Point1.GetZ() + 0.4);
					Point2.Set(Point2.GetX() - 0.6, Point2.GetY() + 0.5, Point2.GetZ() + 0.4);
				}
				else
				{
					Point1.Set(Point1.GetX() + 0.6, Point1.GetY() - 0.5, Point1.GetZ());
					Point2.Set(Point2.GetX() + 0.6, Point2.GetY() - 0.5, Point2.GetZ());
					Point2 = y_right_forearm_matrix * Point2;
					Point1 = y_right_forearm_matrix * Point1;
					Point1.Set(Point1.GetX() - 0.6, Point1.GetY() + 0.5, Point1.GetZ());
					Point2.Set(Point2.GetX() - 0.6, Point2.GetY() + 0.5, Point2.GetZ());
				}

				Point1.Set(Point1.GetX() + 0.1, Point1.GetY() - 0.6, Point1.GetZ());
				Point2.Set(Point2.GetX() + 0.1, Point2.GetY() - 0.6, Point2.GetZ());
				Point2 = x_right_shoulder_matrix * Point2;
				Point1 = x_right_shoulder_matrix * Point1;
				Point1.Set(Point1.GetX() - 0.1, Point1.GetY() + 0.6, Point1.GetZ());
				Point2.Set(Point2.GetX() - 0.1, Point2.GetY() + 0.6, Point2.GetZ());

				Point1.Set(Point1.GetX() + 0.1, Point1.GetY(), Point1.GetZ() - 0.2);
				Point2.Set(Point2.GetX() + 0.1, Point2.GetY(), Point2.GetZ() - 0.2);
				Point2 = y_right_shoulder_matrix * Point2;
				Point1 = y_right_shoulder_matrix * Point1;
				Point1.Set(Point1.GetX() - 0.1, Point1.GetY(), Point1.GetZ() + 0.2);
				Point2.Set(Point2.GetX() - 0.1, Point2.GetY(), Point2.GetZ() + 0.2);

				//pochylenie brzuch
				Point1.Set(Point1.GetX(), Point1.GetY() - 0.05, Point1.GetZ() - 0.2);
				Point2.Set(Point2.GetX(), Point2.GetY() - 0.05, Point2.GetZ() - 0.2);
				Point2 = x_belly_matrix * Point2;
				Point1 = x_belly_matrix * Point1;
				Point1.Set(Point1.GetX(), Point1.GetY() + 0.05, Point1.GetZ() + 0.2);
				Point2.Set(Point2.GetX(), Point2.GetY() + 0.05, Point2.GetZ() + 0.2);

				Point1.Set(Point1.GetX(), Point1.GetY() - 0.05, Point1.GetZ());
				Point2.Set(Point2.GetX(), Point2.GetY() - 0.05, Point2.GetZ());
				Point2 = y_belly_matrix * Point2;
				Point1 = y_belly_matrix * Point1;
				Point1.Set(Point1.GetX(), Point1.GetY() + 0.05, Point1.GetZ());
				Point2.Set(Point2.GetX(), Point2.GetY() + 0.05, Point2.GetZ());
			}
			//Lewa reka
			if (i == 5)
			{
				Point1.Set(Point1.GetX(), Point1.GetY() - 0.2, Point1.GetZ());
				Point2.Set(Point2.GetX(), Point2.GetY() - 0.2, Point2.GetZ());
				Point2 = left_hand_matrix * Point2;
				Point1 = left_hand_matrix * Point1;
				Point1.Set(Point1.GetX(), Point1.GetY() + 0.2, Point1.GetZ());
				Point2.Set(Point2.GetX(), Point2.GetY() + 0.2, Point2.GetZ());

				Point1.Set(Point1.GetX() - 0.6, Point1.GetY() - 0.5, Point1.GetZ());
				Point2.Set(Point2.GetX() - 0.6, Point2.GetY() - 0.5, Point2.GetZ());
				Point2 = x_left_forearm_matrix * Point2;
				Point1 = x_left_forearm_matrix * Point1;
				Point1.Set(Point1.GetX() + 0.6, Point1.GetY() + 0.5, Point1.GetZ());
				Point2.Set(Point2.GetX() + 0.6, Point2.GetY() + 0.5, Point2.GetZ());

				if (m_sldForearmY->GetValue() < 0)
				{
					Point1.Set(Point1.GetX() - 0.6, Point1.GetY() - 0.5, Point1.GetZ() - 0.4);
					Point2.Set(Point2.GetX() - 0.6, Point2.GetY() - 0.5, Point2.GetZ() - 0.4);
					Point2 = y_left_forearm_matrix * Point2;
					Point1 = y_left_forearm_matrix * Point1;
					Point1.Set(Point1.GetX() + 0.6, Point1.GetY() + 0.5, Point1.GetZ() + 0.4);
					Point2.Set(Point2.GetX() + 0.6, Point2.GetY() + 0.5, Point2.GetZ() + 0.4);
				}
				else
				{
					Point1.Set(Point1.GetX() - 0.6, Point1.GetY() - 0.5, Point1.GetZ());
					Point2.Set(Point2.GetX() - 0.6, Point2.GetY() - 0.5, Point2.GetZ());
					Point2 = y_left_forearm_matrix * Point2;
					Point1 = y_left_forearm_matrix * Point1;
					Point1.Set(Point1.GetX() + 0.6, Point1.GetY() + 0.5, Point1.GetZ());
					Point2.Set(Point2.GetX() + 0.6, Point2.GetY() + 0.5, Point2.GetZ());
				}
				Point1.Set(Point1.GetX() - 0.1, Point1.GetY() - 0.6, Point1.GetZ());
				Point2.Set(Point2.GetX() - 0.1, Point2.GetY() - 0.6, Point2.GetZ());
				Point2 = x_left_shoulder_matrix * Point2;
				Point1 = x_left_shoulder_matrix * Point1;
				Point1.Set(Point1.GetX() + 0.1, Point1.GetY() + 0.6, Point1.GetZ());
				Point2.Set(Point2.GetX() + 0.1, Point2.GetY() + 0.6, Point2.GetZ());

				Point1.Set(Point1.GetX() - 0.1, Point1.GetY(), Point1.GetZ() - 0.2);
				Point2.Set(Point2.GetX() - 0.1, Point2.GetY(), Point2.GetZ() - 0.2);
				Point2 = y_left_shoulder_matrix * Point2;
				Point1 = y_left_shoulder_matrix * Point1;
				Point1.Set(Point1.GetX() + 0.1, Point1.GetY(), Point1.GetZ() + 0.2);
				Point2.Set(Point2.GetX() + 0.1, Point2.GetY(), Point2.GetZ() + 0.2);

				//pochylenie brzuch
				Point1.Set(Point1.GetX(), Point1.GetY() - 0.05, Point1.GetZ() - 0.2);
				Point2.Set(Point2.GetX(), Point2.GetY() - 0.05, Point2.GetZ() - 0.2);
				Point2 = x_belly_matrix * Point2;
				Point1 = x_belly_matrix * Point1;
				Point1.Set(Point1.GetX(), Point1.GetY() + 0.05, Point1.GetZ() + 0.2);
				Point2.Set(Point2.GetX(), Point2.GetY() + 0.05, Point2.GetZ() + 0.2);

				Point1.Set(Point1.GetX(), Point1.GetY() - 0.05, Point1.GetZ());
				Point2.Set(Point2.GetX(), Point2.GetY() - 0.05, Point2.GetZ());
				Point2 = y_belly_matrix * Point2;
				Point1 = y_belly_matrix * Point1;
				Point1.Set(Point1.GetX(), Point1.GetY() + 0.05, Point1.GetZ());
				Point2.Set(Point2.GetX(), Point2.GetY() + 0.05, Point2.GetZ());

			}
			//Prawa reka
			if (i == 6)
			{
				Point1.Set(Point1.GetX(), Point1.GetY() - 0.2, Point1.GetZ());
				Point2.Set(Point2.GetX(), Point2.GetY() - 0.2, Point2.GetZ());
				Point2 = right_hand_matrix * Point2;
				Point1 = right_hand_matrix * Point1;
				Point1.Set(Point1.GetX(), Point1.GetY() + 0.2, Point1.GetZ());
				Point2.Set(Point2.GetX(), Point2.GetY() + 0.2, Point2.GetZ());

				Point1.Set(Point1.GetX() + 0.6, Point1.GetY() - 0.5, Point1.GetZ());
				Point2.Set(Point2.GetX() + 0.6, Point2.GetY() - 0.5, Point2.GetZ());
				Point2 = x_right_forearm_matrix * Point2;
				Point1 = x_right_forearm_matrix * Point1;
				Point1.Set(Point1.GetX() - 0.6, Point1.GetY() + 0.5, Point1.GetZ());
				Point2.Set(Point2.GetX() - 0.6, Point2.GetY() + 0.5, Point2.GetZ());

				if (m_sldForearmY->GetValue() < 0)
				{
					Point1.Set(Point1.GetX() + 0.6, Point1.GetY() - 0.5, Point1.GetZ() - 0.4);
					Point2.Set(Point2.GetX() + 0.6, Point2.GetY() - 0.5, Point2.GetZ() - 0.4);
					Point2 = y_right_forearm_matrix * Point2;
					Point1 = y_right_forearm_matrix * Point1;
					Point1.Set(Point1.GetX() - 0.6, Point1.GetY() + 0.5, Point1.GetZ() + 0.4);
					Point2.Set(Point2.GetX() - 0.6, Point2.GetY() + 0.5, Point2.GetZ() + 0.4);
				}
				else
				{
					Point1.Set(Point1.GetX() + 0.6, Point1.GetY() - 0.5, Point1.GetZ());
					Point2.Set(Point2.GetX() + 0.6, Point2.GetY() - 0.5, Point2.GetZ());
					Point2 = y_right_forearm_matrix * Point2;
					Point1 = y_right_forearm_matrix * Point1;
					Point1.Set(Point1.GetX() - 0.6, Point1.GetY() + 0.5, Point1.GetZ());
					Point2.Set(Point2.GetX() - 0.6, Point2.GetY() + 0.5, Point2.GetZ());
				}

				Point1.Set(Point1.GetX() + 0.1, Point1.GetY() - 0.6, Point1.GetZ());
				Point2.Set(Point2.GetX() + 0.1, Point2.GetY() - 0.6, Point2.GetZ());
				Point2 = x_right_shoulder_matrix * Point2;
				Point1 = x_right_shoulder_matrix * Point1;
				Point1.Set(Point1.GetX() - 0.1, Point1.GetY() + 0.6, Point1.GetZ());
				Point2.Set(Point2.GetX() - 0.1, Point2.GetY() + 0.6, Point2.GetZ());

				Point1.Set(Point1.GetX() + 0.1, Point1.GetY(), Point1.GetZ() - 0.2);
				Point2.Set(Point2.GetX() + 0.1, Point2.GetY(), Point2.GetZ() - 0.2);
				Point2 = y_right_shoulder_matrix * Point2;
				Point1 = y_right_shoulder_matrix * Point1;
				Point1.Set(Point1.GetX() - 0.1, Point1.GetY(), Point1.GetZ() + 0.2);
				Point2.Set(Point2.GetX() - 0.1, Point2.GetY(), Point2.GetZ() + 0.2);

				//pochylenie brzuch
				Point1.Set(Point1.GetX(), Point1.GetY() - 0.05, Point1.GetZ() - 0.2);
				Point2.Set(Point2.GetX(), Point2.GetY() - 0.05, Point2.GetZ() - 0.2);
				Point2 = x_belly_matrix * Point2;
				Point1 = x_belly_matrix * Point1;
				Point1.Set(Point1.GetX(), Point1.GetY() + 0.05, Point1.GetZ() + 0.2);
				Point2.Set(Point2.GetX(), Point2.GetY() + 0.05, Point2.GetZ() + 0.2);

				Point1.Set(Point1.GetX(), Point1.GetY() - 0.05, Point1.GetZ());
				Point2.Set(Point2.GetX(), Point2.GetY() - 0.05, Point2.GetZ());
				Point2 = y_belly_matrix * Point2;
				Point1 = y_belly_matrix * Point1;
				Point1.Set(Point1.GetX(), Point1.GetY() + 0.05, Point1.GetZ());
				Point2.Set(Point2.GetX(), Point2.GetY() + 0.05, Point2.GetZ());
			}
			//Klatka piersiowa
			if (i == 7)
			{
				//pochylenie brzuch
				Point1.Set(Point1.GetX(), Point1.GetY() - 0.05, Point1.GetZ() - 0.2);
				Point2.Set(Point2.GetX(), Point2.GetY() - 0.05, Point2.GetZ() - 0.2);
				Point2 = x_belly_matrix * Point2;
				Point1 = x_belly_matrix * Point1;
				Point1.Set(Point1.GetX(), Point1.GetY() + 0.05, Point1.GetZ() + 0.2);
				Point2.Set(Point2.GetX(), Point2.GetY() + 0.05, Point2.GetZ() + 0.2);

				Point1.Set(Point1.GetX(), Point1.GetY() - 0.05, Point1.GetZ());
				Point2.Set(Point2.GetX(), Point2.GetY() - 0.05, Point2.GetZ());
				Point2 = y_belly_matrix * Point2;
				Point1 = y_belly_matrix * Point1;
				Point1.Set(Point1.GetX(), Point1.GetY() + 0.05, Point1.GetZ());
				Point2.Set(Point2.GetX(), Point2.GetY() + 0.05, Point2.GetZ());

			}
			//Lewe Biodro
			if (i == 9)
			{
				Point1.Set(Point1.GetX() - 0.1, Point1.GetY(), Point1.GetZ() - 0.2);
				Point2.Set(Point2.GetX() - 0.1, Point2.GetY(), Point2.GetZ() - 0.2);
				Point2 = x_left_hip_matrix * Point2;
				Point1 = x_left_hip_matrix * Point1;
				Point1.Set(Point1.GetX() + 0.1, Point1.GetY(), Point1.GetZ() + 0.2);
				Point2.Set(Point2.GetX() + 0.1, Point2.GetY(), Point2.GetZ() + 0.2);

				Point1.Set(Point1.GetX() - 0.1, Point1.GetY() + 0.2, Point1.GetZ());
				Point2.Set(Point2.GetX() - 0.1, Point2.GetY() + 0.2, Point2.GetZ());
				Point2 = y_left_hip_matrix * Point2;
				Point1 = y_left_hip_matrix * Point1;
				Point1.Set(Point1.GetX() + 0.1, Point1.GetY() - 0.2, Point1.GetZ());
				Point2.Set(Point2.GetX() + 0.1, Point2.GetY() - 0.2, Point2.GetZ());

			}
			//Prawe Biodro
			if (i == 10)
			{
				Point1.Set(Point1.GetX() + 0.1, Point1.GetY(), Point1.GetZ() - 0.2);
				Point2.Set(Point2.GetX() + 0.1, Point2.GetY(), Point2.GetZ() - 0.2);
				Point2 = x_right_hip_matrix * Point2;
				Point1 = x_right_hip_matrix * Point1;
				Point1.Set(Point1.GetX() - 0.1, Point1.GetY(), Point1.GetZ() + 0.2);
				Point2.Set(Point2.GetX() - 0.1, Point2.GetY(), Point2.GetZ() + 0.2);

				Point1.Set(Point1.GetX() + 0.1, Point1.GetY() + 0.2, Point1.GetZ());
				Point2.Set(Point2.GetX() + 0.1, Point2.GetY() + 0.2, Point2.GetZ());
				Point2 = y_right_hip_matrix * Point2;
				Point1 = y_right_hip_matrix * Point1;
				Point1.Set(Point1.GetX() - 0.1, Point1.GetY() - 0.2, Point1.GetZ());
				Point2.Set(Point2.GetX() - 0.1, Point2.GetY() - 0.2, Point2.GetZ());
			}
			//Lewe Udo
			if (i == 11)
			{
				Point1.Set(Point1.GetX() - 0.2, Point1.GetY() + 0.3, Point1.GetZ() - 0.2);
				Point2.Set(Point2.GetX() - 0.2, Point2.GetY() + 0.3, Point2.GetZ() - 0.2);
				Point2 = left_thigh_matrix * Point2;
				Point1 = left_thigh_matrix * Point1;
				Point1.Set(Point1.GetX() + 0.2, Point1.GetY() - 0.3, Point1.GetZ() + 0.2);
				Point2.Set(Point2.GetX() + 0.2, Point2.GetY() - 0.3, Point2.GetZ() + 0.2);


				Point1.Set(Point1.GetX() - 0.1, Point1.GetY(), Point1.GetZ() - 0.2);
				Point2.Set(Point2.GetX() - 0.1, Point2.GetY(), Point2.GetZ() - 0.2);
				Point2 = x_left_hip_matrix * Point2;
				Point1 = x_left_hip_matrix * Point1;
				Point1.Set(Point1.GetX() + 0.1, Point1.GetY(), Point1.GetZ() + 0.2);
				Point2.Set(Point2.GetX() + 0.1, Point2.GetY(), Point2.GetZ() + 0.2);

				Point1.Set(Point1.GetX() - 0.1, Point1.GetY() + 0.2, Point1.GetZ());
				Point2.Set(Point2.GetX() - 0.1, Point2.GetY() + 0.2, Point2.GetZ());
				Point2 = y_left_hip_matrix * Point2;
				Point1 = y_left_hip_matrix * Point1;
				Point1.Set(Point1.GetX() + 0.1, Point1.GetY() - 0.2, Point1.GetZ());
				Point2.Set(Point2.GetX() + 0.1, Point2.GetY() - 0.2, Point2.GetZ());
			}
			//Prawe Udo
			if (i == 12)
			{
				Point1.Set(Point1.GetX() + 0.2, Point1.GetY() + 0.3, Point1.GetZ() - 0.2);
				Point2.Set(Point2.GetX() + 0.2, Point2.GetY() + 0.3, Point2.GetZ() - 0.2);
				Point2 = right_thigh_matrix * Point2;
				Point1 = right_thigh_matrix * Point1;
				Point1.Set(Point1.GetX() - 0.2, Point1.GetY() - 0.3, Point1.GetZ() + 0.2);
				Point2.Set(Point2.GetX() - 0.2, Point2.GetY() - 0.3, Point2.GetZ() + 0.2);

				Point1.Set(Point1.GetX() + 0.1, Point1.GetY(), Point1.GetZ() - 0.2);
				Point2.Set(Point2.GetX() + 0.1, Point2.GetY(), Point2.GetZ() - 0.2);
				Point2 = x_right_hip_matrix * Point2;
				Point1 = x_right_hip_matrix * Point1;
				Point1.Set(Point1.GetX() - 0.1, Point1.GetY(), Point1.GetZ() + 0.2);
				Point2.Set(Point2.GetX() - 0.1, Point2.GetY(), Point2.GetZ() + 0.2);

				Point1.Set(Point1.GetX() + 0.1, Point1.GetY() + 0.2, Point1.GetZ());
				Point2.Set(Point2.GetX() + 0.1, Point2.GetY() + 0.2, Point2.GetZ());
				Point2 = y_right_hip_matrix * Point2;
				Point1 = y_right_hip_matrix * Point1;
				Point1.Set(Point1.GetX() - 0.1, Point1.GetY() - 0.2, Point1.GetZ());
				Point2.Set(Point2.GetX() - 0.1, Point2.GetY() - 0.2, Point2.GetZ());
			}
			//Lewa £ydka
			if (i == 13)
			{
				Point1.Set(Point1.GetX() - 0.2, Point1.GetY() + 0.5, Point1.GetZ() - 0.2);
				Point2.Set(Point2.GetX() - 0.2, Point2.GetY() + 0.5, Point2.GetZ() - 0.2);
				Point2 = left_calf_matrix * Point2;
				Point1 = left_calf_matrix * Point1;
				Point1.Set(Point1.GetX() + 0.2, Point1.GetY() - 0.5, Point1.GetZ() + 0.2);
				Point2.Set(Point2.GetX() + 0.2, Point2.GetY() - 0.5, Point2.GetZ() + 0.2);

				Point1.Set(Point1.GetX() - 0.2, Point1.GetY() + 0.3, Point1.GetZ() - 0.2);
				Point2.Set(Point2.GetX() - 0.2, Point2.GetY() + 0.3, Point2.GetZ() - 0.2);
				Point2 = left_thigh_matrix * Point2;
				Point1 = left_thigh_matrix * Point1;
				Point1.Set(Point1.GetX() + 0.2, Point1.GetY() - 0.3, Point1.GetZ() + 0.2);
				Point2.Set(Point2.GetX() + 0.2, Point2.GetY() - 0.3, Point2.GetZ() + 0.2);

				Point1.Set(Point1.GetX() - 0.1, Point1.GetY(), Point1.GetZ() - 0.2);
				Point2.Set(Point2.GetX() - 0.1, Point2.GetY(), Point2.GetZ() - 0.2);
				Point2 = x_left_hip_matrix * Point2;
				Point1 = x_left_hip_matrix * Point1;
				Point1.Set(Point1.GetX() + 0.1, Point1.GetY(), Point1.GetZ() + 0.2);
				Point2.Set(Point2.GetX() + 0.1, Point2.GetY(), Point2.GetZ() + 0.2);

				Point1.Set(Point1.GetX() - 0.1, Point1.GetY() + 0.2, Point1.GetZ());
				Point2.Set(Point2.GetX() - 0.1, Point2.GetY() + 0.2, Point2.GetZ());
				Point2 = y_left_hip_matrix * Point2;
				Point1 = y_left_hip_matrix * Point1;
				Point1.Set(Point1.GetX() + 0.1, Point1.GetY() - 0.2, Point1.GetZ());
				Point2.Set(Point2.GetX() + 0.1, Point2.GetY() - 0.2, Point2.GetZ());
			}
			//Prawa £ydka
			if (i == 14)
			{
				Point1.Set(Point1.GetX() + 0.2, Point1.GetY() + 0.5, Point1.GetZ() - 0.2);
				Point2.Set(Point2.GetX() + 0.2, Point2.GetY() + 0.5, Point2.GetZ() - 0.2);
				Point2 = right_calf_matrix * Point2;
				Point1 = right_calf_matrix * Point1;
				Point1.Set(Point1.GetX() - 0.2, Point1.GetY() - 0.5, Point1.GetZ() + 0.2);
				Point2.Set(Point2.GetX() - 0.2, Point2.GetY() - 0.5, Point2.GetZ() + 0.2);

				Point1.Set(Point1.GetX() + 0.2, Point1.GetY() + 0.3, Point1.GetZ() - 0.2);
				Point2.Set(Point2.GetX() + 0.2, Point2.GetY() + 0.3, Point2.GetZ() - 0.2);
				Point2 = right_thigh_matrix * Point2;
				Point1 = right_thigh_matrix * Point1;
				Point1.Set(Point1.GetX() - 0.2, Point1.GetY() - 0.3, Point1.GetZ() + 0.2);
				Point2.Set(Point2.GetX() - 0.2, Point2.GetY() - 0.3, Point2.GetZ() + 0.2);

				Point1.Set(Point1.GetX() + 0.1, Point1.GetY(), Point1.GetZ() - 0.2);
				Point2.Set(Point2.GetX() + 0.1, Point2.GetY(), Point2.GetZ() - 0.2);
				Point2 = x_right_hip_matrix * Point2;
				Point1 = x_right_hip_matrix * Point1;
				Point1.Set(Point1.GetX() - 0.1, Point1.GetY(), Point1.GetZ() + 0.2);
				Point2.Set(Point2.GetX() - 0.1, Point2.GetY(), Point2.GetZ() + 0.2);

				Point1.Set(Point1.GetX() + 0.1, Point1.GetY() + 0.2, Point1.GetZ());
				Point2.Set(Point2.GetX() + 0.1, Point2.GetY() + 0.2, Point2.GetZ());
				Point2 = y_right_hip_matrix * Point2;
				Point1 = y_right_hip_matrix * Point1;
				Point1.Set(Point1.GetX() - 0.1, Point1.GetY() - 0.2, Point1.GetZ());
				Point2.Set(Point2.GetX() - 0.1, Point2.GetY() - 0.2, Point2.GetZ());
			}

			Point1 = transformation * Point1;
			Point2 = transformation * Point2;
			Normalization(Point1);
			Normalization(Point2);
			if (Point1.GetZ() > -2.0 && Point2.GetZ() <= -2.0 || Point2.GetZ() > -2.0 && Point1.GetZ() <= -2.0)
			{
				Vector4 Temp_Point1 = Point2.GetZ() <= 2.0 ? Point2 : Point1;
				Vector4 Temp_Point2 = Point2.GetZ() <= -2.0 ? Point1 : Point2;
				double ratio = fabs((-2.0 - Temp_Point1.data[2]) / (Temp_Point2.data[2] - Temp_Point1.data[2]));
				Temp_Point1.data[0] = (Temp_Point2.data[0] - Temp_Point1.data[0]) * ratio + Temp_Point1.data[0];
				Temp_Point1.data[1] = (Temp_Point2.data[1] - Temp_Point1.data[1]) * ratio + Temp_Point1.data[1];
				Temp_Point1.data[2] = -2.0;
				Point1 = projection * Temp_Point1;
				Point2 = projection * Temp_Point2;
				Normalization(Point1);
				Normalization(Point2);
			}
			else if (Point1.GetZ() <= -2 && Point2.GetZ() <= -2)
				continue;
			else
			{
				Point1 = projection * Point1;
				Point2 = projection * Point2;
				Normalization(Point1);
				Normalization(Point2);
			}

			buffer.DrawLine(Point1.GetX(), Point1.GetY(), Point2.GetX(), Point2.GetY());
		}
	}
}