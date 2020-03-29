#include<stdio.h>
#include<conio.h>


int ARRIVAL_TIME1[20],ARRIVAL_TIME2[20],PRIORITY2[20],PROCESS2[20],ARRIVAL_TIME3[20];
int BURST_TIME1[20],BURST_TIME2[20],BURST_TIME3[20];

int Total=0,t1=0,t2=0,t3=0;

int n,i,arrival_time[20],burst_time[20],priority[20],j=0,k=0,l=0;

int total,x,temp[20],counter=0;
float AVG_WAITING_TIME1=0.0,AVG_TURNAROUND_TIME1=0.0;

int p,WAITING_TIME3[20],TURNAROUND_TIME3[20];
float AVG_WAITING_TIME3=0.0,AVG_TURNAROUND_TIME3=0.0;

int pos,q,temp1,sum=0,WAITING_TIME2[20],TURNAROUND_TIME2[20];
float AVG_WAITING_TIME2,AVG_TURNAROUND_TIME2;

void ROUND_ROBIN()
{   
    printf("\n================================================================================\n");
	printf("Round Robin Algoritm is executing and time quantum is 4\n ");
	printf("\n================================================================================\n"); 
	printf("\nTime Quantum for Queue1 is 4\n");
	for(i=0;i<j;i++)
	{
		temp[i]=BURST_TIME1[i];
	} 
	printf("\n================================================================================\n");
	printf("\nProcess ID\tBurst Time\t Turnaround Time\t Waiting Time\n");
	printf("\n================================================================================\n");
	x=j;
    for(i=0,total=0;x!=0;) 
    { 
    	if(temp[i]<=4 && temp[i]>0) 
        {
			printf("\nProcess[%d] of Queue1 is running for %d units",i+1,temp[i]); 
            total=total+temp[i]; 
            temp[i]=0; 
            counter=1;         
		} 
        else if(temp[i]>0) 
        {
			printf("\nProcess[%d] of Queue1 is running for 4 units",i+1); 
            temp[i]=temp[i]-4; 
            total=total+4; 
        } 
        if(temp[i]==0 && counter==1) 
        { 
            x--; 
            printf("\nProcess[%d]\t%d\t%d\t%d",i+1,BURST_TIME1[i],total-ARRIVAL_TIME1[i],total-ARRIVAL_TIME1[i]-BURST_TIME1[i]);
            AVG_WAITING_TIME1=AVG_WAITING_TIME1+total-ARRIVAL_TIME1[i]-BURST_TIME1[i]; 
            AVG_TURNAROUND_TIME1=AVG_TURNAROUND_TIME1+total-ARRIVAL_TIME1[i]; 
            counter = 0; 
        } 
        if(i==j-1) 
        {
            i=0; 
        }
        else if(ARRIVAL_TIME1[i+1]<=total) 
        {
            i++;
        }
        else 
        {
            i=0;
        }
    } 
    AVG_WAITING_TIME1=AVG_WAITING_TIME1/j;
    AVG_TURNAROUND_TIME1=AVG_TURNAROUND_TIME1/j;
    printf("\nAverage Waiting Time :%f",AVG_WAITING_TIME1); 
    printf("\nAverage Turnaround Time :%f\n",AVG_TURNAROUND_TIME1); 
}

