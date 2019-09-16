CC	:= g++

CChess: main.cpp draw.cpp setup.cpp decodeEncode.cpp checkSquareOccupied.cpp Bishop.o King.o Knight.o Pawn.o Piece.o Queen.o Rook.o
	$(CC) main.cpp draw.cpp setup.cpp decodeEncode.cpp checkSquareOccupied.cpp Bishop.o King.o Knight.o Pawn.o Piece.o Queen.o Rook.o -o CChess

Piece.o: Piece.cpp Piece.h
	$(CC) -c Piece.cpp

Bishop.o: Bishop.cpp Bishop.h
	$(CC) -c Bishop.cpp

King.o: King.cpp King.h
	$(CC) -c King.cpp

Knight.o: .cpp Knight.h
	$(CC) -c Knight.cpp

Pawn.o: Pawn.cpp Pawn.h
	$(CC) -c Pawn.cpp

Queen.o: Queen.cpp Queen.h
	$(CC) -c Queen.cpp

Rook.o: Rook.cpp Rook.h
	$(CC) -c Rook.cpp
