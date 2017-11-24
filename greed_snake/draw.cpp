#include "Canvas.h"
#include <iostream>

using namespace std;

int main()
{
    Canvas canvas(80, 28);

    for (;;)
    {
        cout << "Please input direction: ";
        char snake_direction;
        cin >> snake_direction;
            switch (snake_direction) {
            case 'w':
                canvas.UpSnake();
                //cout << "up happens" << endl;
                break;

            case 's':
                canvas.DownSnake();
                break;
            case 'a':
                canvas.LeftSnake();
                break;
            case 'd':
                canvas.RightSnake();
                break;
            }
        canvas.Output();
    }

    return 0;
}
