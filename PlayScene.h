#pragma once
#include "Engine/GameObject.h"
//class Tank;
class Text;
class PlayScene :
    public GameObject

{
	//Tank* player;
	Text* ptext;
public:
	int enenmyNum;
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
	void DescEnemy() { enenmyNum--; }//������������
	bool IsEnemyLeft() { return enenmyNum > 0; }
	int GetEnemyNum() { return enenmyNum; }
};

