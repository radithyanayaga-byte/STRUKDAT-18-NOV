#include <iostream>
using namespace std;

const int MAX = 5;

struct CircularQueue {
    int info[MAX];
    int head;
    int tail;
    int total;
};

void createQueue(CircularQueue &Q) {
    Q.head = 0;
    Q.tail = -1;
    Q.total = 0;
}

bool isEmptyQueue(CircularQueue Q) {
    return Q.total == 0;
}

bool isFullQueue(CircularQueue Q) {
    return Q.total == MAX;
}

void enqueue(CircularQueue &Q, int value) {
    if (isFullQueue(Q)) {
        cout << "Queue Overflow! Cannot insert " << value << "." << endl;
    } else {
        Q.tail = (Q.tail + 1) % MAX;
        Q.info[Q.tail] = value;
        Q.total++;
        cout << value << " inserted successfully." << endl;
    }
}

void dequeue(CircularQueue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue Underflow! Queue is empty." << endl;
    } else {
        cout << Q.info[Q.head] << " removed successfully." << endl;
        Q.head = (Q.head + 1) % MAX;
        Q.total--;
    }
}

void display(CircularQueue Q) {
    cout << "Queue: ";
    if (isEmptyQueue(Q)) {
        cout << "(empty)" << endl;
    } else {
        for (int i = 0; i < Q.total; i++) {
            cout << Q.info[(Q.head + i) % MAX];
            if (i < Q.total - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void mandatoryTest(CircularQueue &Q) {
    createQueue(Q);

    enqueue(Q, 10);
    enqueue(Q, 20);
    enqueue(Q, 30);
    enqueue(Q, 40);
    enqueue(Q, 50);

    dequeue(Q);
    dequeue(Q);

    enqueue(Q, 60);
    enqueue(Q, 70);

    cout << endl;
    display(Q);
}

int main() {
    CircularQueue Q;
    int choice = 0;
    int value;

    createQueue(Q);

    do {
        cout << "===== CIRCULAR QUEUE MENU =====" << endl;
        cout << "1. Enqueue  2. Dequeue  3. Display" << endl;
        cout << "4. Run Mandatory Test  5. Exit" << endl << endl;
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
            display(Q);
        } else if (choice == 4) {
            mandatoryTest(Q);
        } else if (choice == 5) {
            cout << "Exiting program." << endl;
        } else {
            cout << "Invalid option. Choose 1-5." << endl;
        }
        cout << endl;
    } while (choice != 5);

    return 0;
}
