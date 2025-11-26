#include<stdio.h>
#include<stdlib.h>

void wait(int *s){(*s)--;}
void signal(int *s){(*s)++;}

int main(){
    int mutex=1,full=0,empty=3,x=0,ch;
    while(1){
        printf("\n1.Produce\n2.Consume\n3.Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                if(mutex==1&&empty!=0){
                    wait(&mutex);
                    signal(&full);
                    wait(&empty);
                    x++;
                    printf("Producer produces item %d\n",x);
                    signal(&mutex);
                }else{
                    printf("Buffer is full!\n");
                }
                break;
            case 2:
                if(mutex==1&&full!=0){
                    wait(&mutex);
                    signal(&empty);
                    wait(&full);
                    printf("Consumer consumes item %d\n",x);
                    x--;
                    signal(&mutex);
                }else{
                    printf("Buffer is empty!\n");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}