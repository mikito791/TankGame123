#pragma once
#include "Engine/GameObject.h"
//class Tank;
//class Text;
class PlayScene :
    public GameObject
{
	/*Tank* player;
	Text* ptext;*/
public:
    PlayScene(GameObject* parent);
	int hPict_;
	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
	//�C�����C����`
	void DescEnemy(){}
};

