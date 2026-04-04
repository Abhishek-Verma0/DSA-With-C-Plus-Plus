/*****What is double Hashing ??   Double is hashing is method used to avoid primary and secondary  clustring which we get during trying to manage the collision 
 * so it simply uses two hash function instead of two , first one finds the index where we need to store the elements if the collision occur for any other elements getting the same index as first one so we will use second hashing function to find other index most probably we use table size as prime number to avoid or reduce collision
 */

#include <iostream>
#include <vector>

#define TABLE_SIZE 7  /// table size for the first hash function 
#define PRIME 7  //  nearest prime number to initial table size which we will use as table size for the second function

using namespace std;

vector<int> hash_table(TABLE_SIZE, -1); // this initialzes the array of vector with each value as -1 
int size = 0;

// first hash function
int h1(int key) {
    return (key % TABLE_SIZE);
}
//  second hash fucntion
int h2(int key) {
    return (PRIME - (key % PRIME));
}


void insert(int key) {
    if (size == TABLE_SIZE)
        return; 

    int idx = h1(key);
    if (hash_table[idx] != -1) { // Collision occured we need to go for second hash function now
        int stepSize = h2(key);
        int i = 1;
        while (true) {
            int newIdx = (idx + i * stepSize) % TABLE_SIZE;   
            if (hash_table[newIdx] == -1) { // Found an empty slot
                hash_table[newIdx] = key;
                break;
            }
            i++;
        }
    } else {
        hash_table[idx] = key; // No collision
    }
    size++;
    
}

void display() {
    cout << "Hash Table:" << endl;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] != -1)
            cout << i << " --> " << hash_table[i] << endl;
        else
            cout << i << " --> ∅" << endl;
    }
}

int main() {
    //  initialzing the variables for the number of elemnts and elements we need to enter 
    int n, x;
    cout << "Enter number of elements to insert: ";
    cin >> n;
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(x);
    }
    display();
    return 0;
}





