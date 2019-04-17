# include <stdio.h>
# include <stdlib.h>
#include <time.h>
# define BOUND 100

struct code{	//for queue 1 scheduling
int at,bt,priority,pid,cot;
int wt,tat, at2, bt2, pid2, priority2;
}Q2[BOUND];

void kuchbhi(struct code);
void RoundRobin(int);
void thankyou();

int getLeastPriorityProcess(struct code ){
	loc++;
	int unique,flag,z,temp;
	//unique = Q2[loc].priority2;
	for(unique = 0; unique < num_process ; unique++){
		for(z = 0; z < num_process-unique-1 ; z++){
			if(Q2[z].priority2 > Q2[z+1].priority2){
				temp = Q2[z+1].priority2;
				Q2[z+1].priority2 = Q2[z].priority2;
				Q2[z].priority2 = temp;
			}
		}
	}
			
}

int main(){

	int num_process, k, count=0, flag=0 , ct=0, cnt, check,tik;
	char choice;
FIRST:
	printf("\n*****************************************************************************************\n");
	printf("\n\n\t\t\t\t WELCOME\n");
	printf("\n\t\t\t ASHIKA's PROJECT-MULTILEVEL QUEUE SCHEDULING:\n\n");
	printf("\n*****************************************************************************************\n");
	
	printf("\n\n Enter the number of processes: ");
	scanf("%d",&num_process);
	struct code Q1[num_process];
	for(int i = 0; i < num_process ; ++i)
	{
		printf("\n Enter details for P%d:\n",i);
		printf("\n\t PID\t\t: "); scanf("%d",&Q1[i].pid);
		printf("\n\t Priority\t: "); scanf("%d",&Q1[i].priority);
		printf("\n\t AT\t\t: "); scanf("%d",&Q1[i].at);
		printf("\n\t BT\t\t: "); scanf("%d",&Q1[i].bt);	Q1[i].cot=Q1[i].bt;
	}

	printf("\nWe're entering into Queue 1 now: \n");
	sleep(rand()%3 + 2);

	int cro=0; 
	int i,lbt;
	
	for( i ; i<num_process ; i++ )
	{
		i=getLeastPriorityProcess(size);
		//1.1 Loop for individual process processing
		int lbt=Q1[i].cot;
		int measure=0,stopi[num_process]; k=1;
		for(int j=0;j<lbt;j++)
		{
			//1.2 loop for processing through the burst time until the new process arrives
			if(i==0 && Q1[i].at!=0){
				for(int l=0;l<Q1[i].at;l++){
					count++	;
				}
				tik=Q1[i].at;
				printf("\n\n %3d <----\t\tNULL\t\t----> %3d",0,0,tik);
			}			
			else if(i==0 && Q1[i].at==0 && measure==0){
				for(int l=0;l<Q1[i+1].at;l++){
					count++;
					Q1[i].bt--;
				}
				cro=1;
				printf("\n");
				printf("\n %3d <----\tP[%d]\t---->%3d",Q1[i].at,Q1[i].pid,count);
				tik=Q1[i].at+count;
			}
				if(i==(num_process-1)){
					if(check==1);
					for(int m=0;m<Q1[i].bt;m++){ 
						count++; //Q1[i].bt--;
					}
					printf("\n");
					printf("\n %3d <----\tP[%d]\t---->%3d",tik,Q1[i].pid,count);
					break;
				}
					if( count!=0 && ((count%2)==0) && (Q1[k+i].priority > Q1[i].priority)){
						printf("\n");
						printf("\n %3d <----\tP[%d]\t---->%3d",tik,Q1[i].pid,count);
						tik=count;
						count++;
						Q1[i].bt--;
						flag++;
						k++;
						measure=1;
						continue;
					}
					else if( count!=0 && ((count%2)==0) && (Q1[i+k].priority < Q1[i].priority))
					{
						if(k==2)
						{
							printf("\n");
							printf("\n %3d <----\tP[%d]\t---->%3d",tik,Q1[i].pid,count);
							ct++;
							transfer(Q1[i+1]);
							i=i+1;
							measure=1;
							tik=count;
							count++;
							Q1[i+1].bt--;
							check=1;
							break;
						}
						if(cro!=1)
						{
							printf("\n");
							printf("\n %3d <----\tP[%d]\t---->%3d",tik,Q1[i].pid,count);//printing the first queue
						}
						cro=0;
						if(Q1[i].bt>0)
						{
							ct++;	//ct tracks the # of processes entering Queue2
							transfer(Q1[i]);
						}
						measure=1;
						tik=count;
						count++;
						Q1[i+1].bt--;
						check=1;
						break;
					}
					else
					{
						flag++; 
						Q1[i].bt--;
						count++;
						measure=1;
					}
		}
	}
	sleep(2);
	printf("\n Queue 1 is now empty \n");
	printf("\n Queue 2 is now executing... \n");
	sleep(rand()%3+2);
	RoundRobin(ct);
B:
	printf("\n Would you like to reuse this Scheduling program? (y/n)\n");
	scanf("%c",&choice);
	if(choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N'){
		printf("\nSorry, invalid choice entered. Please enter again.. \n");
		goto B;
	}
	else if(choice == 'n' || choice == 'N')		thankyou();
	else	goto FIRST;
	thankyou();
	return 0;
}

