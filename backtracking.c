#include <stdio.h>

int A[4][4]=
{
    1,1,0,1,
    1,0,1,0,
    1,1,1,0,
    0,0,1,1,
};

int path[4][4]={
    0,0,0,0,
    0,0,0,0,
    0,0,0,0,
    0,0,0,0,
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
    int i,j;
    findpath(0, 0, 4);
    for( i=0;i<4;++i)
    {
        for(j=0;j<4;j++)
        {
            if(path[i][j])
                printf("(%d %d )-->\n",i,j);
        }
        printf("\n");
    }
    
}
