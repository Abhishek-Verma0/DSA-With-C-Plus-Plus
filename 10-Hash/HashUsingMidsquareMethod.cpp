/************ Hash Table using the Midsquare Method ************/

#include <bits/stdc++.h>
using namespace std;

int midsquaremethod(int key, int m)
{
    long square = (long)key * key;
    int middle = (square / 100) % 100;
    return middle % m;
}




int main()
{
    int keys[] = {123, 456, 234};
    int m = 10;
    for (int key : keys)
    {
        long square = (long)key * key;
        int hashvalue = midsquaremethod(key, m);
        cout << key << " " << hashvalue << endl;
    }
    return 0;


}





