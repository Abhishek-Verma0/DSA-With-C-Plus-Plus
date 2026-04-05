#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0;
        int y=0;
        for(int i=0;i<moves.size();i++){
            
            if(moves[i]=='L') x--;
            if(moves[i]=='R') x++;
            if(moves[i]=='U')y++;
            if(moves[i]=='D')y--;

        }
        return (x==0 && y==0);
    }
};

