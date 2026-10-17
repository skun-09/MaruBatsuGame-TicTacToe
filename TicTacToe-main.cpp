#include "Board.h"
#include <iostream>

int main() {
	//初期化
	int select;
	char winner = '.';

	//タイトル表示
	std::cout << "〇×ゲーム" << std::endl;

	//盤面表示
	char board[3][3] = {
	{'.', '.', '.'},
	{'.', '.', '.'},
	{'.', '.', '.'}
	};

	

	ShowBoard(board);

	for (int count = 1;count <= 9;count++) {
		std::cout << "選択するマスを選んでください：";
		std::cin >> select;

		if (PutMark(board, select, count)) {
			ShowBoard(board);

			winner = CheckWin(board);

			if (winner != '.') {
				std::cout << winner << "の勝ち！" << std::endl;

				break;
			}
		}
		else {
			count--;
		}

	}

	if (winner == '.') {
		std::cout << "引き分け" << std::endl;
	}

	return 0;
}