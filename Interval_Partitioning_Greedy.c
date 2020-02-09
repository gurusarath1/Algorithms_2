#include <stdio.h>
#define MAX_ROOMS 50

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


	printf("\n\nMiminum Number of Rooms Required = %d", interval_partition(listOfJobs, n) );



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


int interval_partition(job listOfJobs[], int numberofjobs) 
{
	float roomAvailableTime[MAX_ROOMS];
	int n = numberofjobs;

	for(int i=0; i<MAX_ROOMS; i++)
	{
		//Available from start
		roomAvailableTime[i] = 0;
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