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
                if(i==0)
                {
                if(j == 0 || j == 7) chessBoardArr[i][j] = "whiteRook";
                if(j == 1 || j == 6) chessBoardArr[i][j] = "whiteKnight";
                if(j == 2 || j == 5) chessBoardArr[i][j] = "whiteBishop";
                if(j==3) chessBoardArr[i][j] = "whiteQueen";
                if(j==4) chessBoardArr[i][j] = "whiteKing";
                }
                if(i==1)chessBoardArr[i][j] = "whitePawn";
                if(i>2 && i<6)chessBoardArr[i][j] = "";
                if(i==6)chessBoardArr[i][j] = "blackPawn";
                if(i==7)
                {
                if(j == 0 || j == 7) chessBoardArr[i][j] = "blackRook";
                if(j == 1 || j == 6) chessBoardArr[i][j] = "blackKnight";
                if(j == 2 || j == 5) chessBoardArr[i][j] = "blackBishop";
                if(j==3) chessBoardArr[i][j] = "blackQueen";
                if(j==4) chessBoardArr[i][j] = "blackKing";
                }
            }
        }
        printBoard();
    }
    void printBoard()
    {
        
    }

    void startCord()
        {
        while(true)
        {
            while(true)
            {
            char tempStartX;
            std::cout << "Enter start x" << std::endl;
            std::cin >> tempStartX;
            if(checkCorrectlyStartEnterX(tempStartX)) break;
            }
            while(true)
            {
            std::cout << "Enter start y" << std::endl;
            std::cin >> currentStartY;
            if(checkCorrectlyStartEnterY(currentStartY)) break;
            }
            if(checkAvailabilityFigure()) break;
        }
    }
    void checkFigure()
    {
        
    }

    private:
    int currentStartX;
    int currentStartY;
    std::string currentFigure;

    protected:
    std::string chessBoardArr[8][8];
    bool checkCorrectlyStartEnterX(char startX)
    {
        for(int i = 65; i < 73; i++)
        {
            if((char)i == startX)
            {
                currentStartX = i - 65;
                return true;
            } 
        }
        return false;
    }
    bool checkCorrectlyStartEnterY(char startY)
    {
        for(int i = 0; i < 8; i++)
        {
            if((int)startY == i) return true;
        }
        return false;
    }
    bool checkAvailabilityFigure()
    {
        if(chessBoardArr[currentStartY][currentStartX]!="") 
        {
            currentFigure = chessBoardArr[currentStartY][currentStartX];
            return true;
        }
            else return false;
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
    
    
    return 0;
}