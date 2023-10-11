int checkpalindrome(char *word,LINKED_STACK stack){
    char * temp = word;
    char stackchar ;
    int ispalindrome = 1;
    while (*temp != '\0') {
        linked_stack_push(stack, temp);
        temp++;
    }
    linked_stack_printchar(stack);
    temp = word;
    if ( stack->head == NULL){
        printf("stack is empty");
    }else {
        while(*temp != '\0'){
            stackchar = *(char *)linked_stack_pop(stack);
            if (*(temp++) != stackchar){
                ispalindrome = 0;
                break;
            }
        }
    }
    if (ispalindrome){
        return 1;
    }else{
        return 0;
    }
