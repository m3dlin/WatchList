//
//  LinkedList.h
//  WatchList
//
//  Created by emily m on 9/3/22.
//
#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct listNode
{
    char name[100];
    bool completion;
    double rating;
    int episodeCount;
    char thoughts[100];

    struct listNode* next;
} ListNode;

int count;

bool isListEmpty();
int listSize();
ListNode* HeadOfList();
void addToList(char* name, bool complete, double rating, int episodes, char* thoughts);
void printList();
void deleteListNodeAt(int position);
ListNode* searchTitle(char* name);


#endif // !LINKED_LIST_H

