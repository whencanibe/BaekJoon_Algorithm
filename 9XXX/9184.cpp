//https://www.acmicpc.net/problem/9184
#include <iostream>
#include <vector>

using namespace std;

vector<vector<vector<int> > > memo(51, vector<vector<int> >(51, vector<int>(51, -1)));

int wFunc(int a,int b,int c){
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return wFunc(20,20,20);
    
    if(memo[a][b][c] != -1) return memo[a][b][c];

    if (a < b && b < c) memo[a][b][c] = wFunc(a, b, c-1) + wFunc(a, b-1, c-1) - wFunc(a, b-1, c);
    else return memo[a][b][c] = wFunc(a-1, b, c) + wFunc(a-1, b-1, c) + wFunc(a-1, b, c-1) - wFunc(a-1, b-1, c-1);

    return memo[a][b][c];
}

int main(int argc, char const *argv[])
{
   int a,b,c;

   while(true){
    cin >> a >> b >> c;
    
    if (a==-1 && b ==-1 && c==-1){
        break;
    }
    
    printf("w(%d, %d, %d) = %d\n",a,b,c,wFunc(a,b,c));
   }
    
    return 0;
}
