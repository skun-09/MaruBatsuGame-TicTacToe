#include "Board.h"
#include <iostream>

void ShowBoard(char board[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << board[i][j];

			if (j < 2) {
				std::cout << "｜";
			}
		}

		std::cout << std::endl;

		if (i < 2) {
			std::cout << "ー＋ー＋ー" << std::endl;
		}
	}
}

bool PutMark(char board[3][3], int select, int count)
{
	// 入力チェック
	if (select < 1 || select > 9)
	{
		std::cout << "1～9を入力してください！" << std::endl;
		return false;
	}


	// 数字を配列の場所に変換
	int x = (select - 1) % 3;
	int y = (select - 1) / 3;


	// すでに置かれているか確認
	if (board[y][x] != '.')
	{
		std::cout << "すでに置かれています！" << std::endl;
		return false;
	}


	// OとXを交互に置く
	char mark;

	if (count % 2 == 1)
	{
		mark = 'O';
	}
	else
	{
		mark = 'X';
	}

	board[y][x] = mark;


	return true;
}

char CheckWin(char board[3][3]) {

	//横の判定
	for (int i = 0; i < 3; i++) {

		if (board[i][0] != '.' &&
			board[i][0] == board[i][1] &&
			board[i][1] == board[i][2]) {

			return board[i][0];
		}
	}

	//縦の判定
	for (int i = 0; i < 3; i++) {
		if (board[0][i] != '.' &&
			board[0][i] == board[1][i] &&
			board[1][i] == board[2][i]) {

			return board[0][i];
		}
	}

	//斜めの判定
	if (board[0][0] != '.' &&
		board[0][0] == board[1][1] &&
		board[1][1] == board[2][2]) {

		return board[0][0];
	}
	else if (board[2][0] != '.' &&
		board[2][0] == board[1][1] &&
		board[1][1] == board[0][2]) {

		return board[2][0];
	}

	return '.';
}