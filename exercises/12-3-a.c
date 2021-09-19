#include <stdio.h>
#include "12-3-a.h"

#define METRIC 0
#define US 1

void set_mode(int * mode, int choice)
{
	if (choice != METRIC && choice != US)
		printf("Invalid mode specified. Mode %d (%s) used.\n", *mode, *mode ? "US" : "Metric");
	else
		*mode = choice;
}

void get_info(int mode, float * distance, float * fuel_consumed)
{
	printf("Enter distance traveled in %s: ", mode ? "miles" : "kilometers");
	scanf("%f", distance);
	printf("Enter fuel consumed in %s: ", mode ? "gallons" : "liters");
	scanf("%f", fuel_consumed);
}

void show_info(int mode, float distance, float fuel_consumed)
{
	if (mode == US)
		printf("Fuel consumption is %.1f miles per gallon.\n", distance/fuel_consumed);
	else
		printf("Fuel consumption is %.2f liters per 100 km.\n", fuel_consumed/distance*100);
}
