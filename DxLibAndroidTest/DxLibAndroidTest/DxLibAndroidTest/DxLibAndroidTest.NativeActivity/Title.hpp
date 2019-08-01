#pragma once
#include "BaseScene.hpp"


class Title : public BaseScene
{
private:


public:
	Title();
	~Title();


	// 描画
	void Draw() override;

	// プロセス
	void Process() override;
};

