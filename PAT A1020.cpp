#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
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
vector<int> postorder;
vector<int> inorder;
int len;
int space = 0;

int create_tree(int postl, int postr, int inl, int inr)
{
    if (postl > postr)
        return -1;
    int root = space++;
    Node[root].data = postorder[postr];
    int k;
    for (k = 0; k < len; k++)
        if (inorder[k] == postorder[postr])
            break;
    int lnum = k - inl;
    Node[root].lchild = create_tree(postl, postl + lnum - 1, inl, k - 1);
    Node[root].rchild = create_tree(postl + lnum, postr - 1, k + 1, inr);
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
int main()
{
    int num;
    cin >> num;
    int temp;
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &temp);
        postorder.push_back(temp);
    }
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &temp);
        inorder.push_back(temp);
    }
    len = postorder.size();
    int root = create_tree(0, len - 1, 0, len - 1);
    // for (int i = 0; i < len; i++)
    // {
    //     cout << i << "  " << Node[i].lchild << "  " << Node[i].rchild << endl;
    // }
    levelorder(root);
}
