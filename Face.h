#pragma once
class Face
{
public:
	int GetEyeSize() { return EyesSize; };   //得到眼睛大小
	void SetEyeSize(int a) { EyesSize = a; };   //设置眼睛大小（用于睁眼闭眼）
private:
	int EyesSize;   //眼睛的大小（即半径）
protected:
	void DrawFace();   //画脸上的部件
};