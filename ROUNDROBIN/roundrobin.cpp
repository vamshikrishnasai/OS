#include<stdio.h>
int main(){
	int n,i,j;
	printf("Enter Total Number of Processes: ");
	scanf("%d",&n);
	int wait_time=0,ta_time=0,arr_time[n],burst_time[n],temp_burst_time[n];
	int x=n;
	for(i=0;i<n;i++)
	{
		printf("Enter Details of Process %d\n",i+1);
		printf("Arrival Time: ");
		scanf("%d",&arr_time[i]);
		printf("Burst Time: ");
		scanf("%d",&burst_time[i]);
		temp_burst_time[i]=burst_time[i];
	}
	int time_slot;
	printf("Enter Time Slot: ");
	scanf("%d",&time_slot);

	int total=0,counter=0;
	printf("Process ID\tBurst Time\tTurnaround Time\tWaiting Time");
	for(total=0,i=0;x!=0;)
	{		if(temp_burst_time[i]<=time_slot&&temp_burst_time[i]>0)
		{
			total=total+temp_burst_time[i];
			temp_burst_time[i]=0;
			counter=1;
		}
		else if(temp_burst_time[i]>0)
		{
			temp_burst_time[i]=temp_burst_time[i]-time_slot;
			total+=time_slot;
		}
		if(temp_burst_time[i]==0&&counter==1)
		{
			x--;
			printf("\nP%d\t\t%d\t\t%d\t\t\t%d",i+1,burst_time[i],total-arr_time[i],total-arr_time[i]-burst_time[i]);
			wait_time=wait_time+total-arr_time[i]-burst_time[i];
			ta_time+=total-arr_time[i];
			counter=0;
		}
		if(i==n-1)
		{
			i=0;
		}
		else if(arr_time[i+1]<=total)
		{
			i++;
		}
		else
		{
			i=0;
		}
	}
	float avg_wait_time=wait_time*1.0/n;
	float avg_turnaround_time=ta_time*1.0/n;
	printf("\nAverage Waiting Time: %f",avg_wait_time);
	printf("\nAverage Turnaround Time: %f\n",avg_turnaround_time);
	return 0;
}



