// #ifndef _POLY_CAL_H_
// #define _POLY_CAL_H_

// #define IS_OPERAND(a) (a == '(' || a == ')' || a == '+' || a == '-' || a == '*' || a == '=')

// #include "DataStructure.h"
// #include "InputParser.h"
// #include "string.h"

// typedef struct{
//     int sign;
//     SignStackNode *prev,*next;

// } SignStackNode;

// typedef struct{
//     PolyNode *poly;
//     PolyStackNode *prev,*next; 
// } PolyStackNode;

// typedef struct{
//     char op;// \0 for empty
//     PolyNode *node;// NULL for empty
// } ExpressionNode;

// // SignStackNode* PushSign(SignStackNode *top,int sign);

// // PolyStackNode* PushPoly(PolyStackNode *top,PolyNode *ptr);

// // PolyNode* PopPoly(PolyStackNode *top);

// // int PopSign(SignStackNode *top);

// // int prio(int x);

// // PolyNode *PolyCal(void);

// ExpressionNode *Poly_Cal_Input();


// #endif // !_POLY_OPERATOR_H_