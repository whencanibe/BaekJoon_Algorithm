// https://www.acmicpc.net/problem/1655
//참고
//https://www.acmicpc.net/blog/view/56
//Use scanf and printf instead of cin and cout to save time
#include <iostream>
#include <queue>
#include <vector>

int main()
{
    int n;
    int t;
    std::cin >> n;
    std::priority_queue<int> leftHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int> > rightHeap;
    std::vector<int> result(n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d",&t);
        if (leftHeap.empty() || t <= leftHeap.top())
        {
            leftHeap.push(t);
        }
        else if (t > leftHeap.top())
        {
            rightHeap.push(t);
        }

        if(leftHeap.size() >= rightHeap.size() + 2){
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
        } else if(leftHeap.size() < rightHeap.size()){
            leftHeap.push(rightHeap.top());
            rightHeap.pop();
        }
        printf("%d\n",leftHeap.top());
    }
    return 0;
}