#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

class Node
{
    private:
        int value;
        Node* prev;

    public:
        int returnValue() { return value; }
        Node* returnPtr() { return prev; }

        Node(int val, Node* ptrToLast)
        {
            value = val;
            prev = ptrToLast;
        }
};

class Stack
{
    private:
        Node* top;
        int size;

    public:
        Stack() { size = 0; top = NULL; }
        ~Stack() {
                    while (top != NULL)
                    {
                        Node* tempPtr = top->returnPtr();
                        delete top;
                        top = tempPtr;
                    }
                 }

        Node* returnTopPtr() { return top; }

        void push(int);
        int pop();
        int peek();

        int returnSize();
        bool empty()
        {
            return top==NULL;
        }
};

int Stack::returnSize()
{
    return size;
}
void Stack::push(int value)
{
    ++size;
    Node* tempPtr = top;
    top = new Node(value, tempPtr);
}

int Stack::peek()
{
    return top->returnValue();
}
int Stack::pop()
{
    if (size == 0)
    {
        throw "bad stack size";
    }

    --size;

    Node* tempPtr = top->returnPtr();
    int tempVal = top->returnValue();
    delete top;
    top = tempPtr;

    return tempVal;
}
void example(){
    Stack s;
    s.push(1);

    cout<<s.peek();

    cout<<s.empty();
    s.pop();
    cout<<s.empty();

}

#endif // STACK_H
