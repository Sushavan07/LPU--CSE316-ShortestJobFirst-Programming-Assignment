#include<stdio.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/queue.h>
struct process
{
    int pid;     //process id
    float AT;       //arrival time
    float BT;       //burst time
    float WT;       // waiting time 
    float priority; //priority
    int status;        //status 
    float TT;            //turnaround time
    float CC;           //completion time

    // status 0 : not available
    // status 1 : ready state
    // ststus 2 : processed
};

int main()
{
    printf("\n ************************* SHORTEST JOB SCHEDULING ALLGORITHM PROJECT ***********************************");
    printf("\n\n\n enter the number of processes you want to schedule :  ");
    int number;
    scanf("%d",&number);
    struct process proc[number];
    
    printf("\n enter the burst time of the processes \n");
 
    for(int i=0;i<number;i++)
    {
        printf("\n enter the burst time for the %d process  :  ",i+1);
        scanf("%f",&proc[i].BT);
        proc[i].pid=i+1;
        proc[i].status=0;
    }

    printf("\n enter the arival time of the processes \n");
    for(int i=0;i<number;i++)
    {
        printf("\n enter the arival time for the %d process  :  ",i+1);
        scanf("%f",&proc[i].AT);
    }

   // system("cls");
     
    printf("\n Process:     |   Burst Time:     |   Arival Time:     | ");
    for(int i=0;i<number;i++)
    {
        printf("\n   %d               %d                   %d      ",proc[i].pid,(int )proc[i].BT,(int )proc[i].AT);
    }
    printf("\n");
    for(int i=0;i<number;i++)
    {
        proc[i].WT=0;
    }

    int max_at=0;
    for(int i=0;i<number;i++)
    {
        if((int)proc[i].AT>max_at)
        {
            max_at=(int)proc[i].AT;
        }
    }    
 
 //   printf("\n max is %d ",max);

   int timer=0;
   int j=0;
   int seq[number];

    for (timer=0;timer<=max_at;timer++)
    {
        for(int i=0;i<number;i++)
        {
            if(timer>=(int)proc[i].AT)
            {
                if(proc[i].status==0)
                {
                    seq[j++]=proc[i].pid;
                    proc[i].status=1;
                }
            }
        }
    }
    printf("\n\n\n");

   


    int final_sequence[number];
    final_sequence[0]=seq[0];
    int n;
    n=number;
    int order[n][n];
 
//    order[0][]=seq;
    for(int i=0;i<n;i++)
    {
        order[0][i]=seq[i];
    }

int next_index;
float min=9999.00;
timer=0;
timer=proc[order[0][0]].AT;
int i=0;
    while(n--)
    {
        final_sequence[i]=order[i][0];
           proc[i].status=2;
           timer=timer+proc[i].BT;

            proc[i].CC=(float)timer;
          
           for(int j=0;j<number;j++);
           {
                if(proc[j].status==1)
                {
                    if(proc[j].WT==0)
                    {
                         proc[j].WT=proc[i].BT - proc[j].AT;     
                    }
                    else
                    {
                    proc[j].WT=proc[j].WT+proc[i].BT;
                    }
                }
           }

           i++;

           for(int k=0;k<number;k++)
           {
               if(proc[k].status==1)
               {
                   proc[k].priority=1+ (proc[k].WT) / (proc[k].BT) ;
               }
            }

            for(int l=0;l<number;l++)
            {
                   if( (timer > proc[l].AT) && ( proc[l].status==1 ) )
                   {
                        if(min > proc[l].priority)
                        {
                            min=proc[l].priority;
                            next_index=l;
                        }
                   }
            }
            int z=1;
            for(int j=0;j<number;j++)
            {
                if(j==0)
                {
                    order[i][0]=next_index+1;
                }
                else
                {
                    if(proc[j].status==1)
                    {
                           order[i][z]=proc[j].pid; 
                           z++; 
                    }
                }
            }


            for(int i=0;i<number;i++)
        	{
        		if(proc[i].status==0)
        		{
        			if(timer >= proc[i].AT )
        			{
        				proc[i].status=1;
					}
				}
			}
           
    }

 
    
    int total_wt=0;
    for(int i=0;i<number;i++)
    {
        total_wt=total_wt+proc[i].WT;
    }

    int total_at=0;
    for(int i=0;i<number;i++)
    {
        total_at=total_at+proc[i].AT;
    }

    printf("\n the final scheduled order in shortest job first are as follow \n\n");

    printf("status :--   NOT COMPLETE == NCM \n");
    printf("status :--   COMPLETE     == CM \n");
 //   printf("status :--   COMPLETE  == CM \n");

    printf("\n\n");

    printf(" Process      :    ");
   // int z=number-1;
    for(int i=0;i<number;i++)
    {
        printf("    P%d    ",final_sequence[i]);
    }
    printf("\n\n");
    printf(" waiting time :    ");
    for(int i=0;i<number;i++)
    {
        printf("    %d    ",(int)proc[final_sequence[i]].WT);
    }
    printf("\n\n");
    printf(" arrival time :    ");
    for(int i=0;i<number;i++)
    {
        printf("    %d    ",(int)proc[final_sequence[i]].AT);
    }
    printf("\n\n");
    
    printf(" Complete time:    ");
    for(int i=0;i<number;i++)
    {
        printf("    %d    ",(int)proc[final_sequence[i]].CC);
    }
    printf("\n\n");
    
    printf(" status       :    ");
    for(int i=0;i<number;i++)
    {
        if((int)proc[final_sequence[i]].status==2)
        printf("    CM    ");
    }
    printf("\n\n");

    printf("\n\n");

    float avg_wt;
    avg_wt=total_wt/number;
    printf("AVERAGE WAITING TIME  : %f \n\n",avg_wt);
    printf("\n\n\n");

        }
