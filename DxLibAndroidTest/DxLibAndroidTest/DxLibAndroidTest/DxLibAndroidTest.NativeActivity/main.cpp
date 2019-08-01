#include "Manager.hpp"


/// --------------------------------------------------------------------------------------------------
int android_main(void)
{
	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	// 1260 x 768　がデフォルト。今無理やりでっかくした
	SetGraphMode(1920, 1080, 32);			// 画面サイズ設定


	SetDrawScreen(DX_SCREEN_BACK);	// 背景描画

	Manager m_manager = Manager();


	int m_posX = 0;
	int m_posY = 0;


	// メインループ
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen())
	{
		m_manager.Update();


		// タッチされている箇所の数だけ繰り返し
		for (int i = 0, n = GetTouchInputNum(); i != n; ++i)
		{
			// タッチされている箇所の座標を取得
			GetTouchInput(i, &m_posX, &m_posY, NULL, NULL);

			// タッチされている箇所の座標に円を描画
			DrawCircle(m_posX, m_posY, 40, GetColor(255, 255, 255), TRUE);
		}
	}

	// 削除
	m_manager.~Manager();
	DxLib_End();		// DXライブラリの後始末


	return 0;
}