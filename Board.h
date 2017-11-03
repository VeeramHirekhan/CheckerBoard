#pragma once
class Board
{
public:
	Board();
	
	void reset();
	void addChecker(char who, int row, int col);
	int numJumps(int row, int col);
	void print();
	static const char Black = 'B';
	static const char Red = 'R';
	int getFirstRedPieceRow();
	int getFirstRedPieceCol();
private:
	int tryToJump(int row, int col);
	char board[8][8]{
		{ '0', '0', '0', '0', '0', '0', '0', '0' },
		{ '0', '0', '0', '0', '0', '0', '0', '0' },
		{ '0', '0', '0', '0', '0', '0', '0', '0' },
		{ '0', '0', '0', '0', '0', '0', '0', '0' },
		{ '0', '0', '0', '0', '0', '0', '0', '0' },
		{ '0', '0', '0', '0', '0', '0', '0', '0' },
		{ '0', '0', '0', '0', '0', '0', '0', '0' },
		{ '0', '0', '0', '0', '0', '0', '0', '0' }
	};
	bool jumpNorthEast(int row, int col);
	bool jumpNorthWest(int row, int col);
	bool jumpSouthEast(int row, int col);
	bool jumpSouthWest(int row, int col);
	int currentJump;
	int maxJumps;
	int firstRedPieceCol;
	int firstRedPieceRow;
};

