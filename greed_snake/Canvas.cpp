#include <iostream>
#include "Canvas.h"

using namespace std;

Canvas::Canvas(int width, int height)
{
    Init(width, height);
}

Canvas::~Canvas()
{
    Release();
}

void Canvas::Init(int width, int height)
{
    this->_buffer = new char *[height];
    for (int i = 0; i < height; ++i)
    {
        _buffer[i] = new char[width];
    }
    for (int row = 0; row < height; ++row)
    {
        for (int column = 0; column < width; ++column)
        {
            _buffer[row][column] = ' ';
        }
    }
    _width = width;
    _height = height;
    PositionRow1 = 10;
    PositionCol1 = 10;
    PositionRow2 = 11;
    PositionCol2 = 10;
    PositionRow3 = 12;
    PositionCol3 = 10;
}

void Canvas::UpSnakeHead()
{
    _buffer[PositionRow1][PositionCol1] = ' ';
    PositionRow1 -= 1;
    _buffer[PositionRow1][PositionCol1] = '1';
}

void Canvas::UpSnakeBody()
{
    _buffer[PositionRow2][PositionCol2] = ' ';
    PositionRow2 -= 1;
    _buffer[PositionRow2][PositionCol2] = '2';
//    _buffer[PositionRow3][PositionCol3] = ' ';
//    PositionRow3 -= 1;
//    _buffer[PositionRow3][PositionCol3] = '3';
}

void Canvas::DownSnakeHead()
{
    _buffer[PositionRow1][PositionCol1] = ' ';
    PositionRow1 += 1;
    _buffer[PositionRow1][PositionCol1] = '1';
}

void Canvas::DownSnakeBody()
{
    _buffer[PositionRow2][PositionCol2] = ' ';
    PositionRow2 += 1;
    _buffer[PositionRow2][PositionCol2] = '2';
//    _buffer[PositionRow3][PositionCol3] = ' ';
//    PositionRow3 += 1;
//    _buffer[PositionRow3][PositionCol3] = '3';
}

void Canvas::LeftSnakeHead()
{
    _buffer[PositionRow1][PositionCol1] = ' ';
    PositionCol1 -= 1;
    _buffer[PositionRow1][PositionCol1] = '1';
}
void Canvas::LeftSnakeBody()
{
    _buffer[PositionRow2][PositionCol2] = ' ';
    PositionCol2 -= 1;
    _buffer[PositionRow2][PositionCol2] = '2';
//    _buffer[PositionRow3][PositionCol3] = ' ';
//    PositionCol3 -= 1;
//    _buffer[PositionRow3][PositionCol3] = '3';
}

void Canvas::RightSnakeHead()
{
    _buffer[PositionRow1][PositionCol1] = ' ';
    PositionCol1 += 1;
    _buffer[PositionRow1][PositionCol1] = '1';
}
void Canvas::RightSnakeBody()
{
    _buffer[PositionRow2][PositionCol2] = ' ';
    PositionCol2 += 1;
    _buffer[PositionRow2][PositionCol2] = '2';
//    _buffer[PositionRow3][PositionCol3] = ' ';
//    PositionCol3 += 1;
//    _buffer[PositionRow3][PositionCol3] = '3';
}

//void MoveSnakeBody(char Bodydirection)
//{
//    switch (Bodydirection) {
//    case 'w':
//        canvas.UpSnakeBody();
//        break;
//    case 's':
//        canvas.DownSnakeBody();
//        break;
//    case 'a':
//        canvas.LeftSnakeBody();
//        break;
//    case 'd':
//        canvas.RightSnakeBody();
//        break;
//    }

//}

//void Canvas::MoveSnake(char directionNow, char directionLast)
//{
//    switch (directionNow) {
//    case 'w':
//        canvas.UpSnakeHead();
//        break;
//    case 's':
//        canvas.DownSnakeHead();
//        break;
//    case 'a':
//        canvas.LeftSnakeHead();
//        break;
//    case 'd':
//        canvas.RightSnakeHead();
//        break;
//    }
//    MoveSnakeBody(directionLast);
//}

void Canvas::Output() const
{
    for (int row = 0; row < _height; ++row)
    {
        for (int column = 0; column < _width; ++column)
        {
            cout << _buffer[row][column];
        }
        cout << "\n";
    }
}

void Canvas::Release()
{
    if (_buffer == nullptr)
        return;

    for (int i = 0; i < _height; ++i)
    {
        delete[]_buffer[i];
    }

    delete[]_buffer;
    _buffer = nullptr;
}
