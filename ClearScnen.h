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
	
	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

