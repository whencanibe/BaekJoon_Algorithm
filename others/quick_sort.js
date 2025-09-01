const arr = [5, 3, 1, 4, 2, 6, 8, 7, 9];

const quickSort = (arr, start, end) => {
  if (start >= end) {
    return;
  }

  let pivot = start;
  let left = start + 1;
  let right = end;

  while (left <= right) {
    while (left <= end && arr[left] <= arr[pivot]) {
      left++;
    }

    while (right > start && arr[right] >= arr[pivot]) {
      right--;
    }

    if (left > right) {
      const tmp = arr[pivot];
      arr[pivot] = arr[right];
      arr[right] = tmp;
    } else {
      const tmp = arr[left];
      arr[left] = arr[right];
      arr[right] = tmp;
    }
  }

  quickSort(arr, start, right - 1);
  quickSort(arr, right + 1, end);
};

quickSort(arr, 0, arr.length - 1);
console.log(arr);
