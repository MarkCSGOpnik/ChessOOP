#include <iostream>
#include <string>

class ChessBoard {
    public:
    ChessBoard()
    {
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                
            }
        }
    }
    void printBoard()
    {

    }
    private:
    std::string chessBoardArr[8][8];
};

class ChessPiece{
    public:
    virtual bool isValidMove(int startX, int startY, int endX, int endY) = 0;
};

class King : public ChessPiece{
    bool isValidMove(int startX, int startY, int endX, int endY) override 
    {
        
    }
};

class Queen : public ChessPiece{
    bool isValidMove(int startX, int startY, int endX, int endY) override
    {

    }
};

class Bishop : public ChessPiece{
    bool isValidMove(int startX, int startY, int endX, int endY) override
    {

    }
};

class Knight : public ChessPiece{
    bool isValidMove(int startX, int startY, int endX, int endY) override
    {

    }
};

class Rook : public ChessPiece{
    bool isValidMove(int startX, int startY, int endX, int endY) override
    {

    }
};

class Pawn : public ChessPiece{
    bool isValidMove(int startX, int startY, int endX, int endY) override
    {

    }
};

int main()
{
    ChessBoard board;

    return 0;
}