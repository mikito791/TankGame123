#include "Bullet.h"
#include"Engine/Model.h"
#include"Engine/SphereCollider.h"
#include"PlayScene.h"
#include"Engine/Debug.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hModel_(-1)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("Model\\Bullet.fbx");
	assert(hModel_ >= 0);
	SphereCollider* collider = new SphereCollider(XMFLOAT3(0, 0, 0),0.5);
	AddCollider(collider);
	playscene_ = (PlayScene*)GetParent();
}

void Bullet::Update()
{
	//transform_.positionをmoveDir_とbulletSpeedで更新
	//transform_.position_.z += 0.5;
	transform_.position_.x = transform_.position_.x + moveDir_.x * bulletSpeed_;
	transform_.position_.y = transform_.position_.y + moveDir_.y * bulletSpeed_;
	transform_.position_.z = transform_.position_.z + moveDir_.z * bulletSpeed_;
	//y座標を落とす
	moveDir_ = { moveDir_.x,moveDir_.y - 0.01f,moveDir_.z};
	if (transform_.position_.y < -10)
		KillMe();
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}

void Bullet::OnCollision(GameObject* pTarget)
{

	if (pTarget->GetObjectName() == "Enemy")
	{
		this->KillMe();
		playscene_->DescEnemy();
		pTarget->KillMe();//ここおかしい
		//Debug::Log(playscene_->GetObjectName());
	}

}