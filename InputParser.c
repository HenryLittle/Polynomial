#include "Global.h"
#include "InputParser.h"

#define _ENABLE_PARSE_PRINT_

int min(int a, int b)
{
    return a<b ? a : b;
}

PolyNode *Parse_Poly_Node(char *str, int sign)
{
    PolyNode *p;
    p = (PolyNode*)malloc(sizeof(PolyNode));
    int index_x = -1, index_y = -1;
    int i = 0, a, xPow, yPow;
    while(str[i] != '\0'){
        if(str[i] == 'x'){
            index_x = i;
        }else if(str[i] == 'y'){
            index_y = i;
        }
        i ++;
    }
    //get a
    if(IS_DIGIT(str[0])){
        i = a = 0;
        while(IS_DIGIT(str[i])){
            a = 10 * a + TO_INT(str[i]);
            i ++;
        }
    }else{
        a = 1;
    }
    a = a * sign;
    p->a = a;
    //get xPow
    if(-1 == index_x){
        xPow = 0;
    }else{
        if('^' == str[index_x + 1]){
            i = index_x + 2;
            xPow = 0;
            while(IS_DIGIT(str[i])){
                xPow = 10*xPow + TO_INT(str[i]);
                i ++;
            }
            //p->xPow = xPow;
        }else{
            //p->xPow = 1;
            xPow = 1;
        }
    }
    p->xPow = xPow;
    //get yPow
    if(-1 == index_y){
        yPow = 0;
    }else{
        if('^' == str[index_y + 1]){
            i = index_y + 2;
            yPow = 0;
            while(IS_DIGIT(str[i])){
                yPow = 10*yPow + TO_INT(str[i]);
                i ++;
            }
            //p->yPow = yPow;
        }else{
            //p->yPow = 1;
            yPow = 1;
        }
    }
    p->yPow = yPow;
    #ifdef _ENABLE_PARSE_PRINT_
    int k = 0;
    while(str[k] != '\0'){
        printf("%c", str[k++]);
    }
    printf("\n");
    printf("(%d %d)\n", index_x, index_y);
    printf("%d %d %d\n", a, xPow, yPow);
    #endif // _ENABLE_PARSE_PRINT_
    p->next = p->prev = NULL;
    return p;
}

PolyNode *Parse_Poly_List(char *str)
{
    int i = 0, j = 0, sign;
    char nodeStr[15];
    PolyNode *head = NULL, *p = NULL, *tail = NULL;
    //split the whole input with '+'/'-'
    i = j = 0;
    sign = 1;
    while(IS_SIGN_OR_BLANK(str[i])){
        if ('-' == str[i]) sign = -1;
        i++;
    }
    while(!IS_SIGN_OR_BLANK(str[i]) && str[i] != '\n'){
        nodeStr[j++] = str[i];
        i++;
    }
    nodeStr[j] = '\0';
    head = Parse_Poly_Node(nodeStr, sign);
    tail = head;
    sign = 1;
    while('\n' != str[i]){
        if(IS_SIGN_OR_BLANK(str[i])){
            if('-' == str[i]) sign = -1;
            else if('+' == str[i]) sign = 1;
            i++;
            continue;
        }else{
            j = 0;
            while(!IS_SIGN_OR_BLANK(str[i]) && '\n' != str[i]){
                nodeStr[j++] = str[i];
                i++;
            }
            nodeStr[j] = '\0';
            p = Parse_Poly_Node(nodeStr, sign);

            tail->next = p;
            p->prev = tail;
            p->next = NULL;
            tail = p;
        }
    }
    return head;
}