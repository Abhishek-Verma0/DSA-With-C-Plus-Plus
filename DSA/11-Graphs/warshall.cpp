/***
 * 
 */




#include<bits/stdc++.h>
using namespace std;
const int MAX=40;
int adjmat[MAX][MAX];
int p[MAX][MAX];
void warshall(int m)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(adjmat[i][j]!=0)
            {
                p[i][j]=1;
            }
            else
            {
                p[i][j]=0;
            }
        }
    }

for(int k=0;k<m;k++)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            p[i][j]=p[i][j] || (p[i][k] && p[k][j]);
        }
    }
}
cout<<"Path matrix is"<<endl;
for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
  }  


  
int main()
{
    int m;
    cout<<"Enter the number of vertices: "<<endl;
    cin>>m;
    cout<<"Enter adjacency matrix: "<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>adjmat[i][j];
}
}
warshall(m);
return 0;
}




