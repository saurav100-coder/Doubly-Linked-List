#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node *addToEmpty(struct node *head , int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->next = NULL;
    temp->data = data;
    temp->prev = NULL;
    head = temp;
    return head;
}

struct node *addAtBeg(struct node *head , int data) {
    struct node *temp = NULL;
    temp = addToEmpty(temp , data);
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;

}

void addAtEnd(struct node *head , int data) {
    struct node *newP = NULL;
    struct node *temp = head;
    newP = addToEmpty(newP , data);
    while(temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = newP;
    newP->prev = temp;
}

void addAfterPos(struct node *head,int pos,int data) {
    struct node *newP = NULL;
    newP = addToEmpty(newP,data);
    struct node *temp1 = head;
    struct node *temp2 = NULL;
    int p=pos;

    while (pos!=1) {
        temp1=temp1->next;
        pos--;
    }

    if(temp1->next==NULL)
        addAtEnd(head,data);
    else{
        temp2=temp1->next;
        temp1->next=newP;
        temp2->prev=newP;
        newP->prev=temp1;
        newP->next=temp2;
    }
}

struct node* addBeforePos(struct node *head,int pos,int data) {
    struct node *newP=NULL;
    newP=addToEmpty(newP,data);
    struct node *temp1=head;
    struct node *temp2=NULL;
    int p = pos;
    while(pos>2) {
        temp1=temp1->next;
        pos--;
    }
    if(p==1)
        head=addAtBeg(head,data);
    else{
        temp2 = temp1->next;
        temp1->next=newP;
        temp2->prev=newP;
        newP->prev=temp1;
        newP->next=temp2;
    }
    return head;
}

struct node* createList(struct node *head) {
    int n,i,data,choice,pos;
    printf("Enter the no. of nodes : ");
    scanf("%d",&n);
    printf("Enter Your choice ");
    printf("1 for adding data at end , 2 for at beg , 3 for add before position , 4 for adding after position : ");
    scanf("%d",&choice);
    if(n==0)
        return head;
    printf("Enter the elements for node 1 : ");
    scanf("%d",&data);
    head=addToEmpty(head,data);
    for(i=1;i<n;i++) {
        printf("Enter the element for node %d : ",i+1);
        scanf("%d",&data);
        switch(choice) {
        case 1:
            addAtEnd(head,data);
            break;
        case 2:
            head = addAtBeg(head,data);
            break;
        case 3:
            printf("Enter position : ");
            scanf("%d",&pos);
            head = addBeforePos(head,pos,data);
            break;
        case 4:
            printf("Enter position : ");
            scanf("%d",&pos);
            addAfterPos(head,pos,data);
            break;
        default:
            printf("Wrong choice\n:");
            break;

        }


    }
    return head;
};

void print (struct node *head)
{
    if (head==NULL) printf ("List is empty\n");
    else {
        struct node *temp = head;
        while (temp!=NULL) {
            printf ("%d ",temp->data);
            temp = temp->next;
        }
    }

}

void main() {
    struct node *head = NULL;
    head=createList(head);

    print(head);
}
