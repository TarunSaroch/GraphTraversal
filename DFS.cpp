#include <iostream>
using namespace std;

int main(){
    static int adj[10][10];
    int start, n, edge, i, j, srcVert, destVer;
    int status[10], dfs[10], stack[10], top=-1, w;
    int k=0;



    cout<<"Enter number of nodes & edges for graph : "; cin>>n>>edge;
    /*for (i=0;i<=n;i++){
        for ( j = 0; j <= n; j++)
        {
            adj[i][j] = 0;
        }
        
        
    }*/

    cout<<"Enter Source and Destination node : "<<endl;
    for (i=1;i<=edge;i++){
        cin>>srcVert >>destVer;
        adj[srcVert][destVer] = 1;
        adj[destVer][srcVert] = 1;
    }
    cout<<"Adj Matrix : "<<endl;
    for ( i = 1; i <=n; i++)
    {
        for ( j = 1; j <=n; j++)
        {
            cout<<" "<<adj[i][j];
        }
        cout<<endl;
    }
    cout<<"Enter Initial node : "; cin>>start;
    for( i = 1; i<=n; i++)
    {
        status[i]=0;
    }
    stack[++top]=start;
    status[start]=1; //waiting state
    while (top!=-1)
    {
        w = stack[top];
        top=top-1;
        stack[w]=2;
        dfs[k]=w;
        k++;
        
        for ( j = 1; j <=n; j++)
        {
            if (adj[w][j]!=0 && status[j]==0)
            {
                stack[++top]=j;
                status[j]=1;                
            }
        }        
    }
    cout<<"DFS traversal : ";
    for (int q = 0; q < k; q++)
    {
        cout<<dfs[q]<<" ";
    }    
    return 0;
}