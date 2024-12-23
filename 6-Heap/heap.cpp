//  heap is complete binary tree -- a complete binary tree is tree all node are level is fully filled except last one or leaf node
//  now there are two types of heap max and min heap

/***  in max heap parent node is always greater than child node
 * in min heap parent node is always smaller than both child node
 */

//  Insertion in heap
/**
 * node -> ith index
 * left child -> 2*i   inode
 * right child ->2*i +1 inode
 * parent -> i/2;
 *
 * For max heap implementation
 */


/// o(log(n))  --- time complexity;
#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    int arr[100];  
    int size = 0;
    heap(){
        size=0;
        arr[0]=-1;
    }

    void insert(int val)
    {
        size += 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index=parent;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout<<endl;
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
}