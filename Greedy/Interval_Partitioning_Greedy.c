#include <stdio.h>
#define MAX_ROOMS 50
#define START_TIME 0 // Offset

typedef struct job {
	float start_time;
	float end_time;
} job;

void insertionSort_job(job a[], int size);
int interval_partition(job listOfJobs[], int numberofjobs);

int main()
{

	job listOfJobs[] = {{9,10.5},{11,14},{14,17},{9,12.5}, {13,14.5}, {15,16.5}, {9,10.5}, {11,12.5}, {13,14.5}, {15,16.5}, {-1,10}};

	
	int n = sizeof(listOfJobs) / sizeof(job);

	insertionSort_job(listOfJobs, n);

	for(int i=0; i<n; i++)
	{
		printf("JOB %d : {%f,%f}\n", i+1, listOfJobs[i].start_time, listOfJobs[i].end_time);
	}


	printf("\n\nMinimum Number of Rooms Required = %d", interval_partition(listOfJobs, n) );

	return 0;

}

int interval_partition(job listOfJobs[], int numberofjobs) 
{
	float roomAvailableTime[MAX_ROOMS];
	int n = numberofjobs;

	for(int i=0; i<MAX_ROOMS; i++)
	{
		//Available from start
		roomAvailableTime[i] = START_TIME;
	}

	int minimumNumberOfRoomsRequired = 0;
	int job_scheduled_flag = 0;
	for(int jobX_index=0; jobX_index < n; jobX_index++)
	{
		job_scheduled_flag = 0;
		for(int roomX_index=0; roomX_index < MAX_ROOMS; roomX_index++)
		{
			if(roomAvailableTime[roomX_index] <= listOfJobs[jobX_index].start_time)
			{
				if(roomAvailableTime[roomX_index] == 0)
				{
					minimumNumberOfRoomsRequired += 1;
				}

				roomAvailableTime[roomX_index] = listOfJobs[jobX_index].end_time;
				printf("Room:%d : Job:%d : From %f To %f \n", roomX_index+1, jobX_index+1, listOfJobs[jobX_index].start_time, roomAvailableTime[roomX_index]);	
				job_scheduled_flag = 1;
				break;
			}
		}

		if(!job_scheduled_flag)
		{
			printf("Job:%d : From %f To %f (Could not be scheduled !)\n", jobX_index+1, listOfJobs[jobX_index].start_time, listOfJobs[jobX_index].end_time);
		}
	}

	return minimumNumberOfRoomsRequired;
}


void insertionSort_job(job a[], int size)
{

	job temp;
	int j;

	for(int i=1; i<size; i++)
	{
		if(a[i].start_time < a[i-1].start_time)
		{
			j = i;
			while(a[j].start_time < a[j-1].start_time && j >= 1)
			{
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
				j--;
			}
		}
	}

}


/*
OUTPUT - 

G:\Guru_Sarath\Study\C\DP>gcc Interval_Partitioning_Greedy.c

G:\Guru_Sarath\Study\C\DP>a.exe
JOB 1 : {-1.000000,10.000000}
JOB 2 : {9.000000,10.500000}
JOB 3 : {9.000000,12.500000}
JOB 4 : {9.000000,10.500000}
JOB 5 : {11.000000,14.000000}
JOB 6 : {11.000000,12.500000}
JOB 7 : {13.000000,14.500000}
JOB 8 : {13.000000,14.500000}
JOB 9 : {14.000000,17.000000}
JOB 10 : {15.000000,16.500000}
JOB 11 : {15.000000,16.500000}
Job:1 : From -1.000000 To 10.000000 (Could not be scheduled !)
Room:1 : Job:2 : From 9.000000 To 10.500000
Room:2 : Job:3 : From 9.000000 To 12.500000
Room:3 : Job:4 : From 9.000000 To 10.500000
Room:1 : Job:5 : From 11.000000 To 14.000000
Room:3 : Job:6 : From 11.000000 To 12.500000
Room:2 : Job:7 : From 13.000000 To 14.500000
Room:3 : Job:8 : From 13.000000 To 14.500000
Room:1 : Job:9 : From 14.000000 To 17.000000
Room:2 : Job:10 : From 15.000000 To 16.500000
Room:3 : Job:11 : From 15.000000 To 16.500000


Minimum Number of Rooms Required = 3

*/