//
//  main.cpp
//  leetpalin
//
//  Created by QINQIN ZHU on 15/11/13.
//  Copyright © 2015年 QINQIN ZHU. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<char>> dp(string s){
        
        int n=s.size();
        vector<vector<char>> pal(n,vector<char>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(j==i){pal[i][j]=1;}
                else{
                    if(s[i]==s[j]){
                        if(j==i+1||pal[i+1][j-1]==1) pal[i][j]=1;
                        //else pal[i][j]=false;
                    }
                    //else pal[i][j]=false;
                }
            }
        }
        return pal;
    }
    void dfs(int begin,vector<vector<string>> &res,string s,vector<string> &row,vector<vector<char>> pal){
        if(begin>=s.size()){
            res.push_back(row);
            return;
        }
        else{
            for(int i=begin;i<s.size();i++){
                if(pal[begin][i]==1){
                    row.push_back(s.substr(begin,i-begin+1));
                    dfs(i+1,res,s,row,pal);
                    row.pop_back();
                }
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> row;
        if(s.empty())  return res;
        vector<vector<char>> pal;
        pal=dp(s);
        dfs(0,res,s,row,pal);
        return res;
    }
    
};

int main(int argc, const char * argv[]) {
    Solution s;
   // vector<vector<string>> v=;
    cout<<s.partition("a")[0][0]<<endl;
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
