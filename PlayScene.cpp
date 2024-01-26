#include "PlayScene.h"
#include"Ground.h"
#include"Tank.h"
#include"Enemy.h"
#include"HDU.h"
#include"Engine/SceneManager.h"
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

	enemyNum = ENEMY_NUM;
	for (int i = 0; i < enemyNum; i++)
		Instantiate<Enemy>(this);
	//Instantiate<TankHead>(this);
	ptext = new Text;
	ptext->Initialize();
	Instantiate<HDU>(this);
}

void PlayScene::Update()
{
	/*Camera::SetTarget(player->GetPosition());
	XMFLOAT3 camPos = player->GetPosition();
	camPos.y += 8;
	camPos.z -= 15;
	Camera::SetPosition(camPos);*/
	if (FindObject("Enemy") == nullptr)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}

void PlayScene::Draw()
{
	ptext->Draw(30, 30, "Hello,world");
}

void PlayScene::Release()
{
}
