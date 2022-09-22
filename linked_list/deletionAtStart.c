#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    int a;
    struct node *start = NULL, *p = NULL, *p1 = NULL,*t = NULL;;
    char k;
    start = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &(start->data));
    start->next = NULL;
    p = start;
    do
    {
        p1 = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d", &(p1->data));
        p1->next = NULL;
        p->next = p1;
        p = p1;
        getchar();
        printf("Want to add more? ");
        scanf("%c", &k);

    } while (k == 'y');
    t=start->next;
    free(start);
    start=t;
    p=start;
    
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    return 0;
}