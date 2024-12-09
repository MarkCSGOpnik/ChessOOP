#include <iostream>
#include <string>
#include <unordered_map>

class ChessPiece{
    public:
    virtual bool isValidMove(int startX, int startY, int endX, int endY) = 0;
};

class King : public ChessPiece{ 
    public:
    bool isValidMove(int startX, int startY, int endX, int endY) override 
    {
        if(startX != endX || startY != endY){
            if(startX == endX-- || startX == endX++ || startY == endY-- || startY == endY++) return true;
        }
        return false;
    }
};

class Queen : public ChessPiece{ 
    public:
    bool isValidMove(int startX, int startY, int endX, int endY) override
    {
        if(startX != endX && startY != endY){
            if(endX - startX == endY - startY || endX - startX == -(endY - startY)) return true;
        }
        else if(startX != endX || startY != endY){
            if(startX == endX || startY == endY) return true;
        }
        return false;
    }
};

class Bishop : public ChessPiece{ 
    public:
    bool isValidMove(int startX, int startY, int endX, int endY) override
    {
        if(startX != endX && startY != endY){
            if(endX - startX == endY - startY || endX - startX == -(endY - startY)) return true;
        }
        return false;
    }
};

class Knight : public ChessPiece{
    public:
    bool isValidMove(int startX, int startY, int endX, int endY) override
    {
        if(startX != endX && startY != endY){
            if(startX - endX == 2 || endX - startX == 2){
                if(startY - endY == 1 || endY-startY == 1)return true;
            }
            else if(startY - endY == 2 || endY - startY == 2){
                if(startX - endX == 1 || endX - startX == 1)return true;
            }
        }
        return false;
    }
};

class Rook : public ChessPiece{
    public:
    bool isValidMove(int startX, int startY, int endX, int endY) override
    {
        if(startX != endX || startY != endY){
            if(startX == endX || startY == endY) return true;
        }
        return false;
    }
};

class PawnW : public ChessPiece{
    public:
    bool isValidMove(int startX, int startY, int endX, int endY) override
    {
        if(startX == endX && startY == endY++) return true;
        if(startY == 1 && startY == endY+2 && startX == endX) return true;
        if(startY == endY++ && startX == endX++ || startX == endX--) return true;
        return false;
    }
};

class PawnB : public ChessPiece{
    public:
    bool isValidMove(int startX, int startY, int endX, int endY) override
    {
        if(startX == endX && startY == endY--) return true;
        if(startY == 6 && startY == endY-2 && startX == endX) return true;
        if(startY == endY-- && startX == endX++ || startX == endX--) return true;
        return false;
    }
};


