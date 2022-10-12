#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coef;
    int po;
    struct node *next;
};
struct node *create()
{
    int c, k;
    struct node *start = NULL, *p = NULL, *p1 = NULL;
    start = (struct node *)malloc(sizeof(struct node));
    printf("Enter highest power: ");
    scanf("%d", &k);
    printf("Enter coefficient: ");
    scanf("%d", &c);
    start->coef = c;
    start->po = k;
    start->next = NULL;
    for (int i = k - 1; i >= 0; i--)
    {
        printf("Enter coefficient for power %d ", i);
        printf("Enter coefficient: ");
        scanf("%d", &c);
        if (c != 0)
        {
            p1 = (struct node *)malloc(sizeof(struct node));
            p1->coef = c;
            p1->po = i;
            p1->next = NULL;
        }
    }
    return start;
}
struct node *add(struct node *k1, struct node *k2)
{
    struct node *p1 = NULL, *p2 = NULL, *p3 = NULL, *p = NULL,*k3 = NULL;
    p1 = k1;
    p2 = k2;
    p3 = (struct node *)malloc(sizeof(struct node));
    k3=p3;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->po > p2->po)
        {
            p3->coef = p1->coef;
            p3->po = p1->po;
            p = (struct node *)malloc(sizeof(struct node));
            p->next=NULL;
            p3->next = p;
            p3 = p3->next;
            p1 = p1->next;
        }
        else if (p1->po < p2->po)
        {
            p3->coef = p2->coef;
            p3->po = p2->po;
            p = (struct node *)malloc(sizeof(struct node));
            p->next=NULL;
            p3->next = p;
            p3 = p3->next;
            p2 = p2->next;
        }
        else
        {
            p3->po = p2->po;
            p3->coef = p1->coef + p2->coef;
            p = (struct node *)malloc(sizeof(struct node));
            p->next=NULL;
            p3->next = p;
            p3 = p3->next;
            p2 = p2->next;
            p1 = p1->next;
        }
    }
    return k3;
}
int main()
{
    struct node *s1, *s2, *s3, *p;
    s1 = create();
    printf("second polynimial\n");
        s2 = create();
    s3 = add(s1, s2);
    p = s3;
    while (p != NULL)
    {
        printf("%d %d  ", p->coef, p->po);
        p = p->next;
    }
    return 0;
}
