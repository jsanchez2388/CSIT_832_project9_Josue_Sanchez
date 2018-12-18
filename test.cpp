//Josue Sanchez
//Date: 10/27/2018
//Program: Printer Queueing System
//Description: This program simulates a priority queueing system. The program will prompt the user to 
//simulate adding a printing job to the print queue. The user then has the option to simulate a completed
//print job or viewing the queue. If the user elects to simulate a completed print job, the queue will update.
//The queue completes "print" request in order of priority. 

#include "pqtype.h"

/******Function Prototypes*****/
int menu();
void addJob(pqtype&);
void printJob(pqtype&);
void viewJobs(pqtype&);

int main()
{
	int choice;	//Neded for algorithm
	pqtype printQueue(100);	//Creates a priority queue with 100 available spots
	do
	{
		choice = menu();	//Display menu and return choice
		switch (choice)		//Switch case to determine which function to call
		{
		case 1:
			addJob(printQueue);
			break;
		case 2:
			printJob(printQueue);
			break;
		case 3:
			viewJobs(printQueue);
			break;
		case 4:
			break;
		default:
			cout << "Invalid Input\n";
			break;
		}
	} while (choice != 4);	//Break if choice is 4
	return 0;
}

int menu()
{
	int choice;	//Used to return choice
	cout << "Print Queue\n";
	cout << string(12, '=');
	cout << "\n1. Add job\n";
	cout << "2. Print job\n";
	cout << "3. View jobs\n";
	cout << "4. Exit\n";
	cout << "Enter choice: ";	//Ask user for choice
	cin >> choice;	//Save choice
	return choice;
}

void addJob(pqtype&q)
{
	char title;	//Used to save title for print job
	pJob tempJob;	//Temp job used to add to queue
	int jN = q.getLength();	//Save the current length of queue to be used for print job #

	cout << "Enter title [Instructor (I or i), TA (T or t), or Student (S or s)]: "; //Ask user for title
	cin >> title;

	switch (toupper(title))	//Switch case to determine title and priority
	{
	case 'I':
		tempJob.title = "Instructor";
		tempJob.priority = 3;
		break;
	case 'T':
		tempJob.title = "TA";
		tempJob.priority = 2;
		break;
	case 'S':
		tempJob.title = "Student";
		tempJob.priority = 1;
		break;
	default:
		return;
	}
	tempJob.jobNumber = jN;	//Add job Number to temp
	
	q.Enqueue(tempJob);	//Add it to queue
}
void printJob(pqtype&q)
{
	if (q.isEmpty())	//If queue is empty display that it is empty
	{
		cout << "There are no jobs to print out" << endl;
	}
	else
	{
		pJob job;	//Temp job
		q.Dequeue(job);	//Dequeue pJob and save content to job
		//Cout contents of job
		cout << "Now printing job #" << job.jobNumber + 1 << " "<< job.title << endl;
	}
}
void viewJobs(pqtype&q)
{
	//Copy queue to temp queue
	pqtype temp = q;
	if (temp.isEmpty())	//Notify if queue is empty
	{
		cout << "No items in queue\n";
	}
	else
	{
		pJob t;	//Temp pJob
		int l = q.getLength();	//Return and Save length of queue
		
		for (int i = 0; i < l; i++)	//Iterate through each item in queue
		{
			temp.Dequeue(t);	//Dequeue pJob and save content to t
			
			switch (t.priority)	//Print out content of t
			{
			case 1:
				cout << "Print Job #" << t.jobNumber + 1 << " " << t.title << endl;
				break;
			case 2:
				cout << "Print Job #" << t.jobNumber + 1 << " " << t.title << endl;
				break;
			case 3:
				cout << "Print Job #" << t.jobNumber + 1 << " " << t.title << endl;
				break;
			default:
				break;
			}
		}
		
	}
}