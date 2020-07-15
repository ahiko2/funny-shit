#include <stdio.h> 
#define N 4 

//solvemaze hmr information tway ko yya htae
//maze way, right, down, solution(memorizing way)

bool solvemazeutl(
    int maze[N][N],int x,
     int y,int solu[N][N]
);
//print solve maze
void printsolution(int solu[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            printf ("%d ",solu[i][j]);
        printf("\n");
    }
}
//holding inside bound
bool isSafe(int maze[N][N], int x, int y) 
{ 
	// if (x, y outside maze) return false 
	if ( 
		x >= 0 && x < N &&
        y >= 0 && y < N && 
        maze[x][y] == 1) 
		return true; 

	return false; 
}
//------------------------------------------------/
//recursion of backtracking
bool solvemazeutl( 
	int maze[N][N], int x, 
	int y, int solu[N][N])
{   
    //when rat is hit to goal, return true
    if(x==N-1 && y== N-1 && maze[x][y]==1)
    {
        solu[x][y]=1;
       return true;
    }
    //check x,y are in maze zone. If it is, place x and y on the solu-maze
    if(isSafe(maze,x,y)==true)
    {
        solu[x][y]=1;

        //moving down and right as it find its path
        // 1. x direction
        if (solvemazeutl( maze, x + 1, y, solu) == true) return true; 
        // 2. y direction
        if (solvemazeutl( maze, x, y + 1, solu) == true) return true; 
        //when x and y are not work then backtrack, unmark x,y as of solu-maze
        solu[x][y]=0;
        return false;
    }
    return false;
}
bool solvemaze(int maze[N][N])
{
    int solu[N][N]=
                 {
                    { 0, 0, 0, 0 }, 
					{ 0, 0, 0, 0 }, 
					{ 0, 0, 0, 0 }, 
					{ 0, 0, 0, 0 } 
                };

    if(solvemazeutl(maze,0,0,solu)==false)
    {
        printf("no solution");
        return false;
    }
    
    printsolution(solu);
    return true;

}
int A[N][N]=
{                   { 1, 0, 0, 0 }, 
					{ 1, 1, 0, 1 }, 
					{ 0, 1, 0, 0 }, 
					{ 1, 1, 1, 1 } }; 

int path[N][N]={
                    { 0, 0, 0, 0 }, 
					{ 0, 0, 0, 0 }, 
					{ 0, 0, 0, 0 }, 
					{ 0, 0, 0, 0 } 
                };
int findpath(int i,int j,int n){
    
    if(i==n-1 && j==n-1)
    {
        path[i][j]=1;
        return 1;
    }
    if(A[i][j]==1)
    {
        path[i][j]=1;
        if(findpath(i, j+1, n)==1) return 1;
        if(findpath(i+1, j, n)==1) return 1;
        
        path[i][j]=0;
    }
    return 0;
}
int main() 
{ 
	int maze[N][N] = { 
                    { 1, 0, 0, 0 }, 
					{ 1, 1, 0, 1 }, 
					{ 0, 1, 0, 0 }, 
					{ 1, 1, 1, 1 } }; 

	solvemaze(maze); 
    int i,j;
    findpath(0, 0, 4);
    for( i=0;i<4;++i)
    {
        for(j=0;j<4;j++)
        {
            if(path[i][j])
                printf("(%d %d )-->\n",i,j);
        }
        
    }
	return 0; 
} 
