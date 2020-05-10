#include "Matrix.h"
using namespace std;

void tic_tac_toc();

int main(){
    srand(time(NULL));
    Matrix m1;
    Matrix m2(3, 'F');
    Matrix m3(4, 'L', 1);
    Matrix m4(5,'F',1,10);

    cout << "m1 type " << m1.getType() << endl;
    //m2.set(1,1.5);
    //m2.set(6,0.34);
    //m2.set(5,10);

    //m1.scanMatrix(3, 'F');
    m4.printMatrix();
    cout << "Column sum norm of m1 is " << m1.columnSumNorm() << endl;
    cout << "Row sum norm of m1 is " << m1.rowSumNorm() << endl;
    cout << "Frobenius norm of m1 is " << m1.frobeniusNorm() << endl;
    cout << "Trace of m1 is " << m1.trace() << endl;
    //tic_tac_toc();
}

void tic_tac_toc() {
  // Takes values to use for 2 players
  int p1;
  int p2;
  cout << "Player 1 avatar" << endl;
  cin >> p1;
  assert(p1 != 0);
  cout << "Player 2 avatar" << endl;
  cin >> p2;
  assert(p2 != 0);

  // Define game board pointers for players
  Matrix m(3,'F',0);
  int k1;
  int k2;
  int move = 1;
  while (move) {
    // Display play field
    m.printMatrix();
    //Player 1 move
    cout << "Player 1: Enter a point: ";
    cin >> k1;
    assert(m.get(k1) == 0);
    m.set(k1, p1);

    //Player 2 move
    cout << "Player 2: Enter a point: ";
    cin >> k2;
    assert(m.get(k2) == 0);
    m.set(k2, p2);
   }

   // Check whether one of the players has won
   if ((m.columnSumNorm() == 3*p1) || (m.rowSumNorm() == 3*p1) || (m.trace() == 3*p1)) {
     cout << "Player 1 wins\n";
     move = 0;
   }
   else if ((m.columnSumNorm() == 3*p2) || (m.rowSumNorm() == 3*p2) || (m.trace() == 3*p2)) {
     cout << "Player 2 wins\n";
     move = 0;
   }

   if (m.frobeniusNorm() != 0) {
     cout << "Tied game\n";
     move = 0;
   }
}
