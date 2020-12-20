#pragma once 

#include "FigureFactory.h"
#include "Cells.h"
#include <vector>
#include <iostream>
#include <memory>
#include <Windows.h>

using namespace std;
class PlayField
{
public:

    enum Direction
    {
        DOWN = 80,
        UP = 72,
        RIGHT = 77,
        LEFT = 75
    };

    PlayField(int xSize, int ySize);

    virtual ~PlayField();

    void setFigurePosition(std::shared_ptr<Figure> aFigure, const Position& aPosition);

    bool addFigure(std::shared_ptr<Figure> aFigure);

    void updateFigures(const float& delta);

    void movePacMan(const float& delta);

    void moveGhosts(const float& delta);

    void moveFigure(std::shared_ptr<Figure> figure);

    void setPacManDirection(const int& aKeyCode);

    int getPoints() const;

    int getLifes() const;

    CHAR_INFO* getBuffer();

private:

    void fillField();

    void setCell(const Position& aPos, const wchar_t& aSymbol, 
        const short& aColor = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

    char getCellSymbol(const Position& aPosition) const;

    bool isFigureTypeExists(const Figure& aFigure) const;

    bool isJailCell(const Position& aPosition) const;

    bool isDecidingCell(const Position& aPosition) const;

    std::shared_ptr<Figure> getPacMan();

    const int xSize;

    const int ySize;

    vector<std::shared_ptr<Figure>> mFigures;

    int mScore;

    int mLife;

    CHAR_INFO* mChiBuffer;

    string mScoreStr{ "Score:" };

    vector<Position> mDecidingCells;

    vector<Position> mJailCells;

    vector<string> mLabyrinthMap =
    { {"0000000000000000000000000000"}
     ,{"02....d......00......d....20"}
     ,{"0.0000.00000.00.00000.0000.0"}
     ,{"0.0000.00000.00.00000.0000.0"}
     ,{"0.0000.00000.00.00000.0000.0"}
     ,{"0d....d..d..d..d..d..d....d0"}
     ,{"0.0000.00.00000000.00.0000.0"}
     ,{"0.0000.00.00000000.00.0000.0"}
     ,{"0.....d00....00....00d.....0"}
     ,{"000000.00000.00.00000.000000"}
     ,{"000000.00000.00.00000.000000"}
     ,{"000000.00...d..d...00.000000"}
     ,{"000000.00.000##000.00.000000"}
     ,{"000000.00.000##000.00.000000"}
     ,{"......d..d0######0d..d......"}
     ,{"000000.00.0######0.00.000000"}
     ,{"000000.00.00000000.00.000000"}
     ,{"000000.00d........d00.000000"}
     ,{"000000.00.00000000.00.000000"}
     ,{"000000.00.00000000.00.000000"}
     ,{"0.....d..d...00...d..d.....0"}
     ,{"0.0000.00000.00.00000.0000.0"}
     ,{"0.0000.00000.00.00000.0000.0"}
     ,{"0...00d..d..d..d..d..d00...0"}
     ,{"000.00.00.00000000.00.00.000"}
     ,{"000.00.00.00000000.00.00.000"}
     ,{"0..d...00....00....00...d..0"}
     ,{"0.0000000000.00.0000000000.0"}
     ,{"0.0000000000.00.0000000000.0"}
     ,{"02..........d..d..........20"}
     ,{"0000000000000000000000000000"}
     ,{"                            "} };

};


