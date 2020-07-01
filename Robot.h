#pragma once
#include "Face.h"
#include "Action.h"

class Robot:public Face,public Action
{
public:
	//接口内函数实现
	void Welcome();   //让机器人做欢迎
	void Dance();   //让机器人跳舞
	void Blink();   //机器人眨眼睛
	void Music();   //播放音乐函数

	void Init();   //界面初始化
	void Init2();   //备用函数,用来得到没有消息框的初始界面
	void Init3();   //备用函数，用来得到没有右手臂的机器人
	void Init4();   //备用函数，用来得到没有右手臂和左脚的机器人
	void Init5();   //备用函数，用来得到没有左手臂和右脚的机器人
private:
	void DrawRobot();   //画出机器人
	int flag;   //标志，用来判断是跳舞还是欢迎
};