// checkerboard.cpp : Defines the entry point for the console application.
//Veeram Hirekhan
//Description: The main purpose of the project is to print a checker board (8X8) through an array. and given points on the checker board, 
//you should be able to skip over another checker piece(legally) in order to see how many jumps in a row you can do before
//you end your turn.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "Board.h"
using namespace std;

//Pre:finds out what user input is and then figures out how many test cases, how many red and how many black checker pieces are needed, also excute the totally number of jumps
//Post:finds total amount of pieces that are on the board
int main()
{
	/*Board board;
	board.print();
	board.addChecker('a', 4, 4);
	board.addChecker('b', 3, 3);
	board.print();*/
	int numberOfTestCases;
	int numberOfBlackPieces;
	int numberOfRedPieces;
	int row; 
	int col;
	 

	cout << "Please enter number of test cases " << endl; // asks user to enter amount of test cases
	cin >> numberOfTestCases;
	vector<Board> boards;
	for (int testCaseNumber = 0; testCaseNumber < numberOfTestCases; testCaseNumber++)
	{
		Board board; // ask for number of red and black ckecker pieces
		cin >> numberOfRedPieces >> numberOfBlackPieces;
		for (int redPieceOnBoard = 0; redPieceOnBoard < numberOfRedPieces; redPieceOnBoard++)
		{
			cin >> row >> col;
			board.addChecker(Board::Red, row, col);//stores number in Board
		}
		for (int blackPiecesOnBoard = 0; blackPiecesOnBoard < numberOfBlackPieces; blackPiecesOnBoard++)
		{
			cin >> row >> col;
			board.addChecker(Board::Black, row, col);
		}
		boards.push_back(board);
	}

	for (int boardIndex = 0; boardIndex < boards.size(); boardIndex++)
	{
		cout << "the number of jumps is " << boards.at(boardIndex).numJumps(boards.at(boardIndex).getFirstRedPieceRow(), boards.at(boardIndex).getFirstRedPieceCol()) << endl;
	}
	system("pause");
	return 0;

}
