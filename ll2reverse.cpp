#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;//this pointer is pointing the next node so the pointer will be of type node .....

    node(int val){
        data=val;
       // next=NULL;
    }

};
void insertAtail(node* &head,int val)
{
    node* n=new node(val);

    if(head==NULL)
    {
        head=n;
        return;
    }

    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;//last node or last entry/data  to be filled or entered
}

void display(node* head)
{
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}




node *merge(node* &head1,node* &head2)
{
    node* p1=head1;
    node* p2=head2;
    node* dummynode=new node(-1);
    node* p3=dummynode;

    while(p1!=NULL && p2!=NULL)
    {
        if(p1->data < p2->data)
        {
            p3->next=p1;
            p1=p1->next;
        }
        else
        {
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    } 

    while(p1!=NULL)
    {
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
    while(p2!=NULL)
    {
        p3->next=p1;
        p2=p2->next;
        p3=p3->next;
    }
return dummynode->next;
}


int main()
{
    node *head1=NULL;
    node *head2=NULL;
    int arr1[]={1,4,5,6,7,8};
    int arr2[]={2,3,6};

    for(int i=0;i<6;i++)
    {
        insertAtail(head1,arr1[i]);
    }

    
    for(int i=0;i<4;i++)
    {
        insertAtail(head2,arr1[i]);
    }

    display(head1);
    display(head2);

    node* newhead=merge(head1,head2);
    display(newhead);
}