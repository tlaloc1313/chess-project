CC	:= g++
CXX := g++
VPATH =

Chess++: main.cpp draw.cpp setup.cpp checkCheck.cpp decodeEncode.cpp position.cpp Board.o Bishop.o King.o Knight.o Pawn.o Piece.o Queen.o Rook.o
	$(CXX) main.cpp draw.cpp setup.cpp checkCheck.cpp decodeEncode.cpp position.cpp Board.o Bishop.o King.o Knight.o Pawn.o Piece.o Queen.o Rook.o -o Chess++.out

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

Board.o: Board.cpp Board.h
	$(CXX) -c Board.cpp -o Board.o

Piecetest: Pawn.o Bishop.o Rook.o Knight.o Piece.o King.cpp piecetest.cpp decodeEncode.cpp Queen.o position.cpp
	$(CXX) piecetest.cpp position.cpp Pawn.o Piece.o King.cpp Bishop.o Knight.o Rook.o Queen.o decodeEncode.cpp -o Piecetest.out
