#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head;       //declare globle head pointer to always point head of linked list

//function for insert a node at last
void insertAtend(int data){                        
    struct node *newnode=(struct node*)malloc(sizeof(struct node));      //allocate dynamic memory in heap
    newnode->data=data;
    newnode->next=NULL;
    
    if(head==NULL){
        head=newnode;
    }
    else{
        struct node *temp;
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

//function for display linkedlist
void display(struct node *head){
   
    if(head==NULL){
       printf("first insert the data");
       return;
    }
    else
    {
       struct node *temp;
       temp=head;
        while(temp!=NULL)
        {
           printf("%d->",temp->data);
           temp=temp->next;
        }
        printf("NULL\n");
    }
    
}
// function for insert a node at the beginning
void insertAtbeg(int data){
    struct node* newnode=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
}
//insert node at particular index and index will start from 0
void insertAtmiddle(int data,int index){
    int count=0;
    struct node* newnode=NULL;
    newnode= (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    struct node *temp;
    temp=head;
    while(count!=(index-1)){
        temp=temp->next;
        count++;
    }
    newnode->next =temp->next;
    temp->next=newnode;
     
    

}
void deletelastnode(struct node *head){
    struct node *temp,*p;
    temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;

    }
    p=temp->next->next;
    temp->next=NULL;
    free(p);

}
// In delete first node we have to change head so we have to pass 
//address of head not copy so that what we do change can reflect in main
void deletefirstnode(struct node **head){
    // *head=(*head)->next;
    struct node *temp;
    temp=*head;
    *head=(*head)->next;
    free(temp);
}

void deleteatmiddile(int n){
    struct node *temp,*p;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->next->data==n){
           p=temp->next;
           temp->next=p->next;
           free(p);
           return; 
        }
        temp=temp->next;
    }
}
// In reverse function we have to change head so we have to pass 
//address of head not copy so that what we do change can reflect in main
void reverse(struct node **head){
   struct node *current,*prev=NULL,*next=NULL;
   current=*head;
   while(current!=NULL)
   {
       next=current->next;
       current->next=prev;
       prev=current;
       current=next;
   }
   *head=prev;
}

int main()
{
     int n;
    for(int i=1;i<10;i++)
    {
        n=i*10;
        insertAtend(n);
    }
    insertAtmiddle(35,3);
    insertAtmiddle(75,8);
    insertAtbeg(5);
    deletelastnode(head);
    printf("before deletion:- ");
    display(head);
    deletelastnode(head);
    printf("after deletion last node:- ");
    display(head);
    printf("after delete middile node:- ");
    deleteatmiddile(40);
    display(head);
    deletefirstnode(&head);
    printf("after deletion first node:- ");
    display(head);
    insertAtbeg(65);
    display(head);
    insertAtbeg(336);
    display(head);
    deletefirstnode(&head);
    display(head);
    insertAtbeg(67);
    display(head);
    reverse(&head);
    printf("after reverse:\n");
    display(head);
    return 0;
}
