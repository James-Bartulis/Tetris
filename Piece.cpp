void Piece::moveDown()
{
	ypos++;
}	
void Piece::moveLeft()
{
	xpos--;
}	
void Piece::moveRight()
{
	xpos++;
}
void Piece::Rotate()
{
	vector < bool > row;
	vector < vector < bool > > newMap;
	for (int j = 0; j < width; j++)
	{
		for (int i = height - 1; i >= 0; i--)
		{
			row.push_back(pieceMap[i][j]);
		}
		newMap.push_back(row);
		row.clear();
	}

	int temp = height;
	height = width;
	width = temp;
	pieceMap = newMap;
}
void Piece::Print(int h)
{
	if(!this)
		return;
	if(h >= 0 && h < height)
		for (int j = 0; j < width; j++)
			if(pieceMap[h][j])
				cout << char(178);
			else
				cout << char(255);

}
// _1
// _1
// 11
J::J()
{
	width = 2;
	height = 3;
	vector< bool > row;
	row.push_back(false);
	row.push_back(true);
	pieceMap.push_back(row);
	pieceMap.push_back(row);
	row.clear();
	row.push_back(true);
	row.push_back(true);
	pieceMap.push_back(row);
}

// 1_
// 1_
// 11
L::L()
{
	width = 2;
	height = 3;
	vector< bool > row;
	row.push_back(true);
	row.push_back(false);
	pieceMap.push_back(row);
	pieceMap.push_back(row);
	row.clear();
	row.push_back(true);
	row.push_back(true);
	pieceMap.push_back(row);
}

// 1
// 1
// 1
// 1
I::I()
{
	width = 1;
	height = 4;
	vector< bool > row;
	row.push_back(true);
	pieceMap.push_back(row);
	pieceMap.push_back(row);
	pieceMap.push_back(row);
	pieceMap.push_back(row);
}

// 11
// 11
O::O()
{
	width = 2;
	height = 2;
	vector< bool > row;
	row.push_back(true);
	row.push_back(true);
	pieceMap.push_back(row);
	pieceMap.push_back(row);
}

// 1_
// 11
// _1
S::S()
{
	width = 2;
	height = 3;
	vector< bool > row;
	row.push_back(true);
	row.push_back(false);
	pieceMap.push_back(row);
	row.clear();
	row.push_back(true);
	row.push_back(true);
	pieceMap.push_back(row);
	row.clear();
	row.push_back(false);
	row.push_back(true);
	pieceMap.push_back(row);
}

// _1
// 11
// 1_
MS::MS()
{
	width = 2;
	height = 3;
	vector< bool > row;
	row.push_back(false);
	row.push_back(true);
	pieceMap.push_back(row);
	row.clear();
	row.push_back(true);
	row.push_back(true);
	pieceMap.push_back(row);
	row.clear();
	row.push_back(true);
	row.push_back(false);
	pieceMap.push_back(row);
}

// 1_
// 11
// 1_
T::T()
{
	width = 2;
	height = 3;
	vector< bool > row;
	row.push_back(true);
	row.push_back(false);
	pieceMap.push_back(row);
	row.clear();
	row.push_back(true);
	row.push_back(true);
	pieceMap.push_back(row);
	row.clear();
	row.push_back(true);
	row.push_back(false);
	pieceMap.push_back(row);
}

// _1_1_
// _1_1_
// _____
// 1___1
// _111_
SMILE::SMILE()
{
	width = 5;
	height = 5;
	vector< bool > row;
	row.push_back(false);
	row.push_back(true);
	row.push_back(false);
	row.push_back(true);
	row.push_back(false);
	pieceMap.push_back(row);
	pieceMap.push_back(row);
	row.clear();
	row.push_back(false);
	row.push_back(false);
	row.push_back(false);
	row.push_back(false);
	row.push_back(false);
	pieceMap.push_back(row);
	row.clear();
	row.push_back(true);
	row.push_back(false);
	row.push_back(false);
	row.push_back(false);
	row.push_back(true);
	pieceMap.push_back(row);
	row.clear();
	row.push_back(false);
	row.push_back(true);
	row.push_back(true);
	row.push_back(true);
	row.push_back(false);
	pieceMap.push_back(row);
}

// 1_1
// _1_
// 1_1
X::X()
{
	width = 3;
	height = 3;
	vector< bool > row;
	row.push_back(true);
	row.push_back(false);
	row.push_back(true);
	pieceMap.push_back(row);
	row.clear();
	row.push_back(false);
	row.push_back(true);
	row.push_back(false);
	pieceMap.push_back(row);
	row.clear();
	row.push_back(true);
	row.push_back(false);
	row.push_back(true);
	pieceMap.push_back(row);
}