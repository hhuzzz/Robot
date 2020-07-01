#include "AllHead.h"

void Robot::Init()    //�����ʼ��
{
	TCHAR s[] = _T("Welcome");
	TCHAR r[] = _T("About");
	MessageBox(NULL, TEXT("��ã��ҽв���ġ�"), TEXT("��ӭ"), MB_OK);
	int rel = MessageBox(NULL, TEXT("�Ƿ�Ҫ��������"), TEXT("��ӭ"), MB_YESNO);
	if (rel == IDYES)
	{
		initgraph(600, 480);
		setbkcolor(RGB(96, 96, 96));
		cleardevice();
		MOUSEMSG m;
		settextcolor(RED);
		settextstyle(64, 0, _T("Consolas"));
		outtextxy(200, 100, s);   //��ӡWelcome
		outtextxy(200, 300, r);   //��ӡAbout
		while (1)
		{
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONDOWN && m.x > 200 && m.x < 400 && m.y>100 && m.y < 160)
			{
				ButtonMusic();
				cleardevice();
				loadimage(NULL, _T("E:\\VS����\\���������\\���������\\beijing.jpg"));
				this->DrawRobot();   //��������
	A:			this->flag = InputBox();
				if (this->flag == 1)
				{
					this->Welcome();
				}
				else if (this->flag == 2)
				{
					this->Dance();
				}
				else
				{
					int flag = MessageBox(NULL, TEXT("���ü�������1��2"), TEXT("������ʾ"), MB_OK);
					if (flag == IDOK)
						goto A;

				}
				
			}
			if (m.uMsg == WM_LBUTTONDOWN && m.x > 200 && m.x < 400 && m.y>300 && m.y < 360)
			{
				ButtonMusic();
				setbkcolor(RGB(96, 96, 96));
				cleardevice();
				DrawAbout(this);
			}
		}
	}
	else
	{
		MessageBox(NULL, TEXT("�ðɣ��ټ���"), TEXT("�˳�"), MB_OK);
		return;
	}
}

void Robot::DrawRobot()
{
	setfillcolor(RGB(108,108,108));   //��ͷ
	solidroundrect(250, 140, 350, 220, 30, 30);

	setfillcolor(WHITE);   //������
	solidrectangle(290, 220, 310, 240);

	setfillcolor(BLUE);   //������
	solidrectangle(250, 240, 350, 350);

	setlinecolor(BLACK);   //����
	setlinestyle(PS_SOLID| PS_ENDCAP_FLAT, 10);
	line(270, 350, 270, 460);
	line(330, 350, 330, 460);

    POINT ptr1[] = { {270,460},{260,480},{280,480} };   //����
	POINT ptr2[] = { {330,460},{320,480},{340,480} };
	solidpolygon(ptr1, 3);
	solidpolygon(ptr2, 3);

	setlinecolor(BLACK);   //���ֱ�
	setlinestyle(PS_SOLID, 5);
	line(250, 240, 230, 330);
	line(350, 240, 370, 330);
	setbkcolor(BLACK);
	solidcircle(229, 334, 10);
	solidcircle(371, 334, 10);

	this->DrawFace();   //�����ϵĲ���
}


void Robot::Music()   //�������ֺ���
{
	mciSendString(_T("open E:\\VS����\\���������\\���������\\Avengers.mp3"), NULL, 0, NULL);  //���豸
	mciSendString(_T("play E:\\VS����\\���������\\���������\\Avengers.mp3"), NULL, 0, NULL);  //��������
}

