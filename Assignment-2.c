 #include <stdio.h>

void input(int x[20][20], int r, int c)
{
    int i,j;

    printf("Enter elements:\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&x[i][j]);
        }
    }
}

int compact(int a[20][20],int b[20][20],int r, int c){
        b[0][0]=r;
    b[0][1]=c;
    int z=1;
    
    

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(a[i][j]!=0){
                b[z][0]=i;
                b[z][1]=j;
                b[z][2]=a[i][j];
                z++;
            }
        }
    }

    b[0][2]=z-1;

    return z-1;

}


void display(int x[20][20], int r, int c)
{
    int i,j;

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",x[i][j]);
        }
        printf("\n");
    }
}


void simplet(int b[20][20],int t1[20][20]){

    int i,j;
    int k=1;
    for(i=0;i<b[0][1];i++){
        for(j=1;j<=b[0][2];j++){
                if(b[j][1]==i){
                    t1[k][0]=b[j][1];
                    t1[k][1]=b[j][0];
                    t1[k][2]=b[j][2];
                    k++;

                }

        }
    }

    t1[0][0]=b[0][1];
    t1[0][1]=b[0][0];
    t1[0][2]=b[0][2];
    
}


void fastt(int b[20][20],int t2[20][20]){

    int i,j;
    
    int index[20];
    int count[20]={0};

    t2[0][0]=b[0][1];
    t2[0][1]=b[0][0];
    t2[0][2]=b[0][2];

    for(i=1;i<=b[0][2];i++){
        count[b[i][1]]++;

    }   

    index[0]=1;
    for(i=1;i<b[0][1];i++){
        index[i]=index[i-1]+count[i-1];
    }

    for(i=1;i<=b[0][2];i++){

        j=index[b[i][1]];

        t2[j][0]=b[i][1];
        t2[j][1]=b[i][0];
        t2[j][2]=b[i][2];

        index[b[i][1]]++;
    }

}


int main(){

    int a[20][20],b[20][20];
    int t1[20][20];
    int t2[20][20];
    int r,c;
    int choice;
    do{

        printf("Enter your choice: \n");
        printf("1.Input Matrix\n 2.Display Matrix\n 3.Display Compact form of Matrix\n 4.Display Simple Transpose of Compact form\n5.Display Complex Tranpose of Compact form\n6.Exit\n");
        scanf("%d",&choice);

        switch(choice){

            case 1:
            printf("Enter rows and columns of Matrix A: ");
            scanf("%d%d",&r,&c);    
            input(a,r,c);
            break;

            case 2:
            printf("Your input matrix is : \n");
            display(a,r,c);
            break;

            case 3:
            int x=compact(a,b,r,c);
            printf("The sparse matrix is : \n");
            display(b,x,3);
            break;

            case 4:
            printf("Simple transpose of matrix is : \n");
            simplet(b,t1);
            display(t1,x,3);
            break;
            
            case 5:
            printf("Fast transpose of matrix is : \n");
            fastt(b,t2);
            display(t2,x,3);
            break;

            default:
            printf("Exiting.");

        }
    }while(choice!=6);

}