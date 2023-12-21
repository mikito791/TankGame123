#pragma once
#include "Engine/GameObject.h"
class Tank :
    public GameObject
{
	int hModel_;
	XMVECTOR front_;
	float speed_;
public:
	Tank(GameObject* parent);
	
	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

