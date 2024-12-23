// what is stack ?? - A stack is a type of data structure which follows LIFO (Last in first out )- structure  


/** there are some key conditions to keep in mind while implementing the stack 
 * 1- to check whether stack is empty or full
 * 2- if is empty we can't perform the pop operation on the stack as the  stack is empty
 * 3- if it is full we can go for the pop operation but we can't go for the push operation as stack is already full
 * 
 * 
 * there are some operation we can perform on the stack that are
 *   push,  pop ,  top 

  Disdvantages of the array implementation of the stack is 
    * it is not dynamic means the size of stack can't grow or shrink during runtime 
    we need to define the total size of an stack before

 */


#include<iostream>
using namespace std;

int pus(int  arr[], int &top, int size, int data){
    if(top==size-1){
        cout<<"Overflow";
        return 0;
    }
    top++;
    arr[top]=data;
    return 0;
}

int pop(int arr[], int &top,int size){
    if(top==-1){
        cout<<"Underflow";
        return  0;
    }
    cout<<arr[top]<<" ";
    top--;
    return 0;
}


int  main(){
    int n;
    cout<<"Enter the size of the stack"<<endl;
    cin>>n;
    int stack[n];
    int top=-1;
    int  val;
    cout<<"Enter the values to be stored in the stack :: ";
    for(int i=0;i<n;i++){
        cin>>val;
        pus(stack,top,n,val);
    }

    cout<<"Popping out the values of the stack one by one "<<endl;
    for(int i=0;i<n;i++){
        pop(stack,top,n);
    }

return 0;

}
