#pragma once
#include "Engine/GameObject.h"
class Ground :
    public GameObject
{
public:
	Ground(GameObject* parent);
	int hModel_;
	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;

	int GetModelHandle() { return(hModel_); }
};

