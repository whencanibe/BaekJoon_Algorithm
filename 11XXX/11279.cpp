#include <iostream>
#include <vector>

using namespace std;

class MaxHeap{
private:
    vector<int> heap;

    int parent(int i){
        return (i-1) / 2;
    }

    int leftChild(int i){
        return 2 * i + 1;
    }

    int rightChild(int i){
        return 2 * i + 2;
    }

    void heapifyUp(int i){
        while(i > 0 && heap[parent(i)] < heap[i]){
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i){
        int maxIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);
        int heapSize = heap.size();

        if(left < heapSize && heap[left] > heap[maxIndex]){
            maxIndex = left;
        }
        if(right < heapSize && heap[right] > heap[maxIndex]){
            maxIndex = right;
        }

        if (i != maxIndex){
            swap(heap[i], heap[maxIndex]);
            heapifyDown(maxIndex);
        }
    }

public:
    MaxHeap(){};

    bool isEmpty(){
        return heap.size() == 0;
    }

    void push(int data){
        heap.push_back(data);
        heapifyUp(heap.size() - 1);
    }

    int pop(){
        if (isEmpty()){
            return 0;
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if(!isEmpty()){
            heapifyDown(0);
        }

        return root;
    }
};

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    MaxHeap heap = MaxHeap();
    for(int i = 0 ; i < N ; i++){
        int x;
        scanf("%d",&x);

        if(x==0){
            int tmp = heap.pop();
            printf("%d\n",tmp);
        } else{
            heap.push(x);
        }
    }
    return 0;
}
