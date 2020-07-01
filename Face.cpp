#include "Face.h"
#include<graphics.h>

void Face::DrawFace()
{
	//ª≠—€æ¶
	setlinestyle(PS_SOLID, 3);
	setfillcolor(BLACK);
	circle(275, 160, 10);   //ª≠◊Û—€»¶
	solidcircle(275, 160, 5);   //ª≠◊Û—€÷È
	circle(325, 160, 10);   //ª≠”“—€»¶
	solidcircle(325, 160, 5);   //ª≠”“—€÷È
	
	
	line(300, 180, 300, 190);   //ª≠±«◊”

	line(295, 210, 305, 210);   //ª≠◊Ï∞Õ
}
