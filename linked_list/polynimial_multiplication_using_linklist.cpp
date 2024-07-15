#include <iostream>
using namespace std;
struct node
{
    int coef;
    int pow;
    node *next;
};
node *create(node *start)
{
    int c;
    node *p = NULL, *p1 = NULL;
    start = new node;
    start->next = NULL;
    cout << "Enter highest power of the polynomial eqaution: ";
    cin >> start->pow;
    cout << "Enter its coefficient: ";
    cin >> start->coef;
    p = start;
    int k = start->pow;
    for (int i = k - 1; i >= 0; i--)
    {
        cout << "Enter coefficient of power " << i << ": ";
        cin >> c;
        if (c != 0)
        {
            p1 = new node;
            p1->pow = i;
            p1->coef = c;
            p1->next = NULL;
            p->next = p1;
            p = p->next;
        }
    }
    return start;
}
void display(node *start)
{
    node *p2 = start;
    while (p2 != NULL)
    {
        cout << p2->coef << " " << p2->pow << "  ";
        p2 = p2->next;
    }
    cout << endl;
}
node *polynomial_mul(node *start1, node *start2)
{
    node *p1 = start1;
    node *p2 = start2;
    node *start3 = new node;
    node *p3 = start3;
    node *p = NULL, *t = NULL;
    while (p1 != NULL)
    {
        p2 = start2;
        while (p2 != NULL)
        {
            p3->pow = p1->pow + p2->pow;
            p3->coef = p1->coef * p2->coef;
            p3->next = NULL;
            p2 = p2->next;

            if (p1->next == NULL && p2 == NULL)
            {
                ;
            }
            else
            {
                p = new node;
                p3->next = p;
                p->next = NULL;
                p3 = p;
            }
        }
        p1 = p1->next;
    }
    p3 = start3;
    while (p3 != NULL)
    {
        t = p3;
        while (t->next != NULL)
        {
            p = t;
            t = t->next;
            if (t->pow == p3->pow)
            {
                p3->coef = p3->coef + t->coef;
                p->next = t->next;
                delete (t);
                t = p->next;
            }
        }
        p3 = p3->next;
    }
    return start3;
}
int main()
{
    node *start1 = NULL, *start2 = NULL, *start3 = NULL;
    start1 = create(start1);
    display(start1);
    start2 = create(start2);
    display(start2);
    cout << "MULTIPLICATION: " << "\n";
    start3 = polynomial_mul(start1, start2);
    display(start3);
}