/** What is Queue ??
 *  SO queue is simple data structure which is based on  the structure  FIFO ( First in First Out)
 * for example people standing in the line of  ticket counter in a movie theater
 *    In queue we can add element at the end and remove element from the front of the queue
 * There are different types of queue
 * 1-- Linear queue -- input at end or rear remove element from front
 * 2 -- Circulat queue  -- last position is added to the first one
 * 3- Priority Queue  --- elements are inserted in queue on basis of priority instead of inout order
 * 4 -  Double Ended Queue ( Deque ) -- Elements can be inserted or remove form both ends of the queue
 * 5- input Restricted queue  -- Insertion is allowed at only one end that is rear but deletion can be done from any of the ends
 * 6- Output Restricted Queue -- A type of Deque where insertion is allowed at both end but removal can be done at front
 */

//  this Is array implementation of queue
/** few things need to keep in mind
 * Queue should be empty for Inserting an element or Enqueue  also not be full
 * Queue should not be empty for removal of element from queue or Dequeue
 *
 * Insertion is done at end
 * removal is donea at front
 */

#include <iostream>
using namespace std;

int enq(int arr[],int &size,int maxsize,int data,int &rear){
    if(size==maxsize){
        cout<<"Queue is full"<<endl;
        return 0;
    }
    size++;
    rear++;
    arr[rear]=data;
    return 0;
}


int deq(int arr[],int &size,int &rear){
    if(size==0){
        cout<<"Queue is empty"<<endl;
        return 0;
    }
    cout<<"Dequeued --  ";
        cout<<arr[0]<<endl;
    for(int i=1;i<=rear;i++){
        arr[i-1]=arr[i];
    }
    size--;
    rear--;
    return 1;
}
 


int main()
{
    int n;
    int rear = -1;
    int val ;
    int size = 0;
    cout << "Enter the number of elements you need in the queue  :: ";
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>val;
        enq(arr,size,n,val,rear);
    }
    while(size>0){
    deq(arr,size,rear);
    }

}