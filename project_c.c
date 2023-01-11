#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

struct sudo{
    int num;
    int status;
};
//function
int number(int *number4, int *number6){
    *number4 = 4; //pointer
    *number6 = 6;
}
//main program
int main(void)
{
    //File
    FILE *fp;
    fp = fopen("sudoku.txt","w");
    //เริ่มกำหนดตัวแปร
    int n_1 = 0,n_2 = 0;
    number(&n_1,&n_2); //pointer
    int sel,i,j,temp;
    int tempRow;
    char name[100];
    int isOK;

    struct sudo Sudoku[6][6];

    //เริ่มเกมหน้าแรกเพื่อบอกให้เริ่ม
    system("CLS");
    printf(" ''SUDOKU GAME''\n");
    printf(" Tables used by 4x4 and 6x6 with predefined fields.\n");
    printf(" Username: ");
    scanf("%s",&name);
    fprintf(fp," Username: %s\n",name);
    printf(" Welcome '%s' to Sudoku game\n",name);
    printf(" Select 1) 4x4 2) 6x6 : ");
    scanf("%d",&sel);
    fprintf(fp," %s select : %d \n",name,sel);
    fprintf(fp," The numbers %s put in...\n",name);
    switch(sel)
    {
        case 1 :
            //รูปแบบตัวเลขในตาราง
            Sudoku[0][0].num = 1; Sudoku[0][1].num = 2; Sudoku[0][2].num = 3; Sudoku[0][3].num = 4;
            Sudoku[1][0].num = 3; Sudoku[1][1].num = 4; Sudoku[1][2].num = 1; Sudoku[1][3].num = 2;
            Sudoku[2][0].num = 2; Sudoku[2][1].num = 1; Sudoku[2][2].num = 4; Sudoku[2][3].num = 3;
            Sudoku[3][0].num = 4; Sudoku[3][1].num = 3; Sudoku[3][2].num = 2; Sudoku[3][3].num = 1;

            //แสดงตัวเลขคำใบ้
            Sudoku[0][3].status = 1;
            Sudoku[1][0].status = 1;
            Sudoku[1][3].status = 1;
            Sudoku[2][1].status = 1;
            Sudoku[3][2].status = 1;

            do{
                //กำหนดค่าtemp
                tempRow = 1; isOK = 0;

                //ล้างหน้าจอ
                system("CLS");
                printf("\n");
                printf("       START GAME!!! \n");
                printf(" _______________________\n");

                //ตรวจสอบเงื่อนไขเพื่อสร้างตารางเกมส์
                for(i = 0; i < n_1; i++){
                    for(j = 0; j < n_1; j++){
                        if(Sudoku[i][j].status != 1){
                            printf("  *  |");
                        }
                        else{
                            printf("  %d  |",Sudoku[i][j].num);
                        }
                    }
                    printf("\n _______________________\n");
                }

                printf("\n     'Please enter a number'   \n");
                printf(" _______________________________\n");
                printf("\n");

                //เงื่อนไขเพื่อเล่นเกมส์โดยการป้อนตัวเลข
                for(i = 0; i < n_1; i++){
                    for(j = 0; j < n_1; j++){
                        temp = 0;
                        if(Sudoku[i][j].status != 1){
                            printf(" Please enter row %d, column %d : ",i+1,j+1);
                            scanf("%d",&temp);
                            fprintf(fp," %s enter row %d, column %d : %d\n",name,i+1,j+1,temp);

                            if(temp == Sudoku[i][j].num){
                                Sudoku[i][j].status = 1;
                            }
                        }
                    }
                }
                for(i = 0; i < n_1; i++){
                    for(j = 0; j < n_1; j++){
                        if((tempRow == 1) && (Sudoku[i][j].status == 1)){
                            tempRow = 1;
                        }
                        else{
                            tempRow = 0;
                        }
                    }
                }
                isOK = tempRow;
            }while(isOK != 1);

            //เล่นเกมส์สำเร็จ
            system("CLS");
            printf("\n\n");
            printf(" Congratulations '%s' win ^.^\n",name);
            printf(" You have answered all the questions.\n");
            break;

        case 2 :
                //รูปแบบตัวเลขในตาราง
            Sudoku[0][0].num = 3; Sudoku[0][1].num = 2; Sudoku[0][2].num = 4;
            Sudoku[0][3].num = 5; Sudoku[0][4].num = 6; Sudoku[0][5].num = 1;
            Sudoku[1][0].num = 1; Sudoku[1][1].num = 6; Sudoku[1][2].num = 5;
            Sudoku[1][3].num = 2; Sudoku[1][4].num = 4; Sudoku[1][5].num = 3;
            Sudoku[2][0].num = 4; Sudoku[2][1].num = 5; Sudoku[2][2].num = 1;
            Sudoku[2][3].num = 6; Sudoku[2][4].num = 3; Sudoku[2][5].num = 2;
            Sudoku[3][0].num = 6; Sudoku[3][1].num = 3; Sudoku[3][2].num = 2;
            Sudoku[3][3].num = 4; Sudoku[3][4].num = 1; Sudoku[3][5].num = 5;
            Sudoku[4][0].num = 2; Sudoku[4][1].num = 1; Sudoku[4][2].num = 6;
            Sudoku[4][3].num = 3; Sudoku[4][4].num = 5; Sudoku[4][5].num = 4;
            Sudoku[5][0].num = 5; Sudoku[5][1].num = 4; Sudoku[5][2].num = 3;
            Sudoku[5][3].num = 1; Sudoku[5][4].num = 2; Sudoku[5][5].num = 6;

            //แสดงตัวเลขคำใบ้
            Sudoku[0][0].status = 1; Sudoku[0][2].status = 1;
            Sudoku[0][4].status = 1; Sudoku[1][3].status = 1;
            Sudoku[1][5].status = 1; Sudoku[2][4].status = 1;
            Sudoku[2][2].status = 1; Sudoku[3][0].status = 1;
            Sudoku[3][3].status = 1; Sudoku[4][1].status = 1;
            Sudoku[4][3].status = 1; Sudoku[5][1].status = 1;
            Sudoku[5][2].status = 1; Sudoku[5][5].status = 1;
            do{
                //กำหนดค่าtemp
                tempRow = 1; isOK = 0;

                //ล้างหน้าจอ
                system("CLS");
                printf("\n");
                printf("            START GAME!!! \n");
                printf(" __________________________________\n");

                //ตรวจสอบเงื่อนไขเพื่อสร้างตารางเกมส์
                for(i = 0; i < n_2; i++){
                    for(j = 0; j < n_2; j++){
                        if(Sudoku[i][j].status != 1){
                            printf("  *  |");
                        }
                        else{
                            printf("  %d  |",Sudoku[i][j].num);
                        }
                    }
                    printf("\n __________________________________\n");
                }

                printf("\n       'Please enter a number'   \n");
                printf(" ___________________________________\n");
                printf("\n");

                //เงื่อนไขเพื่อเล่นเกมส์โดยการป้อนตัวเลข
                for(i = 0; i < n_2; i++){
                    for(j = 0; j < n_2; j++){
                        temp = 0;
                        if(Sudoku[i][j].status != 1){
                            printf(" Please enter row %d, column %d : ",i+1,j+1);
                            scanf("%d",&temp);
                            fprintf(fp," %s enter row %d, column %d : %d\n",name,i+1,j+1,temp);

                            if(temp == Sudoku[i][j].num){
                                Sudoku[i][j].status = 1;
                            }
                        }
                    }
                }
                for(i = 0; i < n_2; i++){
                    for(j = 0; j < n_2; j++){
                        if((tempRow == 1) && (Sudoku[i][j].status == 1)){
                            tempRow = 1;
                        }
                        else{
                            tempRow = 0;
                        }
                    }
                }
                isOK = tempRow;
            }while(isOK != 1);

            //เล่นเกมส์สำเร็จ
            system("CLS");
            printf("\n\n");
            printf(" Congratulations '%s' win ^.^\n",name);
            printf(" You have answered all the questions.\n");
            break;
    }
    return 0;
}

