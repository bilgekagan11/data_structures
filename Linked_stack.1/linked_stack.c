//DESCRIPTION : 
/*it's for  creating a stack structures that consider pushing , popping 
 , printing ( char and int ) , initialize 
 , checking top  and checking sturcture is empty or not 
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct LINKED_STACK_NODE_s *LINKED_STACK_NODE;
 typedef struct LINKED_STACK_NODE_s{
     LINKED_STACK_NODE next;
     void *data;
     } LINKED_STACK_NODE_t[1];

 typedef struct LINKED_STACK_s{
     LINKED_STACK_NODE head;
     } LINKED_STACK_t[1], *LINKED_STACK;

 LINKED_STACK linked_stack_init();
 void linked_stack_push(LINKED_STACK stack, void *data);
 void *linked_stack_pop(LINKED_STACK stack);
 void linked_stack_printint(LINKED_STACK stack);
 void linked_stack_printchar(LINKED_STACK stack);
void linked_stack_free(LINKED_STACK stack);
void *linked_stack_top(LINKED_STACK stack);
int linked_stack_is_emtpy(LINKED_STACK stack);
LINKED_STACK linked_stack_init(){
    LINKED_STACK  stack = (LINKED_STACK )malloc(sizeof (LINKED_STACK_t));
    stack->head = NULL;
    return stack;
 }
void linked_stack_push(LINKED_STACK stack, void *data){
    LINKED_STACK_NODE  node  = (LINKED_STACK_NODE )malloc(sizeof (LINKED_STACK_NODE_t));
    node->data = data;
     if ( stack->head == NULL){
         printf("stack is empty \n");
         printf("first stack pushed\n");
         node->next = NULL;
         stack->head = node;
     }else{
         node->next = stack->head;
         stack->head = node;
         printf("stack is pushed \n");
     }
 }
void *linked_stack_pop(LINKED_STACK stack){
     if (stack->head == NULL){
         printf("stack is empty\n");
        return 0;
     }else{
         LINKED_STACK_NODE  temp = stack->head;
         void * data = temp->data;
         stack->head = temp->next;
         free(temp);
         return data;
     }
 }
void linked_stack_printint(LINKED_STACK stack){
    if (stack->head  == NULL){
        printf("stack is empty\n");
    }
     else{
        printf("\nprinting ... \n\n");
        LINKED_STACK_NODE temp = stack->head;
        int datax;
        while (temp != NULL) {
            datax = *(int *) temp->data;
            printf("\n%d", datax);
            temp = temp->next;
        }
     }
 }
void linked_stack_printchar(LINKED_STACK stack){
    if (stack->head  == NULL){
        printf("stack is empty\n");
    }
    else{
        printf("\nprinting ... \n\n");
        LINKED_STACK_NODE temp = stack->head;
        char datax ;
        while (temp != NULL) {
            datax = *(char *) temp->data;
            printf("\n%c", datax);
            temp = temp->next;
        }
    }
}
void *linked_stack_top(LINKED_STACK stack){
    if (stack->head == NULL){
        printf("stack is empty\n");
        return NULL;
    }
     else{
        LINKED_STACK_NODE node = stack->head;
        void *data = node->data;
        return data;
    }

 }
void linked_stack_free(LINKED_STACK stack){
    while (stack->head != NULL){
        linked_stack_pop(stack);
    }
    free(stack);
}
int linked_stack_is_emtpy(LINKED_STACK stack){
     if (stack->head){
         return 1;
     }else return  0;
 }
