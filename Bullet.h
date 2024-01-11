#pragma once
#include "Engine//GameObject.h"
class Bullet :
    public GameObject
{
private:
	int hModel_;
	float bulletSpeed_;
	XMFLOAT3 moveDir_;
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
};

