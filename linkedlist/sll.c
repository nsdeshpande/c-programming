#include<stdio.h>
#include<stdlib.h>
#include"sll.h"

Node* sll_insert_node(int index, int data, Node* head){

    Node *tempNode = (Node*)malloc(sizeof(Node));
    Node *resultNode = head;
    Node *tempSwapPtr = NULL;
   int itr = 0;
    if(index >= SLL_APPEND_NODE){
        if(tempNode == NULL){
            SLL_DEBUG_PRINTF("MEMORY ALLOCATION FAILURE");
        }
        else{
            tempNode->data = data;
            tempNode->nextNode = NULL;
            if(index == SLL_APPEND_NODE){
                if(head == NULL){
                    SLL_DEBUG_PRINTF("CREATING FIRST NODE OF SLL");
                    resultNode = tempNode;
                }else{
                     while(head->nextNode){
                         head = head->nextNode;
                     }
                     head->nextNode = tempNode;
                }
            }else if(index == SLL_HEAD_NODE){
                tempNode->nextNode = head;
                head = tempNode;
                resultNode = head;
            }
            else if(index > SLL_HEAD_NODE){
                for(itr = 1; (itr < index) && (head->nextNode != NULL);itr++){
                    head = head->nextNode;
                }
                if(head->nextNode == NULL){
                    head->nextNode = tempNode;
                    SLL_DEBUG_PRINTF("INSERTING NODE AT TAIL");
               }else{
                   tempSwapPtr = head->nextNode;
                   head->nextNode = tempNode;
                   tempNode->nextNode = tempSwapPtr;
               }
            }
        }
    }else{
                
    }
    return resultNode;
}

void  sll_print_sll(Node *head){

    while(head){
        printf("\nSLL_USER_OUTPUT:DATA(%d) PTR(0X%x) NEXT(0X%x)",head->data,head,head->nextNode);
        head= head->nextNode;
    }
}

int   sll_search_data(int data, Node *head){
    int resultIndex = -1;
    while(head){
        resultIndex++;
        if(head->data == data){
            break;
        }
        head = head->nextNode; 
    }
    if(head==NULL){
        resultIndex = -1;
    }

    return resultIndex;
}

Node* sll_delete_node(int index, Node * head){
    Node *resultPtr = head;
    Node *tempSwapPtr = NULL;
    int itr = 0;
    if(head != NULL){
        if(index == SLL_HEAD_NODE){
            resultPtr = head->nextNode;
            free(head);
        }
        else if(index > SLL_HEAD_NODE){
             for(itr = 1; (itr < index) && (head->nextNode != NULL); itr++){
                 head = head->nextNode;
             }
             if(head->nextNode == NULL){
                 SLL_DEBUG_PRINTF("\n SLL out of bound. Not deleating elements.!");
             }
             else{
                 tempSwapPtr = head->nextNode->nextNode;
                 free(head->nextNode);
                 head->nextNode = tempSwapPtr;
             }
        }
    }
    return resultPtr;
}

/*If the SLL has even number of nodes, the return would be the one at higher index*/
void  sll_find_middle_of_sll_1(Node *head){
    Node *fastPtr = head, *slowPtr = head;
    if(head != NULL){
        while((fastPtr!= NULL) && (fastPtr->nextNode != NULL)){
            slowPtr = slowPtr->nextNode;
            fastPtr = fastPtr->nextNode->nextNode;
        }
        printf("\nSLL_USER_OUTPUT:middle node ptr(0x%x) data(%d)",slowPtr,slowPtr->data);
    }
}

void  sll_find_n_node_from_end(Node *head, int n){
    Node *firstPtr = head;
    Node *secondPtr = head;
    if(head!= NULL && n>0){
        while(n>0){
            firstPtr = firstPtr->nextNode;
            n--;
        }
        while(firstPtr){
            secondPtr = secondPtr->nextNode;
            firstPtr = firstPtr->nextNode;
        }
        printf("\nThe Nth node from end is ptr(0x%x) data(%d)",secondPtr,secondPtr->data);
    }
}

