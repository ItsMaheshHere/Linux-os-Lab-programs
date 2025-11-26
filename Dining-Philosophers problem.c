#include<stdio.h>
#include<stdlib.h>
int main(){
    int state[5];
    int i,ch,left,right;
    int chopstick[5]={1,1,1,1,1};
    while(1){
        printf("\n1.Pick up chopsticks (Eat)\n2.Put down chopsticks (Think)\n3.Exit\nEnter philosopher number (1-5): ");
        scanf("%d",&i);
        if(i==3){
            printf("Exiting...\n");
            break;
        }
        if(i<1||i>5){
            printf("Invalid philosopher number!\n");
            continue;
        }
        i--;
        left=i;
        right=(i+1)%5;
        printf("1. Eat\n2. Think\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                if(chopstick[left]==1&&chopstick[right]==1){
                    chopstick[left]=0;
                    chopstick[right]=0;
                    state[i]=2;
                    printf("Philosopher=%d eating,chopsticks=%d and %d\n",i+1,left+1,right+1);
                }else{
                    state[i]=1;
                    printf("Philosopher=%d hungry\n",i+1);
                }
                break;
            case 2:
                if(state[i]==2){
                    chopstick[left]=1;
                    chopstick[right]=1;
                    state[i]=0;
                    printf("Philosopher=%d puts down chopsticks %d and %d and starts thinking\n",i+1,left+1,right+1);
                }else{
                    printf("Philosopher %d was not eating\n",i+1);
                }
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}