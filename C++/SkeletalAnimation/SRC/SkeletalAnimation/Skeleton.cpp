#include "Skeleton.h"

Part::Part(const string& name)
{
	if (name == "head")
	{
		top1.x = -0.1f;
		top1.y = 0.9f;
		top1.z = 0.f;

		top2.x = 0.1f;
		top2.y = 0.9f;
		top2.z = 0.f;

		top3.x = 0.1f;
		top3.y = 0.9f;
		top3.z = 0.4f;

		top4.x = -0.1f;
		top4.y = 0.9f;
		top4.z = 0.4f;

		bot1.x = -0.1f;
		bot1.y = 0.7f;
		bot1.z = 0.f;

		bot2.x = 0.1f;
		bot2.y = 0.7f;
		bot2.z = 0.f;

		bot3.x = 0.1f;
		bot3.y = 0.7f;
		bot3.z = 0.4f;

		bot4.x = -0.1f;
		bot4.y = 0.7f;
		bot4.z = 0.4f;
	}
	else if (name == "chest")
	{
		top1.x = -0.1f;
		top1.y = 0.7f;
		top1.z = 0.f;

		top2.x = 0.1f;
		top2.y = 0.7f;
		top2.z = 0.f;

		top3.x = 0.1f;
		top3.y = 0.7f;
		top3.z = 0.4f;

		top4.x = -0.1f;
		top4.y = 0.7f;
		top4.z = 0.4f;

		bot1.x = -0.1f;
		bot1.y = 0.05f;
		bot1.z = 0.f;

		bot2.x = 0.1f;
		bot2.y = 0.05f;
		bot2.z = 0.f;

		bot3.x = 0.1f;
		bot3.y = 0.05f;
		bot3.z = 0.4f;

		bot4.x = -0.1f;
		bot4.y = 0.05f;
		bot4.z = 0.4f;
	}
	else if (name == "stomach")
	{
		top1.x = -0.1f;
		top1.y = 0.05f;
		top1.z = 0.f;

		top2.x = 0.1f;
		top2.y = 0.05f;
		top2.z = 0.f;

		top3.x = 0.1f;
		top3.y = 0.05f;
		top3.z = 0.4f;

		top4.x = -0.1f;
		top4.y = 0.05f;
		top4.z = 0.4f;

		bot1.x = -0.1f;
		bot1.y = -0.2f;
		bot1.z = 0.f;

		bot2.x = 0.1f;
		bot2.y = -0.2f;
		bot2.z = 0.f;

		bot3.x = 0.1f;
		bot3.y = -0.2f;
		bot3.z = 0.4f;

		bot4.x = -0.1f;
		bot4.y = -0.2f;
		bot4.z = 0.4f;
	}
	
	lines[0].begin = &top1; lines[0].end = &top2;
	lines[1].begin = &top2; lines[1].end = &top3;
	lines[2].begin = &top3; lines[2].end = &top4;
	lines[3].begin = &top4; lines[3].end = &top1;
	lines[4].begin = &top1; lines[4].end = &bot1;
	lines[5].begin = &top2; lines[5].end = &bot2;
	lines[6].begin = &top3; lines[6].end = &bot3;
	lines[7].begin = &top4; lines[7].end = &bot4;
	lines[8].begin = &bot1; lines[8].end = &bot2;
	lines[9].begin = &bot2; lines[9].end = &bot3;
	lines[10].begin = &bot3; lines[10].end = &bot4;
	lines[11].begin = &bot4; lines[11].end = &bot1;
}

