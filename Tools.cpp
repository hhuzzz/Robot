#include "AllHead.h"

int InputBox()   //�������û�����
{
	// �����ַ������������������û�����
	TCHAR s[] = _T("��ӭ��1�����谴2");
	TCHAR a[10];   //�����洢������ַ���
	InputBox(a, 10, s);

	// ���û�����ת��Ϊ����
	int r;
	sscanf(a, "%d", &r);
	return r;
}

void ButtonMusic()
{
	mciSendString(_T("open E:\\VS����\\���������\\���������\\button.mp3"), NULL, 0, NULL);
	mciSendString(_T("play E:\\VS����\\���������\\���������\\button.mp3"), NULL, 0, NULL);
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
	settextstyle(40, 0, _T("����"));
	setbkmode(TRANSPARENT);   //�������ֱ���Ϊ͸��
	outtextxy(50, 30, s1);
	outtextxy(50, 150, s2);
	outtextxy(50, 270, s3);

	//���Ʒ��ذ�ť
	POINT pts[] = { {520,370},{520,480},{580,425} };
	setfillcolor(GREEN);
	solidrectangle(400, 400, 520, 450);
	solidpolygon(pts, 3);

	//���÷��ذ�ť�Ĺ���
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
			ButtonMusic();   //����ʱ��������
			closegraph();   //�ر�Ŀǰ���ڣ����³�ʼ��
			goto A;
		}
	}
A:r->Init2();
}