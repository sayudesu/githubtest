#include "DxLib.h"

#include "game.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドウモード設定
	ChangeWindowMode(Game::kWindowMode);
	//ウィンドウ名設定
	SetMainWindowText(Game::kTitelText);
	//画面サイズ設定
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	//ダブルバッファモード
	SetDrawScreen(DX_SCREEN_BACK);

	while(ProcessMessage() == 0)
	{
		LONGLONG time = GetNowHiPerformanceCount();

		//画面をクリアする
		ClearDrawScreen();
		//フォント変更
		ChangeFont("ＭＳ 明朝");
		//フォントサイズを変更
		SetFontSize(64);
		//文字を表示
		DrawString(Game::kScreenWidth /2, Game::kScreenHeight /2,"github test",GetColor(255,255,255));

		//裏画面を表画面を入れ替える
		ScreenFlip();

		//escを押して終了
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

		//60fps固定
		while (GetNowHiPerformanceCount() - time < 16667)
		{

		}
	}

	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}