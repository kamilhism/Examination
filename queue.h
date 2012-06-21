#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

class Node
{
public:
   int data;
   Node* next;
};

class ListQueue
{
private:
   Node* front;
   Node* rear;
   int count;

public:
   ListQueue()
   {
       front = NULL;
       rear = NULL;
       count = 0;
   }

   void push(int element)
   {
       Node* tmp = new Node();
       tmp->data = element;
       tmp->next = NULL;

       if ( isEmpty() ) {
           front = rear = tmp;
       }
       else {
           rear->next = tmp;
           rear = tmp;
       }

       count++;
   }

   int del()
   {
       if ( isEmpty() )
           throw "error";

       int ret = front->data;
       Node* tmp = front;

       front = front->next;

       count--;
       delete tmp;
       return ret;
   }

   int Front()
   {
       if ( isEmpty() )
           throw "error";

       return front->data;
   }

   int Size()
   {
       return count;
   }

   bool isEmpty()
   {
       return count == 0 ? true : false;
   }
};

void example()
{
   ListQueue q;


       q.push(100);
       q.push(200);

       cout<< q.Size() << endl;
       cout<< q.Front()<< endl;

       cout << q.del() << endl;
}


#endif // QUEUE_H
