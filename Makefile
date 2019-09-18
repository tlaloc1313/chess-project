CC	:= g++
CXX := g++
VPATH =

CChess: main.cpp draw.cpp setup.cpp checkCheck.cpp decodeEncode.cpp position.cpp checkSquareOccupied.cpp Bishop.o King.o Knight.o Pawn.o Piece.o Queen.o Rook.o
	$(CXX) main.cpp draw.cpp setup.cpp checkCheck.cpp decodeEncode.cpp position.cpp checkSquareOccupied.cpp Bishop.o King.o Knight.o Pawn.o Piece.o Queen.o Rook.o -o CChess

Piece.o: Piece.cpp Pieces.h
	$(CXX) -c Piece.cpp -o Piece.o

Bishop.o: Bishop.cpp Pieces.h
	$(CXX) -c Bishop.cpp -o Bishop.o

King.o: King.cpp Pieces.h
	$(CXX) -c King.cpp -o King.o

Knight.o: Knight.cpp Pieces.h
	$(CXX) -c Knight.cpp -o Knight.o

Pawn.o: Pawn.cpp Pieces.h
	$(CXX) -c Pawn.cpp -o Pawn.o

Queen.o: Queen.cpp Pieces.h
	$(CXX) -c Queen.cpp -o Queen.o

Rook.o: Rook.cpp Pieces.h
	$(CXX) -c Rook.cpp -o Rook.o

Piecetest: Pawn.o Bishop.o Knight.o Piece.o piecetest.cpp decodeEncode.cpp position.cpp
	$(CXX) piecetest.cpp position.cpp Pawn.o Piece.o Bishop.o Knight.o decodeEncode.cpp -o Piecetest.out
