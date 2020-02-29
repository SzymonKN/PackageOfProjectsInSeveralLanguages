#pragma once
#include "MainFrame.h"
#include "Skeleton.h"
#include "Vecmath.h"
#include <wx/dcbuffer.h>

class GUIMainFrame: public MainFrame
{
public:
	GUIMainFrame();
	~GUIMainFrame() = default;

	void Normalization(Vector4& vector);
	void Projection(Matrix4& matrix);
	void Transformation(Matrix4& matrix);
	void DrawSkeleton();
	void MoveHand(Matrix4& matrix);
	void MoveForearmX(Matrix4& matrix);
	void MoveForearmY(Matrix4& matrix);
	void MoveHeadX(Matrix4& matrix);
	void MoveHeadY(Matrix4& matrix);
	void MoveHeadZ(Matrix4& matrix);
	void MoveShoulderX(Matrix4& matrix);
	void MoveShoulderY(Matrix4& matrix);
	void MoveBellyX(Matrix4& matrix);
	void MoveBellyY(Matrix4& matrix);
	void MoveHipX(Matrix4& matrix);
	void MoveHipY(Matrix4& matrix);
	void MoveThigh(Matrix4& matrix);
	void MoveCalf(Matrix4& matrix);

private:
	void WxPanel_Repaint(wxUpdateUIEvent& event);

	Matrix4 left_hand_matrix;
	Matrix4 right_hand_matrix;

	Matrix4 x_left_forearm_matrix;
	Matrix4 y_left_forearm_matrix;

	Matrix4 x_right_forearm_matrix;
	Matrix4 y_right_forearm_matrix;

	Matrix4 x_belly_matrix;
	Matrix4 y_belly_matrix;

	Matrix4 x_head_matrix;
	Matrix4 y_head_matrix;
	Matrix4 z_head_matrix;

	Matrix4 x_left_shoulder_matrix;
	Matrix4 y_left_shoulder_matrix;
	Matrix4 x_right_shoulder_matrix;
	Matrix4 y_right_shoulder_matrix;

	Matrix4 x_left_hip_matrix;
	Matrix4 y_left_hip_matrix;
	Matrix4 x_right_hip_matrix;
	Matrix4 y_right_hip_matrix;

	Matrix4 left_thigh_matrix;
	Matrix4 right_thigh_matrix;

	Matrix4 left_calf_matrix;
	Matrix4 right_calf_matrix;

	Skeleton skeleton;
};