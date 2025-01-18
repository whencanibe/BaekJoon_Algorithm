package j1XXX;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class MinHeap{
    private int initSize;
    private int size;
    private int[] heap;

    public MinHeap(int heapSize){
        this.initSize = heapSize;
        this.heap = new int[initSize];
        this.size = 0;
    }

    public void insert(int data){
        heap[size++] = data;
        heapifyUp(size - 1);
    }

    public int extractMin(){
        if(isEmpty()){
            return 0;
        }
        int value = heap[0];
        
        if (size == 1){
            size--;
            return value;
        } 
        heap[0] = heap[size-1];
        heap[size-1] = 0;
        size--;
        heapifyDown(0);
        
        return value;
    }

    public boolean isEmpty(){
        return size == 0 ? true : false; 
    }

    private void heapifyUp(int index){
        int parentIndex = (index - 1) / 2;

        while(index > 0 &&heap[index] < heap[parentIndex]){ //&& parentIndex >= 0  는 필요없음
            swap(index, parentIndex);
            index = parentIndex;
            parentIndex = (index - 1) / 2;
        }

    }

    private void heapifyDown(int index){
        int smallest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if(leftChild < size && heap[smallest] > heap[leftChild]){
            smallest = leftChild;
        }

        if(rightChild < size && heap[smallest] > heap[rightChild]){
            smallest = rightChild;
        }

        if(index != smallest){
            swap(smallest, index);
            heapifyDown(smallest);
        }

    }

    private void swap(int i, int j){
        int tmp = heap[i];
        heap[i] = heap[j];
        heap[j] = tmp;
    }
    
}
public class j1927 {
    public static void main (String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(reader.readLine());
        MinHeap mh = new MinHeap(N);

        for(int i = 0 ; i < N ; i++){
            int num = Integer.parseInt(reader.readLine());
            if(num == 0){
                int result = mh.extractMin();
                System.out.println(result);
            } else{
                mh.insert(num);
            }
        }

    }
}
