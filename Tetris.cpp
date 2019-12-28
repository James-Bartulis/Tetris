void Tetris::Display()
{
	system("CLS");
	cout << string(width + 2, char(178)) << "Score: " << Score << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if(j == 0)
				cout << char(178);
			if(pieceOnCoord(j, i, currentPiece))
				cout << char(177);
			else if(setPiecesOnCoord(j, i))
				cout << char(177);
			else if(pieceOnCoord(j, i, phantomPiece))
				cout << char(176);
			else
				cout << char(255);

			if(j == width - 1)
				cout << char(178);
		}
		switch(i)
		{
			case 0:
				if(typeOfPieces > 7)
					cout <<  "Extra Pieces Enabled";
				break;
			case 1:
				cout << "Next Piece:";
				break;
			case 7:
				cout << "Saved Piece:";
				break;
			case 13:
				cout << " r: rotate";
				break;
			case 14:
				cout << " t: trade saved";
				break;
			case 15:
				cout << " T: toggle extra pieces";
				break;
			case 16:
				cout << " q: quick drop";
				break;
			case 17:
				cout << " w: pause";
				break;
			default:
				break;
		}
		cout << " ";
		nextPiece->Print(i - 2);
		savedPiece->Print(i - 8);
		cout << endl;
	}
	cout << string(width + 2, char(178)) << endl;
}
void Tetris::Input()
{
	if(_kbhit())
	{
		switch(getch())
		{
			case 'w':
				system("PAUSE");
				break;
			case 'W':
				clearSetPieces();
				setPhantom();
				break;
			case 80: // down arrow
			case 's':
				if(canMoveDown(currentPiece))
					currentPiece->moveDown();
				break;
			case 75: // left arrow
			case 'a':
				if(canMoveLeft(currentPiece))
				{
					currentPiece->moveLeft();
					setPhantom();
				}
				break;
			case 77: // right arrow
			case 'd':
				if(canMoveRight(currentPiece))
				{
					currentPiece->moveRight();
					setPhantom();
				}
				break;
			case 72: // up arrow
			case 'r':
				if(canRotate())
					setPhantom();
				break;
			case ' ': // space
			case 'q':
				while(canMoveDown(currentPiece))
					currentPiece->moveDown();
				frame += 5 - frame % 5;
				break;
			case 't':
				savePiece();
				setPhantom();
				frame += 5 - frame % 5;
				break;
			case 'T':
				ToggleExtraPieces();
				break;
			case 'c':
				Running = false;
				break;
			case 'F':
				cheat();
				clearFullRows();
				setPhantom();
				break;
			default:
				break;
		}
	}	
}
void Tetris::Logic()
{
	if(canMoveDown(currentPiece))
		currentPiece->moveDown();
	else
	{
		SetPiece();
		clearFullRows();
		setNextPiece();
	}
	isGameOver();
}
bool Tetris::canMoveDown(Piece *p)
{
	if(p->ypos + p->height < height)
	{
		for (int i = p->ypos; i < p->ypos + p->height; i++)
			for (int j = p->xpos; j < p->xpos + p->width; j++)
				if(pieceOnCoord(j, i, p) && setPiecesOnCoord(j, i + 1))
					return false;
		return true;
	}
	return false;
}
bool Tetris::canMoveLeft(Piece *p)
{
	if(p->xpos > 0)
	{
		for (int i = p->ypos; i < p->ypos + p->height; i++)
			for (int j = p->xpos; j < p->xpos + p->width; j++)
				if(pieceOnCoord(j, i, p) && setPiecesOnCoord(j - 1, i))
					return false;
		return true;
	}
	return false;
}
bool Tetris::canMoveRight(Piece *p)
{
	if(p->xpos + p->width < width)
	{
		for (int i = p->ypos; i < p->ypos + p->height; i++)
			for (int j = p->xpos; j < p->xpos + p->width; j++)
				if(pieceOnCoord(j, i, p) && setPiecesOnCoord(j + 1, i))
					return false;
		return true;
	}
	return false;
}
bool Tetris::pieceIsOutOfBounds(Piece *p)
{
	if(p->ypos >= 0 && p->ypos + p->height <= height)
		if(p->xpos >= 0 && p->xpos + p->width <= width)
			return false;
	return true;
}
bool Tetris::pieceOnCoord(int x, int y, Piece* p)
{
	if (y - p->ypos >= 0 && y - p->ypos < p->height)
		if (x - p->xpos >= 0 && x - p->xpos < p->width)
			if(p->pieceMap[y - p->ypos][x - p->xpos])
				return true;
	return false;
}
bool Tetris::setPiecesOnCoord(int x, int y)
{
	if(setPieces[y][x])
		return true;
	return false;
}
void Tetris::SetPiece()
{
	for (int i = currentPiece->ypos; i < currentPiece->ypos +  currentPiece->height; i++)
		for (int j = currentPiece->xpos; j < currentPiece->xpos +  currentPiece->width; j++)
			if(pieceOnCoord(j, i, currentPiece))
				setPieces[i][j] = true;
}

