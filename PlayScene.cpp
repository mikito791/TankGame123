#include "PlayScene.h"
#include"Ground.h"
#include"Tank.h"
#include"Enemy.h"
#include"Engine/Camera.h"
#include"Engine/Text.h"
//#include"TankHead.h"
namespace
{
	const int ENEMY_NUM{ 30 };
}
PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "SceneManager"), ptext(nullptr)
{
}

void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	Instantiate<Tank>(this);

	enenmyNum = ENEMY_NUM;
	for (int i = 0; i < enenmyNum; i++)
		Instantiate<Enemy>(this);
	//Instantiate<TankHead>(this);
	ptext = new Text;
	ptext->Initialize();
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
	ptext->Draw(30, 30, "Hello,world");
}

void PlayScene::Release()
{
}
