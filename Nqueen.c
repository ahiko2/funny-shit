#include <iostream>
using namespace std;

#define N 8

int printsolu(int board[N][N])
{
  for (int i = 0; i < N; i++) 
   {
      for (int j = 0; j < N; j++)
        cout << board[i][j] << "  ";
        cout << endl;
        cout << endl;
   }
    
}
int IsSafe(int board[N][N],int row,int col)
{
  //checking for same column
  for(int i=0;i<col;i++)
    if(board[row][i])
    return false;
  //checking for upper left
  for(int i=row,j=col;i>=0 && j>=0;i--,j--)
    if(board[i][j])
    return false;
  //checking for down left side
  for(int i=row,j=col;i<N && j>=0;i++,j--)
    if(board[i][j])
    return false;
  
  return true;
}

bool soluqueen(int board[N][N],int col)
{
  if(col>=N)
    return true;
  for(int i=0;i<N;i++)
  {
    if(IsSafe(board,i,col))
    {
      board[i][col]=1;
      if(soluqueen(board,col+1))
        return true;

      board[i][col]=0;
    }

  }
  return false;
}
bool  checksolu()
{
  int board[N][N];
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      board[i][j]=0; //setting all 0
  if(soluqueen(board,0)==false)
  {
    cout<<"solu error";
    return false;
  }
  printsolu(board);
  return true;

}
int main()
{
  checksolu();
}
