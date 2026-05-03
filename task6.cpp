#include <iostream>
using namespace std;

string fire(char grid[5][5], string pos)
{
    int row = pos[1]-'1';
    int col = pos[0]-'A';

    if(grid[row][col]=='*')
        return "BOOM";
    else
        return "splash";
}

int main()
{
    char grid[5][5] = {
        {'.','.','.','*','*'},
        {'.','*','.','.','.'},
        {'.','*','.','.','.'},
        {'.','*','.','.','.'},
        {'.','.','*','*','.'}
    };

    string input;
    cin>>input;

    cout<<fire(grid,input);
}