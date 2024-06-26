#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void insert(node *&root, node *nn)
{
    char c;
    if (root == NULL)
    {
        root = nn;
        return;
    }
    cout << "where do you want to insert L/R of:" << root->data << endl;
    cin >> c;
    if (c == 'l')
    {
        if (root->left == NULL)
            root->left = nn;
        else
            insert(root->left, nn);
    }
    else if (c == 'r')
    {
        if (root->right == NULL)
            root->right = nn;
        else
            insert(root->right, nn);
    }
}

void inorder(node *&root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node *&root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *&root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelorder(node *&root)
{
    if (root == NULL)
        return;

    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *curr = q.front();
        q.pop();
        cout << curr->data << " ";

        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}


void insertBST(node *&root, node *nn)
{
    if (root == NULL)
    {
        root = nn;
        return;
    }
    if (nn->data > root->data)
    {
        if (root->right == NULL)
            root->right = nn;
        else
            insertBST(root->right, nn);
    }
    if (nn->data < root->data)
    {
        if (root->left == NULL)
            root->left = nn;
        else
            insertBST(root->left, nn);
    }
}
node *search(node *root, int key)
{
    if (root == NULL)
    {
        return (NULL);
    }
    node *temp = root;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            cout << "\nele found\n";
            return (temp);
        }
        if (temp->data > key)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return (NULL);
}
/*int count(node *root)
{
    static int c = 0;
    if (root == NULL)
    {
        return c;
    }
    c = count(root->left);
    c = count(root->right);
    c++;
}
node *inordersucc(node *root)
{
    if (root == NULL)
        return (root);
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return (temp);
}*/



int main()
{
    node *root = NULL;
    char ans = 'y';
    int val;
    while (ans == 'y')
    {
        cout << "enter a node\n";
        cin >> val;
        node *nn = new node(val);
        insertBST(root, nn);
        cout << "continue?\n";
        cin >> ans;
    }
    cout << "traversals\n";
    cout << "\npre\n";
    preorder(root);
    cout << "\nin\n";
   // inorder(root);
    cout << "\npost\n";
    //postorder(root);

    cout << "\nlevel order\n";
    levelorder(root);

    node *a1 = search(root, 7);
    cout << "a1:" << a1 << endl;
    node *a2 = search(root, 99);
    cout << "a2:" << a2 << endl;
    

       
    // deleteinBST(root,6);
    // deleteinBST(root,1);
    // deleteinBST(root,10);
    cout << "\nin\n";
    inorder(root);
    return 0;
}