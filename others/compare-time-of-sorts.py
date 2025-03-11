import time
import insertion_sort
import quick_sort
import selection_sort
import random

new_array = []
for i in range(10000):
    rand_num = random.randint(1,15000)
    new_array.append(rand_num)

array = new_array.copy()
start_time = time.time()
insertion_sort.insertion_sort(array)
end_time = time.time()
print("Insertion sort : ", end_time - start_time)

array = new_array.copy()
start_time = time.time()
selection_sort.selection_sort(array)
end_time = time.time()
print("Selection sort : ", end_time - start_time)

array = new_array.copy()
start_time = time.time()
quick_sort.quick_sort(array,0,len(array)-1)
end_time = time.time()
print("Quick sort : ", end_time - start_time)

array = new_array.copy()
start_time = time.time()
array.sort()
end_time = time.time()
print("Python sort : ", end_time - start_time)


