#include "Tank.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/Camera.h"
#include"Ground.h"
#include"TankHead.h"

//カメラ制御
enum CAM_TYPE
{
	FIXED_TYPE,//固定
	TPS_NOROT_TYPE,
	TPS_TYPE,//3人称
	FPS_TYPE,
	MAX_TYPE,//番兵さん（チェック用の値）
};
Tank::Tank(GameObject* parent)
	:GameObject(parent, "Tank"), hModel_(-1),
	speed_(0.05),front_({0,0,1,0})//camState_(CAM_TYPE::FIXED_TYPE)
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
		//回転行列を求める
		XMMATRIX rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
		//ベクトルの回転結果を求める
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
		transform_.position_.y = -data.dist+0.5f;
	}

	if (Input::IsKeyDown(DIK_Z))
	{
		/*camState_++;
		if (camState_ == CAM_TYPE::MAX_TYPE)
			camState_ = CAM_TYPE::FIXED_TYPE;*/
	}

	/*switch (camState_)
	{
	case CAM_TYPE::FIXED_TYPE:
	{
		Camera::SetPosition(XMFLOAT3(0, 20, -20));
		Camera::SetTarget(XMFLOAT3(0, 0, 0));
		break;
	}
	case CAM_TYPE::TPS_NOROT_TYPE:
	{
		XMFLOAT3 camPos = transform_.position_;
		camPos.y = transform_.position_.y + 5.0f;
		camPos.z = transform_.position_.z - 10.0f;
		Camera::SetPosition(camPos);
		Camera::SetTarget(transform_.position_);
		break;
	}
	case CAM_TYPE::TPS_TYPE:
	{
		break;
	}
	case CAM_TYPE::FPS_TYPE:
	{
		break;
	}
	default:
		break;
	}*/
}

void Tank::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
	
}

void Tank::Release()
{
}
