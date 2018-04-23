#ifndef _POLY_OPERATOR_H_
#define _POLY_OPERATOR_H_

#include "DataStructure.h"
#include "InputParser.h"

/**
 *  \brief: add a polynomial to another
 *
 *  \param[in]  *a  the head pointer of the poly list to be added
 *  \param[in]  *b  the head pointer of the poly list to be added
 */
PolyNode *Poly_Operation_Add(PolyNode *a, PolyNode *b);

/**
 *  \brief: sub polynomial b from a(remember to reverse b again after using
 *   this function to undo the changes)
 *
 *  \param[in]  *a  the head pointer of the poly list to be substracted from
 *  \param[in]  *b  the head pointer of the poly list to be substracted
 */
PolyNode *Poly_Operation_Sub(PolyNode *a, PolyNode *b);

/**
 *  \brief: change the sign of a polynomial to the opposite
 *
 *  \param[in]  *p  the head pointer of the poly list to be reversed
 */
PolyNode *Poly_Operation_Reverse(PolyNode *p);

/**
 *  \brief: do a multipication between the two given polynomial
 *
 *  \param[in]  *a  the head pointer of the poly list to be multiplyed
 *  \param[in]  *b  the head pointer of the poly list to be multiplyed
 */
PolyNode *Poly_Operation_Multiply(PolyNode *a, PolyNode *b);

#endif // !_POLY_OPERATOR_H_