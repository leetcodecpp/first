//
//  main.cpp
//  new
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
//binary indexed tree .need to create a new struct 树状数组bit,in which bit[i] is the sum of the some elements of the original elements in A.根据坐标的最低位Low Bit来决定的,最低位的计算方法有两种，一种是x&(x^(x–1))，另一种是利用补码特性x&-x
// 更新某一位数字时，根据最低位的值来更新后面含有这一位数字的地方，一般只需要更新部分偶数位置的值即可，eg update nums[5],只需更新 bit[5]和其后面含有nums［5］的bit。
//在计算某一位置的前缀和时，利用树状数组的性质也能高效的很快算出来
class NumArray {
private:
    vector<int> num;
    vector<int> bit;
public:
    NumArray(vector<int> &nums) {
        num.resize(nums.size()+1);
        bit.resize(nums.size()+1);
        for(int i=0;i<nums.size();i++){
            update(i,nums[i]);
        }
    }
    
    void update(int i, int val) {
        int diff=val-num[i+1];
        for(int j=i+1;j<num.size();j+=(j&-j)){
            bit[j]+=diff;
        }
        num[i+1]=val;
    }
    int getsum(int i){
        int res=0;
        for(int j=i;j>0;j-=(j&-j)){
            res+=bit[j];
        }
        return res;
        
    }
    int sumRange(int i, int j) {
        return getsum(j+1)-getsum(i);
        
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
