#include <stdio.h>
struct student
{
    int StudentId;
    int FoodTakenTime;
    int WaitingTime;
    int TurnAroundTime;
};

void accept(struct student list[], int s);
void display(struct student list[], int s);
void scheduling(struct student list[], int s);
void waitingTime(struct student list[], int n);
void turnAroundTime(struct student list[], int n);

int main()
{
    struct student data[20];
    int n,i;
    char c='n';
    do
	{
    printf("Please enter the No. of Students wants to eat in mess? : ");
    scanf("%d", &n);
    accept(data, n);
    scheduling(data, n);
    waitingTime(data,n);
    turnAroundTime(data,n);
    display(data, n);
    printf("Want to continue? press 'y' : ");
    scanf("%s",&c);
    }while(c=='y');
    return 0;
} 

void accept(struct student list[80], int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        printf("\n\nEnter data for Student #%d", i + 1);
        
        printf("\nEnter Student id : ");
        scanf("%d", &list[i].StudentId);

        printf("Enter time taken for food (minuts): ");
        scanf("%d", &list[i].FoodTakenTime);
    } 
}

void display(struct student list[80], int s)
{
    int i,AvgWaitingTime=0,AvgTurnAroundTime=0;
	int TotalWatingTime=0,TotalTurnAroundTime=0;
    printf("\n\n\t\t\tOutput according to LRTF\n");
    printf("\n\t\t\t|Student id\tFoodTakenTime\tWaitingTime\tTurnAroundTime  |");    
    for (i = 0; i < s; i++)
    {
        printf("\n\t\t\t|%d\t\t%d\t\t%d\t\t%d\t\t|", list[i].StudentId, list[i].FoodTakenTime,list[i].WaitingTime,list[i].TurnAroundTime);
		TotalWatingTime= TotalWatingTime+list[i].WaitingTime;
		TotalTurnAroundTime= TotalTurnAroundTime+list[i].TurnAroundTime;
	} 
	printf("\n\n\t\t\tTotal Waiting Time is: = %d",TotalWatingTime);
	printf("\n\t\t\tTotal Turn around Time is: = %d\n\n",TotalTurnAroundTime);
	printf("\n\n\t\t\tAverage Waiting Time is: = %d",TotalWatingTime/s);
	printf("\n\t\t\tAverage Turn around Time is: = %d\n\n",TotalTurnAroundTime/s);
}
