#pragma once

typedef struct _point {
	int xpos;
	int ypos;
}Point;

void SetPointPos(Point* ppos, int xpos, int ypos);
void ShowPointPos(Point* ppos);
int PointCmp(Point* pos1, Point* pos2);