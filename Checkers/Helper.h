#pragma once

class WindowSize 
{
public: 
	static const int Weigth = 1000;
	static const int Heigth = 500;
};

struct Characteristc
{
	ILubyte* texture;
	ILuint width;
	ILuint height;
	ILuint type;
	ILuint format;
};
class Draw
{
public:
	unsigned int* textures;
	Characteristc* characteristic;
};