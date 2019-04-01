#include<stdio.h>
#include<stdlib.h>
typedef struct RNode {
    int value;
      struct RNode *random;
        struct RNode *next;

} RNode;
RNode *Copy(RNode *head)
{
  if(head == NULL)
  {
    return NULL;
  }
  RNode * oldNode = head;
  RNode * task = NULL;
  while(oldNode != NULL)
  {
    RNode * newNode = (RNode*)malloc(sizeof(RNode));
    newNode->value = oldNode->value;
    task = oldNode->next;
    oldNode->next = newNode;
    newNode->next = task;
    oldNode = task;
  }
  oldNode = head;
  while(oldNode != NULL)
  { 
    RNode * newNode = oldNode->next;
    if(oldNode->random == NULL)
    {
      oldNode->next->random = NULL;  
    }
    else{
    RNode * oppo = oldNode->random;
    oldNode->next = oppo->next;
  
    oldNode = newNode->next;
   }
  }
    oldNode = head;
    RNode * newHead = head->next;
    while(oldNode != NULL)
    {
      RNode * newNode = oldNode->next;
      oldNode->next = newNode->next;
      if(newNode->next != NULL)
      {
      newNode->next = newNode->next->next;
      }
      oldNode = oldNode->next;
    }
 return newHead; 
 }

