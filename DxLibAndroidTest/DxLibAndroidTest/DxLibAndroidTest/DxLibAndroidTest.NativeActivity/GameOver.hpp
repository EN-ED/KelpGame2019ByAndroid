#pragma once
#include "BaseScene.hpp"


class GameOver : public BaseScene
{
private:
	/// 画像

	int mD_movieDraw;		// 動画の画像

public:
	GameOver();
	~GameOver();


	// 描画
	void Draw() override;

	// プロセス
	void Process() override;
};

