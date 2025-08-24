#include <iostream>

int arr[] = {6, 3, 1, 2, 5, 4, 9, 8, 7};

void quick_sort(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int pivot = start;
    int left = pivot + 1;
    int right = end;

    // 피벗 기준 분할
    while (left <= right)
    {
        while (left <= end && arr[left] <= arr[pivot])
        {
            left++;
        }

        while (right > start && arr[right] >= arr[pivot])
        {
            right--;
        }

        if (left > right)
        {
            int tmp = arr[pivot];
            arr[pivot] = arr[right];
            arr[right] = tmp;
        }
        else
        {
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
        }
    }
    quick_sort(arr, start, right-1);
    quick_sort(arr, right+1, end);

}

int main(int argc, char const *argv[])
{
    int len = sizeof(arr)/sizeof(int);
    quick_sort(arr, 0, len - 1);

    for (int num : arr){
        std::cout << num << " ";
    }
    return 0;
}
