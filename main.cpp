#include <iostream>
#include <string>

class ChessBoard {
    public:
    ChessBoard()
    {
        for(int i = 1; i < 9; i++)
        {
            for(int j = 1; j < 9; j++)
            {
                if(i==1)
                {
                if(j == 1 || 8) chessBoardArr[i][j] = "whiteRook";
                if(j == 2 || 7) chessBoardArr[i][j] = "whiteKnight";
                if(j == 3 || 6) chessBoardArr[i][j] = "whiteBishop";
                if(j==4) chessBoardArr[i][j] = "whiteQueen";
                if(j==5) chessBoardArr[i][j] = "whiteKing";
                }
                if(i=2)chessBoardArr[i][j] = "whitePawn";
                if(i>3 && i<7)chessBoardArr[i][j] = "";
                if(i=7)chessBoardArr[i][j] = "blackPawn";
                if(i==8)
                {
                if(j == 1 || 8) chessBoardArr[i][j] = "blackRook";
                if(j == 2 || 7) chessBoardArr[i][j] = "blackKnight";
                if(j == 3 || 6) chessBoardArr[i][j] = "blackBishop";
                if(j==4) chessBoardArr[i][j] = "blackQueen";
                if(j==5) chessBoardArr[i][j] = "blackKing";
                }
            }
        }
    }
    void printBoard()
    {
        
    }

    void startCord()
        {
        while(true)
        {
        char startX;
        std::cout << "Enter start x" << std::endl;
        std::cin >> startX;
        if(checkCorrectlyStartEnterX(startX)) break;
        }

        while(true)
        {
        char startY;
        std::cout << "Enter start y" << std::endl;
        std::cin >> startY;
        if(checkCorrectlyStartEnterY(startY)) break;
        }
    }
    private:
    

    protected:
    std::string chessBoardArr[8][8];
    bool checkCorrectlyStartEnterX(char startX)
    {
        for(int i = 65; i < 73; i++)
        {
            if((char)i==startX) return true;
        }
        return false;
    }
    bool checkCorrectlyStartEnterY(char startY)
    {
        for(int i = 1; i < 9; i++)
        {
            if(i==(int)startY) return true;
        }
        return false;
    }
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