#include "ClearScnen.h"
#include"Engine/SceneManager.h"
#include"Engine/Image.h"
#include"Engine/Input.h"
#include"Engine/Text.h"

ClearScnen::ClearScnen(GameObject* parent)
	:GameObject(parent,"ClearScnen"),hPict_(-1),ctext(nullptr)
{
}

void ClearScnen::Initialize()
{
	hPict_ = Image::Load("Model\\clear.png");
	assert(hPict_ >= 0);
	ctext = new Text;
	ctext->Initialize();
}

void ClearScnen::Update()
{
	if (Input::IsKeyDown(DIK_R))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}
}

void ClearScnen::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
	ctext->Draw(30, 30, "PUSH,R,RETRYGAME");
}

void ClearScnen::Release()
{
}
