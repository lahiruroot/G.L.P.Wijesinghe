#include <stdio.h>

int main(){
    int park[5][5];
    int i;
    for(i=0; i<5; i++){
        int j;
        for(j=0;j<5;j++){
            park[i][j]=-1;
        }
    }

    int cmd=0;


    while(cmd!=-1){
        printf("Enter command : ");
        scanf("%d",&cmd);
        switch(cmd){
        case 1:
                printf("The available slots are : ");
                int i;
                for(i=0; i<5; i++){
                    int j;
                    for(j=0;j<5;j++){
                        if(park[i][j]==-1){
                            printf("%d, ",(5*i+5*j));
                        }
                    }
                }
                printf("\n");
                break;
        case 2:
                printf("Enter slot number : ");
                int slot;
                scanf("%d",&slot);


                printf("Enter car reg-number : ");
                int carNum;
                scanf("%d",&carNum);

                park[slot/5][slot%5] = carNum;

                printf("Slot : %d\nCar Reg Number : %d\n",slot,park[slot/5][slot%5]);
                break;
        case 3:
                printf("Enter slot to free :");
                int toFree;
                scanf("%d",&toFree);
                park[slot/5][slot%5] = -1;
                break;
        case -1:
                return;
        default:
            printf("Wrong command!\n");
            break;
        }

    }

    return 0;
}
