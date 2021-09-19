#include <stdio.h>

#define LEN 40
#define CSIZE 4

struct name {
	char first[LEN];
	char last[LEN];
};

struct student {
	struct name name;
	float grade[3];
	float average;
};

void acquireScores(struct student *s)
{
	printf("Enter the scores for %s %s: ", s->name.first, s->name.last);
	scanf("%f %f %f", &s->grade[0], &s->grade[1], &s->grade[2]);
}

void calculateAverage(struct student *s)
{
	s->average = 0;
	for (size_t i = 0; i < sizeof s->grade / sizeof *s->grade; i++)
		s->average += s->grade[i];
	s->average = s->average / (sizeof s->grade / sizeof *s->grade);
}

void printStudent(const struct student *s)
{
	printf("Name: %s %s. Grades: %.2f %.2f %.2f. Average: %.2f.\n",
			s->name.first, s->name.last,
			s->grade[0], s->grade[1], s->grade[2],
			s->average);
}

void printClassAverage(const struct student *s, size_t n)
{
	float total = 0;

	for (size_t i = 0; i < n; i++)
		total += s[i].average;

	printf("Class average: %.2f.\n", total / n);
}

int main(void)
{
	struct student students[CSIZE] = {
		{.name.first = "Daniil", .name.last = "Sobolev"},
		{.name.first = "Donald", .name.last = "Trump"},
		{.name.first = "Justin", .name.last = "Walker"},
		{.name.first = "Michael", .name.last = "Johnson"}
	};

	for (int i = 0; i < CSIZE; i++)
	{
		acquireScores(&students[i]);
		calculateAverage(&students[i]);
	}

	for (int i = 0; i < CSIZE; i++)
		printStudent(&students[i]);
	printClassAverage(students, CSIZE);
}
