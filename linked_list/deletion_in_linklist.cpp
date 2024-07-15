#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *create(node *s)
{
    char k;
    node *p = NULL, *p1 = NULL;
    s = new node;
    cout << "Enter Data: ";
    cin >> s->data;
    p = s;
    do
    {
        p1 = new node;
        cout << "Enter Data: ";
        cin >> p1->data;
        p1->next = NULL;
        p->next = p1;
        p = p1;
        cout << "Want to add more: y or n: ";
        cin >> k;
    } while (k == 'y');
    return s;
}
void display(node *start)
{
    node *p2 = start;
    while (p2 != NULL)
    {
        cout << p2->data << " ";
        p2 = p2->next;
    }
    cout << endl;
}
node *deletion(node *start, int x)
{
    node *p = start;
    node *t = start;
    if (start->data == x)
    {
        start = start->next;
        delete (p);
    }
    else
    {
        while (t->next != NULL)
        {
            if (t->next->data == x)
            {
                p = t->next;
                t->next = t->next->next;
                delete (p);
            }
            t = t->next;
        }
    }
    return start;
}
int main()
{
    node *start = NULL;
    int x;
    start = create(start);
    cout << endl
         << "linklist: " << endl;
    display(start);
    cout << "Enter number you want to insert: ";
    cin >> x;
    start = deletion(start, x);
    display(start);
}