#include <stdio.h>
#include <stdlib.h>
 typedef struct LINKED_QUEUE_NODE_s *LINKED_QUEUE_NODE;
 typedef struct LINKED_QUEUE_NODE_s{
LINKED_QUEUE_NODE next;
 void *data;
} LINKED_QUEUE_NODE_t[1];

 typedef struct LINKED_QUEUE_s *LINKED_QUEUE;
typedef struct LINKED_QUEUE_s{
LINKED_QUEUE_NODE head;
 LINKED_QUEUE_NODE tail;
 } LINKED_QUEUE_t[1];

 LINKED_QUEUE linked_queue_init();
 void linked_queue_printint(LINKED_QUEUE queue);
 void linked_queue_free(LINKED_QUEUE queue);
 int linked_queue_is_empty(LINKED_QUEUE queue);
 int linked_queue_size(LINKED_QUEUE queue);
void linked_queue_enqueue(LINKED_QUEUE queue, void *data);
void *linked_queue_dequeue(LINKED_QUEUE queue);
LINKED_QUEUE linked_queue_init(){
    LINKED_QUEUE  queue = (LINKED_QUEUE )malloc(sizeof (LINKED_QUEUE_t));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}
int linked_queue_is_empty(LINKED_QUEUE queue){
    if (queue->head == NULL){
        return 1;
    }else return  0;
}
int linked_queue_size(LINKED_QUEUE queue){
    if (linked_queue_is_empty(queue)== 1){
        printf("\n queue is empty");
        return 0;
    }
    else{
    LINKED_QUEUE_NODE  temp = queue->head;
    int counter = 0;
    while (temp != NULL ){
        counter ++;
        temp = temp->next;
    }counter ++;
    return counter;
}
}
void linked_queue_enqueue(LINKED_QUEUE queue, void *data){
    LINKED_QUEUE_NODE  node = (LINKED_QUEUE_NODE)malloc(sizeof (LINKED_QUEUE_NODE_t));
    node->data = data;
    if (linked_queue_is_empty(queue)== 1){
        printf("\n queue is empty");
        queue->head = node;
        queue->tail = node;
        node->next = NULL;
        printf("\nfirst node enqueued ");
    }else{
        LINKED_QUEUE_NODE temp = queue->tail;
        temp->next = node;
        node->next = NULL;
        queue->tail = node;
        printf("\nnode enqueued ");
    }
}
void *linked_queue_dequeue(LINKED_QUEUE queue){
    if (linked_queue_is_empty(queue)== 1){
        printf("\n queue is empty");
        return NULL;
    }else{
   void * data = queue->head->data;
   LINKED_QUEUE_NODE  temp = queue->head;
   queue->head = temp->next;
        free(temp);
        printf("\n node dequeued");
        return data;
    }
}
void linked_queue_free(LINKED_QUEUE queue) {
    if (queue == NULL) {
        return;
    }

    LINKED_QUEUE_NODE temp = queue->head;
    LINKED_QUEUE_NODE temp2 = NULL;
    while (temp != NULL) {
        temp2 = temp;
        temp = temp->next;
        free(temp2);
        printf("\nNode is freed.");
    }

    free(queue);
}void linked_queue_printint(LINKED_QUEUE queue){
    if (queue == NULL) {
        return;
    }
    int datax ;
    printf("\n\n");
    LINKED_QUEUE_NODE temp = queue->head;
    while (temp != NULL) {
        datax = *(int *) (temp->data);
        temp = temp->next;
        printf("\n%d",datax);
    }
}