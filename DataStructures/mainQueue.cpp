#include <iostream>
#include "Queue.h"


int main()
{
    Queue *q = NULL;
    q = new Queue;

    initQueue(q, 5);

    printList(q);

    enqueue(q, 5);
    enqueue(q, 4);
    enqueue(q, 3);
    enqueue(q, 2);
    enqueue(q, 1);

    printList(q);

    std:: cout << dequeue(q) << "\n";
    std:: cout << dequeue(q) << "\n";
    std:: cout << dequeue(q) << "\n\n";

    printList(q);
    

    freeList(q);

    return 0;
}