void Tetris::ToggleExtraPieces(){
	if(typeOfPieces == 7) typeOfPieces = 9;
	else typeOfPieces = 7;
}
void Tetris::setNextPiece()
{
	switch(rand()% typeOfPieces + 1)
	{
		case 1:
			PFactory = new JFactory();
			break;
		case 2:
			PFactory = new LFactory();
			break;
		case 3:
			PFactory = new IFactory();
			break;
		case 4:
			PFactory = new OFactory();
			break;
		case 5:
			PFactory = new SFactory();
			break;
		case 6:
			PFactory = new MSFactory();
			break;
		case 7:
			PFactory = new TFactory();
			break;
		case 8:
			PFactory = new SMILEFactory();
			break;
		case 9:
			PFactory = new XFactory();
			break;
		default:
			break;
	}
	if(currentPiece)
		delete currentPiece;
	currentPiece = nextPiece;
	nextPiece = PFactory->generate();
	setPhantom();
}
void Tetris::clearFullRows()
{
	bool full = true;
	for (int i = 0; i < height; i++, full = true)
	{
		for (int j = 0; j < width; j++)
			if(setPieces[i][j] == false)
				full = false;
		if(full)
		{
			for (int k = i; k > 0; k--)
				for (int j = 0; j < width; j++)
					setPieces[k][j] = setPieces[k - 1][j];
			Score+=10;
		}
	}
}
bool Tetris::canRotate()
{
	Piece* oldPiece;
	oldPiece = new Piece(currentPiece);
	currentPiece->Rotate();
	for (int i = currentPiece->ypos; i < currentPiece->ypos + currentPiece->height; i++)
			for (int j = currentPiece->xpos; j < currentPiece->xpos + currentPiece->width; j++)
			{
				while(canMoveLeft(currentPiece) && (pieceOnCoord(j, i, currentPiece) && setPieces[i][j] || pieceIsOutOfBounds(currentPiece)))
					currentPiece->moveLeft();
				if(pieceOnCoord(j, i, currentPiece) && setPieces[i][j] || pieceIsOutOfBounds(currentPiece))
				{
					delete currentPiece;
					currentPiece = oldPiece;
					return false;
				}
			}
	delete oldPiece;
	return true;
}
void Tetris::setPhantom()
{
	phantomPiece = new Piece(currentPiece);
	while(canMoveDown(phantomPiece))
		phantomPiece->moveDown();
}
void Tetris::savePiece()
{
	if(savedPiece)
	{
		Piece *temp;
		temp = currentPiece;
		currentPiece = savedPiece;
		savedPiece = temp;
		currentPiece->ypos = 0;
		currentPiece->xpos = 5;
	}
	else
	{
		savedPiece = currentPiece;	
		currentPiece = NULL;
		setNextPiece();
	}
}
void Tetris::clearSetPieces()
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			setPieces[i][j] = false;
}
bool Tetris::isGameOver()
{
	for (int j = 0; j < width; j++)
		if(setPieces[0][j])
			Running = false;
}
void Tetris::cheat()
{
	int count = 0;
	for (int j = 0; j < width; j++, count = 0)
	{
		for (int i = 0; i < height; i++)
			if(setPieces[i][j])
				count++;
		for (int i = 0; i < height; i++)
		{
			if(height - count <= i)
				setPieces[i][j] = true;
			else
				setPieces[i][j] = false;
		}
	}
}