#include<stdio.h>
#include<stdlib.h>

int main()
{
      int queue1[6760], queue2[6760],queue3[6760];
      int limit, disk_head, count = 0, j, seek_time =4999 , range, diff;
      int t1, t2 = 0, t3 = 4999;
      float avg_seek_time;
      printf("Maximum Range of Disk:\t");
      scanf("%d", &range);
      printf("Initial Head Request Position:\t");
      scanf("%d", &disk_head);
      printf(" Enter Queue Request Size:\t");
      scanf("%d", &limit);
      printf("Enter Disk Queue Element Positions:\n");
      while(count < limit)
      {
            scanf("%d", &t1);
            if(t1 >= disk_head)
            {
                  queue1[t2] = t1;
                  t2++;
            } 
            else
            {
                  queue2[t3] = t1;
                  t3++;
            }
            count++;
      }
      count = 0;
      while(count < t2 - 1)
      {
            j = count + 1;
            while(j < t2)
            {
                  if(queue1[count] > queue1[j])
                  {
                        t1 = queue1[count];
                        queue1[count] = queue1[j];
                        queue1[j] = t1;
                  }
                  j++;
            }
            count++;
      }
      count = 0;
      while(count < t3 - 1)
      {
            j = count + 1;
            while(j < t3)
            {
                  if(queue2[count] > queue2[j])
                  {
                        t1 = queue2[count];
                        queue2[count] = queue2[j];
                        queue2[j] = t1;
                  }
                  j++;
            }
            count++;
      }
      count = 1;
      j = 0;
      while(j < t2)
      {
            queue3[count] = queue1[j];
            queue3[count] = range;
            queue3[count + 1] = 0;
            count++;
            j++;
      }
      count = t2 + 3;
      j = 0;
      while(j < t3)
      {
            queue3[count] = queue2[j];
            queue3[0] = disk_head;
            count++;
            j++;
      }
