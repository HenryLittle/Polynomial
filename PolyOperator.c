#include "Global.h"
#include "PolyOperator.h"

PolyNode *Poly_Operation_Add(PolyNode *a, PolyNode *b)
{
    PolyNode *result, *p, *node;
    result = NULL;
    for(p = a; p != NULL; p = p->next){
        //copy the origianl node
        node = (PolyNode*)malloc(sizeof(PolyNode));
        *node = *p;
        printf("%d %d %d\n", node->a, node->xPow, node->yPow);
        result = Add_Poly_Seq(result, node);
    }
    for(p = b; p != NULL; p = p-> next){
        //copy the origianl node
        node = (PolyNode*)malloc(sizeof(PolyNode));
        *node = *p;
        result = Add_Poly_Seq(result, node);
    }
    return result;
}

PolyNode *Poly_Operation_Sub(PolyNode *a, PolyNode *b)
{
    return Poly_Operation_Add(a, Poly_Operation_Reverse(b));
}

PolyNode *Poly_Operation_Reverse(PolyNode *p)
{
    // change the sign of each node to its reverse
    PolyNode *ptr;
    ptr = p;
    for(p; p != NULL; p = p->next){
        p->a = -p->a;
    }
    return ptr;
}

PolyNode *Poly_Operation_Multiply(PolyNode *a, PolyNode *b)
{
    PolyNode *node, *result, *p1, *p2;
    result = NULL;
    for(p1 = a; p1 != NULL; p1 = p1->next){
        for(p2 = b; p2 != NULL; p2 = p2->next){
            node = (PolyNode*)malloc(sizeof(PolyNode));
            node->a = p1->a * p2->a;
            node->xPow = p1->xPow + p2->xPow;
            node->yPow = p1->yPow + p2->yPow;
            result = Add_Poly_Seq(result, node);
        }
    }
    return result;
}