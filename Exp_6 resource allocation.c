#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char jobName[20];    
    int resourceNeeded;  
    int profit; 
}Task;
	         

// Comparison function to sort tasks by their profit-to-resource ratio in descending order
int compare(const void *a, const void *b) {
    Task taskA = *(Task *)a;
    Task taskB = *(Task *)b;

    double ratioA = (double)taskA.profit / taskA.resourceNeeded;
    double ratioB = (double)taskB.profit / taskB.resourceNeeded;

    if (ratioA < ratioB) return 1;
    else if (ratioA > ratioB) return -1;
    else return 0;
}

void efficientResourceAllocation(Task tasks[], int n, int totalResources) {
   qsort(tasks, n, sizeof(Task), compare);

    printf("Allocated Jobs: [");
    int totalProfit = 0;
    int resourcesUsed = 0;
    int firstJob = 1;
    int i;
    for ( i = 0; i < n; i++) {
        if (resourcesUsed + tasks[i].resourceNeeded <= totalResources) {
            
            if (!firstJob) {
                printf(", ");
            }
            printf("'%s'", tasks[i].jobName);
            firstJob = 0;
            resourcesUsed += tasks[i].resourceNeeded;
            totalProfit += tasks[i].profit;
        }
    }
    printf("]\n");

    printf("Total Profit: %d\n", totalProfit);
    printf("Total Resources Used: %d (out of %d)\n", resourcesUsed, totalResources);
}

int main() {
    int n,i, totalResources;

    printf("Enter the number of Jobs: ");
    scanf("%d", &n);

    printf("Enter the total resources available: ");
    scanf("%d", &totalResources);

    Task tasks[n];

    for ( i = 0; i < n; i++) {
        printf("Enter job name, resource needed, and profit for Jobs %d: ", i + 1);
        scanf("%s %d %d", tasks[i].jobName, &tasks[i].resourceNeeded, &tasks[i].profit);
    }

   
    efficientResourceAllocation(tasks, n, totalResources);

    return 0;
}
