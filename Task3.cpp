#include <iostream>
using namespace std;

char b[3][3];

void resetBoard()
{
    char ch = '1';

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            b[i][j] = ch++;
        }
    }
}

void displayBoard()
{
    cout << "\n";

    for(int i=0;i<3;i++)
    {
        cout << " " << b[i][0]
             << " | " << b[i][1]
             << " | " << b[i][2];

        if(i<2)
            cout << "\n---|---|---\n";
    }

    cout << "\n\n";
}

int checkWin()
{
    for(int i=0;i<3;i++)
    {
        if(b[i][0]==b[i][1] && b[i][1]==b[i][2])
            return 1;

        if(b[0][i]==b[1][i] && b[1][i]==b[2][i])
            return 1;
    }

    if(b[0][0]==b[1][1] && b[1][1]==b[2][2])
        return 1;

    if(b[0][2]==b[1][1] && b[1][1]==b[2][0])
        return 1;

    return 0;
}

int main()
{
    char again;

    do
    {
        resetBoard();

        char player='X';
        int move=0;
        int pos;

        while(move<9)
        {
            displayBoard();

            cout<<"Player "<<player<<" Enter Position (1-9): ";
            cin>>pos;

            if(pos<1 || pos>9)
            {
                cout<<"Invalid Position\n";
                continue;
            }

            int row=(pos-1)/3;
            int col=(pos-1)%3;

            if(b[row][col]=='X' || b[row][col]=='O')
            {
                cout<<"Position Already Taken\n";
                continue;
            }

            b[row][col]=player;
            move++;

            if(checkWin())
            {
                displayBoard();
                cout<<"Player "<<player<<" Wins!\n";
                break;
            }

            if(player=='X')
                player='O';
            else
                player='X';
        }

        if(move==9 && !checkWin())
        {
            displayBoard();
            cout<<"Game Draw\n";
        }

        cout<<"\nPlay Again? (y/n): ";
        cin>>again;

    }while(again=='y' || again=='Y');

    cout<<"\nThank You For Playing!\n";

    return 0;
}