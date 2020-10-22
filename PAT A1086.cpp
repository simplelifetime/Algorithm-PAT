#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

typedef struct n
{
    int data;
    int lchild;
    int rchild;
    n()
    {
        data = -1;
        lchild = -1;
        rchild = -1;
    }
} node;

node Node[1000000];
vector<int> preorder;
vector<int> inorder;
int len;
int space = 0;
int PrintAlready=0;

int create_tree(int prel, int prer, int inl, int inr)
{
    if (prel > prer)
        return -1;
    int root = space++;
    Node[root].data = preorder[prel];
    int k;
    for (k = 0; k < len; k++)
        if (inorder[k] == preorder[prel])
            break;
    int lnum = k - inl;
    Node[root].lchild = create_tree(prel + 1, prel + lnum, inl, k - 1);
    Node[root].rchild = create_tree(prel + lnum + 1, prer, k + 1, inr);
    return root;
}

void levelorder(int root)
{
    queue<int> Nodeq;
    Nodeq.push(root);
    vector<int> ss;
    while (!Nodeq.empty())
    {
        int temp = Nodeq.front();
        ss.push_back(Node[temp].data);
        if (Node[temp].lchild != -1)
            Nodeq.push(Node[temp].lchild);
        if (Node[temp].rchild != -1)
            Nodeq.push(Node[temp].rchild);
        Nodeq.pop();
    }
    for (int i = 0; i < ss.size(); i++)
    {
        printf("%d", ss[i]);
        if (i != ss.size() - 1)
            printf(" ");
    }
    return;
}

void postorder(int root)
{
    if (root == -1)
        return;
    postorder(Node[root].lchild);
    postorder(Node[root].rchild);
    if (PrintAlready==0)
    {
        cout << Node[root].data;
        PrintAlready = 1;
    }
    else
        cout << " " << Node[root].data;
}

int main()
{
    int num;
    cin >> num;
    int temp;
    char strtemp[5];
    stack<int> InputStore;
    for (int i = 0; i < 2 * num; i++)
    {
        scanf("%s", strtemp);
        if (!strcmp(strtemp, "Push"))
        {
            scanf("%d", &temp);
            preorder.push_back(temp);
            InputStore.push(temp);
        }
        else
        {
            int stemp = InputStore.top();
            inorder.push_back(stemp);
            InputStore.pop();
        }
    }
    len = preorder.size();
    int root = create_tree(0, len - 1, 0, len - 1);

    postorder(root);
}