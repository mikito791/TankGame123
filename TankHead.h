#pragma once
#include "Engine//GameObject.h"
class TankHead :
    public GameObject
{
private:
	int hModel_;
public:
	TankHead(GameObject* parent);
	~TankHead();
	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	/// <summary>
	/// ���f���ԍ���Ԃ��֐�
	/// </summary>
	/// <returns>int hModel:���f���ԍ�</returns>
	int GetModelHandle() { return hModel_; }
};

