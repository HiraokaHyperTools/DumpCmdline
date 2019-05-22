// DumpCmdline.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"

int main()
{
	{
		printf("GetCommandLineA:\n");
		LPCSTR text = GetCommandLineA();
		for (int y = 0;; y += 16) {
			int x;
			for (x = 0; x < 16 && text[y + x] != 0; ++x) {
				printf("%02X ", text[y + x] & 255);
			}
			bool eof = x != 16;
			for (; x < 16; ++x) {
				printf("   ");
			}
			for (x = 0; x < 16 && text[y + x] != 0; ++x) {
				printf("%c", isprint(text[y + x]) ? text[y + x] : '.');
			}
			printf("\n");
			if (eof) {
				break;
			}
		}
	}
	{
		printf("\n\nGetCommandLineW:\n");
		LPCWSTR text = GetCommandLineW();
		for (int y = 0;; y += 16) {
			int x;
			for (x = 0; x < 16 && text[y + x] != 0; ++x) {
				printf("%04X ", text[y + x] & 65535);
			}
			bool eof = x != 16;
			for (; x < 16; ++x) {
				printf("     ");
			}
			for (x = 0; x < 16 && text[y + x] != 0; ++x) {
				printf("%C", isprint(text[y + x]) ? text[y + x] : L'.');
			}
			printf("\n");
			if (eof) {
				break;
			}
		}
	}
	return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
