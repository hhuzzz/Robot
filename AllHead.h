#pragma once
#pragma comment(lib,"winmm.lib")
#include<graphics.h>
#include<Windows.h>
#include<conio.h>
#include<cstdio>
#include<mmsystem.h>   //���ֲ�������
#include<cmath>
#include "Robot.h"
#include "Face.h"
#include "Action.h"

#define pi 3.1415926

int InputBox();   //���û�����

void DrawAbout(Robot* r);   //�ڻ����ϴ�ӡ������Ϣ

void Back(Robot* r);   //���÷��ذ�ť�Ĺ���

void ButtonMusic();   //����ʱ��������
