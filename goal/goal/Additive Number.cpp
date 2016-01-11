//
//  main.cpp
//  goal
//
//  Created by QINQIN ZHU on 16/1/10.
//  Copyright © 2016年 QINQIN ZHU. All rights reserved.
//

#include <iostream>

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
//枚举前两个数的位置，因为前两个数决定了num是否为Additive
//然后递归。

class Solution {
public:
    bool isAdditiveNumber(string num) {
        string first;
        string second;
        for(int i=0;i<num.size();i++){
            for(int j=i+1;j<num.size()-i-1;j++){
                first=num.substr(0,i+1);
                second=num.substr(i+1,j-i);
                if(valid(first,second,num,j+1)) return true;
                
            }
            
        }
        return false;
    }
    
    bool valid(string first,string second,string num,int index){
        if(index==num.size()) return true;
        long f=atol(first.c_str());
        long s=atol(second.c_str());
        //this sentance will avoid the situation with numbers start with 0.eg,first=02,f=2.
        if(to_string(f)!=first||to_string(s)!=second) return false;
        long sum=f+s;
        string sumstr=to_string(sum);
        if(index+sumstr.size()>num.size()) return false;
        string third=num.substr(index,sumstr.size());
        if(sumstr!=third) return false;
        else return valid(second,third,num,index+sumstr.size());
        
        
    }
    
};
int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    cout<<s.isAdditiveNumber("1023");
    std::cout << "Hello, World!\n";
    return 0;
}
