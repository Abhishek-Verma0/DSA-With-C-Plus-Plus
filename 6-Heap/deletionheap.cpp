


#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;
    heap(){
        size = 0;
        arr[0]=-1;
    }
    void insert(int val){
        size+=1;
        int index=size;
        arr[index]=val;
        while(index>1){
            int parent=index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
            }
            else{
                return;
            }
        }

    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


    void deleteHeap(){
        if(size==0){
            cout<<"Heap is empty";
            return;
        }
        arr[1]=arr[size]; // assigning the last element to very first one 
        size--;
        // taking the root node to its correct postion 
        int i=1;
        while(i<size){
            int leftIndex=i*2;
            int rightIndex=i*2 +1;
            if(leftIndex <size && arr[leftIndex] > arr[i]){
                swap(arr[i],arr[leftIndex]);
            }
            else if(rightIndex < size && arr[i]< arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
        }
        else{
            return ;
        }
    }
    }
};





int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteHeap();
    h.print();
}