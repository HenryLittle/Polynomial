#ifndef _POLY_UI_BETA_H_
#define _POLY_UI_BETA_H_

#define WRONG_OPTION -1

#include "Global.h"
#include "InputParser.h"
#include "PolyOperator.h"
#include "PolyCal.h"

char CHOOSE_INPUT[80] = {"Please choose your input mode:\n[n]:normal input\n[x]:complex input\n[0]:quit\n"};
char CHOOSE_OPERATION_ONE[170] = {"Choose your operation:\n[1]:input a polynomial\n[2]:add a polynomial\n[3]:substract a polynomial\n[4]:mutiplies a polynomial\n[5]:print current result\n[0]:quit program\n"};
char CHOOSE_OPERATION_TWO[100] = {"Choose your operation:\n[2~4]:continue calulation with ans\n[1]:restart the program\n[0]:quit\n"};
char INPUT_TIP[80] = {"Please input your polynomail:\n(press enter when finish)\n"};
char ADD_TIP[100] = {"Input a polynomial that will be added to the current result\n"};
char SUB_TIP[100] = {"Input a polynomial that will be substracted from the current result\n"};
char MULTIPLY_TIP[100] = {"Input a polynomial that will be multiplied with the current result\n"};

#endif // !_POLY_UILBETA_H_