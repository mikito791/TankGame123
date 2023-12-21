#pragma once
#include "Engine/GameObject.h"
class Ground :
    public GameObject
{
public:
	Ground(GameObject* parent);
	int hModel_;
	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	int GetModelHandle() { return(hModel_); }
};

