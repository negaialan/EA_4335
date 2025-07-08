#pragma once
#include <map>

using namespace std;

struct cmp_str
{
	bool operator()(char const* a, char const* b) const
	{
		return std::strcmp(a, b) < 0;
	}
};

class TextureManager
{
public:
	static TextureManager* instance;

public:
	static TextureManager* GetInstance();

public:
	TextureManager();
	~TextureManager();
public:
	void LoadImg();
	int GetTextureID(const char* imgName);

private:
	map<const char*, int, cmp_str>* textureIDs;

};