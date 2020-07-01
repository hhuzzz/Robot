#pragma once

class Action   //纯虚类，用来让子类实现机器人的动作
{
public:
	virtual void Welcome() = 0;   //让机器人做欢迎
	virtual void Dance() = 0;   //让机器人跳舞
	virtual void Music() = 0;   //播放音乐函数
};