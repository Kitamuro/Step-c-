#include<iostream>
#include<ctime>
#include<vector>
#include<windows.h>
using namespace std;

class Point {
public:
    int *x, *y;
    Point(int x, int y) {
        this->x = new int(x);
        this->y = new int(y);
    }
    Point(const Point &point) {
        this->x = new int(*point.x);
        this->y = new int(*point.y);
    }
    Point() {
        
    }
    ~Point() {
        delete x;
        delete y;
    }
    void draw(char sign) {
        goToXY();
        cout << sign;
    }
    void clear() {
        goToXY();
        cout << ' ';
    }
    void goToXY() {
        COORD position = { (short)*x,(short)*y };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
    }
};

class Wall {
public:
    Point *body;
    char *sign;
    Wall() {
        sign = new char('#');
        body = new Point[80];
        for (int i = 0; i < 20; i++) {
            body[i] = *(new Point(i, 0));
            body[i + 20] = *(new Point(0, i));
            body[i + 40] = *(new Point(i, 19));
            body[i + 60] = *(new Point(19, i));
        }
    }
    ~Wall() {
        delete[] body;
        delete sign;
    }
    void draw() {
        for (int i = 0; i < 80; i++) {
            body[i].draw(*sign);
        }
    }
};
class Food {
public:
    Point *point;
    char *foodSign;
    Food(int x, int y) {
        foodSign = new char('@');
        point = new Point(x, y);
    }
    ~Food() {
        delete point;
        delete foodSign;
    }
    void draw() {
        point->draw(*foodSign);
    }
    void reinit(vector <Point> snakeBody, Point wall[]) {
        *point->x = (rand() % 19 + 1);
        *point->y = (rand() % 19 + 1);
        for (int i = 0; i < snakeBody.size(); i++) {
            if (*snakeBody.at(i).x == *point->x &&
                *snakeBody.at(i).y == *point->y) {
                reinit(snakeBody, wall);
            }
        }
        for (int i = 0; i < 80; i++) {
            if (*wall[i].x == *point->x &&
                *wall[i].y == *point->y) {
                reinit(snakeBody, wall);
            }
        }
    }
};

class Snake {
public:
    vector<Point> *body;
    char *sign;
    Snake(int x, int y) {
        sign = new char('*');
        body = new vector<Point>();
        body->reserve(100);
        body->push_back(*(new Point(x, y)));
        //body->push_back(*(new Point(x, y)));
        
    }
    ~Snake() {
        delete body;
        delete sign;
    }
    void eat(Point point) {
        body->push_back(*(new Point(point)));
    }
    void move(int dx, int dy) {
        for (int i = body->size() - 1; i > 0; i--) {
            *body->at(i).x = *body->at(i - 1).x;
            *body->at(i).y = *body->at(i - 1).y;
        }
        *body->at(0).x = *body->at(0).x + dx;
        *body->at(0).y = *body->at(0).y + dy;
    }
    void draw() {
        for (int i = 0; i < body->size(); i++) {
            body->at(i).draw(*sign);
        }
    }
    void clear() {
        body->at(body->size() - 1).clear();
    }
};
class Game {
public:
    Food *food;
    Snake *snake;
    Wall * wall;
    bool trig;
    Game() {
        srand(time_t(NULL));
        trig = true;
        snake = new Snake(5, 5);
        food = new Food(rand() % 19 + 1, rand() % 19 + 1);
        wall = new Wall();
        food->reinit(*snake->body, wall->body);
    }
    ~Game() {
        delete snake;
        delete food;
        delete wall;
    }
    void checkIfSnakeEats() {
        if (*snake->body->at(0).x == *food->point->x &&
            *snake->body->at(0).y == *food->point->y) {
            snake->eat(*food->point);
            food->reinit(*snake->body, wall->body);
            food->draw();
        }
    }
    bool checkIfSnakeBreaksIntoWall() {
        for (int i = 0; i < 80; i++) {
            if (*snake->body->at(0).x == *wall->body[i].x &&
                *snake->body->at(0).y == *wall->body[i].y) {
                exit();
                return false;
            }
        }
        return true;
    }
    bool checkIfSnakeEatsItself() {
        if(snake->body->size() > 1){
            for (int i = 0; i < snake->body->size(); i++) {
                if (*snake->body->at(0).x == *snake->body->at(i).x &&
                    *snake->body->at(0).y == *snake->body->at(i).y) {
                    exit();
                    return false;
                }
            }
            return true;
        }
    }
    void exit() {
        system("cls");
        COORD position = { 5,3 };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
        cout << "Your score is: " << snake->body->size() << endl;
    }
    void play() {
        wall->draw();
        food->draw();
        snake->draw();
        int dx = 0, dy = 0;
        while (trig) {
            snake->clear();
            char action = '~';
            if (_kbhit()) {
                action = _getch();
            }
            switch (action) {
                case 'w':
                    dx = 0; dy = -1;
                    break;
                case 'a':
                    dx = -1; dy = 0;
                    break;
                case 's':
                    dx = 0; dy = 1;
                    break;
                case 'd':
                    dx = 1; dy = 0;
                    break;
                case 'e': {
                    exit();
                    return;
                }
                default:
                    break;
            }
            snake->clear();
            snake->move(dx, dy);
            snake->draw();
            Sleep(300);
            trig = checkIfSnakeEatsItself() || checkIfSnakeBreaksIntoWall();
            checkIfSnakeEats();
        }
        
    }
};
int main()
{
    Game *game = new Game();
    game->play();
    delete game;
    system("pause");
}
