CC	:= g++
CXX := g++ -std=c++11 -Wall

Chess++: main.cpp draw.cpp setup.cpp decodeEncode.cpp position.cpp Board.o Bishop.o King.o Knight.o Pawn.o Piece.o Queen.o Rook.o
	$(CXX) main.cpp draw.cpp setup.cpp decodeEncode.cpp position.cpp Board.o Bishop.o King.o Knight.o Pawn.o Piece.o Queen.o Rook.o -o Chess++

Piece.o: Piece.cpp Pieces.h
	$(CXX) -c Piece.cpp -o Piece.o

Bishop.o: Bishop.cpp Bishop.h Piece.h
	$(CXX) -c Bishop.cpp -o Bishop.o

King.o: King.cpp King.h Piece.h
	$(CXX) -c King.cpp -o King.o

Knight.o: Knight.cpp Knight.h Piece.h
	$(CXX) -c Knight.cpp -o Knight.o

Pawn.o: Pawn.cpp Pawn.h Piece.h
	$(CXX) -c Pawn.cpp -o Pawn.o

Queen.o: Queen.cpp Queen.h Piece.h
	$(CXX) -c Queen.cpp -o Queen.o

Rook.o: Rook.cpp Rook.h Piece.h
	$(CXX) -c Rook.cpp -o Rook.o

Board.o: Board.cpp Board.h
	$(CXX) -c Board.cpp -o Board.o

Checktest: checktest.cpp draw.cpp setup.cpp decodeEncode.cpp position.cpp Board.o Bishop.o King.o Knight.o Pawn.o Piece.o Queen.o Rook.o
	$(CXX) checktest.cpp draw.cpp setup.cpp decodeEncode.cpp position.cpp Board.o Bishop.o King.o Knight.o Pawn.o Piece.o Queen.o Rook.o -o Checktest
