

#include <bits/stdc++.h>
using namespace std;
int main()
{

    int m = 10;
    int hashtable[m];
    for (int i = 0; i < m; i++)
    {
        hashtable[i] = -1;
    }
    int keys[] = {10, 55, 32, 77};
    int n = sizeof(keys) / sizeof(keys[0]);
    for (int i = 0; i < n; i++)
    {
        int key = keys[i];
        int index = key % m;
        if (hashtable[index] == -1)
        {
            hashtable[index] = key;
        }
        else
        {
            cout << "collision occured";

            return -1;
        }
    }
    cout << "hash table is  "<<endl;
    for (int i = 0; i < m; i++)
    {
        if (hashtable[i] != -1)
        {
            cout <<"Index "<<i<<" "<< hashtable[i]<<" "<<endl;
        }
    }
    return 0;
}



