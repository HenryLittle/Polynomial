#include "Global.h"
#include "DataStructure.h"

PolyNode *Add_Poly_Node(PolyNode *head, PolyNode *p, int mode)
{
    //0 add to first
    //1 add to tail
    //2 add with seq
    PolyNode *ptr;
    ptr = head;
    if(head == NULL){
        return p;
    }
    switch (mode) {
        case 0:
        //add to first
            p->next = head;
            p->prev = NULL;
            ptr = p;
            break;
        case 1:
        //add to last
            while(head->next != NULL){
                head = head->next;
            }
            head->next = p;
            p->next = NULL;
            p->prev = head;
            break;
        case 2:
        //add with seq
            Add_Poly_Seq(head, p);
            break;
        default:
            p->next = head;
            p->prev = NULL;
            head = p;
            break;
    }
    return ptr;
}

PolyNode *Add_Poly_Seq(PolyNode *head, PolyNode *p)
{
    //todo:
    //add the node of the polynomial follow power decent
    int a, xPow, yPow, position;
    a = p->a;
    xPow = p->xPow;
    yPow = p->yPow;
    PolyNode *ptr;
    ptr = head;
    if(head == NULL){
        head = p;
        p->prev = NULL;
        p->next = NULL;
        return head;
    }
    position = 0;
    while(ptr != NULL){
        position ++;
        int ai, xPi, yPi;
        ai = ptr->a;
        xPi = ptr->xPow;
        yPi = ptr->yPow;
        if(xPi == xPow && yPi == yPow){
            //merge
            ptr->a = ai + a;
            return head;
        }else if (xPi < xPow) {
			//in the front
			//if it's the first node
			if (1 == position) {
				ptr->prev = p;
				p->prev = NULL;
				p->next = ptr;
				head = p;
				return head;
			}
			else {
				ptr->prev->next = p;
				p->prev = ptr->prev;
				p->next = ptr;
				ptr->prev = p;
				return head;
			}
		}else if (xPi == xPow && yPi < yPow) {
			//in the front
			//if it's the first node
			if (1 == position) {
				ptr->prev = p;
				p->prev = NULL;
				p->next = ptr;
				head = p;
				return head;
			}
			else {
				ptr->prev->next = p;
				p->prev = ptr->prev;
				p->next = ptr;
				ptr->prev = p;
				return head;
			}
		}
		else if (xPi == xPow && yPi > yPow) {
			//behind
			//check the latter node
			if (ptr->next == NULL) {
				//if it is the last node
				p->next = NULL;
				p->prev = ptr;
				ptr->next = p;
				return head;
			}
			else {
				//if it is in the middle
				//dodge it change it to the previous(front) case
				ptr = ptr->next;
				continue;
			}
	    }else if(xPi > xPow){
            //behind
            //check the latter node
            if(ptr->next == NULL){
                //if it is the last node
                p->next = NULL;
                p->prev = ptr;
                ptr->next = p;
                return head;
            }else{
                //if it is in the middle
                //dodge it change it to the previous(front) case
                ptr = ptr->next;
                continue; 
            }
        }else if(IS_CONST_NODE){
            //what to do if node p is a constant
            return Add_Poly_Node(head, p, 2);
        }else if(xPi <= xPow && yPi < yPow){
            //in the front
            //if it's the first node
            if(1 == position){
                ptr->prev = p;
                p->prev = NULL;
                p->next = ptr;
                head = p;
                return head;
            }else{
                ptr->prev->next = p;
                p->prev = ptr->prev;
                p->next = ptr;
                ptr->prev = p;
                return head;
            }
        }else{
            ptr = ptr->next;
        }
    }
    return head;
}

void Print_List(PolyNode *head)
{
    //s -> simple print
    //c -> complete print
    //set simple print to default
    int isFirst = 1;
    for(head; head != NULL; head = head->next){
        int a, xPow, yPow;
        a = head->a;
        xPow = head->xPow;
        yPow = head->yPow;
        //if a is 0
        if(a == 0){
            continue;
        }
        //print a
        if(a > 0 && !isFirst) printf("+");
        if(1 != a && -1 != a && !IS_CONST_NODE){
            printf("%d", a);
        }else if(IS_CONST_NODE){
            printf("%d", a);
        }else if(-1 == a && !IS_CONST_NODE){
            printf("-");
        }
        //print x
        if(1 == xPow){
            printf("x");
        }else if(0 != xPow){
            printf("x^%d", xPow);
        }
        //print y
        if(1 == yPow){
            printf("y");
        }else if(0 != yPow){
            printf("y^%d", yPow);
        }
        if(isFirst) isFirst = 0;
    }
}