void  sll_swap_two_nodes(Node *head, int x, int y){
    
    Node *temp = head, *x_previous = NULL, *y_previous = NULL, *x_next = NULL, *y_next = NULL;
    Node *x_node = NULL, *y_node = NULL;
    int is_x_found = 0, is_y_found = 0;
    if(head == NULL){
        SLL_DEBUG_PRINTF("HEAD IS NULL! RETURNING.");
        return;
    }else{
        while( (temp != NULL) && (temp->nextNode != NULL)){
            if(temp->nextNode->data == x){
                x_previous = temp;
                x_next = temp->nextNode->nextNode;
                is_x_found = 1;
            }
            else if(temp->nextNode->data == y){
                y_previous = temp;
                y_next = temp->nextNode->nextNode;
                is_y_found = 1;
            }
            temp = temp->nextNode;
            if(is_x_found && is_y_found){
                SLL_DEBUG_PRINTF("Both nodes found\n");
                printf("SLL_DEBUG:x_previous(0x%x) x_node(0x%x) x_next(0x%x)\n",
                                  x_previous,x_node,x_next);
                printf("SLL_DEBUG:y_previous(0x%x) y_node(0x%x) y_next(0x%x)\n",
                                  y_previous,y_node,y_next);
                break;
            }
        }
        if((is_x_found == 0) || (is_y_found == 0)){
            SLL_DEBUG_PRINTF("One of the nodes is not found! Returning.\n");
            printf("is_x_found(%d) is_y_found(%d)",is_x_found,is_y_found);
            return ;
        }else if (is_x_found && is_y_found){
            x_node = x_previous->nextNode;
            y_node = y_previous->nextNode;

            if(x_next == y_node){
                x_previous->nextNode = y_node;
                y_node->nextNode = x_node;
                x_node->nextNode = y_next;
            }
            else{
                x_previous->nextNode = y_node;
                y_node->nextNode = x_next;
                y_previous->nextNode = x_node;
                x_node->nextNode = y_next;
            }
        }
    }
}

void sll_merge_sorte_ll(void){
    Node *head1 = NULL, *head2 = NULL;
    Node *tail1 = NULL, *tail2 = NULL;
    Node *tempPtr = NULL;

    Node *destination = NULL, *source = NULL;
    Node *temp = NULL, *temp1 = NULL, *temp2 = NULL, *temp3 = NULL, *Srctemp = NULL;
    int itr = 0,itr1 = 0;
    for(itr = 0; itr<10;itr++){
        tempPtr = (Node *)malloc(sizeof(Node));
        if(tempPtr){
            tempPtr->nextNode = NULL;
            tempPtr->data     = itr;
            if(itr == 0){
                head1 = tempPtr;
                tail1 = head1;
                SLL_DEBUG_PRINTF("SLL_MERGE:HEAD1 CREATED\n");
            }else if(itr == 1){
                head2 = tempPtr;
                tail2 = head2;
                SLL_DEBUG_PRINTF("SLL_MERGE:HEAD2 CREATED\n");
            }else{
                if(itr%2 == 0){
                    if(tail1->nextNode == NULL){
                        tail1->nextNode = tempPtr;
                        tail1 = tail1->nextNode;
                    }
                }else{
                    if(tail2->nextNode == NULL){
                        tail2->nextNode = tempPtr;
                        tail2 = tail2->nextNode;
                    }
                }
                    
            }
        }
            
    }
    tail1 = head1;
    tail2 = head2;
    itr = 0;
    
    while(tail1!= NULL){
        printf("SLL_OUT: L1(%d) = %d\n",itr,tail1->data);
        tail1 = tail1->nextNode;
        itr++;
    }

    itr = 0;
    
    while(tail2!= NULL){
        printf("SLL_OUT: L2(%d) = %d\n",itr,tail2->data);
        tail2 = tail2->nextNode;
        itr++;
    }

    /*Star the merge procedure here*/   
    if(head1->data <= head2->data){
        destination = head1;
        source      = head2;
    }else{
        destination = head2;
        source      = head1;
    }
    
    /*Iterate till the src and destination are still same length*/
    while((destination->nextNode != NULL) && (source->nextNode != NULL)){
        if( (destination->nextNode != NULL) && (destination->nextNode->data < source->data)){
            destination = destination->nextNode;
        }
        else{
            temp = destination;
            temp1 = destination->nextNode;
            Srctemp = source->nextNode;

            temp->nextNode = source;
            source->nextNode = temp1;
            
            source = Srctemp;
            destination = destination->nextNode;
        }
    }
    if((destination->nextNode == NULL) && (source->nextNode == NULL) ){
        SLL_DEBUG_PRINTF("BOTH LIST REACHED END\n");
    }else if(destination->nextNode == NULL){
        destination->nextNode = source;
    }else if (source->nextNode == NULL){
        source->nextNode = destination;
    }

    while(head1 != NULL){
        printf("\nL1(%d) address(0x%x)",head1->data,head1);
        head1 = head1->nextNode;
    }

    while(head2 != NULL){
        printf("\nL2(%d) address(0x%x)",head2->data,head2);
        head2 = head2->nextNode;
    }
}
Node* sll_delete_sll(Node *head){
    Node *nodetoDelete = head;
    while(head!= NULL){
        nodetoDelete = head;
        head = head->nextNode;
        free(nodetoDelete);
    }
    return head;
}
