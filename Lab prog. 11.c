#include<stdio.h>
#include<conio.h>

void DFS(int);
int graph[30][30],visited[10],total;
void main()
{
    int i,j;
    printf("Enter total number of vertices/cities in graph\n");
    scanf("%d",&total);
    printf("The adjacency matrix is\n");
    for(i=0; i<total; i++)
    {
        for(j=0; j<total; j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    printf("The Depth First Traversal is:\n");
    for(i=0; i<total; i++)
    {
        visited[i]=0;
    }
    DFS(0);
}
void DFS(int vertex)
{
    int j;
    printf("%d\t",vertex);
    visited[vertex]=1;
    for(j=0; j<total; j++)
    {
        if(!visited[j]&&graph[vertex][j]==1)
        {
            DFS(j);
        }
    }
}
