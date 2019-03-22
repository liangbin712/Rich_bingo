#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
typedef int SlistDatetype;
typedef struct Node{
  SlistDatetype value;
  Node *next;
}Node;
typedef struct Slist{
  Node * first;
}Slist;
void SlistInit (Slist * slist)
{
  slist->first = NULL; 
}
void SlistPushfront(Slist * slist, SlistDatetype v)
{
   Node * node = (Node *)malloc(sizeof(Node));
   node->value = v;
   node->next = slist->first;
   slist->first = node;
}
void SListPushFrontVersion2(Node **ppfirst ,SlistDatetype v)
{
  Node * node = (Node *)malloc(sizeof(Node));
  node->value = v;
  node->next = *ppfirst;
  *ppfirst = node; 
}
void SlistPushback(Slist * slist,SlistDatetype v)
{
  Node * node = (Node *)malloc(sizeof(Node));
  node->value = v;
  node->next = NULL;
  if(slist->first == NULL)
  {
     slist->first = node;
  }
  else{
     Node * c = slist->first; 
     while(c->next != NULL)
     {
         c = c->next;
     }
     c->next = node;
  } 
}
void SlistPopBack(Slist *slist)
{
  assert(slist->first != NULL);
  if(slist->first->next == NULL)
  {
    free(slist->first);
    slist->first = NULL;
  }
  else
  {
    Node * del = slist->first->next;
    while(slist->first != NULL)
    {
      free(slist->first);
      slist->first = del;
    }
  } 
}
Node * SListFind(Slist * slist,SlistDatetype v)
{
   assert(slist != NULL);
   Node * find = slist->first->next;
   while(slist->first != NULL)
   {
     if(slist->first->value == v)
     {
       return find;
     }
     slist->first = find;
   }
   return 0;
}
void SListInsertAfter(Slist * slist,Node *pos, SlistDatetype v)
{
  assert(slist->first != NULL);
  Node * node = (Node *)malloc(sizeof(Node));
  node->value = v;
  node->next = pos->next;
  pos->next = node;
}
void SlistEraseAfter (Slist * slist,Node *pos)
{
  assert(slist->first != NULL); 
  Node * c = pos->next->next; 
  free(pos->next);
  pos->next = c;
}
void SListRemove(Slist *slist, SlistDatetype v)
{
  if(slist->first == NULL)
  {
    return;
  }
  if(slist->first->value == v)
  {
    free(slist->first);
    slist->first = NULL;
  }
  Node * c = slist->first;
  while(c->next != NULL)
  {
    if(c->next->value == v)
    {
      Node * next = c->next;
      c = c->next->next;
      free(next);
      return;
    }
    else{
      c = c->next;
    }
  } 
}
void SListRemoveAll(Slist *slist, SlistDatetype v)
{
  if(slist->first == NULL)
  {
    return;
  }
  Node * c = slist->first;
  while(c->next != NULL)
  {
    if(c->next->value == v)
    {
      Node *next = c->next;
      c = c->next->next;
      free(next);
    }
    else{
      c = c->next;
    }
  }
  if(slist->first->value == v)
  {
    Node * first =  slist->first->next;
    free(slist->first);
    slist->first = first;
  }
}
