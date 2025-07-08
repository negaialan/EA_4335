#include "TextureManager.h"
#include <vector>
#include <string>
#include "Sprite.h"
TextureManager* TextureManager::instance = nullptr;

TextureManager* TextureManager::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new TextureManager();
    }
    return instance;
}

TextureManager::TextureManager()
{
    textureIDs = new map<const char*, int, cmp_str>();
}

TextureManager::~TextureManager()
{
}

void TextureManager::LoadImg()
{
    vector<string>* imgs = new vector<string>();
    imgs->push_back("sun.png");
    imgs->push_back("mars.png");
    imgs->push_back("moon.png");
    imgs->push_back("earth.png");
    for (int i = 0; i < imgs->size(); i++)
    {
        string path = "Resources/" + imgs->at(i);
        Sprite s(path.c_str());

        int textID = s.GenTexture();

        textureIDs->insert(pair<const char*, int>(imgs->at(i).c_str(), textID));
    }
}

int TextureManager::GetTextureID(const char* imgName)
{
    return textureIDs->at(imgName);
}
