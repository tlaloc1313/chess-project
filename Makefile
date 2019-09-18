CC	:= clang++
CXX := clang++
VPATH = /pieceFiles

CChess: main.cpp draw.cpp setup.cpp checkCheck.cpp decodeEncode.cpp position.cpp checkSquareOccupied.cpp Bishop.o King.o Knight.o Pawn.o Piece.o Queen.o Rook.o
	$(CXX) main.cpp draw.cpp setup.cpp checkCheck.cpp decodeEncode.cpp position.cpp checkSquareOccupied.cpp Bishop.o King.o Knight.o Pawn.o Piece.o Queen.o Rook.o -o CChess

Piece.o: Piece.cpp Pieces.h
	$(CXX) -c Piece.cpp

Bishop.o: Bishop.cpp Pieces.h
	$(CXX) -c Bishop.cpp

King.o: King.cpp Pieces.h
	$(CXX) -c King.cpp

Knight.o: Knight.cpp Pieces.h
	$(CXX) -c Knight.cpp

Pawn.o: Pawn.cpp Pieces.h
	$(CXX) -c Pawn.cpp

Queen.o: Queen.cpp Pieces.h
	$(CXX) -c Queen.cpp

Rook.o: Rook.cpp Pieces.h
	$(CXX) -c Rook.cpp

Piecetest: Pawn.o Bishop.o Knight.o piecetest.cpp decodeEncode.cpp
	$(CXX) Pieces.h Pawn.cpp Bishop.cpp Knight.cpp decodeEncode.cpp piecetest.cpp -o piecetest
