#include "AllHead.h"

int InputBox()   //用来与用户交互
{
	// 定义字符串缓冲区，并接收用户输入
	TCHAR s[] = _T("欢迎按1，跳舞按2");
	TCHAR a[10];   //用来存储输入的字符串
	InputBox(a, 10, s);

	// 将用户输入转换为数字
	int r;
	sscanf(a, "%d", &r);
	return r;
}

void ButtonMusic()
{
	mciSendString(_T("open E:\\VS代码\\仿真机器人\\仿真机器人\\button.mp3"), NULL, 0, NULL);
	mciSendString(_T("play E:\\VS代码\\仿真机器人\\仿真机器人\\button.mp3"), NULL, 0, NULL);
}

void CheckButton(MOUSEMSG m,Robot* r)
{
	TCHAR s[] = _T("Welcome");
	m = GetMouseMsg();
	if (m.uMsg == WM_LBUTTONDOWN && m.x > 50 && m.x < 250 && m.y>30 && m.y < 100)
	{
		ButtonMusic();
		//r->Welcome();
	}
	if (m.uMsg == WM_LBUTTONDOWN && m.x > 350 && m.x < 550 && m.y>30 && m.y < 100)
	{
		ButtonMusic();
		//r->Dance();
	}
}

void DrawAbout(Robot* r)
{
	TCHAR s1[] = _T( "Welcome press 1" );
	TCHAR s2[] = _T( "Dance press 2" );
	TCHAR s3[] = _T("Developed by HuHuan");
	settextstyle(40, 0, _T("宋体"));
	setbkmode(TRANSPARENT);   //设置文字背景为透明
	outtextxy(50, 30, s1);
	outtextxy(50, 150, s2);
	outtextxy(50, 270, s3);

	//绘制返回按钮
	POINT pts[] = { {520,370},{520,480},{580,425} };
	setfillcolor(GREEN);
	solidrectangle(400, 400, 520, 450);
	solidpolygon(pts, 3);

	//设置返回按钮的功能
	Back(r);
}

void Back(Robot* r)
{
	MOUSEMSG m;;
	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN && m.x > 400 && m.x < 580 && m.y>370 && m.y < 480)
		{
			ButtonMusic();   //按键时发出声音
			closegraph();   //关闭目前窗口，重新初始化
			goto A;
		}
	}
A:r->Init2();
}