#ifndef _INPUT_PARSER_H_
#define _INPUT_PARSER_H_

#include "DataStructure.h"

#define IS_DIGIT(a) (a <= '9' && a >= '0')  /* whether char a is a digit */
#define TO_INT(a) (a - '0')  /* convert char a to int */
#define IS_SIGN_OR_BLANK(a) (a == '+' || a == '-' || a == ' ')  /* whether char a is a ' ' or '+/-' */

/**
 *  \brief: parse a segment of string in to a node of polynomial
 *
 *  \param[in]  *str  the sting of the node to be parsed
 *  \param[in]  sign  the sign(-/+) of the node
 */
PolyNode *Parse_Poly_Node(char *str, int sign);

/**
 *  \brief: parse the whole input string into a list of polynomial
 *   '\n' means end of the input str
 *
 *  \param[in]  *str  the whole input string
 */
PolyNode *Parse_Poly_List(char *str);

#endif  // !_INPUT_PARSER_H_