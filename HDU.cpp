#include "HDU.h"
#include"Engine/Image.h"
#include"PlayScene.h"

HDU::HDU(GameObject* parent)
	:GameObject(parent,"HDU"),hHDU_(-1),hNumber_(-1)
{
}

HDU::~HDU()
{
}

string HDU::ConstructEnemyNumberString()
{
	int enemies = ((PlayScene*)GetParent())->GetEnemyNum();
	string enemyNumStr = std::to_string(enemies);
	return enemyNumStr;
}

void HDU::Initialize()
{
	hHDU_ = Image::Load("Model\\HUD.png");
	assert(hHDU_ >= 0);
	hNumber_ = Image::Load("Model\\Num.png");
	assert(hNumber_ >= 0);
}

void HDU::Update()
{
	tHud_.scale_ = { 0.6, 0.6, 1.5 };
	tHud_.position_ = { -0.8, 0.90, 0 };//Ç±Ç±Ç≈âÊëúÇÃà íuí≤êÆ
}

void HDU::Draw()
{
	Image::SetTransform(hHDU_, tHud_);
	Image::Draw(hHDU_);

	Transform TraNum;
	TraNum.scale_ = { 0.65,0.75,1.0 };
	TraNum.position_ = { -0.7,0.90,0 };
	Image::SetRect(hNumber_, 51.2 * 3, 0, 51.2, 99);
	Image::SetTransform(hNumber_, TraNum);
	Image::Draw(hNumber_);

}

void HDU::Release()
{
}
