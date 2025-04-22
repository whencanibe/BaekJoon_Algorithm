#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d",&N);

    std::vector<int> levels;

    for (int i = 0 ; i < N ; i++){
        int num;
        scanf("%d", &num);
        levels.push_back(num);
    }
    int count = 0;
    for (int i = N - 1 ; i > 0 ; i--){
        if (levels[i] <= levels[i-1]){
            int res = levels[i] - 1;
            int diff = levels[i-1] - res;
            levels[i-1] = res;
            count += diff;
        }
    }

    printf("%d", count);
    return 0;
}
