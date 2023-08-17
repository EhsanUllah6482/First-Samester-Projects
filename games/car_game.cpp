#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70
using namespace std;
void gotoxy(int x, int y);
void setcursor(bool visible, DWORD size);
void drawBorder();
void genEnemy(int ind);
void drawEnemy(int ind);
void eraseEnemy(int ind);
void resetEnemy(int ind);
void drawCar();
void eraseCar();
int collision();
void gameover();
void updateScore();
void instructions();
void play(bool);
bool checklive();
bool checkhealth();
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
int enemyY[3];
int enemyX[3];
int enemyFlag[3];
char car[4][4] = {char(29), char(94), char(94), char(29),
                  char(220), char(220), char(220), char(220),
                  char(182), char(220), char(220), char(182),
                  char(64), char(220), char(220), char(64)};

int carPos = WIN_WIDTH / 2;
bool alive = false;
bool health_again = false;
int lives = 3;
int health = 100;
int score = 0;
int option = 5;

int colour = 0;
int randomnumberGenerator()
{
    srand(time(0));
    return 1 + (rand() % 12);
}

int main()
{
    setcursor(0, 0);
    srand((unsigned)time(NULL));
    colour = randomnumberGenerator();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
    while (option != 4)
    {
        system("cls");
        colour = randomnumberGenerator();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
        gotoxy(10, 5);
        colour = randomnumberGenerator();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
        cout << " -------------------------- ";
        colour = randomnumberGenerator();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
        gotoxy(10, 6);
        colour = randomnumberGenerator();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
        cout << " |        ";
        colour = randomnumberGenerator();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
        cout << "Car Game";
        colour = randomnumberGenerator();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
        cout << "        | ";
        colour = randomnumberGenerator();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
        gotoxy(10, 7);
        colour = randomnumberGenerator();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
        cout << " --------------------------";
        colour = randomnumberGenerator();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
        gotoxy(10, 9);
        colour = randomnumberGenerator();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
        gotoxy(10, 10);
        colour = randomnumberGenerator();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
        cout << "1. Start Game\n";
        cout << "2. Instructions\n";
        colour = randomnumberGenerator();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
        gotoxy(10, 11);
        colour = randomnumberGenerator();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
        cout << "3. Quit\n";
        colour = randomnumberGenerator();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
        gotoxy(10, 13);
        colour = randomnumberGenerator();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
        cout << "Select option: ";
        colour = randomnumberGenerator();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
        char op = getche();
        colour = randomnumberGenerator();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
        if (op == '1')
        {
            colour = randomnumberGenerator();
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
            bool flag = true;
            alive = false;
            health_again = false;
            colour = randomnumberGenerator();
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
            play(flag);
            colour = randomnumberGenerator();
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
        }
        else if (op == '2')
        {
            colour = randomnumberGenerator();
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
            instructions();
        }
        else if (op == '3')
            break;
    }

    return 0;
}
void gotoxy(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

void setcursor(bool visible, DWORD size)
{
    if (size == 0)
        size = 20;

    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}

void drawBorder()
{
    fstream f;
    f.open("cartable.txt", ios::in);
    SetConsoleTextAttribute(color, 47);
    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            gotoxy(0 + j, i);
            cout << char(220);
            gotoxy(WIN_WIDTH - j, i);
            cout << char(220);
        }
    }
    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        gotoxy(SCREEN_WIDTH, i);
        cout << char(221);
    }
    f.close();
}

void genEnemy(int ind)
{
    enemyX[ind] = 12 + rand() % (33);
}

void drawEnemy(int ind)
{
    if (enemyFlag[ind] == true)
    {
        SetConsoleTextAttribute(color, 12);
        gotoxy(enemyX[ind], enemyY[ind]);
        cout << char(64) << char(220) << char(220) << char(64);
        gotoxy(enemyX[ind], enemyY[ind] + 1);
        cout << char(182) << char(220) << char(220) << char(182);
        gotoxy(enemyX[ind], enemyY[ind] + 2);
        cout << char(220) << char(220) << char(220) << char(220);
        gotoxy(enemyX[ind], enemyY[ind] + 3);
        cout << char(29) << char(157) << char(157) << char(29);
    }
}

void eraseEnemy(int ind)
{
    if (enemyFlag[ind] == true)
    {
        gotoxy(enemyX[ind], enemyY[ind]);
        cout << "    ";
        gotoxy(enemyX[ind], enemyY[ind] + 1);
        cout << "    ";
        gotoxy(enemyX[ind], enemyY[ind] + 2);
        cout << "    ";
        gotoxy(enemyX[ind], enemyY[ind] + 3);
        cout << "    ";
    }
}

void resetEnemy(int ind)
{
    eraseEnemy(ind);
    enemyY[ind] = 1;
    genEnemy(ind);
}

void drawCar()
{
    SetConsoleTextAttribute(color, 10);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            gotoxy(j + carPos, i + 18);
            cout << car[i][j];
        }
    }
}

void eraseCar()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            gotoxy(j + carPos, i + 18);
            cout << " ";
        }
    }
}

