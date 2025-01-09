#include <iostream>
#include <algorithm>
using namespace std;

bool binarySearch(int *A, int N, int target)
{
    int left = 0;
    int right = N - 1;

    

    while(left <= right){
        int mid = left + (right - left) / 2;
        if(A[mid] == target) return true;
        else if (A[mid] < target){
            left = mid + 1;
        } else{
            right = mid - 1;
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    int N, M;
    int *A;
    scanf("%d",&N);
    A = new int[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&A[i]);
    }

    sort(A, A + N);

    scanf("%d",&M);
    int num;
    for (int i = 0; i < M; i++)
    {
        scanf("%d",&num);
        int result = binarySearch(A, N, num);
        if (result) printf("1\n");
        else printf("0\n");
    }

    delete[] A;
    return 0;
}
