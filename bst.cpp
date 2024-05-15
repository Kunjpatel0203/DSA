#include <iostream>
#include <queue>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
void korder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *current = q.front();
        // current=;

        cout << current->data << " ";
        if (current->left != NULL)
        {
            q.push(root->left);
        }
        if (current->right != NULL)
        {
            q.push(root->right);
        }
        q.pop();
    }
}

void create1(node *root, node *new1)
{

    if (root->data > new1->data)
    {
        if (root->left == NULL)
            root->left = new1;
        else
            create1(root->left, new1);
    }
    else
    {
        if (root->right == NULL)
            root->right = new1;
        else
            create1(root->right, new1);
    }
}
void search(node *root, int key)
{
    if (root == NULL)
        return;
    if (root->data == key)
    {
        cout << "match succsesfully find\n";
    }
    else
    {
        if (root->data > key)
            search(root->left, key);
        else
            search(root->right, key);
    }
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    int d;
    cout << "enter the root node data\n";
    cin >> d;

    struct node *root = new node(d);

    int n;
    cout << "enter the how many node to create\n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d;
        cout << "enter the data";
        cin >> d;
        struct node *new1 = new node(d);
        create1(root, new1);
    }
    int data1;
    cout << "enter the serch number";
    cin >> data1;

    search(root, data1);
    cout << "\n";
    inorder(root);
}