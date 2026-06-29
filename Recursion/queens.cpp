#include <iostream>
#include <ostream>
class ChessBoard{
public:
    ChessBoard();
    ChessBoard(int);
    void findSolution();
private:
    const bool available;
    const int squares, norm;
    bool *column, *leftDiagonal, *rightDiagonal;
    int *positionInRow, howMany;
    void putQueen(int);
    void printBoard(std::ostream&);
    void initializeBoard();
};

ChessBoard::ChessBoard() : available(true), squares(8), norm(squares-1){
    initializeBoard();
}

ChessBoard::ChessBoard(int n) : available(true), squares(n), norm(squares-1){
    initializeBoard();
}

void ChessBoard::initializeBoard(){
    int i;
    column = new bool[squares];
    positionInRow = new int[squares];
    leftDiagonal = new bool[squares*2 - 1];
    rightDiagonal = new bool[squares*2 - 1];

    for(i = 0; i < squares; i++){
        positionInRow[i] = -1;
    }
    for(i = 0; i < squares; i++){
        column[i] = available;
    }
    for(i = 0; i < squares; i++){
        leftDiagonal[i] = rightDiagonal[i] = available;
    }

    howMany = 0;
}

void ChessBoard::putQueen(int row){
    for (int col = 0; col < squares; col++){
        if(column[col] == available && leftDiagonal[row+col] == available && rightDiagonal[row-col+norm] == available){
            positionInRow[row] = col;
            column[col] = available;
            leftDiagonal[row+col] = !available;
            rightDiagonal[row-col+norm] = !available;
            if(row < squares-1) putQueen(row+1);
            else printBoard(std::cout);
            column[col] = available;
            leftDiagonal[row+col] = available;
            rightDiagonal[row-col+norm] = available;
        }
    }
}

void ChessBoard::findSolution(){
    putQueen(0);
    std::cout << howMany << " solutions" << std::endl;
}

void ChessBoard::printBoard(std::ostream& out){

}

int main(){
    ChessBoard cb;
    cb.findSolution();
}
