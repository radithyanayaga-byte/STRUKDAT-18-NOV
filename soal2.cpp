#include <iostream>
using namespace std;

const int MAX = 100;

struct StackChar {
    char info[MAX];
    int top;
};

void createStack(StackChar &S) {
    S.top = -1;
}

bool isEmptyStack(StackChar S) {
    return S.top == -1;
}

bool isFullStack(StackChar S) {
    return S.top == MAX - 1;
}

void push(StackChar &S, char c) {
    if (isFullStack(S)) {
        cout << "Stack Overflow! Cannot insert '" << c << "'." << endl;
    } else {
        S.top++;
        S.info[S.top] = c;
    }
}

char pop(StackChar &S) {
    char c = S.info[S.top];
    S.top--;
    return c;
}

int main() {
    StackChar S;
    char word[MAX + 1];
    char reversed[MAX + 1];
    int length = 0;
    int n = 0;

    createStack(S);

    cout << "Enter a word: ";
    cin.width(MAX + 1);
    cin >> word;

    while (word[length] != '\0') {
        push(S, word[length]);
        length++;
    }

    while (!isEmptyStack(S)) {
        reversed[n] = pop(S);
        n++;
    }
    reversed[n] = '\0';

    cout << endl;
    cout << "Original word: " << word << endl;
    cout << "Reversed word: " << reversed << endl;

    return 0;
}
