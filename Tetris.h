#ifndef _tetris_h_
#define _tetris_h_

using namespace std;

class Tetris
{
public:
	Tetris()
	{
		Running = true;
		Score = 0;
		width = 10;
		height = 24;
		typeOfPieces = 7;
		vector< bool > row;
		row.resize(10, false);
		setPieces.resize(24,row);
		currentPiece = NULL;
		nextPiece = new L();
		savedPiece = NULL;
		setNextPiece();
		setPhantom();
	}
	~Tetris();

	void Display();
	void Input();
	void Logic();
	bool canMoveDown(Piece *p);
	bool canMoveLeft(Piece *p);
	bool canMoveRight(Piece *p);
	bool pieceIsOutOfBounds(Piece *p);
	bool pieceOnCoord(int x, int y, Piece* p);
	bool setPiecesOnCoord(int x, int y);
	void SetPiece();
	void ToggleExtraPieces();
	void setNextPiece();
	void clearFullRows();
	bool canRotate();
	void setPhantom();
	void savePiece();
	void clearSetPieces();
	bool isGameOver();
	void cheat();

	int getFrame() { return frame++;}
	bool isRunning(){ return Running; }



private:
	bool Running;
	PieceFactory *PFactory;
	Piece *currentPiece, *nextPiece, *savedPiece, *phantomPiece;
	int width, height, frame, Score, typeOfPieces;
	vector< vector < bool > > setPieces;
};

#endif