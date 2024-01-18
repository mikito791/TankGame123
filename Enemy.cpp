#include "Enemy.h"
#include"Engine/Model.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy"),hModel_(-1)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Model\\player.fbx");
	assert(hModel_ >= 0);
	Model::SetAnimFrame(hModel_, 0, 60, 1);
	//transform_.position_ = { (float)(rand() % 41 - 20), 0, 30 };
	float x = (float)rand() / RAND_MAX;//0-1‚Ì—”

	x = 2.0 * x;//0-2‚Ì—”
	transform_.position_.x = 25.0 * (x - 1.0);
	float z = (float)rand() / RAND_MAX;//0-1‚Ì—”
	z = 2.0 * z;//0-2‚Ì—”
	transform_.position_.z = 25.0 * (z - 1.0);
	transform_.position_.y = 0;
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Bullet") {
		this->KillMe();
		pTarget->KillMe();
	}
}