class ChessBoard {
    public:
    ChessBoard()
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (i == 0)
                {
                    if (j == 0 || j == 7) chessBoardArr[i][j] = "whiteRook";
                    if (j == 1 || j == 6) chessBoardArr[i][j] = "whiteKnight";
                    if (j == 2 || j == 5) chessBoardArr[i][j] = "whiteBishop";
                    if (j == 3) chessBoardArr[i][j] = "whiteQueen";
                    if (j == 4) chessBoardArr[i][j] = "whiteKing";
                }
                if (i == 1)chessBoardArr[i][j] = "whitePawn";
                if (i > 2 && i < 6)chessBoardArr[i][j] = "";
                if (i == 6)chessBoardArr[i][j] = "blackPawn";
                if (i == 7)
                {
                    
                    if (j == 0 || j == 7) chessBoardArr[i][j] = "blackRook";
                    if (j == 1 || j == 6) chessBoardArr[i][j] = "blackKnight";
                    if (j == 2 || j == 5) chessBoardArr[i][j] = "blackBishop";
                    if (j == 3) chessBoardArr[i][j] = "blackQueen";
                    if (j == 4) chessBoardArr[i][j] = "blackKing";
                }
            }
        }
    printBoard();
    }
    void printBoard()
    {
        for(int i = 0;i < 8;i++){
            for(int j = 0;j < 8;j++){
                if(chessBoardArr[i][j] == "whiteRook") std::cout<<" wR";
                if(chessBoardArr[i][j] == "whiteKnight") std::cout<<" wK";
                if(chessBoardArr[i][j] == "whiteBishop") std::cout<<" wB";
                if(chessBoardArr[i][j] == "whiteQueen") std::cout<<" wQ";
                if(chessBoardArr[i][j] == "whiteKing") std::cout<<" ++";
                if(chessBoardArr[i][j] == "whitePawn") std::cout<<" wP";
                if(chessBoardArr[i][j] == "blackPawn") std::cout<<" bP";
                if(chessBoardArr[i][j] == "blackRook") std::cout<<" bR";
                if(chessBoardArr[i][j] == "blackKnight") std::cout<<" bK";
                if(chessBoardArr[i][j] == "blackBishop") std::cout<<" bB";
                if(chessBoardArr[i][j] == "blackQueen") std::cout<<" bQ";
                if(chessBoardArr[i][j] == "blackKing") std::cout<<" --";
                
            }
            std::cout << std::endl;
        }
    }

    void move(){
        while(true)
        {
            while(true)
            {
            startCord();
            endCord();
            if(enterFigure()) break;
            }
            chessBoardArr[currentStartX][currentEndY] = " ";
            chessBoardArr[currentEndX][currentEndY] = currentFigure;
            printBoard();
        }
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
            if(checkCorrectlyEnterStartX(tempStartX)) break;
            std::cout << "S";
            }
            while(true)
            {
            std::cout << "Enter start y" << std::endl;
            std::cin >> currentStartY;
            currentStartY--;
            if(checkCorrectlyEnterStartY()) break;
            std::cout << "S";
            }
            if(checkAvailabilityFigure()) break;
        }
    }

    void endCord()
    {
        while(true)
        {
            while(true)
            {
            char tempEndX;
            std::cout << "Enter end x" << std::endl;
            std::cin >> tempEndX;
            if(checkCorrectlyEnterEndX(tempEndX)) break;
            }
            while(true)
            {
            std::cout << "Enter end y" << std::endl;
            std::cin >> currentEndY;
            currentEndY--;
            if(checkCorrectlyEnterEndY()) break;
            }
            if(enterFigure()) break;
        }
    }



    bool enterFigure()
    {
        switch (figure[currentFigure])
        {
        case -1: 
        case 1:
        {
            return king.isValidMove(currentStartX, currentStartY, currentEndX, currentEndY);
        }
        case -2:
        case 2:
        {
            return queen.isValidMove(currentStartX, currentStartY, currentEndX, currentEndY);
        }   
        case -3:
        case 3: 
        {
            return bishop.isValidMove(currentStartX, currentStartY, currentEndX, currentEndY);
        }  
        case -4:
        case 4:
        {
            return knight.isValidMove(currentStartX, currentStartY, currentEndX, currentEndY);
        }
        case -5:
        case 5:
        {
            return rook.isValidMove(currentStartX, currentStartY, currentEndX, currentEndY);
        }    
        case -6:
        {
            return pawnB.isValidMove(currentStartX, currentStartY, currentEndX, currentEndY);
        }
        case 6: 
        {
            return pawnW.isValidMove(currentStartX, currentStartY, currentEndX, currentEndY);
        }  
        default:
       {
            return false;
       }
       }
    }

    private:

    int step;
    King king;
    Queen queen;
    Bishop bishop;
    Knight knight;
    Rook rook;
    PawnW pawnW;
    PawnB pawnB;

    std::unordered_map<std::string, int> figure = {
        {"whiteKing", 1},
        {"whiteQueen", 2},
        {"whiteBishop", 3},
        {"whiteKnight", 4},
        {"whiteRook", 5},
        {"whitePawn", 6},
        {"blackKing", -1},
        {"blackQueen", -2},
        {"blackBishop", -3},
        {"blackKnight", -4},
        {"blackRook", -5},
        {"blackPawn", -6}
    };

    std::string currentFigure;
    int currentStartX;
    int currentStartY;
    int currentEndX;
    int currentEndY;
    std::string chessBoardArr[8][8];

    bool checkCorrectlyEnterStartX(char x)
    {
        for(int i = 65; i < 73; i++)
        {
            if((char)i == x)
            {
                this->currentStartX = i - 65;
                return true;
            } 
        }
        return false;
    }

    bool checkCorrectlyEnterStartY()
    {
        for(int i = 0; i < 8; i++){
            if(this->currentStartY == i) return true;
        }
        return false;
    }

    bool checkCorrectlyEnterEndX(char x)
    {
        for(int i = 65; i < 73; i++)
        {
            if((char)i == x)
            {
                this->currentEndX = i - 65;
                return true;
            } 
        }
        return false;
    }

    bool checkCorrectlyEnterEndY()
    {
        for(int i = 0; i < 8; i++){
            if(this->currentEndY == i) return true;
        }
        return false;
    }



    bool checkAvailabilityFigure()
    {
        if(chessBoardArr[currentStartY][currentStartX] != "") {
            currentFigure = chessBoardArr[currentStartY][currentStartX];
            return true;
        }
            else return false;
    }
};



int main()
{
    ChessBoard game;
    game.move();
    return 0;
}