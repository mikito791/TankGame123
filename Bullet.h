#pragma once
#include "Engine//GameObject.h"
class PlayScene;
class Bullet :
    public GameObject
{
	int hModel_; //�e�ۂ̃��f���ԍ������߂Ă������
	float bulletSpeed_; //�e�ۂ̑���
	XMFLOAT3 moveDir_; //�����̃x�N�g��
	PlayScene* playscene_;
public:
	Bullet(GameObject* parent);
	~Bullet();
	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	void SetMoveDir(XMFLOAT3 _move) { moveDir_ = _move; }
	void SetSpeed(float _speed) { bulletSpeed_ = _speed; }
	void OnCollision(GameObject* pTarget) override;
};