void RoundRobin(int c){ 
	//RoundRobin code executing q2:
	int i, limit, total = 0, x, counter = 0, tq;
	int wt = 0, tat = 0, arrivaltime[BOUND], bursttime[BOUND], temp[BOUND];
	float avgwt, avgtat; 
	limit=c;
	//struct code proc2[BOUND];
	x = limit;
	for(i = 0; i <limit ; i++)
	{    
		arrivaltime[i]=Q2[i].at2;
		bursttime[i]=Q2[i].bt2;
		temp[i] = bursttime[i];
	}
	printf("\n\n Enter Time Quantum:\t");
	scanf("%d", &tq);
	printf("\n\tPID\t\tArrival Time\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
	for(total = 0, i = 0; x != 0; )
	{
		if(temp[i] <= tq && temp[i] > 0)
		{
			total = total + temp[i];	//if burst time < tq then process executes without pause
			temp[i] = 0;			//bt = 0 since process has executed
			counter = 1;
		}
		else if(temp[i] > 0 && temp[i] > tq)
		{
			temp[i] = temp[i] - tq;	//when bt > tq, p executes until time tq and BTi+1 = bt - tq;
			total = total + tq;		//total denotes the time taken to execute in one go
		} 
		if(temp[i] == 0 && counter == 1)	//checks for finished processes
		{
			x--;
printf("\nProcess[%d]\t\t%d\t\t%d\t\t %d\t\t\t %d",Q2[i].pid2,Q2[i].at,bursttime[i],total-arrivaltime[i],total-arrivaltime[i]-bursttime[i]);
			wt	=	wt	+	total	-	arrivaltime[i]	-	bursttime[i];
			tat	=	tat	+	total	-	arrivaltime[i];
			counter = 0;
		}
		if(i == limit - 1)
		{
			i = 0;
		}
		else if(arrivaltime[i + 1] <= total)
		{
			i++;
		}
		else
		{
			i = 0;
		}
	}
	avgwt = wt * 1.0 / limit;
	avgtat = tat * 1.0 / limit;
	printf("\n\n Average Waiting Time for queue2 :\t%.1f", avgwt);
	printf("\n Average Turnaround Time for queue2:\t%.1f\n", avgtat);
}

void transfer(struct code kuchbhi){ //copying the info of queue2 process that has entered
	int cnt = 0;	
	Q2[cnt].bt2		=	kuchbhi.bt;
	Q2[cnt].at2		=	kuchbhi.at;
	Q2[cnt].priority2	=	kuchbhi.priority;
	Q2[cnt].pid2		=	kuchbhi.pid;
	cnt++;
}

void thankyou(){
	printf("\n*****************************************************************************************\n");
	printf("\n\n\t\tTHANKS FOR USING MULTILEVEL-QUEUE-PROGRAM DESIGNED BY ASHIKA!\n\n");
	printf("\n*****************************************************************************************\n");
	exit(1);
}
