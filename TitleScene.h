#pragma once
#include "Engine/GameObject.h"
class TitleScene :
    public GameObject
{
public:
	TitleScene(GameObject* parent);
	int hPict_;
	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};
