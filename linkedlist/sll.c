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
