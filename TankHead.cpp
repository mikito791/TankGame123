#include "TankHead.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Bullet.h"

TankHead::TankHead(GameObject* parent)
	:GameObject(parent,"TankHead"),hModel_(-1)
{
}

TankHead::~TankHead()
{
}

void TankHead::Initialize()
{
	hModel_ = Model::Load("Model\\TankHead.fbx");
	assert(hModel_ >= 0);
}

void TankHead::Update()
{
	if (Input::IsKey(DIK_A))
	{
		this->transform_.rotate_.y -= 1;
	}
	if (Input::IsKey(DIK_D))
	{
		this->transform_.rotate_.y += 1;
	}
	if (Input::IsKeyDown(DIK_SPACE))
	{
		XMFLOAT3 cannonTopPos = Model::GetBonePosition(hModel_, "cannonTopPos");
		XMFLOAT3 cannonRootPos = Model::GetBonePosition(hModel_, "cannonRootPos");
		XMVECTOR vtop = XMLoadFloat3(&cannonTopPos);
		XMVECTOR vroot = XMLoadFloat3(&cannonRootPos);

		XMVECTOR moveDir = vtop - vroot;
		moveDir = XMVector3Normalize(moveDir);

		XMFLOAT3 vmove;
		XMStoreFloat3(&vmove, moveDir);

		Bullet* pBullet = Instantiate<Bullet>(this->GetParent()->GetParent());
		pBullet->SetPosition(cannonTopPos);
		pBullet->SetMoveDir(vmove);
		pBullet->SetSpeed(0.1);
	}
}

void TankHead::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void TankHead::Release()
{
	
}
