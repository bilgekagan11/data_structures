#include <stdio.h>
#include <stdlib.h>
typedef struct queue{
     int size;
     unsigned  capacity;
    int rear;
    int front;
    int *array;
}*ARRAY_QUEUE;
 ARRAY_QUEUE create_queue(unsigned capacity){
     ARRAY_QUEUE  queue = (ARRAY_QUEUE)malloc(sizeof(struct queue));
     queue->array = (int *)malloc(capacity*sizeof(int));
     queue->front = -1;
     queue->rear = -1;
    queue->size = 0;
    queue->capacity = capacity;
     return  queue;
 }
 void enqueue(int value,ARRAY_QUEUE queue){
     if(queue->front == -1){
         queue->array[queue->rear + 1] = value;
         queue->size++;
         queue->rear++;
         queue->front++;
     }
     else{
         if (queue->capacity - 1 == queue->rear) {
             unsigned new_capacity = queue->capacity + 2;
             queue->array = (int *) realloc(queue->array, new_capacity * sizeof(int));
             queue->array[queue->rear + 1] = value;
             queue->rear++;
             queue->size++;
             queue->capacity = new_capacity;
         } else {
             queue->array[queue->rear + 1] = value;
             queue->size++;
             queue->rear++;
         }
     }
 }
 int  dequeue(ARRAY_QUEUE queue){
     if(queue->front == -1){
         printf("queue is not exist\n");
         return -1;
     }
     else{
         int data = queue->array[queue->front];
        if (queue->front == queue->rear){
            queue->front = -1;
            queue->rear = -1;
        }else{
            queue->front =(queue->front+1) % queue->capacity;
        }
        queue->size --;
         return data;
     }
 }
void print_array(ARRAY_QUEUE queue) {
    printf("Kuyruk Elemanlari: ");
    int i ;
    for (i= queue->front; i <= queue->rear; i++) {

        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

