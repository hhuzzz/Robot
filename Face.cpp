#include "Face.h"
#include<graphics.h>

void Face::DrawFace()
{
	//���۾�
	setlinestyle(PS_SOLID, 3);
	setfillcolor(BLACK);
	circle(275, 160, 10);   //������Ȧ
	solidcircle(275, 160, 5);   //��������
	circle(325, 160, 10);   //������Ȧ
	solidcircle(325, 160, 5);   //��������
	
	
	line(300, 180, 300, 190);   //������

	line(295, 210, 305, 210);   //�����
}
