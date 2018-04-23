#include "Global.h"
#include "PolyCal.h"

// SignStackNode* PushSign(SignStackNode *top, int sign) 
// {
//     SignStackNode *p;
//     p = (SignStackNode*)malloc(sizeof(SignStackNode));
//     if (top == NULL) {
//         p->prev=p->next=NULL;
//         p->sign=sign;
//         return p;
//     }
//     p->sign = sign;
//     p->next = NULL;
//     p->prev = top;
//     top->next = p;
//     top = p;
//     return top;
// }

// PolyStackNode *PushPoly(PolyStackNode *top, PolyNode *ptr) 
// {
//     PolyStackNode *p;
//     p = (PolyStackNode*)malloc(sizeof(PolyStackNode));
//     if (top == NULL) {
//         p->prev = p->next = NULL;
//         p->poly = ptr;
//         return p;
//     }
//     p->poly = ptr;
//     p->next = NULL;
//     p->prev = top;
//     top->next = p;
//     top = p;
//     return top;
// }

// PolyNode* PopPoly(PolyStackNode *top) {
//     PolyStackNode *p;
//     p = top;
//     top = top->prev;
//     top->next = NULL;
//     return p->poly;
// }

// int PopSign(SignStackNode *top) {
//     SignStackNode *p;
//     p = top;
//     top = top->prev;
//     top->next = NULL;
//     return p->sign;
// }

// int prio(int x) {
//     if (x == 1 || x == 2) return 1;
//     if (x == 3) return 2;
//     if (x == 4) return 0;
// }

// PolyNode *PolyCal(void) {
//     static PolyStackNode *Polytop=NULL;
//     static SignStackNode *Signtop=NULL;
//     PolyNode *ptr,*q,*p,*result;
//     int signo;

//     Polytop = PushPoly(getpoly); //the first poly
//     Signtop = PushSign(getsign); //the first sign
//     Polytop = PushPoly(getpoly); //the second poly
//     while (Polytop->prev != NULL) { 
//         sign = getsign; //get sign
//         while (sign <= Signtop->sign) {
//             p = (PolyNode*)malloc(sizeof(PolyNode));
//             q = (PolyNode*)malloc(sizeof(PolyNode));
//             p = PopPoly(Polytop);
//             q = PopPoly(Polytop);
//             signo = PopSign(Signtop);
//             switch (signo) {
//                 case 1: ptr = Poly_Operation_Sub(q,p); break;
//                 case 2: ptr = Poly_Operation_Add(q,p); break;
//                 case 3: ptr = Poly_Operation_Multiply(q,p); break;
//             }
//             Polytop = PushPoly(Polytop,ptr);
//     }
//     if (sign != 4) PushPoly(getpoly); //get poly
//     }
//     return PopPoly(Polytop);
//  }

// int priority(char c)
// {
//     int k;
//     switch (c){
//         case '*': k = 2; break;
//         case '/': k = 2; break;
//         case '+': k = 1; break;
//         case '-': k = 1; break;
//         case '(': k = 0; break;
//         case ')': k = 0; break;
//         default: k = -1; 
//     }
//     return k;
// }

PolyNode *Poly_Cal_Alt(ExpressionNode *head)
{

}

ExpressionNode *Poly_Cal_Input()
{
    int i = 0, k;
    char expr[200];
    static ExpressionNode out[20];
    k = 0;// indicator for out
    while(1){
        // initiate a looper
        i = 0;
        scanf("%c", &expr[i]);
        while(expr[i] != '\n'){
            scanf("%c", &expr[++i]);
        }
        // is it a operand?
        if(expr[1] == '\n' && IS_OPERAND(expr[0])){
            // consider \n
            if(expr[0] == '='){
                out[k].node = NULL;
                out[k].op = '\0';
                break;
            }else{
                // store a operand ExpressionNode
                printf("Poly_cal:%c\n", expr[0]);
                out[k].op = expr[0];
                out[k++].node = NULL;
            }
        }else{
            out[k].node = Parse_Poly_List(expr);
            out[k++].op = '\0';
        }
    }
    return out;
}