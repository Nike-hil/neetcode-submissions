class DynamicArray {
private:
    int size;
    int capacity;
    int* arr;

public:
    DynamicArray(int cap) {
        size = 0;
        capacity = cap;
        arr = new int[capacity];
    }
    ~DynamicArray() {
        delete[] arr;
    }

    int get(int i) {
        if (i < 0 || i >= size) {
            cout << "Index out of bounds\n";
            return -1;
        }
        return arr[i];
    }

    void set(int i, int n) {
        if (i < 0 || i >= size) {
            cout << "Index out of bounds\n";
            return;
        }
        arr[i] = n;
    }

    void pushback(int n) {
        if (size == capacity) {
            resize();
        }

        arr[size] = n;
        size++;
    }

    int popback() {
        if (size == 0) {
            cout << "Array is empty\n";
            return -1;
        }

        int val = arr[size - 1];
        size--;
        return val;
    }

    void resize() {
        capacity = capacity * 2;

        int* newArr = new int[capacity];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};