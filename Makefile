CC	:= g++
VPATH = /pieceFiles

Chess++: main.cpp draw.cpp checkCheck.cpp setup.cpp decodeEncode.cpp checkSquareOccupied.cpp Bishop.o King.o Knight.o Pawn.o Piece.o Queen.o Rook.o
	$(CC) main.cpp draw.cpp checkCheck.cpp setup.cpp decodeEncode.cpp checkSquareOccupied.cpp Bishop.o King.o Knight.o Pawn.o Piece.o Queen.o Rook.o -o CChess

Piece.o: Piece.cpp Pieces.h
	$(CC) -c Piece.cpp

Bishop.o: Bishop.cpp Pieces.h
	$(CC) -c Bishop.cpp

King.o: King.cpp Pieces.h
	$(CC) -c King.cpp

Knight.o: Knight.cpp Pieces.h
	$(CC) -c Knight.cpp

Pawn.o: Pawn.cpp Pieces.h
	$(CC) -c Pawn.cpp

Queen.o: Queen.cpp Pieces.h
	$(CC) -c Queen.cpp

Rook.o: Rook.cpp Pieces.h
	$(CC) -c Rook.cpp
