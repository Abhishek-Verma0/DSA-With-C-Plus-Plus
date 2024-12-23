/***********************************************FLoyd Warshall Algorithm ************************************* 
 * 
*/




#include<bits/stdc++.h>
using namespace std;




void floyd(int arr[][4],int m) 
{ 
    int i,j,k; 
    for(int k=0;k<m;k++) 
    { 
        for(int i=0;i<m;i++) 
        { 
            for(int j=0;j<m;j++) 
        { 
            if(i!=j) 
            { 
                if((arr[i][j]>arr[i][k]+arr[k][j]) || (arr[i][j]==0)) 
                { 
                    arr[i][j]=arr[i][k]+arr[k][j];
                } 
            } 
} 
} 
} 
for(int i=0;i<m;i++) 
        { 
            for(int j=0;j<m;j++) 
        { 
            cout<<arr[i][j]<<" "; 
        } 
        } 
} 
 
     
int main() 
{ 
    int arr[4][4]; 
    int m;
    cout<<"Enter the value for adjacency matrix"; 
    cin>>m; 
    cout<<"Enter adjacency matrix"; 
    for(int i=0;i<4;i++) 
    { 
        for(int j=0;j<4;j++) 
        { 
            cin>>arr[i][j]; 
} 
 
floyd(arr,m); 
return 0; 
}
}