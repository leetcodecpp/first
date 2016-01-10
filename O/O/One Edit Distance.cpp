//
//  One Edit Distance.cpp
//  O
//
//  Created by QINQIN ZHU on 16/1/9.
//  Copyright © 2016年 QINQIN ZHU. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <math.h>
#include<queue>
#include<stack>
#include<streambuf>
#include<strstream>
#include<strings.h>
#include<sstream>
using namespace std;
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        cout<<"8"<<endl;
        int m=s.size();
        int n=t.size();
        if(m>n) return isOneEditDistance(t,s);
        if(n-m>1) return false;
        int c=n-m;
        int i=0;
        while(s[i]==t[i]&&i<m) ++i;
        if(i==m) return c>0;
        if(c==0) ++i;
        while(s[i]==t[i+c]&&i<m) ++i;
        return (i==m);
    }
};
int main(int argc, const char * argv[]) {
    cout << "k";
    Solution s;
    bool flag=s.isOneEditDistance("a","");
    if(flag==true) cout<<"1"<<endl;
    else cout<<"0"<<endl;
    cout << "Hello, World!\n";
    return 0;
}