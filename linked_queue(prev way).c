// i just write enqueue and dequeue func on this c file
#include <stdlib.h>
#include <stdio.h>
#define TRUE  1
#define FALSE	0
typedef struct {
    int info;
} DATA;

typedef struct Node_t {
    DATA data;
    struct Node_t *prev;
} NODE;

typedef struct Queue {
    NODE *head;
    NODE *tail;
    int size;
    int limit;
} Queue;

Queue *ConstructQueue(int limit);
int Enqueue(Queue *pQueue, NODE *item);
NODE *Dequeue(Queue *pQueue);

int Enqueue(Queue *pQueue, NODE *item) {
   /*Fill in this function*/ 
   if (pQueue->size == pQueue->limit){
   	return FALSE;
   }else {
   if (pQueue->size == 0){
   	printf("queue is empty \n");
   	pQueue->head = item;
   	pQueue->tail = item;
   	item->prev = NULL;
   }else{
		pQueue->tail->prev = item;
		pQueue->tail = item;
		item->prev = NULL;
	   }
   pQueue->size ++; 
   	return TRUE;
   }

}

NODE * Dequeue(Queue *pQueue) {
    /*Fill in this function*/ 
	if (pQueue->size== 0){
		printf("queue is empty \n");
		return NULL;
	}else{ 
		NODE * temp = pQueue->head;
		pQueue->head = pQueue->head->prev;
		pQueue->size --;
		return temp;
		}
}