void Robot::Welcome()   //��ӭ����
{
	double r = 96.3;   //�ֱ۳��ȣ���ǰ�Ѿ����
	IMAGE img,img2;
	this->Init3();
	getimage(&img, 0, 0, 600, 480);

	mciSendString("close E:\\VS����\\���������\\���������\\Avengers.mp3", NULL, 0, NULL);   //�ر�ԭBGM

	putimage(0, 0, &img);
	setbkcolor(RGB(108, 108, 108));   //����һ�±�����ɫ������Ĩȥԭ�ȱ���
	clearrectangle(295, 200, 305, 220);   //Ĩȥ��ǰ���
	clearrectangle(264, 149, 336, 171);   //Ĩȥ�����۾�
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 3);
	arc(290, 200, 310, 210, pi, 2 * pi);   //��Ц��
	//��Ц��
	line(265, 150, 275, 160);
	line(275, 160, 265, 170);
	line(335, 150, 325, 160);
	line(325, 160, 335, 170);
	getimage(&img2, 0, 0, 600, 480);

	setorigin(350, 240);   //��������ԭ��Ϊ�ֱ۵�һ��
	//���û��ֱ��ߵ���ʽ
	setlinecolor(BLACK);  
	setlinestyle(PS_SOLID, 5);
	setfillcolor(BLUE);
	BeginBatchDraw();   //��ʼ������ͼ
	for (double cita = 4 * pi / 9; cita >= (-pi/4); cita -= pi / 90)
	{
		cleardevice();
		putimage(-350, -240, &img2);
		line(0, 0, r*cos(cita), (r*sin(cita)));   //���ֱ�
		solidcircle(r*cos(cita), (r*sin(cita)), 10);   //����
		Sleep(50);
		FlushBatchDraw();
	}
	EndBatchDraw();   //����������ͼ

	//�û�����˵���
	mciSendString("open E:\\VS����\\���������\\���������\\nihao.mp3", NULL, 0, NULL);
	mciSendString("play E:\\VS����\\���������\\���������\\nihao.mp3", NULL, 0, NULL);

	Sleep(3000);   //�ȴ�3s
	this->Init2();   //�ص���ʼ����
}

