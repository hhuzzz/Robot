#pragma once
#include "Face.h"
#include "Action.h"

class Robot:public Face,public Action
{
public:
	//�ӿ��ں���ʵ��
	void Welcome();   //�û���������ӭ
	void Dance();   //�û���������
	void Blink();   //������գ�۾�
	void Music();   //�������ֺ���

	void Init();   //�����ʼ��
	void Init2();   //���ú���,�����õ�û����Ϣ��ĳ�ʼ����
	void Init3();   //���ú����������õ�û�����ֱ۵Ļ�����
	void Init4();   //���ú����������õ�û�����ֱۺ���ŵĻ�����
	void Init5();   //���ú����������õ�û�����ֱۺ��ҽŵĻ�����
private:
	void DrawRobot();   //����������
	int flag;   //��־�������ж������軹�ǻ�ӭ
};