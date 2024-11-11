#include <iostream>
#include <string>

class ChessBoard {
    public:
    void printBoard()
    {

    }
};

class ChessPiece{
    public:
    ChessPiece()
    {
        for(int i; i < 8; i++)
        {
            for(int j; j < 8; j++)
            {
                arrChess[i][j] = 0;
            }
        }    
    }
    bool isValidMove(int startX, int startY, int endX, int endY)
    {
        
    }
    protected:
    int arrChess[8][8];

};


int main()
{
    
    return 0;
}