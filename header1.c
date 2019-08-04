#include<stdlib.h>
struct Contact
{
    char name[20];
    char phone[12];
    char email[30];
};
struct Node{
    struct Contact c1;
    struct Node* next;
};
struct Node* CreateNode(){
    struct Node* second;
    second=(struct Node*)malloc(sizeof(struct Node));
    second->next=NULL;
    return second;
}
void DisplayDetails(struct Contact c1,int id){
    printf("\t[%d]  %s",id,c1.name);
    printf("\t     %s",c1.phone);
    printf("\t     %s",c1.email);
    printf("\n\t---------------------------\n");
}
struct Contact CreateContact(){
    struct Contact c1;
    printf("Enter details: \n");
    scanf("%s",&c1.name);
    scanf("%s",&c1.phone);
    scanf("%s",&c1.email);
    return c1;
}