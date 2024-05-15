
#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

void Enter(node** H,int key){

    node* nn;
    node *temp=*H;
    nn = new node;
    nn->data = key;
    nn->next  = NULL;
    if(*H==NULL){
        *H = nn;
    }
    else{
        while(temp != NULL){
            temp = temp->next;
        }
        temp->next = nn;
    }
}


int ha(int key){
    return (key%10);
}


void Insert(node**H,int key){

    int index = ha(key);
    Enter(&H[index],key);
}
node* Search(node *temp,int key)
{
    while(temp!=NULL)
    {
        if(key==temp->data)
        {
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}
int main(){

    int n;
    cout<<"Enter total number of elements:";
    cin>>n;

    node* Hash[20];
    node* temp;

    for(int i=0; i < 20;i++)
        Hash[i]=NULL;

    cout << "Enter elements : ";
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        Insert(Hash,a);
    }

    cout<<"which element you have to search:";
    int x;
    cin >> x;

    temp = Search(Hash[ha(x)],x);

    if(temp==NULL)
        cout<<"data not found in Hash Table" << endl;

    else
        cout << temp->data << " is found in Hash Table" << endl;

    return 0;
}