//https://www.acmicpc.net/problem/12865
#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n,k;
    std::cin >> n >> k;
    std::vector<std::pair<int,int> > items(n);

    for (int i = 0 ; i < n ; i++){
        std::cin >> items[i].first >> items[i].second;
    }

    std::vector<int> dp(k+1,0);
    for (int i = 0 ; i < n ; i++){
        int W = items[i].first;
        int V = items[i].second;
        for (int j = k ; j >= W ; j--){
            dp[j] = std::max(dp[j],dp[j-W]+V);
        }
    }

    std::cout << dp[k] <<std::endl;
   
    return 0;
}
