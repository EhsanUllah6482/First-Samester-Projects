#include <iostream>
#include <windows.h>
using namespace std;
char space[][70] = {
    {"#####################################################################"},
    {"|                                                                   |"},
    {"|                                                                   |"},
    {"|                                                                   |"},
    {"|                                                                   |"},
    {"|                                                                   |"},
    {"|                                                                   |"},
    {"|>                                                                  |"},
    {"|                                                                   |"},
    {"|                                                                   |"},
    {"|                                                                   |"},
    {"|                                                                   |"},
    {"|                                                                   |"},
    {"|                                                                   |"},
    {"#####################################################################"}};

bool gamerunning = true;
int playerxCoordinate, playeryCoordinate;
int controlAliens = 0;
int controlSpeedAliens = 0;
int score = 0;
string reason = " ";
int randomnumberGenerator();
int bulletxcoordinate[100], bulletycoordinate[100];
int aliensX[100], aliensY[100];

void gotoxy(int y, int x);
void displaymaze();
bool findplayerposition();
void generateBullet();
void moveBullets();
void moveShip(int variablepass);
void generateAliens();
void moveAliens();
int color = 0;
int main()
{

    cout << "Game Menu:" << endl;
    cout << "Press one Start your game.\n"
         << endl;
    cout << "Press two to exit your game.\n"
         << endl;
    int choice;
    cin >> choice;
    if (choice == 2)
    {
        reason = "Your game has been closed!";
        color = randomnumberGenerator();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
        gamerunning = false;
    }

    color = randomnumberGenerator();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    gotoxy(0, 0);
    color = randomnumberGenerator();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    displaymaze();
    color = randomnumberGenerator();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    while (gamerunning)
    {
        color = randomnumberGenerator();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
        findplayerposition();
        gotoxy(16, 0);
        cout << "\tScore: " << score;
        if (GetAsyncKeyState(VK_SPACE))
        {
            generateBullet();
            color = randomnumberGenerator();
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
        }
        moveBullets();
        color = randomnumberGenerator();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

        if (GetAsyncKeyState(VK_DOWN))
        {
            moveShip(1);
            color = randomnumberGenerator();
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
        }
        if (GetAsyncKeyState(VK_UP))
        {
            moveShip(2);
            color = randomnumberGenerator();
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
        }
        findplayerposition();
        color = randomnumberGenerator();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

        generateAliens();
        moveAliens();
    }
    color = randomnumberGenerator();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    system("cls");
    cout << "Score: " << score;
    cout << reason << endl
         << endl;
    system("pause");
    return 0;
}
void gotoxy(int y, int x)
{
    COORD c;
    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void displaymaze()
{
    for (int row = 0; row < 15; row++)
    {
        for (int col = 0; col < 70; col++)
        {
            cout << space[row][col];
        }
        cout << "\n";
    }
}

bool findplayerposition()
{
    for (int row = 0; row < 15; row++)
    {
        for (int col = 0; col < 70; col++)
        {
            if (space[row][col] == '>')
            {
                playerxCoordinate = row;
                playeryCoordinate = col;
                return true;
            }
        }
    }
    return false;
}

void generateBullet()
{
    space[playerxCoordinate][playeryCoordinate + 1] = '-';
}
void moveBullets()
{
    int count = 0;
    for (int row = 0; row < 15; row++)
    {
        for (int col = 0; col < 70; col++)
        {
            if (space[row][col] == '-')
            {
                bulletxcoordinate[count] = row;
                bulletycoordinate[count] = col;
                count++;
            }
        }
    }
    for (int i = 0; i < count; i++)
    {

        if (space[bulletxcoordinate[i]][bulletycoordinate[i] + 1] == '<')
        {
            space[bulletxcoordinate[i]][bulletycoordinate[i] + 1] = ' ';
            gotoxy(bulletxcoordinate[i], bulletycoordinate[i] + 1);
            cout << ' ';
            score++;
        }
        else if (space[bulletxcoordinate[i]][bulletycoordinate[i] + 1] != '|')
        {
            space[bulletxcoordinate[i]][bulletycoordinate[i] + 1] = '-';
            gotoxy(bulletxcoordinate[i], bulletycoordinate[i] + 1);
            cout << '-';
        }
        space[bulletxcoordinate[i]][bulletycoordinate[i]] = ' ';
        gotoxy(bulletxcoordinate[i], bulletycoordinate[i]);
        cout << ' ';
    }
}
void moveShip(int variablepass)
{
    if (variablepass == 1)
    {

        if (space[playerxCoordinate + 1][playeryCoordinate] != '#')
        {
            space[playerxCoordinate + 1][playeryCoordinate] = '>';
            gotoxy(playerxCoordinate + 1, playeryCoordinate);
            cout << '>';
        }
        space[playerxCoordinate][playeryCoordinate] = ' ';
        gotoxy(playerxCoordinate, playeryCoordinate);
        cout << ' ';
    }
    if (variablepass == 2)
    {

        if (space[playerxCoordinate - 1][playeryCoordinate] != '#')
        {

            space[playerxCoordinate - 1][playeryCoordinate] = '>';
            gotoxy(playerxCoordinate - 1, playeryCoordinate);
            cout << '>';
        }
        space[playerxCoordinate][playeryCoordinate] = ' ';
        gotoxy(playerxCoordinate, playeryCoordinate);
        cout << ' ';
    }
}

int randomnumberGenerator()
{
    srand(time(0));
    return 1 + (rand() % 12);
}

void generateAliens()
{

    int ax = randomnumberGenerator();
    int ay = 65;

    space[ax][ay] = '<';
    gotoxy(ax, ay);
    cout << "<";
    controlAliens++;
}

void moveAliens()
{
    int c = 10;
    if (controlSpeedAliens == c)
    {
        int count = 0;
        for (int row = 0; row < 15; row++)
        {
            for (int col = 0; col < 70; col++)
            {
                if (space[row][col] == '<')
                {
                    aliensX[count] = row;
                    aliensY[count] = col;
                    count++;
                }
            }
        }
        for (int i = 0; i < count; i++)
        {
            if (space[aliensX[i]][aliensY[i] - 1] == '|')
            {
                gamerunning = false;
                reason = "Your game is over. The enemy has crossed the space!";
            }
            else if (space[aliensX[i]][aliensY[i] - 1] != '|')
            {
                bool found = false;
                for (int j = playeryCoordinate; j < 70; j++)
                {
                    if (space[playerxCoordinate][j] == '<')
                    {
                        found = true;
                    }
                }
                if (found == false)
                {
                    if (aliensX[i] > playerxCoordinate)
                    {
                        space[aliensX[i] - 1][aliensY[i] - 1] = '<';
                        gotoxy(aliensX[i] - 1, aliensY[i] - 1);
                        cout << '<';
                    }
                    else if (aliensX[i] < playerxCoordinate)
                    {
                        space[aliensX[i] + 1][aliensY[i] - 1] = '<';
                        gotoxy(aliensX[i] + 1, aliensY[i] - 1);
                        cout << '<';
                    }
                }
                if (found == true)
                {
                    space[aliensX[i]][aliensY[i] - 1] = '<';
                    gotoxy(aliensX[i], aliensY[i] - 1);
                    cout << '<';
                }
            }
            space[aliensX[i]][aliensY[i]] = ' ';
            gotoxy(aliensX[i], aliensY[i]);
            cout << ' ';
        }
        controlSpeedAliens = 0;
        Sleep(50);
    }
    controlSpeedAliens++;
}