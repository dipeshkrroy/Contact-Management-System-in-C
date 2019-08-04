#include<stdio.h>
#include "header1.c"
#include<stdlib.h>
struct Node* head;
int size=0;
void ReadContact();
void DisplayContact();
void AddContact();
void DeleteContact();
void UpdateContact();
void WirtetoFile(int id);
int main(){
    system("cls");
    ReadContact();
    int choice;
    do{
        printf("\n**************************Contact Management System***************************\n\n");
        printf("[1]Add Contact [2]View Contact [3]Update Contact [4]Delete Contact [0]EXIT CMD\n\n");
        printf("**************************Contact Management System***************************\n");
        printf("Your Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: system("cls");AddContact();         
            break;
        case 2: system("cls");DisplayContact();
            break;
        case 3: system("cls");UpdateContact();
            break;
        case 4: system("cls");DeleteContact();
            break;
        case 0: system("cls");
            break;
        default:system("cls");printf("--Enter Valid Command--\n");
            break;
        }
    }while(choice!=0);

}
void ReadContact(){
    FILE * fpointer;
    fpointer = fopen("list.txt","r");
    struct Node* first=(struct Node*)malloc(sizeof(struct Node));
    head=first;
    int j=0;
    do{
        if(!feof(fpointer)){
            
            fgets(first->c1.name,120,fpointer);
            fgets(first->c1.phone,120,fpointer);
            fgets(first->c1.email,120,fpointer);
            size++;
            first->next=CreateNode();first=first->next;
            
        }else
        {
            j=1;
        }        

    }while(j!=1);
    fclose(fpointer);
    printf("Size: %d\n",size);
}
void DisplayContact(){
    printf("\t*******Contacts List*******\n");
    printf("\tID   Details\n");
    printf("\t==========================\n");
    struct Node* temp=head;
    for(int i=0;i<size;i++){
        DisplayDetails(temp->c1,i);
        temp=temp->next;
    }
}
void AddContact(){
    struct Contact c1=CreateContact();
    FILE * fpointer;
    fpointer=fopen("list.txt","a");
    fprintf(fpointer,"\n%s\n%s\n%s",c1.name,c1.phone,c1.email);
    fclose(fpointer);
    size=0;
    ReadContact();
    system("cls");
}
void DeleteContact(){
    DisplayContact();
    int id;
    printf("Enter ID: ");
    scanf("%d",&id);
    struct Node* temp;
    temp=head;
    if(id==0){
        head=temp->next;       
    }else{
        for(int i=0;i<id-1;i++){
            temp=temp->next;
        }
        struct Node *next = temp->next->next;
        free(temp->next);
        temp->next = next;           
    }
    system("cls");
    size--;
    WirtetoFile(-1);    
}
void UpdateContact(){
    struct Node* temp;
    temp=head;
    DisplayContact();
    int id;
    printf("Enter ID: ");
    scanf("%d",&id);
    struct Contact c1;
    c1=CreateContact();
    for(int i=0;i<id;i++){
        temp=temp->next;
    }
    temp->c1=c1;
    WirtetoFile(id);
}
void WirtetoFile(int id){
    struct Node* temp;
    temp=head;
    
    FILE * fpointer;
    fpointer=fopen("list.txt","w");
    for(int i=0;i<size;i++){
        if(i==id){
            fprintf(fpointer,"%s\n%s\n%s\n",temp->c1.name,temp->c1.phone,temp->c1.email);
        }else{
            fprintf(fpointer,"%s%s%s",temp->c1.name,temp->c1.phone,temp->c1.email);
        }
        temp=temp->next;        
    }
    fclose(fpointer);
    size=0;
    ReadContact();
    system("cls");
}
