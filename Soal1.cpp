#include <iostream>
using namespace std;

const int MAX = 5;
struct Stack {
    int info[MAX];
    int top;
};

void createStack(Stack &S){
    S.top = -1;
}

void isEmpty(Stack S){
    return S.top == -1;
}

void isFull(Stack S){
    return S.top = MAX - 1;
}

void push(Stack &S, int value){
    if(isFull(S)){
        cout << "Stack Overflow! Cannot insert " << value << endl;
    }else{
    S.top++
    S.info[S.top] = value;
    cout << value << "Inserted successfully." << endl;
    }
}

void pop(Stack S){
    if(isEmpty(S)){
        cout << "Stack Underflow cannot insert " << endl;
    }else{
    cout << S.info[S.top] << "Removed successfully." << endl;
    S.top--
    }
}

void peek(Stack S){
    if(isEmpty(S)){
        cout << "Stack (Top to bottom) : " << endl;
    }else{
        cout << "Top Element : " << S.info[S.top] << endl;
    }
}

void display(Stack S){
    if(isEmpty(S)){
        cout << "Stack (Top to bottom) : " << endl;
    }else{
        cout << "Top Element : " << S.info[S.top] << endl;
        for (int i = S.top; i >= 0; i--){
            cout << S.info[i] << " " << endl;
        }
    }
}

int main() {
    Stack S;
    int choice = 0;
    int value;

    createStack(S);

    while (choice != 5){
        cout << "===== STACK MENU =====" << endl;
        cout << "1. Push 2. Pop 3. Peek" << endl;
        cout << "4. Display 5. Exit" << endl;
        cout << "Choose Operation";
        cin >> choice;

        if (choice == 1){
            cout << "Enter Value : ";
            cin >> value;
            push(S, value);
        }else if (choice == 2){
            pop(5);
        }else if (choice == 3){
            peek(5);
        }else if (choice == 4){
            display(S);
        }else if (choice == 5)
            cout << "Exitting Program" << endl
        {else{
            cout << "Invalid Option Choose 1-5" << endl;
        }
    }
    return 0
}
