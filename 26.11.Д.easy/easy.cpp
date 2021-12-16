#include <iostream>
using namespace std;

typedef struct tree
{
    int data;
    tree* left;
    tree* right;
    tree* parent;
} tree;

tree* gettree(int x, tree* parent) {
    tree* tmp = new tree;
    tmp->left = tmp->right = NULL;
    tmp->data = x;
    tmp->parent = parent;
    return tmp;
}
void insert(tree** head, int x) {
    tree* tmp = NULL;
    tree* ins = NULL;
    int side;
    tmp = *head;
    while (tmp) {
        cout << "which side? (0 - left, 1 - right) = ";
        cin >> side;
        if (side == 1) 
        {
            if (tmp->right) {
                tmp = tmp->right;
                continue;
            }
            else {
                tmp->right = gettree(x, tmp);
                return;
            }
        }
        else if (side == 0) {
            if (tmp->left) {
                tmp = tmp->left;
                continue;
            }
            else {
                tmp->left = gettree(x, tmp);
                return;
            }
        }
        else {
            exit(0);
        }
    }
}
void printTree(tree* head, const char* dir, int level) {
    if (head) {
        cout << "lvl " << level << " " << dir << " = " << head->data << endl;
        printTree(head->left, "left", level + 1);
        printTree(head->right, "right", level + 1);
    }
}

void roundleft(tree* head, int knot, int left)
{
    if ((head == NULL) || (head->data == left))
        return;
    roundleft(head->left, knot, left);
    if ((head->data) < knot)
        exit(0);
    roundleft(head->right, knot, left);
}
void roundright(tree* head, int knot, int right)
{ 
    if ((head == NULL) || (head->data == right))
        return;
    roundright(head->right, knot, right);
    if ((head->data) > knot)
        exit(0);
    roundright(head->left, knot, right);
}

void destroy(tree* head)
{
    if (head != NULL)
    {
        if (head->left != NULL)
            destroy(head->left);
        if (head->right != NULL)
            destroy(head->right);
        free(head);
    }
}
int main() {
    int x, size;
    tree* head = NULL;
    cout << "Number of knots = ";
    cin >> size;
    cout << "Root value = ";
    cin >> x;
    head = gettree(x, NULL);
    cout << "Knots values:" << endl;
    for (int i = 0; i < size - 1; i++)
    {
        cin >> x;
        insert(&head, x);
    }
    printTree(head, "head", 0);
    roundleft(head, head->data, head->left->data);
    roundright(head, head->data, head->right->data);
    destroy(head);
    return(1);
}
