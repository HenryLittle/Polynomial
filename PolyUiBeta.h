#ifndef _POLY_UI_BETA_H_
#define _POLY_UI_BETA_H_

#define WRONG_OPTION -1

#include "Global.h"
#include "InputParser.h"
#include "PolyOperator.h"
#include "PolyCal.h"

char WELCOME[400] = {
    "#####################################################\n"
    "# \\\\      /\\\\      /          ____________          #\n"
    "#  \\\\    /  \\\\    /           ||  \\____  |          #\n"
    "#   \\\\  /    \\\\  /        TO  ||__/ /  \\ |          #\n"
    "#    \\\\/      \\\\/ ElCOME      ||    \\__/ |___       #\n"
    "#                                    ----by Group33 #\n"
    "#####################################################\n"
};
char CHOOSE_INPUT[80] = {"Please choose your input mode:\n[n]:normal input\n[x]:complex input\n[0]:quit\n"};
char CHOOSE_OPERATION_ONE[190] = {"Choose your operation:\n[1]:input a polynomial\n[2]:add a polynomial\n\
[3]:substract a polynomial\n[4]:mutiplies a polynomial\n[5]:print current result\n[0]:quit program\n[h]:input requirements\n"};
char INPUT_TIP[80] = {"Please input your polynomial:\n(press enter when finish)\n"};
char ADD_TIP[100] = {"Input a polynomial that will be added to the current result\n"};
char SUB_TIP[100] = {"Input a polynomial that will be substracted from the current result\n"};
char MULTIPLY_TIP[100] = {"Input a polynomial that will be multiplied with the current result\n"};
char PARSE_RULES[350] = {"Must use '^' to indicate the power of x ro y, only in form like 'x^3'|'x' will be parsed correctly\n "
"each node expression can have at most 1 x and y (like 3x^3y|6|6y, but x^3xy will not be parsed correctly)\n"
"the '*' operand is optional. There can be any number of spaces between two node expressions\n"
"ForEXAMPLE: 'x +xy'|'y -   6x +  3'|'4x+y^2'\n"};

#endif // !_POLY_UILBETA_H_