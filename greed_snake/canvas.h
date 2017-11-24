#pragma once

class Canvas
{
public:
    Canvas(int width, int height); // constructor
    ~Canvas();	// destructor

    void MoveSnake(char directionNow, char directionLast);
    void UpSnakeHead();
    void DownSnakeHead();
    void LeftSnakeHead();
    void RightSnakeHead();
    void UpSnakeBody();
    void DownSnakeBody();
    void LeftSnakeBody();
    void RightSnakeBody();
    //void DrawRectangle(int left, int top, int width, int height);
    void Output() const;
    int PositionRow1;
    int PositionCol1;
    int PositionRow2;
    int PositionCol2;
    int PositionRow3;
    int PositionCol3;

private:
    void Init(int width, int height);
    void Release();

    char ** _buffer;
    int _width;
    int _height;

};
