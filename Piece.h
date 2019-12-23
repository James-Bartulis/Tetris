#ifndef _Piece_h_
#define _Piece_h_

using namespace std;

class Piece
{
public:
	Piece()
	{
		xpos = 5;
		ypos = 0;
	}
	Piece(Piece *p)
	{
		xpos = p->xpos;
		ypos = p->ypos;
		width = p->width;
		height = p->height;
		pieceMap = p->pieceMap;
	}
	void moveDown();	
	void moveLeft();	
	void moveRight();
	void Rotate();
	void Print(int h);

	friend class Tetris;
protected:
	int xpos, ypos, width, height;
	vector< vector < bool > > pieceMap;
};

class PieceFactory
{
public:
	PieceFactory(){}
	virtual Piece* generate() = 0;
};

class J : public Piece
{
public:
	J();
};

class JFactory : public PieceFactory
{
public:
	JFactory(){}
	Piece* generate()
	{
		return new J();
	}
};

class L : public Piece
{
public:
	L();
};

class LFactory : public PieceFactory
{
public:
	LFactory(){}
	Piece* generate()
	{
		return new L();
	}
};

class I : public Piece
{
public:
	I();
};

class IFactory : public PieceFactory
{
public:
	IFactory(){}
	Piece* generate()
	{
		return new I();
	}
};

class O : public Piece
{
public:
	O();
};

class OFactory : public PieceFactory
{
public:
	OFactory(){}
	Piece* generate()
	{
		return new O();
	}
};

class S : public Piece
{
public:
	S();
};

class SFactory : public PieceFactory
{
public:
	SFactory(){}
	Piece* generate()
	{
		return new S();
	}
};

class MS : public Piece
{
public:
	MS();
};

class MSFactory : public PieceFactory
{
public:
	MSFactory(){}
	Piece* generate()
	{
		return new MS();
	}
};

class T : public Piece
{
public:
	T();
};

class TFactory : public PieceFactory
{
public:
	TFactory(){}
	Piece* generate()
	{
		return new T();
	}
};
class SMILE : public Piece
{
public:
	SMILE();
};

class SMILEFactory : public PieceFactory
{
public:
	SMILEFactory(){}
	Piece* generate()
	{
		return new SMILE();
	}
};
class X : public Piece
{
public:
	X();
};

class XFactory : public PieceFactory
{
public:
	XFactory(){}
	Piece* generate()
	{
		return new X();
	}
};

#endif