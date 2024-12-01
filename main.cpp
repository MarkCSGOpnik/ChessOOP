#include <iostream>
#include <string>
#include <unordered_map>

class ChessPiece{
    public:
    virtual bool isValidMove(int startX, int startY, int endX, int endY) = 0;
    static int step;
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

class Pawn : public ChessPiece{
    public:
    bool isValidMove(int startX, int startY, int endX, int endY) override
    {
        
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
        
    }

    void move(){
        while(true)
        {
        startCord();
        endCord();
        enterFigure();
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
            }
            while(true)
            {
            std::cout << "Enter start y" << std::endl;
            std::cin >> currentStartY;
            if(checkCorrectlyEnterStartY()) break;
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
            if(checkCorrectlyEnterEndY()) break;
            }
        }
    }



    void enterFigure()
    {
        switch (figure[currentFigure])
        {
        case -1: 
        case 1:
        {
            if(king.isValidMove(currentStartX, currentStartY, currentEndX, currentEndY)) ChessPiece::step++;
            break;
        }
        case -2:
        case 2:
        {
            queen.isValidMove(currentStartX, currentStartY, currentEndX, currentEndY);
            break;
        }   
        case -3:
        case 3: 
        {
            bishop.isValidMove(currentStartX, currentStartY, currentEndX, currentEndY);
            break;
        }  
        case -4:
        case 4:
        {
            knight.isValidMove(currentStartX, currentStartY, currentEndX, currentEndY);
            break;
        }
        case -5:
        case 5:
        {
            rook.isValidMove(currentStartX, currentStartY, currentEndX, currentEndY);
            break;
        }    
        case -6:
        case 6: 
        {
            pawn.isValidMove(currentStartX, currentStartY, currentEndX, currentEndY);
            break;
        }  
        default:
       {

       }
       }
    }

    private:
    King king;
    Queen queen;
    Bishop bishop;
    Knight knight;
    Rook rook;
    Pawn pawn;
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