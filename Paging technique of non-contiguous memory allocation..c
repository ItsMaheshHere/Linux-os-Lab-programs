#include<stdio.h>
#include<stdlib.h>
int main(){
    int ms,ps,np,nf,i,j;
    int s[10],fno[10][10];
    printf("Enter memory size: ");
    scanf("%d",&ms);
    printf("Enter page size: ");
    scanf("%d",&ps);
    nf=ms/ps;
    printf("Number of frames available=%d\n",nf);
    printf("Enter number of processes: ");
    scanf("%d",&np);
    for(i=0;i<np;i++){
        int pages;
        printf("Enter no. of pages for P %d: ",i+1);
        scanf("%d",&pages);
        if(pages>nf){
            printf("Not enough memory for P %d\n",i+1);
            s[i]=-1;
        }else{
            s[i]=pages;
            nf-=pages;
            printf("Enter frame no. P %d:\n",i+1);
            for(j=0;j<pages;j++){
                scanf("%d",&fno[i][j]);
            }
        }
    }
    while(1){
        int pno,pgn;
        printf("\nEnter P no. and page no. to access (-1 to exit): ");
        scanf("%d",&pno);
        if(pno==-1)break;
        printf("Enter page no. : ");
        scanf("%d",&pgn);
        if(s[pno-1]==-1){
            printf("P %d not loaded into memory\n",pno);
        }else if(pgn>=s[pno-1]){
            printf("Invalid page no. for P %d\n",pno);
        }else{
            int physaddr=fno[pno-1][pgn]*ps;
            printf("Physical address=Frame %d, Starting address=%d\n",fno[pno-1][pgn],physaddr);
        }
    }
    return 0;
}