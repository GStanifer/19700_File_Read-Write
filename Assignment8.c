/*
Program:  Assignment 8
Made by:  Garrett Stanifer
Date:  4/12/2021
Reads data from one .txt document and prints results on a new .txt document
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int datapoints;
	int date[30];
	int newyork[31];
	int anchorage[31];
	int i;
	int sum1=0;
	int sum2=0;
	double avg1=1;
	double avg2=1;

	FILE *fileInp;
	FILE *fileOut;

	fileInp = fopen("Temps.txt", "r");
	fileOut = fopen("results.txt", "w");

	if (fileInp == NULL)
	{
		printf("Error opening input file\n");
		exit(100);
	}

	if (fileOut == NULL)
	{
		printf("Error opening output file\n");
		exit(100);
	}

	fscanf(fileInp, "%d", &datapoints);
	for (i = 1; i < datapoints; i++)
	{
		fscanf(fileInp, "%d %d %d", &date[i - 1], &newyork[i - 1], &anchorage[i - 1]);
	}

	for (i = 0; i < datapoints; i++)
	{
		sum1 += newyork[0];
		sum2 += anchorage[0];
	}
	avg1 = sum1 / datapoints;
	avg2 = sum2 / datapoints;

	fprintf(fileOut, "The average temperature in New York is %.2lf\n", avg1);
	fprintf(fileOut, "The average temperature in Anchorage is %.2lf\n", avg2);

	for (i = 0; i < datapoints; i++)
	{
		int date = i + 1;

		if (anchorage[i] > newyork[i])
			fprintf(fileOut, "%d\n", date);
	}

		for (i = 0; i < datapoints; i++)
		{
			int max1 = -999;

			if (anchorage[i] > max1)
			max1 = anchorage[i];
		}

		for (i = 0; i < datapoints; i++)
		{
			int min1 = 999;

			if (newyork[i] < min1)
			min1 = newyork[i];
		}

		fclose(fileInp);
		fclose(fileOut);

		return 0;
}
