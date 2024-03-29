﻿#include<iostream>
using namespace std;
int j;

struct Node {
    char data;
    Node* next;
};

struct Stack {
    Node* head = nullptr;
    int size = 0;
};

void push(Stack& stack, char a) {
    Node* new_node = new Node;
    new_node->data = a;
    new_node->next = stack.head;
    stack.head = new_node;
    stack.size++;
}

void pop(Stack& stack) {
    Node* delete_node = stack.head;
    stack.head = delete_node->next;
    delete delete_node;
    stack.size--;
}

void print(Stack& stack) {
    Node* current_node = stack.head;
    while (current_node != nullptr) {
        cout << current_node->data << " ";
        current_node = current_node->next;
    }
    cout << endl;
}

char top(Stack& stack) {
    return stack.head->data;
}

int main() {
    setlocale(LC_ALL, "Rus");
    int n;
    Stack stack;
    char a;
    cout << "Введите кол-во элементов в стеке: ";
    cin >> n;
    cout << "Введите элементы в стеке: ";

    for (int i = 0; i < n; i++) {
        cin >> a;
        push(stack, a);
    }

    cout << "Стек: ";
    print(stack);

    char key, key1;
    cout << "Введите, значение после которого нужно добавить: ";
    cin >> key;
    cout << "Введите, значение которое нужно добавить: ";
    cin >> key1;
    Stack stack1;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (flag == true) {
            push(stack1, key1);
            flag = false;
        }
        if (top(stack) == key) {
            flag = true;
            push(stack1, top(stack));
            pop(stack);
        }
        else {
            push(stack1, top(stack));
            pop(stack);
        }
    }

    Stack stack2;
    n = stack1.size;
    for (int i = 0; i < n; i++) {
        push(stack, top(stack1));
        pop(stack1);
    }
    cout << "Финальный стек: ";
    print(stack);
    return 0;
}