void Robot::Dance()   //���躯��
{
	mciSendString("close E:\\VS����\\���������\\���������\\Avengers.mp3", NULL, 0, NULL);   //�ر�ԭBGM
	mciSendString("open E:\\VS����\\���������\\���������\\dance.mp3", NULL, 0, NULL);
	mciSendString("play E:\\VS����\\���������\\���������\\dance.mp3", NULL, 0, NULL);
	Sleep(3000);

	double r = 96.3;   //�ֱ۳��ȣ���ǰ�Ѿ����
	IMAGE img1, img2;
	this->Init4();
	getimage(&img1, 0, 0, 600, 480);   //�õ�ͼƬ
	
	putimage(0, 0, &img1);
	setbkcolor(RGB(108, 108, 108));   //����һ�±�����ɫ������Ĩȥԭ�ȱ���
	clearrectangle(295, 200, 305, 220);   //Ĩȥ��ǰ���
	clearrectangle(264, 149, 336, 171);   //Ĩȥ�����۾�
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 3);
	arc(290, 200, 310, 210, pi, 2 * pi);   //��Ц��
	//��Ц��
	line(265, 150, 275, 160);
	line(275, 160, 265, 170);
	line(335, 150, 325, 160);
	line(325, 160, 335, 170);
	getimage(&img1, 0, 0, 600, 480);

	setorigin(350, 240);   //��������ԭ��Ϊ�ֱ۵�һ��
	//���û��ֱ��ߵ���ʽ
	setlinecolor(BLACK);
	setfillcolor(BLUE);
	double l,cita;
	BeginBatchDraw();   //��ʼ������ͼ
	for (cita = 4 * pi / 9,l=0; cita >= 0,l<=110; cita -= pi / 90,l+=2.75)
	{
		setlinestyle(PS_SOLID, 5);   //�����ߵ���ʽ
		cleardevice();
		putimage(-350, -240, &img1);
		line(0, 0, r*cos(cita), (r*sin(cita)));   //���ֱ�
		solidcircle(r*cos(cita), (r*sin(cita)), 10);   //����

		setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 10);
		line(-80, 110, -80, 220 - l);
		int* a = new int[6];   //������6��������int������
		a[0] = -80;
		a[1] = 220 - l;
		a[2] = -90;
		a[3] = 240 - l;
		a[4] = -70;
		a[5] = 240 - l;
		solidpolygon((POINT*)a, 3);
		delete[]a;
		Sleep(50);
		FlushBatchDraw();
	}
	for (cita = 0, l = 0; cita <= 4 * pi / 9, l <= 110; cita += pi / 90, l += 2.75)
	{
		setlinestyle(PS_SOLID, 5);   //�����ߵ���ʽ
		cleardevice();
		putimage(-350, -240, &img1);
		line(0, 0, r*cos(cita), (r*sin(cita)));   //���ֱ�
		solidcircle(r*cos(cita), (r*sin(cita)), 10);   //����

		setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 10);
		line(-80, 110, -80, 110 + l);
		int* a = new int[6];   //������6��������int������
		a[0] = -80;
		a[1] = 110 + l;
		a[2] = -90;
		a[3] = 130 + l;
		a[4] = -70;
		a[5] = 130 + l;
		solidpolygon((POINT*)a, 3);
		delete[]a;
		Sleep(50);
		FlushBatchDraw();
	}

	setorigin(-350, -240);   //������ԭ��Ż����Ͻ�
	this->Init5();
	getimage(&img2, 0, 0, 600, 480);

	putimage(0, 0, &img2);
	setbkcolor(RGB(108, 108, 108));   //����һ�±�����ɫ������Ĩȥԭ�ȱ���
	clearrectangle(295, 200, 305, 220);   //Ĩȥ��ǰ���
	clearrectangle(264, 149, 336, 171);   //Ĩȥ�����۾�
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 3);
	arc(290, 200, 310, 210, pi, 2 * pi);   //��Ц��
	//��Ц��
	line(265, 150, 275, 160);
	line(275, 160, 265, 170);
	line(335, 150, 325, 160);
	line(325, 160, 335, 170);
	getimage(&img2, 0, 0, 600, 480);
	setorigin(250, 240);   //��������Ϊ�ֱ۵�һ��
	setaspectratio(-1, 1);   //�ı������᷽��ʹ����Ĵ����ܸ���

	//���û��ֱ��ߵ���ʽ
	setlinecolor(BLACK);
	setfillcolor(BLUE);
	for (cita = 4 * pi / 9, l = 0; cita >= 0, l <= 110; cita -= pi / 90, l += 2.75)
	{
		setlinestyle(PS_SOLID, 5);   //�����ߵ���ʽ
		cleardevice();
		putimage(-350, -240, &img1);
		line(0, 0, r*cos(cita), (r*sin(cita)));   //���ֱ�
		solidcircle(r*cos(cita), (r*sin(cita)), 10);   //����

		setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 10);
		line(-80, 110, -80, 220 - l);
		int* a = new int[6];   //������6��������int������
		a[0] = -80;
		a[1] = 220 - l;
		a[2] = -90;
		a[3] = 240 - l;
		a[4] = -70;
		a[5] = 240 - l;
		solidpolygon((POINT*)a, 3);
		delete[]a;
		Sleep(50);
		FlushBatchDraw();
	}
	for (cita = 0, l = 0; cita <= 4 * pi / 9, l <= 110; cita += pi / 90, l += 2.75)
	{
		setlinestyle(PS_SOLID, 5);   //�����ߵ���ʽ
		cleardevice();
		putimage(-350, -240, &img1);
		line(0, 0, r*cos(cita), (r*sin(cita)));   //���ֱ�
		solidcircle(r*cos(cita), (r*sin(cita)), 10);   //����

		setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 10);
		line(-80, 110, -80, 110 + l);
		int* a = new int[6];   //������6��������int������
		a[0] = -80;
		a[1] = 110 + l;
		a[2] = -90;
		a[3] = 130 + l;
		a[4] = -70;
		a[5] = 130 + l;
		solidpolygon((POINT*)a, 3);
		delete[]a;
		Sleep(50);
		FlushBatchDraw();
	}
	EndBatchDraw();   //����������ͼ

	mciSendString(_T("open E:\\VS����\\���������\\���������\\question.mp3"), NULL, 0, NULL);  //���豸
	mciSendString(_T("play E:\\VS����\\���������\\���������\\question.mp3"), NULL, 0, NULL);  //��������
	int flag = MessageBox(NULL, TEXT("�����������զ��"), TEXT("����"), MB_YESNO);
	if (flag == IDYES)
	{
		mciSendString(_T("open E:\\VS����\\���������\\���������\\answer1.mp3"), NULL, 0, NULL);  //���豸
		mciSendString(_T("play E:\\VS����\\���������\\���������\\answer1.mp3"), NULL, 0, NULL);  //��������
	}
	if (flag == IDNO)
	{
		mciSendString(_T("open E:\\VS����\\���������\\���������\\answer2.mp3"), NULL, 0, NULL);  //���豸
		mciSendString(_T("play E:\\VS����\\���������\\���������\\answer2.mp3"), NULL, 0, NULL);  //��������
	}

	Sleep(3000);   //�ȴ�����
	this->Init2();   //�ص���ʼ����
}