void ROUND_ROBIN1()
{
	printf("\n================================================================================\n");
	printf("Round Robin1 Algoritm is executing and time quantum is 10\n ");
	printf("\n================================================================================\n");
	printf("\nTime Quantum between the 3 queues is 10\n");
	for(i=1;i<Total;i=i+10)
	{
		if(t1>10)
		{
			printf("Queue 1 is running for 10 units\n");
			t1=t1-10;
			printf("Queue 1 is running for %d units\n",t1);
		}
		else if(t1<=10 && t1!=0)
		{
			printf("Queue 1 is running for %d units\n",t1);
			t1=0;
		}
		if(t2>10)
		{
			printf("Queue 2 is running for 10 units\n");
			t2=t2-10;
			printf("Queue 2 is running for %d units\n",t2);
		}
		else if(t2<=10 && t2!=0)
		{
			printf("Queue 2 is running for %d units\n",t2);
			t2=0;
		}
		if(t3>10)
		{
			printf("Queue 3 is running for 10 units\n");
			t3=t3-10;
			printf("Queue 3 is running for %d units\n",t3);
		}
		else if(t3<=10 && t3!=0)
		{
			printf("Queue 3 is running for %d units\n",t3);
			t3=0;
		}
	}
}

void FCFS()
{
	printf("\n================================================================================\n");
	printf("Fisrt Come First Serve algorithm is executing\n");
	printf("\n================================================================================\n\n");
	WAITING_TIME3[0] = 0;   
    for(i=1;i<l;i++)
    {
        WAITING_TIME3[i] = 0;
        for(p=0;p<l;p++)
        {
            WAITING_TIME3[i]=WAITING_TIME3[i]+BURST_TIME3[p];
        }
    }
    printf("\n================================================================================\n");
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    printf("\n================================================================================\n\n");
	for(i=0;i<l;i++)
    {
        TURNAROUND_TIME3[i]=BURST_TIME3[i]+WAITING_TIME3[i];
        AVG_WAITING_TIME3=AVG_WAITING_TIME3+WAITING_TIME3[i];
        AVG_TURNAROUND_TIME3=AVG_TURNAROUND_TIME3+TURNAROUND_TIME3[i];
        printf("\nProcess[%d]\t\t%d\t\t%d\t\t%d\n",i+1,BURST_TIME3[i],WAITING_TIME3[i],TURNAROUND_TIME3[i]);
    }
    AVG_WAITING_TIME3=AVG_WAITING_TIME3/l;
    AVG_TURNAROUND_TIME3=AVG_TURNAROUND_TIME3/l;
    printf("\nAverage Waiting Time=%f",AVG_WAITING_TIME3);
    printf("\nAverage Turnaround Time=%f",AVG_TURNAROUND_TIME3);
    for(i=0;i<l;i++)
    {
    	while(BURST_TIME3[i]!=0)
    	{
    		if(BURST_TIME3[i]>10)
    		{
				printf("\nProcess[%d] of Queue3 is running for 10 units",i+1);
				BURST_TIME3[i]=BURST_TIME3[i]-10;
			}
			else if(BURST_TIME3[i]<=10)
			{
				printf("\nProcess[%d] of Queue2 is running for %d units",i+1,BURST_TIME3[i]);
				BURST_TIME3[i]=0;
			}
		}
	}
}

