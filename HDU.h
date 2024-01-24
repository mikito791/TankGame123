#pragma once
#include "Engine//GameObject.h"
#include<vector>
#include<string>
using std::string;
using std::vector;
class HDU :
    public GameObject
{
public:
	HDU(GameObject* parent);
	~HDU();
	int hHDU_;
	int hNumber_;
	Transform tHud_;

	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;
};

