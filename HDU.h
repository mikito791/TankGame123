#pragma once
#include "Engine//GameObject.h"
#include<vector>
#include<string>
using std::string;
using std::vector;
class HDU :
    public GameObject
{
	string ConstructEnemyNumberString();
public:
	HDU(GameObject* parent);
	~HDU();
	int hHDU_;
	int hNumber_;
	Transform tHud_;
	vector<Transform> tNumber;
	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

