#include <stdio.h>
#include <stdlib.h>




struct LinkNode {
        int value;
        struct LinkNode *next;
};


struct LinkNode *g_Header = NULL;

void LinkCreate()
{
        int i;
        struct LinkNode *newNode = NULL;
        struct LinkNode *tail = NULL;
        for (i = 0; i< 10; i++)
        {
                newNode = (struct LinkNode *)malloc(sizeof(struct LinkNode));
                newNode->value = i;
                newNode->next = NULL;
                if(g_Header == NULL)
                {
                        g_Header = newNode;
                        tail = newNode;
                }
                else
                {
                        tail->next = newNode;
                        tail = newNode;
                }
        }
        printf("LinkCreate ok\n");
}

void LinkWalk()
{
        struct LinkNode *p = NULL;
        int count = 0;

        printf("LinkWalk......\n");

        p = g_Header;
        if(p == NULL)
        {
                printf("link is null\n");
                return;
        }

        while(p)
        {
                printf("node: %d, value: %d\n", count, p->value);
                p = p->next;
                count++;
        }

        return;
}

void LinkRevert()
{
        struct LinkNode *p = NULL;
        struct LinkNode *y = NULL;

        printf("LinkRevert....\n");

        p = g_Header;
        if(p == NULL)
        {
                printf("link is null\n");
                return ;
        }

        y = p->next;
        while(y)
        {
                p->next = y->next;
                y->next = g_Header;
                g_Header = y;
                y = p->next;
        }

        LinkWalk();
}

int main()
{
        LinkCreate();
        LinkWalk();
        LinkRevert();
        return 0;
}
