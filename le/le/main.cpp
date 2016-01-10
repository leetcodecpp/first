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