void PRIORITY()
{   printf("\n================================================================================\n");
	printf("Priority Scheduling algorithm is executing\n");
	printf("\n================================================================================\n\n");
	for(i=0;i<k;i++)
    {
        pos=i;
        for(q=i+1;q<k;q++)
        {
            if(PRIORITY2[q]<PRIORITY2[pos])
            {
                pos=q;
            }
        }
        temp1=PRIORITY2[i];
        PRIORITY2[i]=PRIORITY2[pos];
        PRIORITY2[pos]=temp1; 
        
        temp1=BURST_TIME2[i];
        BURST_TIME2[i]=BURST_TIME2[pos];
        BURST_TIME2[pos]=temp1;
        
        temp1=PROCESS2[i];
        PROCESS2[i]=PROCESS2[pos];
        PROCESS2[pos]=temp1;
    }
    WAITING_TIME2[0]=0;
    for(i=1;i<k;i++)
    {
        WAITING_TIME2[i]=0;
        for(q=0;q<i;q++)
        {
            WAITING_TIME2[i]=WAITING_TIME2[i]+BURST_TIME2[j];
        }
        sum=sum+WAITING_TIME2[i];
    }
    AVG_WAITING_TIME2=sum/k;
    sum=0;
    printf("\n================================================================================\n");
    printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
    printf("\n================================================================================\n");
    for(i=0;i<k;i++)
    {
    	TURNAROUND_TIME2[i]=BURST_TIME2[i]+WAITING_TIME2[i];
        sum=sum+TURNAROUND_TIME2[i];
        printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\n",PROCESS2[i],BURST_TIME2[i],WAITING_TIME2[i],TURNAROUND_TIME2[i]);
    }
    AVG_TURNAROUND_TIME2=sum/k;
    printf("\nAverage Waiting Time:\t%f",AVG_WAITING_TIME2);
    printf("\nAverage Turnaround Time:\t%f\n",AVG_TURNAROUND_TIME2);
    
    for(i=0;i<k;i++)
    {
    	while(BURST_TIME2[i]!=0)
    	{
    		if(BURST_TIME2[i]>10)
    		{
				printf("\nProcess[%d] of Queue2 is running for 10 units",i+1);
				BURST_TIME2[i]=BURST_TIME2[i]-10;
			}
			else if(BURST_TIME2[i]<=10)
			{
				printf("\nProcess[%d] of Queue2 is running for %d units",i+1,BURST_TIME2[i]);
				BURST_TIME2[i]=0;
			}
		}
	}

}

int main()
{   printf("\n================================================================================\n");
	printf("\t\t\tMULTILEVEL QUEUE SCHEDULING\n ");
	printf("\n================================================================================\n");
	printf("Enter the number of process you want to enter\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter details of process[%d]\n",i+1);
		printf("Enter ARRIVAL TIME of Process[%d]:",i+1);
		scanf("%d",&arrival_time[i]);
		printf("Enter BURST TIME of Process[%d]:",i+1);
		scanf("%d",&burst_time[i]);
		printf("Enter PRIORITY(1 to 15) of Process[%d]:",i+1);
		scanf("%d",&priority[i]);
		Total=Total+burst_time[i];
    }
    
    printf("\n================================================================================\n");
	printf("Details of Process:\n");
	
	printf("\nProcess ID\t\tARRIVAL TIME\t BURST TIME\t PRIORITY\n");
	printf("\n================================================================================\n");
    for(i=0;i<n;i++)
    {
		printf("\nPROCESS[%d]\t\t%d\t\t%d\t\t%d\n",i+1,arrival_time[i],burst_time[i],priority[i]);
	}
	for(i=0;i<n;i++)
	{
		if(priority[i]>=1 && priority[i]<=5)
		{
			printf("\n\nProcess[%d] belongs to Queue 1(HIGHEST PRIORITY)\n",i+1);
			ARRIVAL_TIME1[j]=arrival_time[i];
			BURST_TIME1[j]=burst_time[i];
			j++;
			t1=t1+burst_time[i];
			ROUND_ROBIN();
		}
		
		else if(priority[i]>=6 && priority[i]<=10)
		{
			printf("\nProcess[%d] belongs to Queue 2(MEDIUM PRIORITY)\n",i+1);
			ARRIVAL_TIME2[k]=arrival_time[i];
			BURST_TIME2[k]=burst_time[i];
			PRIORITY2[k]=priority[i];
			PROCESS2[k]=k+1;
			k++;
			t2=t2+burst_time[i];
			PRIORITY();
		}
		
		else if(priority[i]>=11 && priority[i]<=15)
		{
			printf("\nProcess[%d] belongs to Queue 3(LEAST PRIORITY)\n",i+1);  
			ARRIVAL_TIME3[l]=arrival_time[i];
			BURST_TIME3[l]=burst_time[i];
			l++;
			t3=t3+burst_time[i];
			FCFS();
		}
	}
	
	ROUND_ROBIN1();
	/*ROUND_ROBIN();
	FCFS();
	PRIORITY(); */
	
	return 0;
}
