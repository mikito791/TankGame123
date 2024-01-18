#include "PlayScene.h"
#include"Ground.h"
#include"Tank.h"
#include"Enemy.h"
#include"Engine/Camera.h"
//#include"TankHead.h"
namespace
{
	const int ENEMY_NUM{ 30 };
}
PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "SceneManager")
{
}

void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	Instantiate<Tank>(this);
	for (int i = 0; i < ENEMY_NUM; i++)
		Instantiate<Enemy>(this);
	//Instantiate<TankHead>(this);
}

void PlayScene::Update()
{
	/*Camera::SetTarget(player->GetPosition());
	XMFLOAT3 camPos = player->GetPosition();
	camPos.y += 8;
	camPos.z -= 15;
	Camera::SetPosition(camPos);*/
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
