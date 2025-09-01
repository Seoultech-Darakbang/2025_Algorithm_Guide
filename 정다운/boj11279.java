import java.util.*;
import java.io.*;

class MaxHeap {
    ArrayList<Integer> heap = new ArrayList<>();
    int heapCount = 0;

    MaxHeap() {
        heap.add(0);
    }

    public boolean isEmpty() {
        return heapCount == 0;
    }

    public void push(int data) {
        heapCount++;
        if (heap.size() <= heapCount) {
            heap.add(data);
        } else {
            heap.set(heapCount, data);
        }

        int child = heapCount;
        int parent = child / 2;
        while (child > 1) {
            if (heap.get(parent) < heap.get(child)) {
                Collections.swap(heap, child, parent);
                child = parent;
                parent = child / 2;
            } else
                break;
        }
    }

    public int pop() {
        if (isEmpty())
            return 0;
        int temp = heap.get(1);
        heap.set(1, heap.get(heapCount));
        heapCount--;

        int parent = 1;
        int child = parent * 2;

        while (child <= heapCount) {
            if (heap.get(child) < heap.get(child + 1))
                child++;
            if (heap.get(parent) < heap.get(child)) {
                Collections.swap(heap, parent, child);
                parent = child;
                child = parent * 2;
            } else
                break;
        }
        return temp;
    }
}


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        MaxHeap heap = new MaxHeap();
        ArrayList<Integer> result = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int x = Integer.parseInt(br.readLine());
            if (x == 0) {
                result.add(heap.pop());
            } else {
                heap.push(x);
            }
        }

        for (int i : result) {
            System.out.println(i);
        }
    }
}
