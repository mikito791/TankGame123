#pragma once
#include"Engine/GameObject.h"
class Text;
class ClearScnen :
    public GameObject
{
	int hPict_;
	Text* ctext;
public:
	ClearScnen(GameObject* parent);
	
	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;
};

