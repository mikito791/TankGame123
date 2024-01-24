#pragma once
#include "Engine/GameObject.h"
//class Tank;
//class Text;
class PlayScene :
    public GameObject
{
	/*Tank* player;
	Text* ptext;*/
public:
    PlayScene(GameObject* parent);
	int hPict_;
	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
	//インライン定義
	void DescEnemy(){}
};

