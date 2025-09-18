#include <bits/stdc++.h>
using namespace std;

char board[3][3];

bool valid(int r, int c)
{
    return r >= 0 and r < 3 and c >= 0 and c < 3 and board[r][c] == '_';
}
bool won(char player)
{

    for (int i = 0; i < 3; i++)
    {
        int xwin = 0;
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == player)
            {
                xwin++;
                if (xwin == 3)
                {
                    return true;
                }
            }
        }
    }

    for (int j = 0; j < 3; j++)
    {
        int xwin = 0;
        int ywin = 0;
        for (int i = 0; i < 3; i++)
        {
            if (board[i][j] == 'X')
            {
                xwin++;
                if (xwin == 3)
                {

                    return true;
                }
            }
            if (board[i][j] == 'O')
            {
                ywin++;
                if (ywin == 3)
                {
                    return true;
                }
            }
        }
    }

    if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'))
    {

        return true;
    }
    if ((board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') || (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))
    {

        return true;
    }

    return false;
}
void display()
{
    cout<<" Make a Powerfull Move"<<endl;
    cout<<"------------------------"<<endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"------------------------"<<endl;
}
int main()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '_';
        }
    }
    char player ;
    cin>>player;
    int moves = 0;
    display();
    while (moves < 9)
    {
        int r, c;
        cin >> r >> c;

        if (valid(r, c) == false)
        {   
            system("clear");
            display();
            cout << "Try again " << endl;
            continue;
        }
        board[r][c] = player;
        moves++;
        system("clear");
        display();

        if (won(board[r][c]))
        {
            cout << "player " << player << " won" << endl;
            break;
        }
        if (moves == 9)
        {
            cout << "draw" << endl;
            break;
        }

        if (player == 'X')
        {
            player = 'O';
        }
        else
        {
            player = 'X';
        }
    }
}
