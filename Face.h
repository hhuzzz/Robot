#pragma once
class Face
{
public:
	int GetEyeSize() { return EyesSize; };   //�õ��۾���С
	void SetEyeSize(int a) { EyesSize = a; };   //�����۾���С���������۱��ۣ�
private:
	int EyesSize;   //�۾��Ĵ�С�����뾶��
protected:
	void DrawFace();   //�����ϵĲ���
};