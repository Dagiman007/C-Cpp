exe : ex1.cpp ex2.cpp ex3.cpp ex4.cpp ex5.cpp ex6.cpp ex7.cpp ex8.cpp diagonalMatrix.o lowerTriangularMatrix.o matrix.o SkewSymmetricMatrix.o squareMatrix.o SymmetricMatrix.o vector.o
	g++ ex1.cpp matrix.o squareMatrix.o diagonalMatrix.o vector.o -o ex1
	g++ ex2.cpp matrix.o squareMatrix.o SymmetricMatrix.o lowerTriangularMatrix.o vector.o -o ex2
	g++ ex3.cpp matrix.o squareMatrix.o SkewSymmetricMatrix.o vector.o -o ex3
	g++ ex4.cpp matrix.o squareMatrix.o lowerTriangularMatrix.o SymmetricMatrix.o vector.o -o ex4
	g++ ex5.cpp matrix.o squareMatrix.o vector.o -o ex5
	g++ ex6.cpp matrix.o squareMatrix.o diagonalMatrix.o lowerTriangularMatrix.o vector.o -o ex6
	g++ ex7.cpp matrix.o squareMatrix.o vector.o -o ex7
	g++ ex8.cpp matrix.o squareMatrix.o diagonalMatrix.o lowerTriangularMatrix.o vector.o -o ex8
	

diagonalMatrix.o : diagonalMatrix.cpp
	g++ -c diagonalMatrix.cpp

lowerTriangularMatrix.o : lowerTriangularMatrix.cpp
	g++ -c lowerTriangularMatrix.cpp

matrix.o : matrix.cpp
	g++ -c matrix.cpp

SkewSymmetricMatrix.o : SkewSymmetricMatrix.cpp
	g++ -c SkewSymmetricMatrix.cpp

squareMatrix.o : squareMatrix.cpp
	g++ -c squareMatrix.cpp

SymmetricMatrix.o : SymmetricMatrix.cpp
	g++ -c SymmetricMatrix.cpp

vector.o : vector.cpp
	g++ -c vector.cpp