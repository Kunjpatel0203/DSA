#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next; // this pointer is pointing the next node so the pointer will be of type node .....

    node(int val)
    {
        data = val;
        // next=NULL;
    }
};
void insertAtail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n; // last node or last entry/data  to be filled or entered
}

void deleteathead(node* &head)//delete first node
{
    node* todelete=head;
    head=head->next;

    delete todelete;

}

void deletion(node* &head,int val)//delete any node.
{

    if(head==NULL)
    {
        return;
    }
    if(head->next=NULL)
    {
        deleteathead(head);
        return;
    }
    node* temp=head;

    while(temp->next->data!=val)
    {
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;

    delete todelete;
}

// insert before
void insertbefore(node *&head, int j, int k)
{
    node *temp = head;
    node *insertAtbefore = new node(j);
    if (temp->data == k)
    {
        insertAtbefore->next = head;
        head = insertAtbefore;
        return;
    }
    else
    {
        cout << "your node is nor first";
    }

    while (temp->next != NULL && temp->next->data != k)
    {
        temp = temp->next;
    }
    insertAtbefore->next = temp->next;

    temp->next = insertAtbefore;
}


void insertafter(node *&head, int j, int k)
{
    node *temp = head;
    node *insertAtafter = new node(j);
    while (temp->next != NULL && temp->next->data != k)
    {
        temp = temp->next;
    }
    insertAtafter->next = temp->next->next;

    temp->next->next= insertAtafter;

}
void display(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

node *reverse(node *&head)
{
    node *prev = NULL;
    node *currtptr = head;
    node *nextptr;

    while (currtptr != NULL)
    {
        nextptr = currtptr->next;
        currtptr->next = prev;
        prev = currtptr;
        currtptr = nextptr;
    }
    return prev;
}

int main()
{

    node *head = NULL;
    insertAtail(head, 1);
    insertAtail(head, 2);
    insertAtail(head, 3);
    insertAtail(head, 4);
    insertAtail(head, 5);
    display(head);

    // deletion(head,3);
    // display(head);

    // insertion before
    /*int j,k;
    cout<<"enter the number you want to enter and before which number"<<endl;
    cin>>j>>k;
    insertbefore(head,6,4);
    display(head);*/

    // insertion after
    int c, b;
    cout << "enter the number you want to enter and after which number you want to enter" << endl;
    cin >> c >> b;
    insertafter(head, c, b);
    display(head);

    node *newhead = reverse(head);
    display(newhead);
    return 0;
}
