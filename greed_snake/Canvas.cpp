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
    PositionRow = 10;
    PositionCol = 10;
}

void Canvas::UpSnake()
{
    _buffer[PositionRow][PositionCol] = ' ';
    PositionRow -= 1;
    _buffer[PositionRow][PositionCol] = '*';
//  cout << PositionRow << " " << PositionCol << endl;
}

void Canvas::DownSnake()
{
    _buffer[PositionRow][PositionCol] = ' ';
    PositionRow += 1;
    _buffer[PositionRow][PositionCol] = '*';
}

void Canvas::LeftSnake()
{
    _buffer[PositionRow][PositionCol] = ' ';
    PositionCol -= 1;
    _buffer[PositionRow][PositionCol] = '*';
}

void Canvas::RightSnake()
{
    _buffer[PositionRow][PositionCol] = ' ';
    PositionCol += 1;
    _buffer[PositionRow][PositionCol] = '*';
}

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
