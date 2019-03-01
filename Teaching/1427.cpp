#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include <cctype>
#include <vector>

using namespace std;

const char * Y = "Yes";
const char * N = "No";

vector<int> dp[4][4]; //dp[0][3]表示0~3区间内有多少个值
int arr[4];
string strs[4];

int convert(const string & str){
    if(str == "A")
        return 1;
    else if(str.size() == 2)
        return 10;
    else if(isdigit(str[0]))
        return str[0] - '0';
    else if(str == "J")
        return 11;
    else if(str == "Q")
        return 12;
    else if(str == "K")
        return 13;
}

void init(){

    for(int j = 0;j != 4;j++){
        for(int k = 0;k != 4;k++){
            dp[j][k].clear();
        }
    }
    for(int j = 0;j != 4;j++){
        dp[j][j].push_back(arr[j]);
    }
}

void DP(int l , int r){
    if(l == r) 
        return;
    for(int j = l ;j < r ;j++){
        if(dp[l][j].empty())
            DP(l , j);
        if(dp[j + 1][r].empty())
            DP(j + 1 , r);

        for(auto & e1 : dp[l][j]){
            for(auto & e2 : dp[j + 1][r]){
                dp[l][r].push_back(e1 + e2);
                dp[l][r].push_back(e1 * e2);
                dp[l][r].push_back(e1 - e2);
                if(e2 && e1 % e2 == 0)
                    dp[l][r].push_back(e1 / e2);
            }
        }
    }
}

bool isSolveInSeq(){
    init();
    DP(0 , 3);
    
    for(auto & e : dp[0][3])
        if(e == 24)
            return true;

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> strs[0] >> strs[1] >> strs[2] >> strs[3]){
        for(int j = 0;j != 4;j++)
            arr[j] = convert(strs[j]);
        sort(arr , arr + 4);

        bool flag = false;
        do{
            if(isSolveInSeq()){
                flag = true;
                break;
            }
        }while(next_permutation(arr , arr + 4));

        cout << (flag ? Y : N) << endl;
    }
    return 0;
} 
