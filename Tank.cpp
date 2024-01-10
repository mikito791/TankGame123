#include "Tank.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Ground.h"
#include"TankHead.h"

Tank::Tank(GameObject* parent)
	:GameObject(parent,"Tank"),hModel_(-1)
{
}

void Tank::Initialize()
{
	hModel_ = Model::Load("Model\\TankBody.fbx");
	assert(hModel_ >= 0);
	speed_ = 0.05;
	front_ = XMVECTOR({ 0,0,1,0 });
	Instantiate<TankHead>(this);
}

void Tank::Update()
{
	if (Input::IsKey(DIK_UP))
	{
		//‰ñ“]s—ñ‚ð‹‚ß‚é
		XMMATRIX rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
		//ƒxƒNƒgƒ‹‚Ì‰ñ“]Œ‹‰Ê‚ð‹‚ß‚é
		XMVECTOR rotVec = XMVector3TransformCoord(front_, rotY);
		XMVECTOR move;
		move = speed_ * rotVec;
		XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
		pos = pos + move;
		XMStoreFloat3(&(transform_.position_), pos);
	}
	if (Input::IsKey(DIK_LEFT))
	{
		this->transform_.rotate_.y -= 1;
	}
	if (Input::IsKey(DIK_RIGHT))
	{
		this->transform_.rotate_.y += 1;
	}

	Ground* pGround = (Ground*)FindObject("Ground");
	int hGmodel = pGround->GetModelHandle();

    RayCastData data;
	data.start = transform_.position_;
	data.start.y = 0;
	data.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &data);
	if (data.hit == true)
	{
		transform_.position_.y = -data.dist;
	}
}

void Tank::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
	
}

void Tank::Release()
{
}
