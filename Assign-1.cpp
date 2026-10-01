
#include <iostream>
using namespace std;



class Queue {
private:
    static const int SIZE = 1000;

    int arr[SIZE];
    int front;
    int rear;
    int count;

public:
    Queue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == SIZE;
    }

    void enqueue(int value) {
        if (isFull()) {
            return;
        }

        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        count++;
    }

    int dequeue() {
        if (isEmpty()) {
            return -1;
        }

        int value = arr[front];

        front = (front + 1) % SIZE;
        count--;

        return value;
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }

        return arr[front];
    }
};




class StackWithQueue {
public:
    Queue q1;
    Queue q2;

    void push(int value) {

        // Insert new element into q2
        q2.enqueue(value);

        // Move all elements from q1 to q2
        while (!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }

        // Move everything back from q2 to q1
        while (!q2.isEmpty()) {
            q1.enqueue(q2.dequeue());
        }
    }

    int pop() {
        if (q1.isEmpty()) {
            return -1;
        }

        return q1.dequeue();
    }

    int top() {
        if (q1.isEmpty()) {
            return -1;
        }

        return q1.peek();
    }

    bool isEmpty() {
        return q1.isEmpty();
    }
};




void convertToBinary(int n) {

    StackWithQueue stack;

    if (n == 0) {
        cout << "0" << endl;
        return;
    }

    while (n > 0) {
        stack.push(n % 2);
        n = n / 2;
    }

    while (!stack.isEmpty()) {
        cout << stack.pop();
    }

    cout << endl;
}



void generateBinaryNumbers(int m) {

    Queue q;

    q.enqueue(1);

    for (int i = 0; i < m; i++) {

        int current = q.dequeue();

        cout << current;

        if (i < m - 1) {
            cout << " ";
        }

        q.enqueue(current * 10);
        q.enqueue(current * 10 + 1);
    }

    cout << endl;
}



void sortUsingStack(int arr[], int n) {

    StackWithQueue stack;
    StackWithQueue sorted;


    for (int i = 0; i < n; i++) {
        stack.push(arr[i]);
    }


    while (!stack.isEmpty()) {

        int temp = stack.pop();

        while (!sorted.isEmpty() && sorted.top() > temp) {
            stack.push(sorted.pop());
        }

        sorted.push(temp);
    }


    for (int i = 0; i < n; i++) {
        arr[i] = sorted.pop();
    }
}




void printArray(int arr[], int n) {

    for (int i = 0; i < n; i++) {
        cout << arr[i];

        if (i < n - 1) {
            cout << " ";
        }
    }

    cout << endl;
}




int main() {

    int decimalNumber;
    int m;
    int n;


    cin >> decimalNumber;


    convertToBinary(decimalNumber);


    cin >> m;


    generateBinaryNumbers(m);


    cin >> n;

    int arr[1000];


    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sortUsingStack(arr, n);


    printArray(arr, n);

    return 0;
}


