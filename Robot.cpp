#include "AllHead.h"

void Robot::Init()    //界面初始化
{
	TCHAR s[] = _T("Welcome");
	TCHAR r[] = _T("About");
	MessageBox(NULL, TEXT("你好，我叫布里茨。"), TEXT("欢迎"), MB_OK);
	int rel = MessageBox(NULL, TEXT("是否要看看我呢"), TEXT("欢迎"), MB_YESNO);
	if (rel == IDYES)
	{
		initgraph(600, 480);
		setbkcolor(RGB(96, 96, 96));
		cleardevice();
		MOUSEMSG m;
		settextcolor(RED);
		settextstyle(64, 0, _T("Consolas"));
		outtextxy(200, 100, s);   //打印Welcome
		outtextxy(200, 300, r);   //打印About
		while (1)
		{
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONDOWN && m.x > 200 && m.x < 400 && m.y>100 && m.y < 160)
			{
				ButtonMusic();
				cleardevice();
				loadimage(NULL, _T("E:\\VS代码\\仿真机器人\\仿真机器人\\beijing.jpg"));
				this->DrawRobot();   //画机器人
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
					int flag = MessageBox(NULL, TEXT("请用键盘输入1或2"), TEXT("错误提示"), MB_OK);
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
		MessageBox(NULL, TEXT("好吧，再见！"), TEXT("退出"), MB_OK);
		return;
	}
}

void Robot::DrawRobot()
{
	setfillcolor(RGB(108,108,108));   //画头
	solidroundrect(250, 140, 350, 220, 30, 30);

	setfillcolor(WHITE);   //画脖子
	solidrectangle(290, 220, 310, 240);

	setfillcolor(BLUE);   //画身子
	solidrectangle(250, 240, 350, 350);

	setlinecolor(BLACK);   //画腿
	setlinestyle(PS_SOLID| PS_ENDCAP_FLAT, 10);
	line(270, 350, 270, 460);
	line(330, 350, 330, 460);

    POINT ptr1[] = { {270,460},{260,480},{280,480} };   //画脚
	POINT ptr2[] = { {330,460},{320,480},{340,480} };
	solidpolygon(ptr1, 3);
	solidpolygon(ptr2, 3);

	setlinecolor(BLACK);   //画手臂
	setlinestyle(PS_SOLID, 5);
	line(250, 240, 230, 330);
	line(350, 240, 370, 330);
	setbkcolor(BLACK);
	solidcircle(229, 334, 10);
	solidcircle(371, 334, 10);

	this->DrawFace();   //画脸上的部件
}


void Robot::Music()   //播放音乐函数
{
	mciSendString(_T("open E:\\VS代码\\仿真机器人\\仿真机器人\\Avengers.mp3"), NULL, 0, NULL);  //打开设备
	mciSendString(_T("play E:\\VS代码\\仿真机器人\\仿真机器人\\Avengers.mp3"), NULL, 0, NULL);  //播放音乐
}

void Robot::Welcome()   //欢迎函数
{
	double r = 96.3;   //手臂长度，先前已经算好
	IMAGE img,img2;
	this->Init3();
	getimage(&img, 0, 0, 600, 480);

	mciSendString("close E:\\VS代码\\仿真机器人\\仿真机器人\\Avengers.mp3", NULL, 0, NULL);   //关闭原BGM

	putimage(0, 0, &img);
	setbkcolor(RGB(108, 108, 108));   //设置一下背景颜色，用来抹去原先表情
	clearrectangle(295, 200, 305, 220);   //抹去当前嘴巴
	clearrectangle(264, 149, 336, 171);   //抹去两个眼睛
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 3);
	arc(290, 200, 310, 210, pi, 2 * pi);   //画笑脸
	//画笑眼
	line(265, 150, 275, 160);
	line(275, 160, 265, 170);
	line(335, 150, 325, 160);
	line(325, 160, 335, 170);
	getimage(&img2, 0, 0, 600, 480);

	setorigin(350, 240);   //设置坐标原点为手臂的一端
	//设置画手臂线的样式
	setlinecolor(BLACK);  
	setlinestyle(PS_SOLID, 5);
	setfillcolor(BLUE);
	BeginBatchDraw();   //开始批量绘图
	for (double cita = 4 * pi / 9; cita >= (-pi/4); cita -= pi / 90)
	{
		cleardevice();
		putimage(-350, -240, &img2);
		line(0, 0, r*cos(cita), (r*sin(cita)));   //画手臂
		solidcircle(r*cos(cita), (r*sin(cita)), 10);   //画手
		Sleep(50);
		FlushBatchDraw();
	}
	EndBatchDraw();   //结束批量绘图

	//让机器人说你好
	mciSendString("open E:\\VS代码\\仿真机器人\\仿真机器人\\nihao.mp3", NULL, 0, NULL);
	mciSendString("play E:\\VS代码\\仿真机器人\\仿真机器人\\nihao.mp3", NULL, 0, NULL);

	Sleep(3000);   //等待3s
	this->Init2();   //回到初始界面
}