Part::Part(const string& name, const string& side)
{
	if (name == "shoulder")
	{
		if (side == "left")
		{
			top1.x = 0.1f;
			top1.y = 0.7f;
			top1.z = 0.f;

			top2.x = 0.6f;
			top2.y = 0.7f;
			top2.z = 0.f;

			top3.x = 0.6f;
			top3.y = 0.7f;
			top3.z = 0.4f;

			top4.x = 0.1f;
			top4.y = 0.7f;
			top4.z = 0.4f;

			bot1.x = 0.1f;
			bot1.y = 0.5f;
			bot1.z = 0.f;

			bot2.x = 0.6f;
			bot2.y = 0.5f;
			bot2.z = 0.f;

			bot3.x = 0.6f;
			bot3.y = 0.5f;
			bot3.z = 0.4f;

			bot4.x = 0.1f;
			bot4.y = 0.5f;
			bot4.z = 0.4f;
		}
		else if (side == "right")
		{
			top1.x = -0.1f;
			top1.y = 0.7f;
			top1.z = 0.f;

			top2.x = -0.6f;
			top2.y = 0.7f;
			top2.z = 0.f;

			top3.x = -0.6f;
			top3.y = 0.7f;
			top3.z = 0.4f;

			top4.x = -0.1f;
			top4.y = 0.7f;
			top4.z = 0.4f;

			bot1.x = -0.1f;
			bot1.y = 0.5f;
			bot1.z = 0.f;

			bot2.x = -0.6f;
			bot2.y = 0.5f;
			bot2.z = 0.f;

			bot3.x = -0.6f;
			bot3.y = 0.5f;
			bot3.z = 0.4f;

			bot4.x = -0.1f;
			bot4.y = 0.5f;
			bot4.z = 0.4f;
		}
	}
	else if (name == "forearm")
	{
		if (side == "left")
		{
			top1.x = 0.4f;
			top1.y = 0.5f;
			top1.z = 0.f;

			top2.x = 0.6f;
			top2.y = 0.5f;
			top2.z = 0.f;

			top3.x = 0.6f;
			top3.y = 0.5f;
			top3.z = 0.4f;

			top4.x = 0.4f;
			top4.y = 0.5f;
			top4.z = 0.4f;

			bot1.x = 0.4f;
			bot1.y = 0.2f;
			bot1.z = 0.f;

			bot2.x = 0.6f;
			bot2.y = 0.2f;
			bot2.z = 0.f;

			bot3.x = 0.6f;
			bot3.y = 0.2f;
			bot3.z = 0.4f;

			bot4.x = 0.4f;
			bot4.y = 0.2f;
			bot4.z = 0.4f;
		}
		else if (side == "right")
		{
			top1.x = -0.4f;
			top1.y = 0.5f;
			top1.z = 0.f;

			top2.x = -0.6f;
			top2.y = 0.5f;
			top2.z = 0.f;

			top3.x = -0.6f;
			top3.y = 0.5f;
			top3.z = 0.4f;

			top4.x = -0.4f;
			top4.y = 0.5f;
			top4.z = 0.4f;

			bot1.x = -0.4f;
			bot1.y = 0.2f;
			bot1.z = 0.f;

			bot2.x = -0.6f;
			bot2.y = 0.2f;
			bot2.z = 0.f;

			bot3.x = -0.6f;
			bot3.y = 0.2f;
			bot3.z = 0.4f;

			bot4.x = -0.4f;
			bot4.y = 0.2f;
			bot4.z = 0.4f;
		}
	}
	else if (name == "arm")
	{
		if (side == "left")
		{
			top1.x = 0.4f;
			top1.y = 0.2f;
			top1.z = 0.f;

			top2.x = 0.6f;
			top2.y = 0.2f;
			top2.z = 0.f;

			top3.x = 0.6f;
			top3.y = 0.2f;
			top3.z = 0.4f;

			top4.x = 0.4f;
			top4.y = 0.2f;
			top4.z = 0.4f;

			bot1.x = 0.4f;
			bot1.y = -0.1f;
			bot1.z = 0.f;

			bot2.x = 0.6f;
			bot2.y = -0.1f;
			bot2.z = 0.f;

			bot3.x = 0.6f;
			bot3.y = -0.1f;
			bot3.z = 0.4f;

			bot4.x = 0.4f;
			bot4.y = -0.1f;
			bot4.z = 0.4f;
		}
		else if (side == "right")
		{
			top1.x = -0.4f;
			top1.y = 0.2f;
			top1.z = 0.f;

			top2.x = -0.6f;
			top2.y = 0.2f;
			top2.z = 0.f;

			top3.x = -0.6f;
			top3.y = 0.2f;
			top3.z = 0.4f;

			top4.x = -0.4f;
			top4.y = 0.2f;
			top4.z = 0.4f;

			bot1.x = -0.4f;
			bot1.y = -0.1f;
			bot1.z = 0.f;

			bot2.x = -0.6f;
			bot2.y = -0.1f;
			bot2.z = 0.f;

			bot3.x = -0.6f;
			bot3.y = -0.1f;
			bot3.z = 0.4f;

			bot4.x = -0.4f;
			bot4.y = -0.1f;
			bot4.z = 0.4f;
		}
	}
	else if (name == "hip")
	{
		if (side == "left")
		{
			top1.x = 0.1f;
			top1.y = -0.1f;
			top1.z = 0.f;

			top2.x = 0.3f;
			top2.y = -0.1f;
			top2.z = 0.f;

			top3.x = 0.3f;
			top3.y = -0.1f;
			top3.z = 0.4f;

			top4.x = 0.1f;
			top4.y = -0.1f;
			top4.z = 0.4f;

			bot1.x = 0.1f;
			bot1.y = -0.3f;
			bot1.z = 0.f;

			bot2.x = 0.3f;
			bot2.y = -0.3f;
			bot2.z = 0.f;

			bot3.x = 0.3f;
			bot3.y = -0.3f;
			bot3.z = 0.4f;

			bot4.x = 0.1f;
			bot4.y = -0.3f;
			bot4.z = 0.4f;
		}
		else if(side == "right")
		{
			top1.x = -0.1f;
			top1.y = -0.1f;
			top1.z = 0.f;

			top2.x = -0.3f;
			top2.y = -0.1f;
			top2.z = 0.f;

			top3.x = -0.3f;
			top3.y = -0.1f;
			top3.z = 0.4f;

			top4.x = -0.1f;
			top4.y = -0.1f;
			top4.z = 0.4f;

			bot1.x = -0.1f;
			bot1.y = -0.3f;
			bot1.z = 0.f;

			bot2.x = -0.3f;
			bot2.y = -0.3f;
			bot2.z = 0.f;

			bot3.x = -0.3f;
			bot3.y = -0.3f;
			bot3.z = 0.4f;

			bot4.x = -0.1f;
			bot4.y = -0.3f;
			bot4.z = 0.4f;
		}
	}
	else if (name == "thigh")
	{
		if (side == "left")
		{
			top1.x = 0.2f;
			top1.y = -0.3f;
			top1.z = 0.f;

			top2.x = 0.4f;
			top2.y = -0.3f;
			top2.z = 0.f;

			top3.x = 0.4f;
			top3.y = -0.3f;
			top3.z = 0.4f;

			top4.x = 0.2f;
			top4.y = -0.3f;
			top4.z = 0.4f;

			bot1.x = 0.2f;
			bot1.y = -0.6f;
			bot1.z = 0.f;

			bot2.x = 0.4f;
			bot2.y = -0.6f;
			bot2.z = 0.f;

			bot3.x = 0.4f;
			bot3.y = -0.6f;
			bot3.z = 0.4f;

			bot4.x = 0.2f;
			bot4.y = -0.6f;
			bot4.z = 0.4f;
		}
		else if (side == "right")
		{
			top1.x = -0.2f;
			top1.y = -0.3f;
			top1.z = 0.f;

			top2.x = -0.4f;
			top2.y = -0.3f;
			top2.z = 0.f;

			top3.x = -0.4f;
			top3.y = -0.3f;
			top3.z = 0.4f;

			top4.x = -0.2f;
			top4.y = -0.3f;
			top4.z = 0.4f;

			bot1.x = -0.2f;
			bot1.y = -0.6f;
			bot1.z = 0.f;

			bot2.x = -0.4f;
			bot2.y = -0.6f;
			bot2.z = 0.f;

			bot3.x = -0.4f;
			bot3.y = -0.6f;
			bot3.z = 0.4f;

			bot4.x = -0.2f;
			bot4.y = -0.6f;
			bot4.z = 0.4f;
		}
	}
	else if (name == "calf")
	{
		if (side == "left")
		{
			top1.x = 0.2f;
			top1.y = -0.6f;
			top1.z = 0.f;

			top2.x = 0.4f;
			top2.y = -0.6f;
			top2.z = 0.f;

			top3.x = 0.4f;
			top3.y = -0.6f;
			top3.z = 0.4f;

			top4.x = 0.2f;
			top4.y = -0.6f;
			top4.z = 0.4f;

			bot1.x = 0.2f;
			bot1.y = -0.9f;
			bot1.z = 0.f;

			bot2.x = 0.4f;
			bot2.y = -0.9f;
			bot2.z = 0.f;

			bot3.x = 0.4f;
			bot3.y = -0.9f;
			bot3.z = 0.4f;

			bot4.x = 0.2f;
			bot4.y = -0.9f;
			bot4.z = 0.4f;
		}
		else if (side == "right")
		{
			top1.x = -0.2f;
			top1.y = -0.6f;
			top1.z = 0.f;

			top2.x = -0.4f;
			top2.y = -0.6f;
			top2.z = 0.f;

			top3.x = -0.4f;
			top3.y = -0.6f;
			top3.z = 0.4f;

			top4.x = -0.2f;
			top4.y = -0.6f;
			top4.z = 0.4f;

			bot1.x = -0.2f;
			bot1.y = -0.9f;
			bot1.z = 0.f;

			bot2.x = -0.4f;
			bot2.y = -0.9f;
			bot2.z = 0.f;

			bot3.x = -0.4f;
			bot3.y = -0.9f;
			bot3.z = 0.4f;

			bot4.x = -0.2f;
			bot4.y = -0.9f;
			bot4.z = 0.4f;
		}
	}

	lines[0].begin = &top1; lines[0].end = &top2;
	lines[1].begin = &top2; lines[1].end = &top3;
	lines[2].begin = &top3; lines[2].end = &top4;
	lines[3].begin = &top4; lines[3].end = &top1;
	lines[4].begin = &top1; lines[4].end = &bot1;
	lines[5].begin = &top2; lines[5].end = &bot2;
	lines[6].begin = &top3; lines[6].end = &bot3;
	lines[7].begin = &top4; lines[7].end = &bot4;
	lines[8].begin = &bot1; lines[8].end = &bot2;
	lines[9].begin = &bot2; lines[9].end = &bot3;
	lines[10].begin = &bot3; lines[10].end = &bot4;
	lines[11].begin = &bot4; lines[11].end = &bot1;
}

Skeleton::Skeleton()
{
	head = new Part("head");
	left_shoulder = new Part("shoulder","left");
	right_shoulder = new Part("shoulder", "right");
	left_forearm = new Part("forearm", "left");
	right_forearm = new Part("forearm", "right");
	left_arm = new Part("arm", "left");
	right_arm = new Part("arm", "right");
	chest = new Part("chest");
	stomach = new Part("stomach");
	left_hip = new Part("hip", "left");
	right_hip = new Part("hip", "right");
	left_thigh = new Part("thigh", "left");
	right_thigh = new Part("thigh", "right");
	left_calf = new Part("calf", "left");
	right_calf = new Part("calf", "right");
}
Skeleton::~Skeleton()
{
	delete head;
	delete left_shoulder;
	delete right_shoulder;
	delete left_forearm;
	delete right_forearm;
	delete left_arm;
	delete right_arm;
	delete chest;
	delete stomach;
	delete left_hip;
	delete right_hip;
	delete left_thigh;
	delete right_thigh;
	delete left_calf;
	delete right_calf;
}


