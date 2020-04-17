#include <stdio.h>
#include <stdlib.h>
int main()
{
  int Max[10][10], need[10][10], alloc[10][10], avail[10], completed[10], safeSequence[10];
  int p, r, i, j, thread, count;
  count = 0;
  printf("Enter the no of threads: ");
  scanf("%d", &p);
  for(i = 0; i< p; i++)
        completed[i] = 0;

    printf("\n\nEnter the no of resources : ");
    scanf("%d", &r);
    printf("\n\nEnter the Max Matrix for each thread : ");
    for(i = 0; i < p; i++)
    {
        printf("\nFor thread %d : ", i + 1);
        for(j = 0; j < r; j++)
            scanf("%d", &Max[i][j]);
    }
    printf("\n\nEnter the allocation for each thread: ");
    for(i = 0; i < p; i++)
    {
        printf("\nFor thread %d : ",i + 1);
        for(j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);
    }
    printf("\n\nEnter the Available Resources : ");
    for(i = 0; i < r; i++)
        scanf("%d", &avail[i]);
     for(i = 0; i < p; i++)

        for(j = 0; j < r; j++)
            need[i][j] = Max[i][j] - alloc[i][j];

        do
        {
            printf("\n Max matrix:\tAllocation matrix:\n");

            for(i = 0; i < p; i++)
            {
                for( j = 0; j < r; j++)
                    printf("%d ", Max[i][j]);
                printf("\t\t");
                for( j = 0; j < r; j++)
                    printf("%d ", alloc[i][j]);
                printf("\n");
            }

            thread = -1;

            for(i = 0; i < p; i++)
            {
                if(completed[i] == 0)//if not completed
                {
                    thread = i ;
                    for(j = 0; j < r; j++)
                    {
                        if(avail[j] < need[i][j])
                        {
                            thread = -1;
                            break;
                        }
                    }
                }
                if(thread != -1)
                    break;
            }

            if(thread != -1)
            {
                printf("\nthread %d runs to completion!", thread + 1);
                safeSequence[count] = thread + 1;
                count++;
                for(j = 0; j < r; j++)
                {
                    avail[j] += alloc[thread][j];
                    alloc[thread][j] = 0;
                    Max[thread][j] = 0;
                    completed[thread] = 1;
                }
            }
        }
        while(count != p && thread != -1);
        if(count == p)
         {
            printf("\nThe system is in a safe state!!\n");
            printf("Safe Sequence : < ");
            for( i = 0; i < p; i++)
                printf("%d ", safeSequence[i]);
            printf(">\n");
          }
         else
            printf("\nThe system is in an unsafe state!!");
}
