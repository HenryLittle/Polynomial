#ifndef _DATA_STRUCTURE_H_
#define _DATA_STRUCTURE_H_

#define IS_CONST_NODE (0 == xPow && 0 == yPow)  /* whether the current node is a constant */

/* the type that holds a sigle node */
typedef struct polyNode
{
    int a;
    int xPow;
    int yPow;
    struct polyNode *prev;
    struct polyNode *next;
}PolyNode;

/**
 *  \brief: add a node to a existing list, if the list is NULL return p
 *
 *  \param[in]  *head  the head of the list to hold the node
 *  \param[in]  *p     the node to be added
 *  \param[in]  mode   where to add the node(0:first|1:last|2:Add_Poly_Seq)
 */
PolyNode *Add_Poly_Node(PolyNode *head, PolyNode *p, int mode);

/**
 *  \brief: add a node to a existing list wit h sequence, if the list is NULL return p.
 *   follow the increase of the power of x. Merge if a node with the same power is
 *   already in the list.
 *
 *  \param[in]  *head  the head of the list to hold the node
 *  \param[in]  *p     the node to be added
 */
PolyNode *Add_Poly_Seq(PolyNode *head, PolyNode *p);

/**
 *  \brief: print the list in polynomial form
 *
 *  \param[in]  *head  the head of the list to be printed
 */
void Print_List(PolyNode *head);

#endif // ! _DATA_STRUCTURE_H_