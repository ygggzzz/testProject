#include <iostream>
using namespace std;

typedef struct Node
{

    int num;

    struct Node *next;

} Node, *LinkList;

void InsertNode(LinkList L, int i, int e);
void CreateList(LinkList &L, int n); // n为结点数量
void PrintList(LinkList N);

int main()
{
    LinkList L;
    int n = 10;
    CreateList(L, n);
    PrintList(L);
    InsertNode(L, 5, 10);
    PrintList(L);
    delete L;
    return 0;
}

void InsertNode(LinkList L, int i, int e)
{
    Node *pre, *s;
    int k;
    if (i <= 0)
    {
        cout << "ERROR" << endl;
        return;
    }
    pre = L;
    k = 0;
    while (pre != NULL && k < i - 1)
    {
        pre = pre->next;
        k++;
    }
    if (pre == NULL)
    {
        cout << "ERROR" << endl;
        return;
    }
    s = new Node;
    s->num = e;
    s->next = pre->next;
    pre->next = s;
    return;
}

void CreateList(LinkList &L, int n) // n为结点数量 L需要深拷贝，所以要带& 二InsertNode仅仅只用更改结点链接情况，所以不用
{
    L = new Node; // 头结点
    Node *p = L;
    for (int i = 1; i <= n; i++)
    {
        Node *newNode = new Node;
        newNode->num = i;
        newNode->next = NULL;
        p->next = newNode;
        p = newNode;
    }
    return;
}

void PrintList(LinkList N)
{
    Node *p = N->next;
    while (p != NULL)
    {
        cout << p->num << " ";
        p = p->next;
    }
    cout << endl;
}