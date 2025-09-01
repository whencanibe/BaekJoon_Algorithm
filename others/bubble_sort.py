array = [5,7,9,0,3,1,6,2,4,8]

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-1-i):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr

sorted_array = bubble_sort(array)
print(sorted_array)