void Robot::Dance()   //跳舞函数
{
	mciSendString("close E:\\VS代码\\仿真机器人\\仿真机器人\\Avengers.mp3", NULL, 0, NULL);   //关闭原BGM
	mciSendString("open E:\\VS代码\\仿真机器人\\仿真机器人\\dance.mp3", NULL, 0, NULL);
	mciSendString("play E:\\VS代码\\仿真机器人\\仿真机器人\\dance.mp3", NULL, 0, NULL);
	Sleep(3000);

	double r = 96.3;   //手臂长度，先前已经算好
	IMAGE img1, img2;
	this->Init4();
	getimage(&img1, 0, 0, 600, 480);   //得到图片
	
	putimage(0, 0, &img1);
	setbkcolor(RGB(108, 108, 108));   //设置一下背景颜色，用来抹去原先表情
	clearrectangle(295, 200, 305, 220);   //抹去当前嘴巴
	clearrectangle(264, 149, 336, 171);   //抹去两个眼睛
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 3);
	arc(290, 200, 310, 210, pi, 2 * pi);   //画笑脸
	//画笑眼
	line(265, 150, 275, 160);
	line(275, 160, 265, 170);
	line(335, 150, 325, 160);
	line(325, 160, 335, 170);
	getimage(&img1, 0, 0, 600, 480);

	setorigin(350, 240);   //设置坐标原点为手臂的一端
	//设置画手臂线的样式
	setlinecolor(BLACK);
	setfillcolor(BLUE);
	double l,cita;
	BeginBatchDraw();   //开始批量绘图
	for (cita = 4 * pi / 9,l=0; cita >= 0,l<=110; cita -= pi / 90,l+=2.75)
	{
		setlinestyle(PS_SOLID, 5);   //设置线的样式
		cleardevice();
		putimage(-350, -240, &img1);
		line(0, 0, r*cos(cita), (r*sin(cita)));   //画手臂
		solidcircle(r*cos(cita), (r*sin(cita)), 10);   //画手

		setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 10);
		line(-80, 110, -80, 220 - l);
		int* a = new int[6];   //申请有6个变量的int型数组
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
		setlinestyle(PS_SOLID, 5);   //设置线的样式
		cleardevice();
		putimage(-350, -240, &img1);
		line(0, 0, r*cos(cita), (r*sin(cita)));   //画手臂
		solidcircle(r*cos(cita), (r*sin(cita)), 10);   //画手

		setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 10);
		line(-80, 110, -80, 110 + l);
		int* a = new int[6];   //申请有6个变量的int型数组
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

	setorigin(-350, -240);   //将坐标原点放回左上角
	this->Init5();
	getimage(&img2, 0, 0, 600, 480);

	putimage(0, 0, &img2);
	setbkcolor(RGB(108, 108, 108));   //设置一下背景颜色，用来抹去原先表情
	clearrectangle(295, 200, 305, 220);   //抹去当前嘴巴
	clearrectangle(264, 149, 336, 171);   //抹去两个眼睛
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 3);
	arc(290, 200, 310, 210, pi, 2 * pi);   //画笑脸
	//画笑眼
	line(265, 150, 275, 160);
	line(275, 160, 265, 170);
	line(335, 150, 325, 160);
	line(325, 160, 335, 170);
	getimage(&img2, 0, 0, 600, 480);
	setorigin(250, 240);   //设置坐标为手臂的一端
	setaspectratio(-1, 1);   //改变坐标轴方向，使上面的代码能复用

	//设置画手臂线的样式
	setlinecolor(BLACK);
	setfillcolor(BLUE);
	for (cita = 4 * pi / 9, l = 0; cita >= 0, l <= 110; cita -= pi / 90, l += 2.75)
	{
		setlinestyle(PS_SOLID, 5);   //设置线的样式
		cleardevice();
		putimage(-350, -240, &img1);
		line(0, 0, r*cos(cita), (r*sin(cita)));   //画手臂
		solidcircle(r*cos(cita), (r*sin(cita)), 10);   //画手

		setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 10);
		line(-80, 110, -80, 220 - l);
		int* a = new int[6];   //申请有6个变量的int型数组
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
		setlinestyle(PS_SOLID, 5);   //设置线的样式
		cleardevice();
		putimage(-350, -240, &img1);
		line(0, 0, r*cos(cita), (r*sin(cita)));   //画手臂
		solidcircle(r*cos(cita), (r*sin(cita)), 10);   //画手

		setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 10);
		line(-80, 110, -80, 110 + l);
		int* a = new int[6];   //申请有6个变量的int型数组
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
	EndBatchDraw();   //结束批量绘图

	mciSendString(_T("open E:\\VS代码\\仿真机器人\\仿真机器人\\question.mp3"), NULL, 0, NULL);  //打开设备
	mciSendString(_T("play E:\\VS代码\\仿真机器人\\仿真机器人\\question.mp3"), NULL, 0, NULL);  //播放音乐
	int flag = MessageBox(NULL, TEXT("你觉得我跳的咋样"), TEXT("问题"), MB_YESNO);
	if (flag == IDYES)
	{
		mciSendString(_T("open E:\\VS代码\\仿真机器人\\仿真机器人\\answer1.mp3"), NULL, 0, NULL);  //打开设备
		mciSendString(_T("play E:\\VS代码\\仿真机器人\\仿真机器人\\answer1.mp3"), NULL, 0, NULL);  //播放音乐
	}
	if (flag == IDNO)
	{
		mciSendString(_T("open E:\\VS代码\\仿真机器人\\仿真机器人\\answer2.mp3"), NULL, 0, NULL);  //打开设备
		mciSendString(_T("play E:\\VS代码\\仿真机器人\\仿真机器人\\answer2.mp3"), NULL, 0, NULL);  //播放音乐
	}

	Sleep(3000);   //等待几秒
	this->Init2();   //回到初始界面
}

