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
/*
thress cases:
 //make sure m<n
 1.case 1:m==n,only need to modify the different one and ++i.then check if rest of the s[i] and t[i] are the same.
     after first loop,if i==m and m==n return false(same);or i==m but m!=n return true;(insert the last one.)
 case 2:n-m==1,only need to insert into s.then check if s[i] and t[i+1] are the same.
 
 conclude 1 and 2:s[i]==t[i+shift]
 
 
 
 
 
*/
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
        // if two string are the same (shift==0), return false
        if(i==m) return c>0;
        // if n==m skip current char in s (modify operation in s)
        if(c==0) ++i;
        // use shift to skip one char in t
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