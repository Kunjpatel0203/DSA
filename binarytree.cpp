#include <iostream>
#include <cstdio> // Include the <cstdio> header for getchar()

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

void insert(node *root, node *New)
{
    cout << "Where to insert left / right of " << root->data << "? ";
    char ch = getchar(); // Use getchar() instead of getche()

    if (ch == 'r') // Use single quotes for character literals
    {
        if (root->right == NULL)
            root->right = New;
        else
            insert(root->right, New);
    }
    else
    {
        if (root->left == NULL)
            root->left = New;
        else
            insert(root->left, New);
    }

    cout<<"data entered"<<endl;
}

node *get_node()
{
    node *temp;
    temp = new node;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int main()
{
    node *New, *root;
    root = NULL;
    char ans;

    do
    {
        New = get_node();
        cout << "Enter data: ";
        cin >> New->data;
        if (root == NULL)
            root = New;
        else
            insert(root, New);
        cout << "Do you want to enter more elements? (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y'); // Use single quotes for character literals

    return 0;
}
