#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Max 50
int A[Max][Max];

int simple_recursion(int n, int k) {

	if (k > n)
		return 0;

	if (k == 0 || k == n)
		return 1;
	return simple_recursion(n - 1, k - 1) + simple_recursion(n - 1, k);
}

/* bottom-up implementation for the binominal coefficient problem */
int bottom_up(int n, int k) {

	int i, j;
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= k && j <= i; j++) {

			if (j == 0 || j == i)
				A[i][j] = 1;
			else
				A[i][j] = A[i - 1][j - 1] + A[i - 1][j];
		}
	}

	return A[n][k];
}

/* top-down implementation for the binominal coefficient problem */
int top_down(int n, int k) {

	if (k > n)
		return 0;

	if (k == 0 || k == n)
		return 1;


	if (A[n][k] != -1)
		return A[n][k];

	return A[n][k] = top_down(n - 1, k - 1) + top_down(n - 1, k);
}

int main(){

	int n, k;
	double avg_timespent1 = 0.0, avg_timespent2 = 0.0, avg_timespent3 = 0.0;

	for (n = 20, k = 5; n < 30; ++n, ++k) {
		clock_t begin1 = clock();
		printf("Result from recursive implementation is: %d\n", simple_recursion(n, k));
		clock_t end1 = clock();
		double time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
		printf("Time for simple_recursion is: %.32f\n\n", time_spent1);
		avg_timespent1 += time_spent1;
	}

	printf("\n\n\n");

	for (n = 20, k = 5; n < 30; ++n, ++k) {
		memset(A, 0, sizeof(A));
		clock_t begin2 = clock();
		printf("Result from bottom-up implementation is: %d\n", bottom_up(n, k));
		clock_t end2 = clock();
		double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
		printf("Time for bottom-up is: %.32f\n\n", time_spent2);
		avg_timespent2 += time_spent2;
	}

	printf("\n\n\n");

	for (n = 20, k = 5; n < 30; ++n, ++k) {
		memset(A, -1, sizeof(A));
		clock_t begin3 = clock();
		printf("Result from top-down implementation is: %d\n", top_down(n, k));
		clock_t end3 = clock();
		double time_spent3 = (double)(end3 - begin3) / CLOCKS_PER_SEC;
		printf("Time for top_down is: %.32f\n\n", time_spent3);
		avg_timespent3 += time_spent3;
	}

	//counting the process time so we see which one did the best

	printf("\n\nAverage time for simple_recursion  is: %.32f\n", avg_timespent1 / 10);
	printf("\n\nAverage time for bottom-up  is: %.32f\n", avg_timespent2 / 10);
	printf("\n\nAverage time for top_down  is: %.32f\n", avg_timespent3 / 10);

}