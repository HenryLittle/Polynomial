#include "InputParser.h"
#include "PolyOperator.h"
#include "PolyCal.h"
#include "Global.h"
#include <windows.h>

int main(){
    //TEST ONLY!!!
    // char a[100] = {"x^3y^2  + x^2y + xy^2\n"};
	// char b[100] = {"5x^3y^2 + xy + 5y^2\n"};
	char a[100] = {"x\n"};
	char b[100] = {"x+y\n"};
	int i = 0;
	//scanf("%c", &a[i]);
	// while(a[i] != '\n'){
	// 	scanf("%c", &a[++i]);
	// }
	//PolyNode *p = Poly_Operation_Sub(Parse_Poly_List(b), Parse_Poly_List(a));
	// for(p;p!=NULL;p = p->next){
	// 	printf("node:%d %d %d\n", p->a, p->xPow, p->yPow);
	// }
    //printf("%d %d %d\n", p->a, p->xPow, p->yPow);
	//Print_List(p);
	//system("pause");
	ExpressionNode *ptr = NULL;
	ptr = Poly_Cal_Input();
	while(ptr[i].node != NULL || ptr[i].op != '\0'){
		if(ptr[i].node == NULL){
			printf("Test OP:%c\n", ptr[i].op);
		}else{
			printf("Test NODE:%d %d %d\n", ptr[i].node->a, ptr[i].node->xPow, ptr[i].node->yPow);
		}
		i++;
	}
	return 0;
}
