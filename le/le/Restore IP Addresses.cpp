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
 一个有效的IP地址由4个数字组成，每个数字在0-255之间。对于其中的2位数或3位数，不能以0开头。所以对于以s[i]开头的数字有3种可能：
 
 1. s[i]
 2. s[i : i+1]，s[i] !=0时
 3. s[i : i+2]，s[i] != 0，且s[i : i+2] <= 255
 
 根据以上规律，对s从头开始进行DFS寻找4个数字即可。

*/

class Solution93 {
public:
    bool isvalid(string s){
        if(s.empty()||s.size()>3) return false;
        if(s[0]=='0'&&s.size()!=1) return false;
        if(s.size()==3&&stoi(s)>255) return false;
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> cur;
        dfs(res,cur,s,0);
        return res;
    }
    void dfs(vector<string> &res,vector<string> cur,string &s,int index){
        if(cur.size()==4){
            if(index==s.size()){
                string tmp=cur[0];
                for(int i=1;i<4;i++){
                    tmp+="."+cur[i];
                }
                res.push_back(tmp);
            }
            return;
        }
        string curstring;
        for(int i=index;i<s.size()&&i<index+3;i++){
            curstring.push_back(s[i]);
            if(isvalid(curstring)){
                cur.push_back(curstring);
                dfs(res,cur,s,i+1);
                cur.pop_back();
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution93 s;
    cout<<s.restoreIpAddresses("0000")[0];
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
