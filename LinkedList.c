//
//  LinkedList.c
//  WatchList
//
//  Created by emily m on 10/10/22.
//

#include"LinkedList.h"

ListNode* head = NULL;
ListNode* tail = NULL;
count = 0;

bool isListEmpty()
{
    return (head == NULL);
}
int listSize()
{
    return count;
}
ListNode* HeadOfList()
{
    return head;
}
void addToList(char* name, bool complete, double rating, int episodes, char* thoughts)
{
    ListNode* newNode = malloc(sizeof(ListNode));
    if (newNode == NULL)
    {
        printf("Anime not added. No memory available");
        return;
    }
    //adding anime info in node
    strcpy(newNode->name, name);
    newNode->completion = complete;
    newNode->rating = rating;
    newNode->episodeCount = episodes;
    strcpy(newNode->thoughts, thoughts);
    newNode->next = NULL;
    //where to add to list
    if (isListEmpty())
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    count++;

}
void printList()
{
    if (isListEmpty())
    {
        puts("Watch List is empty");
        return;
    }
    ListNode* temp = head;
    int i = 0;
    while (temp != NULL)
    {
        //begin to list off info
        puts("--------------------------------");
        printf("Anime: %s\n", temp->name);
        printf((temp->completion) ? "Completion Status: FINISHED\n" : "Completion Status: UNFINISHED\n");
        printf("Rating: %.2lf\n", temp->rating);
        printf("Episode Count: %d\n", temp->episodeCount);
        printf("Thoughts: %s\n\n", temp->thoughts);
        
        temp = temp->next;
        i++;
    }
}
ListNode* searchTitle(char* name)
{
    ListNode* temp = head;

    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
