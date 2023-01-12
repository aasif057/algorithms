#include<stdio.h>

void knapsack(int n, float profit[], float weight[], float capacity)
{
    float vec[20], max_profit=0,u;
    int i, j;
    u = capacity;

    for(i=0;i<n;i++){
        vec[i]=0.0;

    }
    for(i=0;i<n;i++){
        if(weight[i] > u)
            break;
        else
        {
            vec[i] = 1.0;
            max_profit = max_profit + profit[i];
            u = u - weight[i];
            printf("item no %d, profit%.2f, weight%.2f, curr_weight%d\n",  i+1,profit[i],weight[i],u);
        }
    }
    if(i<n){
        vec[i] = u/weight[i];
        max_profit = max_profit + (vec[i]*profit[i]);
        printf("item no %d, profit%.2f, weight%.2f\n",  i+1,profit[i],vec[i]*weight[i]);
    }
    printf("The maximum profit is %f", max_profit);
}

int main(){
    float profit[20], weight[20];
    int n,i,j;
    float capacity,temp;
    float ratio[20];

    printf("Enter the number of items in knapsack: ");
    scanf("%d", &n);

    printf("Enter the weight and profit of knapsack\n");
    for(i=0;i<n;i++){
        printf("Enter weight of item%d: ",i+1);
        scanf("%f", &weight[i]);
        printf("Enter profit of item%d: ",i+1);
        scanf("%f", &profit[i]);
        printf("/n");
    }

    printf("Enter capacity of knapsack: ");
    scanf("%f", &capacity);

    for(i=0;i<n;i++){
        ratio[i]=profit[i]/weight[i];
    }

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if (ratio[i]<ratio[j]){
                
                temp = ratio[j];
                ratio[j]=ratio[i];
                ratio[i]=temp;

                temp = profit[j];
                profit[j]=profit[i];
                profit[i]=temp;

                temp = weight[j];
                weight[j]=weight[i];
                weight[i]=temp;
            }
        }
    }
    knapsack(n, profit, weight, capacity);
    return 0;
}