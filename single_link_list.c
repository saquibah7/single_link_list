#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head;
void begin_insert();
void last_insert();
void random_insert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();
void exit();
//----------------------------
void main(){
    int choice=0;
    while(choice!=9){
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\t\t\t\tMain Menu\n");
            printf("\t\t\tChoose One Option From The List:\n");
            printf("\n\t\t\t1.Insert At The Beginning\n\t\t\t2.Insert At The Last\n\t\t\t3.Random Insertion\n\t\t\t4.Delete At The Beginning\n\t\t\t5.Delete At The Last\n\t\t\t6.Random Delete\n\t\t\t7.Display Elements\n\t\t\t8.Search the Node\n\t\t\t9.Exit\n");
            printf("\t\t\tEnter Your Choice :");
            scanf("\n%d",&choice);
            switch(choice){
                case 1:begin_insert(); break;
                case 2:last_insert(); break;
                case 3:random_insert(); break;
                case 4:begin_delete(); break;
                case 5:last_delete(); break;
                case 6:random_delete(); break;
                case 7:display(); break;
                case 8:search(); break;
                case 9:exit(0); break;
                default: printf("\t\t\tPlease Enter Valid Choice......");
            }
    }
}
//---------------------Inserting A Node---------------------
void begin_insert(){
    struct node *ptr;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node*));
    if(ptr==NULL){
        printf("\n\t\t\tOVERFLOW\n");
    }else{
        printf("\n\t\t\tEnter Value :");
        scanf("%d",&item);
        ptr->data=item;
        ptr->next=head;
        head=ptr;
        printf("\n\t\t\tNode Inserted..!");
    }
}
//---------------------Inserting a Node At last-----------------------------------
void last_insert(){
    struct node *ptr,*temp;
    int item;
    ptr=(struct node*)malloc(sizeof(struct node*));
    if(ptr==NULL){
            printf("\n\t\t\tOVERFLOW\n");
    }else{
        printf("\t\t\tEnter The Value :");
        scanf("%d",&item);
        ptr->data=item;
        if(head==NULL){
            ptr->next=NULL;
            head=ptr;
            printf("\n\t\t\tNode Inserted..!\n");
        }else{
            temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->next=NULL;
            printf("\n\t\t\tNode Inserted..!\n");
        }
    }
}
//------------Inserting a Node at any Position--------------
void random_insert(){
    int i,loc,item;
    struct node *ptr,*temp;
    ptr =(struct node *)malloc(sizeof(struct node *));
    if(ptr==NULL){
        printf("\n\t\t\tOVERFLOW\n");
    }else{
        printf("\t\t\tEnter The Value :");
        scanf("%d",&item);
        ptr->data=item;
        printf("\t\t\tEnter The Location After Which You Want To Insert... :");
        scanf("\n%d",&loc);
        temp=head;
        for(i=0;i<loc;i++){
            temp=temp->next;
            if(temp==NULL){
                printf("\t\t\tCan't Insert..!!\n");
                return;
            }
        }
        ptr->next=temp->next;
        temp->next=ptr;
        printf("\n\t\t\tNode Inserted.\n");
    }
}
//---------------Deleting a Node at the beginning----------------
void begin_delete(){
    struct node *ptr;
    if(head==NULL){
        printf("\n\t\t\tList Is Empty.\n");
    }else{
        ptr=head;
        head=ptr->next;
        free(ptr);
        printf("\t\t\tNode Deleted !.");
    }
}
//--------------Deleting a Node at Last Of LL------------
void last_delete(){
    struct node *ptr,*ptr1;
    if(head==NULL){
        printf("\t\t\tList Is Empty!.");
    }else if(head->next=NULL){
        head=NULL;
        free(head);
        printf("\t\t\tOnly Node Of List Deleted!.");
    }else{
        ptr=head;
        while(ptr->next!=NULL){
            ptr1=ptr;
            ptr=ptr->next;
        }
        ptr1->next=NULL;
        printf("\n\t\t\tDeleted Node From The List!.");
    }
}
//------------------Deleting A Node Randomly-------------
void random_delete(){
    struct node *ptr,*ptr1;
    int loc,i;
    printf("\n\t\t\tEnter the location of node after you want to perform deletion!");
    scanf("%d",&loc);
    ptr=head;
    for(i=0;i<loc;i++){
        ptr1=ptr;
        ptr1=ptr->next;
        if(ptr==NULL){
            printf("\t\t\tCan't Delete!.\n");
            return;
        }
    }
    ptr1->next=ptr->next;
    free(ptr);
    printf("\n\t\t\t%d Node Deleted!.\n",loc+1);
}
//--------------------Display Elements From LL---------------
void display(){
    struct node *ptr;
    ptr=head;
    if(ptr==NULL){
        printf("\t\t\tNothing To Print!.\n");
    }else{
        printf("\n\t\t\tPrinting Values.........\n");
        while(ptr!=NULL){
            printf("\n\t\t\t%d",ptr->data);
            ptr=ptr->next;
        }
    }
}
//----------------------Search a Element in LL-------------------
void search(){
    struct node *ptr;
    int item,flag,i=0;
    ptr=head;
    if(ptr==NULL){
        printf("\n\t\t\tList Is Empty!.\n");
    }else{
        printf("\t\t\tEnter the item which you want to SEARCH :");
        scanf("%d",&item);
        while(ptr!=NULL){
            if(ptr->data==item){
                printf("\t\t\tItem Found At Location %d \n",i+1);
                flag=0;
            }else{
                flag=1;
            }
            i++;
            ptr=ptr->next;
        }
        if(flag==1){
            printf("\n\t\t\tItem Not Found!.\n");
        }
    }
}
