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
	tHud_.scale_ = { 0.5, 0.5, 1.0 };
	tHud_.position_ = { -0.6, 0.85, 0 };//‚±‚±‚Å‰æ‘œ‚ÌˆÊ’u’²®
}

void HDU::Draw()
{
	Image::SetTransform(hHDU_, tHud_);
	Image::Draw(hHDU_);
}

void HDU::Release()
{
}
