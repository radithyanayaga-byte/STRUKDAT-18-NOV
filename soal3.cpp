#include <iostream>
using namespace std;

const int MAX = 5;

struct Queue {
    int info[MAX];
    int head;
    int tail;
};

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.head == -1;
}

bool isFullQueue(Queue Q) {
    return Q.tail == MAX - 1;
}

void enqueue(Queue &Q, int value) {
    if (isFullQueue(Q)) {
        cout << "Queue Overflow! Cannot insert " << value << "." << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
        }
        Q.tail++;
        Q.info[Q.tail] = value;
        cout << value << " inserted successfully." << endl;
    }
}

void dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue Underflow! Queue is empty." << endl;
    } else {
        cout << Q.info[Q.head] << " removed successfully." << endl;
        if (Q.head == Q.tail) {
            createQueue(Q);
        } else {
            Q.head++;
        }
    }
}

void front(Queue Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Front element: " << Q.info[Q.head] << endl;
    }
}

void display(Queue Q) {
    cout << "Queue: ";
    if (isEmptyQueue(Q)) {
        cout << "(empty)" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    Queue Q;
    int choice = 0;
    int value;

    createQueue(Q);

    do {
        cout << "===== QUEUE MENU =====" << endl;
        cout << "1. Enqueue  2. Dequeue" << endl;
        cout << "3. Front  4. Display  5. Exit" << endl << endl;
        display(Q);
        cout << "Choose operation: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            enqueue(Q, value);
        } else if (choice == 2) {
            dequeue(Q);
        } else if (choice == 3) {
            front(Q);
        } else if (choice == 4) {
            display(Q);
        } else if (choice == 5) {
            cout << "Exiting program." << endl;
        } else {
            cout << "Invalid option. Choose 1-5." << endl;
        }
        cout << endl;
    } while (choice != 5);

    return 0;
}