int collision()
{
    if (enemyY[0] + 5 >= 23)
    {
        if (enemyX[0] + 5 - carPos >= 0 && enemyX[0] + 4 - carPos < 9)
        {
            return 1;
        }
    }
    return 0;
}

void gameover()
{
    system("cls");
    cout << endl;
    SetConsoleTextAttribute(color, 10);
    cout << "\t\t--------------------------" << endl;
    cout << "\t\t--------";
    SetConsoleTextAttribute(color, 13);
    cout << " Game Over ";
    SetConsoleTextAttribute(color, 10);
    cout << "-------" << endl;
    cout << "\t\t--------------------------" << endl
         << endl;
    cout << "\t\tPress any key to go back to menu.";
    getch();
}

void updateScore()
{
    gotoxy(WIN_WIDTH + 7, 5);
    cout << "Score: " << score << endl;
}

void instructions()
{

    system("cls");
    // SetConsoleTextAttribute(color, 2);
    cout << "Instructions";
    cout << "\n----------------";
    cout << "\n Avoid Cars by moving left or right. ";
    cout << "\n\n Press 'Left arrow key' to move left";
    cout << "\n Press 'Right arrow key' to move right";
    cout << "\n Press 'escape' to exit";
    cout << "\n\nPress any key to go back to menu";
    getch();
}

void play(bool flag1)
{
    carPos = -1 + WIN_WIDTH / 2;
    lives = 3;
    health = 100;
    gotoxy(29, 29);
    cout << health;
    score = 0;
    enemyFlag[0] = 1;
    enemyFlag[1] = 0;
    enemyY[0] = enemyY[1] = 1;

    system("cls");
    drawBorder();
    updateScore();
    genEnemy(0);
    genEnemy(1);

    SetConsoleTextAttribute(color, 13);
    gotoxy(WIN_WIDTH + 7, 2);
    cout << "Car Game";
    gotoxy(WIN_WIDTH + 6, 4);
    cout << "----------";
    gotoxy(WIN_WIDTH + 6, 6);
    cout << "----------";
    gotoxy(WIN_WIDTH + 7, 12);
    cout << "Control ";
    gotoxy(WIN_WIDTH + 7, 13);
    cout << "-------- ";
    gotoxy(WIN_WIDTH + 2, 14);
    cout << " Left  Key - Left";
    gotoxy(WIN_WIDTH + 2, 15);
    cout << " Right Key - Right";

    gotoxy(18, 5);
    cout << "Press any key to start";
    getch();
    gotoxy(18, 5);
    cout << "                      ";

    while (flag1)
    {
        if (kbhit())
        {
            if (GetAsyncKeyState(VK_LEFT))
            {
                if (carPos > 14)
                {
                    carPos -= 4;
                }
            }
            if (GetAsyncKeyState(VK_RIGHT))
            {
                if (carPos < 54)
                {
                    carPos += 4;
                }
            }
            if (GetAsyncKeyState(VK_ESCAPE))
            {
                break;
            }
        }

        drawCar();
        drawEnemy(0);
        drawEnemy(1);
        if (collision() == true)
        {
            checkhealth();
            if (health_again == true)
            {
                health_again == false;
                checklive();
                if (alive == true)
                {
                    gameover();
                    flag1 = false;
                }
            }
        }
        Sleep(50);
        eraseCar();
        eraseEnemy(0);
        eraseEnemy(1);

        if (enemyY[0] == 10)
            if (enemyFlag[1] == 0)
                enemyFlag[1] = 1;

        if (enemyFlag[0] == 1)
            enemyY[0] += 1;

        if (enemyFlag[1] == 1)
            enemyY[1] += 1;

        if (enemyY[0] > SCREEN_HEIGHT - 4)
        {
            resetEnemy(0);
            score++;
            updateScore();
        }
        if (enemyY[1] > SCREEN_HEIGHT - 4)
        {
            resetEnemy(1);
            score++;
            updateScore();
        }
    }
}
bool checklive()
{

    lives--;
    eraseEnemy(0);
    resetEnemy(0);

    if (lives == 0)
    {
        alive = true;
    }
    if (alive == false)
    {
        health = 100;
        gotoxy(WIN_WIDTH + 2, 20);
        cout << "      lives=" << lives;
        char temp;
        gotoxy(18, 5);
        cout << "enter any key to live " << lives << " =";
        cin >> temp;
        gotoxy(18, 5);
        cout << "                             ";
    }
}
bool checkhealth()
{
    health = health - 30;
    eraseEnemy(0);
    resetEnemy(0);
    eraseEnemy(1);
    resetEnemy(1);
    if (health_again == false)
    {
        gotoxy(WIN_WIDTH + 1, 20);
        cout << "            ";
        gotoxy(WIN_WIDTH + 1, 20);
        cout << "   Health = " << health;
    }
    if (health == 10)
    {
        health_again = true;
        health = 100;
        gotoxy(WIN_WIDTH + 1, 20);
        cout << "            ";
        gotoxy(WIN_WIDTH + 1, 20);
        cout << "   Health = " << health;
    }
}