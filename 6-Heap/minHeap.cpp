
#include<bits/stdc++.h>
using namespace std;


class heap{
    public:
    int arr[200];
    int size;
    heap(){
        arr[0]=-1;
        size=0;
    }
    
    
    void insert(int val){
        size++;
        int index= size;
        arr[index]=val;
        
        while(index > 1){
            int parent=index/2;
            if(arr[parent] > arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return ;
            }
        }
    }
    
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
};


int main(){
    heap h;
    int n,val;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>val;
        h.insert(val);
}
h.print();
}




