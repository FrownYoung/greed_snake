#include "Canvas.h"
#include <iostream>

using namespace std;

int main()
{
    Canvas canvas(80, 28);
    char snake_direction_now, snake_dirction_last = 'w';
    for (;;)
    {
        cout << "Please input direction: ";
//        char snake_direction_now, snake_dirction_last;
        cin >> snake_direction_now;
//        canvas.MoveSnake(snake_direction_now, snake_dirction_last);
        switch (snake_direction_now) {
        case 'w':
            canvas.UpSnakeHead();
            break;
        case 's':
            canvas.DownSnakeHead();
            break;
        case 'a':
            canvas.LeftSnakeHead();
            break;
        case 'd':
            canvas.RightSnakeHead();
            break;
        }
        cout << "body moves" << endl;
        switch (snake_dirction_last) {
        case 'w':
            canvas.UpSnakeBody();
            break;
        case 's':
            canvas.DownSnakeBody();
            break;
        case 'a':
            canvas.LeftSnakeBody();
            break;
        case 'd':
            canvas.RightSnakeBody();
            cout << snake_dirction_last << endl;
            break;
        }
        snake_dirction_last = snake_direction_now;
       // cout << snake_dirction_last << endl;
        canvas.Output();
    }

    return 0;
}
