#include <stdio.h>
#include <stdlib.h>
typedef struct LINKED_LIST_NODE_s *LINKED_LIST_NODE;
 typedef struct LINKED_LIST_NODE_s{
 LINKED_LIST_NODE next; /*Do not change the order.*/
 void *data;
 } LINKED_LIST_NODE_t[1];

 typedef struct LINKED_LIST_s *LINKED_LIST;
 typedef struct LINKED_LIST_s{
     LINKED_LIST_NODE head; /*May overlap with next.*/
     } LINKED_LIST_t[1];

 LINKED_LIST linked_list_init();
 int linked_list_size(LINKED_LIST list);
 void linked_list_prepend(LINKED_LIST list, void *data);
 void linked_list_append(LINKED_LIST list, void *data);
 void linked_list_insert(LINKED_LIST list, void *data, int idx);
 void linked_list_set(LINKED_LIST list, void *data, int idx);
 void *linked_list_get(LINKED_LIST list, int idx);
 void *linked_list_remove(LINKED_LIST list, int idx);
 void linked_list_removeall(LINKED_LIST list);
LINKED_LIST linked_list_init(){
    LINKED_LIST  list = (LINKED_LIST) malloc(sizeof(LINKED_LIST_t));
    list->head = NULL;
    return list;
}
void linked_list_append(LINKED_LIST list, void *data){
    LINKED_LIST_NODE  node  = (LINKED_LIST_NODE)malloc(sizeof (LINKED_LIST_NODE_t));
    node->data = data;
    if (list->head == NULL){
        printf("list is empty \n");
        list->head = node;
        node->next = NULL;
        printf("first node appended\n");
    }else{
        node->next = list->head;
        list->head = node;
        printf("node is appended\n");
    }
}
void linked_list_prepend(LINKED_LIST list, void *data){
    LINKED_LIST_NODE  node  = (LINKED_LIST_NODE)malloc(sizeof (LINKED_LIST_NODE_t));
    node->data = data;
    node->next = NULL;
    if (list->head == NULL){
        printf("list is empty \n");
        list->head = node;
        printf("first node prepended\n");
    }else{
        LINKED_LIST_NODE temp = list->head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = node;
        printf("node is prepended\n");
    }
}
int linked_list_size(LINKED_LIST list){
    if (list->head == NULL) {
        printf("list is empty \n");
        return 0;

    } else {
        LINKED_LIST_NODE temp = list->head;
        int counter = 0;
        while (temp != NULL) {
            counter++;
            temp = temp->next;
        }
        return counter;
    }
}
void linked_list_insert(LINKED_LIST list, void *data, int idx){
    LINKED_LIST_NODE  node = (LINKED_LIST_NODE) malloc(sizeof (LINKED_LIST_NODE_t));
        node->data = data;
    if (linked_list_size(list) >= idx){
         LINKED_LIST_NODE temp = list->head;
        int counter = 0;
        while (counter != idx-1) {
            counter++;
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;
    }else if (idx > linked_list_size(list)){
        int counter =0;
        while (counter != idx-linked_list_size(list)){
            counter ++;
            linked_list_prepend(list,NULL);
        }
        linked_list_prepend(list,node->data);
    }
}
void linked_list_set(LINKED_LIST list, void *data, int idx){
    if (list->head == NULL){
        printf("list empty \n");
    }
    else{
        if (idx <= linked_list_size(list)) {
            LINKED_LIST_NODE temp = list->head;
            int counter = 0;
            while (counter != idx) {
                counter++;
                temp = temp->next;
            }
            temp->data = data;
        }
        else {
            printf("there is not a node here  . please write valid index\n");
        }
    }
}
void *linked_list_get(LINKED_LIST list, int idx){
    if (list->head == NULL){
        printf("list empty \n");
        return NULL;
    }
    else{
        if (idx <= linked_list_size(list)) {
            LINKED_LIST_NODE temp = list->head;
            int counter = 0;
            while (counter != idx) {
                counter++;
                temp = temp->next;
            }
            void * datax = temp->data;
            return datax;
        }
        else {
            printf("there is not a node here  . please write valid index\n");
            return NULL;
        }
    }
}
void *linked_list_remove(LINKED_LIST list, int idx) {
    if (linked_list_size(list) >= idx) {
        LINKED_LIST_NODE temp = list->head;
        LINKED_LIST_NODE temp2 = NULL;
        void *datax = NULL;
        int counter = 0;
        while (counter != idx - 1) {
            counter++;
            temp2 = temp;
            temp = temp->next;
        }
        datax = temp->data;
        temp2->next = temp->next;
        free(temp);
        return datax;
    } else  {
        printf("you can not  remove . node is not exist\n");
        list->head = NULL;
        return  NULL;
    }
}
void linked_list_removeall(LINKED_LIST list){
    if (list->head == NULL){
        printf("list is empty \n");
    }else{
        {
            LINKED_LIST_NODE temp = list->head;
            int counter = 0;
            LINKED_LIST_NODE temp2 = NULL;
            while (counter != linked_list_size(list)) {
                counter++;
                temp2 = temp;
                temp = temp->next;
                free(temp2);
            }
            list->head = NULL;
        }
    }
}
