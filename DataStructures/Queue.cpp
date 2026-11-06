#include "Queue.h"
#include <iostream>


void initQueue(Queue* q, unsigned int size)
{
    /*
    initializes the struct
    */
    
    q->arr = new int[size];
    q->size = size;

    for(int i = 0; i < q->size; i++)
    {
        q->arr[i] = 0;
    }
     
}

void cleanQueue(Queue* q)
{
    /*
    removes all the values from the list
    */
    
    for(int i = 0; i < q->size; i++)
    {
        q->arr[i] = 0;
    }
} 

void enqueue(Queue* q, unsigned int newValue)
{
    /*
    places a value  into the furthermost empty space in the queue
    */
    
    if(q->arr[0] != 0)
    {
        std::cout << "Queue is full!\n";
        return;
    }
    
    for(int i = 0; i < q->size; i++)
    {
        if(q->arr[i + 1] != 0 || i == q->size - 1)
        {
            q->arr[i] = newValue;
            return;
        }
    }
}

int dequeue(Queue* q)
{
    /*
    removes the firstmost value from the queue
    */
    
    int value = 0;

    value = q->arr[q->size - 1];

    for(int i = q->size; i > 0; i--)
    {
        q->arr[i] = q->arr[i - 1];
    }

    q->arr[0] = 0;

    return value;
}

bool isEmpty(Queue *s)
{
    /*
    checks if the queue is empty
    */
    
    for(int i = 0; i < s->size; i++)
    {
        if(s->arr[i] != 0)
        {
            return false;
        }
    }

    return true;
}

bool isFull(Queue* s)
{
    /*
    Checks if the queue is full
    */

    for(int i = 0; i < s->size; i++)
    {
        if(s->arr[i] == 0)
        {
            return false;
        }
    }

    return true;
}


void printList(Queue *q)
{
    /*
    prints a linked list
    */
    
    for(int i = 0; i < q->size; i++)
    {
        std::cout << q->arr[i] << "\n";
    }

    std::cout << "\n";
}

void freeList(Queue *q)
{
    /*
    frees the allocated structs
    */

    delete q->arr;
    delete q;
}