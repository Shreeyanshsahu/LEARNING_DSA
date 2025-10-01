#include <iostream>
using namespace std;

class Queue {
    int *arr;        // array to store elements
    int front;       // index of front element
    int rear;        // index of last element
    int capacity;    // maximum capacity
    int count;       // current size of queue

public:
    Queue(int size);
    ~Queue();

    void enqueue(int x);  // insert element at rear
    int dequeue();        // remove element from front
    int peek();           // get front element
    int size();           // get current size
    bool isEmpty();       // check if empty
    bool isFull();        // check if full
};

// Constructor
Queue::Queue(int size) {
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// Destructor
Queue::~Queue() {
    delete[] arr;
}

// Insert at rear
void Queue::enqueue(int x) {
    if (isFull()) {
        cout << "Queue Overflow\n";
        return;
    }

    rear = (rear + 1) % capacity; // circular increment
    arr[rear] = x;
    count++;
    cout << x << " enqueued\n";
}

// Remove from front
int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow\n";
        return -1;
    }

    int x = arr[front];
    front = (front + 1) % capacity;
    count--;
    return x;
}

// Get front element
int Queue::peek() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return -1;
    }
    return arr[front];
}

// Current size
int Queue::size() {
    return count;
}

// Empty?
bool Queue::isEmpty() {
    return (count == 0);
}

// Full?
bool Queue::isFull() {
    return (count == capacity);
}

// Driver code
int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element is: " << q.peek() << endl;
    cout << "Queue size is " << q.size() << endl;

    q.dequeue();
    q.dequeue();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70); // This will show overflow because capacity=5

    while (!q.isEmpty()) {
        cout << "Dequeued: " << q.dequeue() << endl;
    }

    return 0;
}
