#include "DxLib.h"

int android_main(void)
{
	int i;
	int PosX, PosY;

	// ＤＸライブラリの初期化
	if (DxLib_Init() < 0) return -1;

	// 描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	// テスト画像
	int testGraph = 0;
	testGraph = LoadGraph("images.jpg");

	// メインループ
	while (ProcessMessage() == 0)
	{
		// 画面のクリア
		ClearDrawScreen();

		// 画像表示
		DrawGraph(0, 0, testGraph, false);

		// タッチされている箇所の数だけ繰り返し
		for (i = 0; i < GetTouchInputNum(); i++)
		{
			// タッチされている箇所の座標を取得
			GetTouchInput(i, &PosX, &PosY, NULL, NULL);

			// タッチされている箇所の座標に円を描画
			DrawCircle(PosX, PosY, 40, GetColor(255, 255, 255), TRUE);
		}

		// 裏画面の内容を表画面に反映
		ScreenFlip();
	}

	// 画像削除
	DeleteGraph(testGraph);

	// ＤＸライブラリの後始末
	DxLib_End();

	// ソフトの終了
	return 0;
}