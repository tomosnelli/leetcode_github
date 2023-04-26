/*
    622. Design Circular Queue

    Design your implementation of the circular queue.
    The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle,
    and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

    One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

    Implement the MyCircularQueue class:

        MyCircularQueue(k) Initializes the object with the size of the queue to be k.
        int Front() Gets the front item from the queue. If the queue is empty, return -1.
        int Rear() Gets the last item from the queue. If the queue is empty, return -1.
        boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
        boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
        boolean isEmpty() Checks whether the circular queue is empty or not.
        boolean isFull() Checks whether the circular queue is full or not.

    You must solve the problem without using the built-in queue data structure in your programming language. 

    

    Example 1:

        Input
        ["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
        [[3], [1], [2], [3], [4], [], [], [], [4], []]
        Output
        [null, true, true, true, false, 3, true, true, true, 4]

        Explanation
        MyCircularQueue myCircularQueue = new MyCircularQueue(3);
        myCircularQueue.enQueue(1); // return True
        myCircularQueue.enQueue(2); // return True
        myCircularQueue.enQueue(3); // return True
        myCircularQueue.enQueue(4); // return False
        myCircularQueue.Rear();     // return 3
        myCircularQueue.isFull();   // return True
        myCircularQueue.deQueue();  // return True
        myCircularQueue.enQueue(4); // return True
        myCircularQueue.Rear();     // return 4

    

    Constraints:

        1 <= k <= 1000
        0 <= value <= 1000
        At most 3000 calls will be made to enQueue, deQueue, Front, Rear, isEmpty, and isFull.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int front;
    int rear;
    int count;
    int length;
    int* queue;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(k)
int k;
{
    MyCircularQueue* obj = (MyCircularQueue*) malloc(sizeof(MyCircularQueue));
    obj->front = 0;
    obj->rear = 0;
    obj->count = 0;
    obj->length = k;
    obj->queue = (int*) malloc(sizeof(int) * k);

    return obj;
}

bool myCircularQueueEnQueue(obj, value)
MyCircularQueue* obj;
int value;
{
    if(obj->count == obj->length) return false;

    obj->queue[obj->rear] = value;

    ++(obj->rear);
    obj->rear %= obj->length;

    ++(obj->count);

    return true;
}

bool myCircularQueueDeQueue(obj)
MyCircularQueue* obj;
{
    if(obj->count == 0) return false;

    int front = obj->front;

    obj->queue[obj->front] = -1;

    ++(obj->front);
    obj->front %= obj->length;

    --(obj->count);

    return true;
}

bool myCircularQueueIsEmpty(obj)
MyCircularQueue* obj;
{
    if(!(obj->count)) return true;
    return false;
}

bool myCircularQueueIsFull(obj)
MyCircularQueue* obj;
{
    if(obj->count == obj->length) return true;
    return false;
}

int myCircularQueueFront(obj)
MyCircularQueue* obj;
{
    if(myCircularQueueIsEmpty(obj)) return -1;
    return obj->queue[obj->front];
}

int myCircularQueueRear(obj)
MyCircularQueue* obj;
{
    if(myCircularQueueIsEmpty(obj)) return -1;
    int rear = obj->rear;
    return obj->queue[(rear - 1 < 0) ? (obj->length - 1) : rear];
}

void myCircularQueueFree(obj)
MyCircularQueue* obj;
{
    free(obj->queue);
    free(obj);
}

void testMyCircularQueueEnQueue()
{
    MyCircularQueue* obj = myCircularQueueCreate(5);

    for(int i = 0; i < obj->length; ++i){
        if(!myCircularQueueEnQueue(obj,i)){
            printf("tesMyCircularQueueEnQueue: Error: Enqueue failed within the defined length\n");
            exit(1);
        }
    }

    if(myCircularQueueEnQueue(obj, 10)){
        printf("tesMyCircularQueueEnQueue: Error: Enqueue failed beyond the defined length\n");
        exit(1);
    }

    myCircularQueueFree(obj);

    printf("tesMyCircularQueueEnQueue: PASS\n");
}

void testMyCircularQueueDeQueue()
{
    MyCircularQueue* obj = myCircularQueueCreate(5);

    /* Dequeue Empty queue */
    if(myCircularQueueDeQueue(obj)){
        printf("testMyCircularQueueDeQueue: Error: failed handling empty queue\n");
        exit(1);
    }

    /* Dequeue a full queue */
    for(int i = 0; myCircularQueueEnQueue(obj, i); ++i){}
    for(int i = 0; i < obj->length; ++i){
        if(!myCircularQueueDeQueue(obj)){
            printf("testMyCircularQueueDeQueue: Error: failed to dequeue a full queue\n");
            exit(1);
        }
    }

    myCircularQueueFree(obj);

    printf("testMyCircularQueueDeQueue: PASS\n");
}

void testMyCircularQueueFront()
{
    MyCircularQueue* obj = myCircularQueueCreate(5);

    /* get front of empty queue */
    {
        int actual = myCircularQueueFront(obj);
        int expected = -1;
        
        if(actual != expected){
            printf("testMyCircularQueueFront: Error: failed to return correct value for empty queue\n");
            exit(1);
        }
    }

    /* get front of full queue */
    {
        for(int i = 0; myCircularQueueEnQueue(obj, i); ++i){}

        int actual = myCircularQueueFront(obj);
        int expected = 0;

        if(actual != expected){
            printf("testMyCircularQueueFront: Error: failed to get front of full queue\n");
            exit(1);
        }
    }
    
    printf("testMyCircularQueueFront: PASS\n");
}

void testMyCircularQueueRear()
{
    MyCircularQueue* obj = myCircularQueueCreate(5);

    /* get rear from empty queue */
    {
        int actual = myCircularQueueRear(obj);
        int expected = -1;
        
        if(actual != expected){
            printf("testMyCircularQueueRear: Error: failed to correctly handle empty queue\n");
            exit(1);
        }
    }

    /* get rear from full queue */
    {
        for(int i = 0; myCircularQueueEnQueue(obj, i); ++i){}

        int actual = myCircularQueueRear(obj);
        int expected = 4;

        if(actual != expected){
            printf("testMyCircularQueueRear: Error: failed to correctly get rear of full queue\n");
            exit(1);
        }
    }

    printf("testMyCircularQueueRear: PASS\n");
}

int main()
{
    testMyCircularQueueEnQueue();
    testMyCircularQueueDeQueue();
    testMyCircularQueueFront();
    testMyCircularQueueRear();
    return 0;
}