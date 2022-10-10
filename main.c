//
//  main.c
//  WatchList
//
//  Created by emily m on 9/3/22.
//
#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"


int menu();
void createFile();
void saveFile();
void readFile();
void addNewAnime();
void searchList();
void editList();
int main()
{
    puts("***************************");
    puts(" Mini Anime Watch List Maker");
    puts("***************************");
    int option = 0;
    while ((option = menu()) != 8)
    {
        switch (option)
        {
        case 1:
            createFile();
            break;
        case 2:
            readFile();
            break;
        case 3:
            printList();
            break;
        case 4:
            addNewAnime();
            break;
        case 5:
            searchList();
            break;
        case 6:
            editList();
            break;
        case 7:
            saveFile();
            break;
        default:
            break;
        }
    }
    system("PAUSE");
    return 0;
}
int menu()
{
    int choice = 0;
    
    puts("");
    puts("\tMAIN MENU");
    puts("-------------------------------");
    puts("1- Create a new list.");
    puts("2- Upload a current watch list. (WIP)");
    puts("3- Display watch list.");
    puts("4- Add an anime.");
    puts("5- Search for an anime.");
    puts("6- Edit Watch List.");
    puts("7- Save Watch List.");
    puts("8- Exit.");
    printf("\n%s", "Choice> ");
    scanf("%d", &choice);

    return choice;
}
void createFile()
{
    FILE* pf = NULL;
    char userfile[255];
    char username[255]="";
    printf("%s","First Name: ");
    scanf("%s", username);
    sprintf(userfile, "%sWatchList.txt", username);
    pf = fopen(userfile, "w");
    fclose(pf);
    puts("\nWatch List has been created.");
}
void saveFile()
{
    //finding specific file
    char username[255] = "";
    char userfile[255];
    printf("%s", "First Name: ");
    scanf("%s", username);
    sprintf(userfile, "%sWatchList.txt", username);
    FILE* cfPtr = fopen(userfile, "w");
    if (cfPtr == NULL)
    {
        puts("File could not be opened");
    }
    else
    {
        ListNode* temp = HeadOfList();
        while (temp != NULL)
        {
            fprintf(cfPtr,"Anime: %s\n", temp->name);
            fprintf(cfPtr,(temp->completion) ? "Completion Status: FINISHED\n" : "Completion Status: UNFINISHED\n");
            fprintf(cfPtr,"Rating: %.2lf\n", temp->rating);
            fprintf(cfPtr,"Episode Count: %d\n", temp->episodeCount);
            fprintf(cfPtr,"Thoughts: %s\n\n", temp->thoughts);
            temp = temp->next;
        }
        fclose(cfPtr);
        puts("\nWatch List has been saved.");
    }
}
void readFile()
{
    char name[100] = "";
    char completion = ' ';
    //bool completionValue;
    double rating = 0.00;
    int episodeCount = 0;
    char personalThoughts[100] = "";

    //finding specific file
    char username[255] = "";
    char userfile[255];
    printf("%s", "First Name: ");
    scanf("%s", username);
    sprintf(userfile, "%sWatchList.txt", username);
    FILE* cfPtr = fopen(userfile, "r");
    if (cfPtr == NULL)
    {
        puts("File could not be opened or found.");
    }
    else
    {
        //how to upload info....
        puts("\nWatch List has been loaded.");
    }
}
void addNewAnime()
{
    char name[100] = "";
    char completion = ' ';
    bool completionValue;
    double rating = 0.00;
    int episodeCount = 0;
    char personalThoughts[100] = "";

    printf("%s", "Anime: ");
    scanf(" %[^\n]s", name);
    
    printf("%s", "Completed? (Y or N): ");
    scanf("%c", &completion);
    while (completion != 'Y' && completion != 'N')
        scanf("%c", &completion);
    if (completion == 'Y')
        completionValue = true;
    else
        completionValue = false;

    printf("%s", "Rating: ");
    scanf("%lf", &rating);

    printf("%s", "Episodes: ");
    scanf("%d", &episodeCount);

    printf("%s", "Any Thoughts?: ");
    scanf(" %[^\n]s", personalThoughts);

    addToList(name, completionValue, rating, episodeCount, personalThoughts);

    puts("\nAnime has been added to your watchlist.");
}
void searchList()
{
    char name[100] = "";
    printf("%s", "Anime Name?: ");
    scanf(" %[^\n]s", name);

    ListNode* targetNode = searchTitle(name);
    if (targetNode != NULL)
    {
        printf("\nAnime: %s\n", targetNode->name);
        printf((targetNode->completion) ? "Completion Status: FINISHED\n" : "Completion Status: UNFINISHED\n");
        printf("Rating: %.2lf\n", targetNode->rating);
        printf("Episode Count: %d\n", targetNode->episodeCount);
        printf("Thoughts: %s\n\n", targetNode->thoughts);
    }
    else
        printf("The anime %s was not found in your watch list.\n", name);
}
void editList()
{
    char newName[100] = "";
    char newCompletion = ' ';
    bool completionValue;
    double rating = 0;
    int episodes = 0;
    char personalThoughts[100] = "";

    char name[100] = "";
    printf("%s", "Anime Name? ");
    scanf(" %[^\n]s", name);
    ListNode* targetNode = searchTitle(name);
    if (targetNode != NULL)
    {
        puts("What would you like to edit?");
        puts("1) Anime Name\n2) Completion Status\n3) Rating\n4) Episode Count\n5)Thoughts");
        int choice = 0;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("%s","Change name to: ");
            scanf(" %[^\n]s", newName);
            strcpy(targetNode->name, newName);
            break;
        case 2:
            printf("%s", "Completed? (Y or N): ");
            scanf("%c", &newCompletion);
            while (newCompletion != 'Y' && newCompletion != 'N')
                scanf("%c", &newCompletion);
            if (newCompletion == 'Y')
                completionValue = true;
            else
                completionValue = false;
            targetNode->completion = completionValue;
            break;
        case 3:
            printf("%s", "Change rating to: ");
            scanf("%lf", &rating);
            targetNode->rating = rating;
            break;
        case 4:
            printf("%s", "Change episode count to: ");
            scanf("%d", &episodes);
            targetNode->episodeCount = episodes;
            break;
        case 5:
            printf("%s", "Change thoughts to: ");
            scanf(" %[^\n]s", personalThoughts);
            strcpy(targetNode->thoughts, personalThoughts);
            break;
        default:
            break;
        }

        puts("\nWatch List has been edited");
    }
    else
        printf("Anime with name: %s is not found in your watch list.\n", name);
}