void Robot::Init2()   //���ú���
{
	TCHAR s[] = _T("Welcome");
	TCHAR r[] = _T("About");
	initgraph(600, 480);
	setbkcolor(RGB(96, 96, 96));
	cleardevice();
	MOUSEMSG m;
	settextcolor(RED);
	settextstyle(64, 0, _T("Consolas"));
	outtextxy(200, 100, s);   //��ӡwelcome
	outtextxy(200, 300, r);   //��ӡAbout
	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN && m.x > 200 && m.x < 400 && m.y>100 && m.y < 160)
		{
			ButtonMusic();
			cleardevice();
			loadimage(NULL, _T("E:\\VS����\\���������\\���������\\beijing.jpg"));
			this->DrawRobot();   //��������
			this->flag = InputBox();
			if (this->flag == 1)
			{
				this->Welcome();
			}
			if (this->flag == 2)
			{
				this->Dance();
			}
			//this->Blink();    //գ��
		}
		if (m.uMsg == WM_LBUTTONDOWN && m.x > 200 && m.x < 400 && m.y>300 && m.y < 360)
		{
			ButtonMusic();
			setbkcolor(RGB(96, 96, 96));
			cleardevice();
			DrawAbout(this);
		}
	}
}

void Robot::Init3()   //���ú����������õ�û�����ֱ۵Ļ�����
{
	initgraph(600, 480);
	setbkcolor(RGB(96, 96, 96));
	loadimage(NULL, _T("E:\\VS����\\���������\\���������\\beijing.jpg"));
	setfillcolor(RGB(108, 108, 108));   //��ͷ
	solidroundrect(250, 140, 350, 220, 30, 30);

	setfillcolor(WHITE);   //������
	solidrectangle(290, 220, 310, 240);

	setfillcolor(BLUE);   //������
	solidrectangle(250, 240, 350, 350);

	setlinecolor(BLACK);   //����
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 10);
	line(270, 350, 270, 460);
	line(330, 350, 330, 460);

	POINT ptr1[] = { {270,460},{260,480},{280,480} };   //����
	POINT ptr2[] = { {330,460},{320,480},{340,480} };
	solidpolygon(ptr1, 3);
	solidpolygon(ptr2, 3);

	setlinecolor(BLACK);   //���ֱ�
	setlinestyle(PS_SOLID, 5);
	line(250, 240, 230, 330);
	setfillcolor(BLUE);
	solidcircle(229, 334, 10);

	this->DrawFace();   //�����ϵĲ���
}

void Robot::Init4()   //���ú����������õ�û�����ֱۺ���ŵĻ�����
{
	initgraph(600, 480);
	setbkcolor(RGB(96, 96, 96));
	loadimage(NULL, _T("E:\\VS����\\���������\\���������\\beijing.jpg"));
	setfillcolor(RGB(108, 108, 108));   //��ͷ
	solidroundrect(250, 140, 350, 220, 30, 30);

	setfillcolor(WHITE);   //������
	solidrectangle(290, 220, 310, 240);

	setfillcolor(BLUE);   //������
	solidrectangle(250, 240, 350, 350);

	setlinecolor(BLACK);   //����
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 10);
	line(330, 350, 330, 460);

	POINT ptr2[] = { {330,460},{320,480},{340,480} };   //����
	solidpolygon(ptr2, 3);

	setlinecolor(BLACK);   //���ֱ�
	setlinestyle(PS_SOLID, 5);
	line(250, 240, 230, 330);
	setfillcolor(BLUE);
	solidcircle(229, 334, 10);

	this->DrawFace();   //�����ϵĲ���
}

void Robot::Init5()   //���ú����������õ�û�����ֱۺ��ҽŵĻ�����
{
	initgraph(600, 480);
	setbkcolor(RGB(96, 96, 96));
	loadimage(NULL, _T("E:\\VS����\\���������\\���������\\beijing.jpg"));

	setfillcolor(RGB(108, 108, 108));   //��ͷ
	solidroundrect(250, 140, 350, 220, 30, 30);

	setfillcolor(WHITE);   //������
	solidrectangle(290, 220, 310, 240);

	setfillcolor(BLUE);   //������
	solidrectangle(250, 240, 350, 350);

	setlinecolor(BLACK);   //����
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 10);
	line(270, 350, 270, 460);
	line(330, 350, 330, 460);

	POINT ptr1[] = { {270,460},{260,480},{280,480} };   //����
	solidpolygon(ptr1, 3);

	setlinecolor(BLACK);   //���ֱ�
	setlinestyle(PS_SOLID, 5);
	line(350, 240, 370, 330);
	setbkcolor(BLACK);
	solidcircle(371, 334, 10);

	this->DrawFace();   //�����ϵĲ���
}