void Robot::Init2()   //备用函数
{
	TCHAR s[] = _T("Welcome");
	TCHAR r[] = _T("About");
	initgraph(600, 480);
	setbkcolor(RGB(96, 96, 96));
	cleardevice();
	MOUSEMSG m;
	settextcolor(RED);
	settextstyle(64, 0, _T("Consolas"));
	outtextxy(200, 100, s);   //打印welcome
	outtextxy(200, 300, r);   //打印About
	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN && m.x > 200 && m.x < 400 && m.y>100 && m.y < 160)
		{
			ButtonMusic();
			cleardevice();
			loadimage(NULL, _T("E:\\VS代码\\仿真机器人\\仿真机器人\\beijing.jpg"));
			this->DrawRobot();   //画机器人
			this->flag = InputBox();
			if (this->flag == 1)
			{
				this->Welcome();
			}
			if (this->flag == 2)
			{
				this->Dance();
			}
			//this->Blink();    //眨眼
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

void Robot::Init3()   //备用函数，用来得到没有右手臂的机器人
{
	initgraph(600, 480);
	setbkcolor(RGB(96, 96, 96));
	loadimage(NULL, _T("E:\\VS代码\\仿真机器人\\仿真机器人\\beijing.jpg"));
	setfillcolor(RGB(108, 108, 108));   //画头
	solidroundrect(250, 140, 350, 220, 30, 30);

	setfillcolor(WHITE);   //画脖子
	solidrectangle(290, 220, 310, 240);

	setfillcolor(BLUE);   //画身子
	solidrectangle(250, 240, 350, 350);

	setlinecolor(BLACK);   //画腿
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 10);
	line(270, 350, 270, 460);
	line(330, 350, 330, 460);

	POINT ptr1[] = { {270,460},{260,480},{280,480} };   //画脚
	POINT ptr2[] = { {330,460},{320,480},{340,480} };
	solidpolygon(ptr1, 3);
	solidpolygon(ptr2, 3);

	setlinecolor(BLACK);   //画手臂
	setlinestyle(PS_SOLID, 5);
	line(250, 240, 230, 330);
	setfillcolor(BLUE);
	solidcircle(229, 334, 10);

	this->DrawFace();   //画脸上的部件
}

void Robot::Init4()   //备用函数，用俩得到没有右手臂和左脚的机器人
{
	initgraph(600, 480);
	setbkcolor(RGB(96, 96, 96));
	loadimage(NULL, _T("E:\\VS代码\\仿真机器人\\仿真机器人\\beijing.jpg"));
	setfillcolor(RGB(108, 108, 108));   //画头
	solidroundrect(250, 140, 350, 220, 30, 30);

	setfillcolor(WHITE);   //画脖子
	solidrectangle(290, 220, 310, 240);

	setfillcolor(BLUE);   //画身子
	solidrectangle(250, 240, 350, 350);

	setlinecolor(BLACK);   //画腿
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 10);
	line(330, 350, 330, 460);

	POINT ptr2[] = { {330,460},{320,480},{340,480} };   //画脚
	solidpolygon(ptr2, 3);

	setlinecolor(BLACK);   //画手臂
	setlinestyle(PS_SOLID, 5);
	line(250, 240, 230, 330);
	setfillcolor(BLUE);
	solidcircle(229, 334, 10);

	this->DrawFace();   //画脸上的部件
}

void Robot::Init5()   //备用函数，用来得到没有左手臂和右脚的机器人
{
	initgraph(600, 480);
	setbkcolor(RGB(96, 96, 96));
	loadimage(NULL, _T("E:\\VS代码\\仿真机器人\\仿真机器人\\beijing.jpg"));

	setfillcolor(RGB(108, 108, 108));   //画头
	solidroundrect(250, 140, 350, 220, 30, 30);

	setfillcolor(WHITE);   //画脖子
	solidrectangle(290, 220, 310, 240);

	setfillcolor(BLUE);   //画身子
	solidrectangle(250, 240, 350, 350);

	setlinecolor(BLACK);   //画腿
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 10);
	line(270, 350, 270, 460);
	line(330, 350, 330, 460);

	POINT ptr1[] = { {270,460},{260,480},{280,480} };   //画脚
	solidpolygon(ptr1, 3);

	setlinecolor(BLACK);   //画手臂
	setlinestyle(PS_SOLID, 5);
	line(350, 240, 370, 330);
	setbkcolor(BLACK);
	solidcircle(371, 334, 10);

	this->DrawFace();   //画脸上的部件
}
