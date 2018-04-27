#include "PolyUiBeta.h"
#include "Global.h"
#include <windows.h>
#include <conio.h>

PolyNode *Poly_Ui_Input()
{
    char str[200];
    int i = 0;
    scanf("%c", &str[i]);
    while(str[i] != '\n'){
        scanf("%c", &str[++i]);
    }
    return Parse_Poly_List(str);
}

int Get_Option()
{
    int ascii;
    ascii = getch();
    if(-1 == ascii){
        printf("Error Input\n");
    }else if('0' <= ascii && '5' >= ascii){
        return ascii - '0';
    }else if('h' == ascii){
        return ascii;
    }else{
        printf("Uhn, not in option\n");
    }
    return WRONG_OPTION;
}

int main()
{
    // a welcome here, maybe?
    //TODO Done add the welcome view
    printf(WELCOME);
    system("pause");
    // some preparation
    PolyNode *ans = NULL, *polyNode = NULL;
    // init a looper
    while(1){
        system("cls");
        printf(CHOOSE_OPERATION_ONE);
        int option;
        option = Get_Option();
        if(WRONG_OPTION != option){
            //printf("%d", option);
        }else{
            printf("Please choose again.\n");
            Sleep(400);
            system("cls");
            continue;
        }
        // handle the options
        int i;
        switch(option){
            case 0:
                // a small exiting animation
                printf("Exiting ");
                for(i = 1; i <= 6; i ++){
                    Sleep(200);
                    printf(". ");
                }
                printf("\n");
                exit(0);
                break;
            case 1:
            // input a polynomial
                system("cls");
                printf(INPUT_TIP);
                ans = Poly_Ui_Input();
                continue;
                break;
            case 2: 
            // add operation
                system("cls");
                printf(ADD_TIP);
                polyNode = Poly_Ui_Input();
                ans = Poly_Operation_Add(ans, polyNode);
                continue;
                break;
            case 3: 
            // substract operation
                system("cls");
                printf(SUB_TIP);
                polyNode = Poly_Ui_Input();
                ans = Poly_Operation_Sub(ans, polyNode);
                continue;
                break;
            case 4: 
            // multiply operation
                system("cls");
                printf(MULTIPLY_TIP);
                polyNode = Poly_Ui_Input();
                ans = Poly_Operation_Multiply(ans, polyNode);
                continue;
                break;
            case 5: 
            // print the result
                if(ans == NULL){
                    printf("Empty polynomial :\n(Input one?)\n");
                }else{
                    Print_List(ans);
                    printf("\n");
                }
                system("pause");
                continue;
                break;
            case 'h':
            // print input requirments
                system("cls");
                printf(PARSE_RULES);
                system("pause");
                continue;
                break;
            default: break;
        }
    }
}