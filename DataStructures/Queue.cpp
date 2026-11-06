#include "Queue.h"
#include <iostream>


void initQueue(Queue* q, unsigned int size)
{
    /*
    fills values for all the spaces in the queue
    */
    
    if(size == 0)
    {
        return;
    }
    
    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter number " << i + 1 << ": ";
        std::cin >> q->value;

        q = q->next;
    }
     
}

void cleanQueue(Queue* q)
{
    /*
    removes all the values from the list
    */
    
    if(q)
    {
        q->value = 0;

        cleanQueue(q->next);
    }
} 

void enqueue(Queue* q, unsigned int newValue)
{
    /*
    places a value  into the furthermost empty space in the queue
    */
    
    if(q->value != 0)
    {
        std::cout << "The queue is full!\n";
        return;
    }

    else
    {
        while(q->next != NULL && q->next->value == 0)
        {
            q = q->next;
        }

        q->value = newValue;
    }
}

int dequeue(Queue* q)
{
    /*
    removes the firstmost value from the queue
    */
    
    int value = 0;

    while(q != NULL && q->value == 0)
    {
        q = q->next;
    }

    if(q == NULL)
    {
        return -1;
    }

    value = q->value;
    q->value = 0;

    return value;
}

bool isEmpty(Queue *s)
{
    /*
    checks if the queue is empty
    */
    
    while(s)
    {
        if(s->value != 0)
        {
            return false;
        }

        s = s->next;
    }

    return true;
}

bool isFull(Queue* s)
{
    /*
    Checks if the queue is full
    */

    while(s)
    {
        if(s->value == 0)
        {
            return false;
        }

        s = s->next;
    }

    return true;
}

/*Queue *createNode()
{
    Queue *newNode = NULL;

    newNode = new Queue;
    newNode->value = 0;
    newNode->next = NULL;

    return newNode;
}*/

void printList(Queue *q)
{
    /*
    prints a linked list
    */
    
    if(q)
    {
        std::cout << q->value << "\n";

        printList(q->next);
        return;
    }
    std::cout << "\n";
}

void freeList(Queue *q)
{
    /*
    frees the allocated structs
    */

    if(q)
    {
        freeList(q->next);
        delete q;
    } 
}