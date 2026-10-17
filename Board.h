#pragma once

void ShowBoard(char board[3][3]);       // 盤面を表示

bool PutMark(char board[3][3], int select, int count); // O・Xを置く

char CheckWin(char board[3][3]);        // 勝者を確認