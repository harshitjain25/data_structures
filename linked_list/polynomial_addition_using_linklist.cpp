#include <iostream>
using namespace std;
struct node
{
    int coef;
    int pow;
    node *next;
    //node *prev;
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
    //start->prev = NULL;
    p = start;
    int k = start->pow;
    for (int i = k - 1; i >= 0; i--)
    {
        cout << "Enter coefficient of power "<< i << ": ";
        cin >> c;
        if (c != 0)
        {
            p1 = new node;
            p1->pow = i;
            p1->coef = c;
            p1->next = NULL;
            //p1->prev = p;
            p->next = p1;
            p = p->next;
        }
    }
    return start;
}
node *polynomial_add(node *start1, node *start2)
{
    node *p1 = start1;
    node *p2 = start2;
    node *start3 = NULL;
    node *p3;
    node *p = NULL;
    
    while (p1 != NULL && p2 != NULL)
    {
        if (start3==NULL)
        {   start3=new node;
            p3=start3;
        } 
        else
        { p3->next = new node;
          p3=p3->next; 
        }  
        if (p1->pow == p2->pow)
        {
            p3->coef = p1->coef + p2->coef;
            p3->pow = p1->pow;
            p1 = p1->next;
            p2 = p2->next;
            
        }
        else if (p1->pow > p2->pow)
        {
            p3->coef = p1->coef;
            p3->pow = p1->pow;
            p1 = p1->next;
            
        }
        else
        {
            p3->coef = p2->coef;
            p3->pow = p2->pow;
            p2 = p2->next;
            
        }
        
    }
    while (p1 != NULL)
    {
        p3->next = new node;
        p3=p3->next;
        p3->next=NULL;
        p3->coef = p1->coef;
        p3->pow = p1->pow;
        p1 = p1->next;
        
    }
    while (p2 != NULL)
    {
        p3->next = new node;
        p3=p3->next;
       
        p3->coef = p2->coef;
        p3->pow = p2->pow;
        p2 = p2->next;
    }
    return start3;
}
void display(node *start)
{
    node *p2 = start;
    while (p2 != NULL)
    {
        cout << p2->coef << " " << p2->pow<<"  ";
        p2 = p2->next;
    }
    cout << endl;
}
int main()
{
    node *start1 = NULL, *start2 = NULL, *start3 = NULL;
    start1 = create(start1);
    display(start1);
    start2 = create(start2);
    display(start2);
    start3 = polynomial_add(start1, start2);
    display(start3);
}