/*** What is linear probing ?? ---
 * 
 */


#include<bits/stdc++.h>
using namespace std;

int main(){

    int num;
     cout<<"Enter number of elements :: ";
     cin>>num;
     int elements[num];
     int hashtable[10];
     for(int i=0;i<10;i++){
        hashtable[i]=-1;
     }

     cout<<"Enter the elemnts :: ";
    for(int i=0;i<num;i++){
        cin>>elements[i];
    }




    for(int i=0;i<num;i++){
            int index=elements[i]%10;


            while(hashtable[index]!=-1){
                index=(index+1)%10;
            }
            hashtable[index]=elements[i];
    }



    for(int i=0;i<10;i++){
        if(hashtable[i]!=-1){
            cout<<i<<" "<<hashtable[i]<<endl;
        }
        else{
            cout<<"empty space "<<i<<endl;
        }
    }
    return 0;
}