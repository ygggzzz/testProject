#include <iostream> //????? ????? ??????? ???? ???? ??? ??¦Ë ???? ??? ??????
using namespace std;

#define MAXSIZE 100

typedef struct
{
    int elem[MAXSIZE];
    int length;
} SeqList;

int emptyL(SeqList *q);
void LocateList(SeqList *q, int e);
void InsertList(SeqList *q, int i, int e); // i??????e
void output(SeqList L);
void InitList(SeqList *q);

SeqList L;

int main()
{
    SeqList *p;
    p = &L;
    L.length = 0;
    InitList(p);

    /* int n, e;
    cin >> n >> e;
    InsertList(p, n, e); */

    /* int e;
    cin >> e;
    LocateList(p, e); */

    /* int i;
    cin >> i;
    DelList(p, i); */

    /* int c = emptyL(p);
    cout << c <<endl; */

    return 0;
}

void output(SeqList L)
{
    cout << L.length << endl;
    for (int i = 0; i < L.length; i++)
    {
        cout << L.elem[i] << " ";
    }
    cout << endl;
}

void InitList(SeqList *q)
{
    cout << "?????????-1????" << endl;
    int n;
    int i = 0;
    cin >> n;
    while (n != -1)
    {
        q->length++;
        q->elem[i] = n;
        i++;
        cin >> n;
    }
    output(L);
}

void InsertList(SeqList *q, int i, int e) // i??????e
{
    int k;
    if ((i < 1 || (i > q->length + 2) || (q->length >= MAXSIZE - 1)))
    {
        cout << "???????" << endl;
        return;
    }
    for (k = q->length; k >= i - 1; k--)
    {
        q->elem[k + 1] = q->elem[k];
    }
    q->elem[i - 1] = e;
    q->length++;
    output(L);
}

void LocateList(SeqList *q, int e)
{
    int i = 0;
    while (i < q->length && q->elem[i] != e)
    {
        i++;
    }
    if (i < q->length)
    {
        cout << i + 1 << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
}

void DelList(SeqList *q, int i)
{
    int k;
    if (i < 1 || i > q->length)
    {
        cout << "???????" << endl;
        return;
    }
    for (int k = i; k <= q->length; k++)
    {
        q->elem[k - 1] = q->elem[k];
    }
    q->length--;
    output(L);
}

int emptyL(SeqList *q)
{
    if (q->length == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
