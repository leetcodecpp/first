//
//  main.cpp
//  le
//
//  Created by QINQIN ZHU on 16/1/10.
//  Copyright © 2016年 QINQIN ZHU. All rights reserved.
//

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
/*
因此这题不是简单的一维DP，而是二维DP，需要计算并记录任意s[i:j]是否是回文：

定义bool isPal[i][j]表示s[i:j]是否为回文，isPal[i][j] = true需要满足两个条件:
1. s[i] ==s[j]
2. i+1>j-1或 isPal[i+1][j-1] == true (即s[i+1 : j-1]是回文)*/


class Solution5 {
public:
    string longestPalindrome(string s) {
        if(s.empty()||s.size()==1) return s;
        //当数组大小固定时,vector的效率要低一些，因此此题用vector会超时，但用数组不会。
        //vector<vector<bool>> pal(1000,vector<bool>(1000,false));
        bool pal[1000][1000]={false};
        int n=s.size();
        int maxlen=1;
        int start=0;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j]&&(i+1>j-1||pal[i+1][j-1]==true)){
                    pal[i][j]=true;
                    if(j-i+1>maxlen){
                        maxlen=j-i+1;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,maxlen);
    }
};

int main(int argc, const char * argv[]) {
    Solution5 s;
    cout<<s.longestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
