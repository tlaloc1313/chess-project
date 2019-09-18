CC	:= g++
CXX := g++
VPATH = pieceFiles

CChess: main.cpp draw.cpp setup.cpp checkCheck.cpp decodeEncode.cpp position.cpp checkSquareOccupied.cpp Bishop.o King.o Knight.o Pawn.o Piece.o Queen.o Rook.o
	$(CXX) main.cpp draw.cpp setup.cpp checkCheck.cpp decodeEncode.cpp position.cpp checkSquareOccupied.cpp Bishop.o King.o Knight.o Pawn.o Piece.o Queen.o Rook.o -o CChess

Piece.o: pieceFiles/Piece.cpp pieceFiles/Pieces.h
	$(CXX) -c pieceFiles/Piece.cpp -o Piece.o

Bishop.o: pieceFiles/Bishop.cpp pieceFiles/Pieces.h
	$(CXX) -c pieceFiles/Bishop.cpp -o Bishop.o

King.o: pieceFiles/King.cpp pieceFiles/Pieces.h
	$(CXX) -c pieceFiles/King.cpp -o King.o

Knight.o: pieceFiles/Knight.cpp pieceFiles/Pieces.h
	$(CXX) -c pieceFiles/Knight.cpp -o Knight.o

Pawn.o: pieceFiles/Pawn.cpp pieceFiles/Pieces.h
	$(CXX) -c pieceFiles/Pawn.cpp -o Pawn.o

Queen.o: pieceFiles/Queen.cpp pieceFiles/Pieces.h
	$(CXX) -c pieceFiles/Queen.cpp -o Queen.o

Rook.o: pieceFiles/Rook.cpp pieceFiles/Pieces.h
	$(CXX) -c pieceFiles/Rook.cpp -o Rook.o

Piecetest: Pawn.o Bishop.o Knight.o Piece.o piecetest.cpp decodeEncode.cpp position.cpp
	$(CXX) piecetest.cpp position.cpp Pawn.o Piece.o Bishop.o Knight.o decodeEncode.cpp -o Piecetest.out
