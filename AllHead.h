#pragma once
#pragma comment(lib,"winmm.lib")
#include<graphics.h>
#include<Windows.h>
#include<conio.h>
#include<cstdio>
#include<mmsystem.h>   //音乐播放所需
#include<cmath>
#include "Robot.h"
#include "Face.h"
#include "Action.h"

#define pi 3.1415926

int InputBox();   //与用户交互

void DrawAbout(Robot* r);   //在画布上打印帮助信息

void Back(Robot* r);   //设置返回按钮的功能

void ButtonMusic();   //按键时发出声音
