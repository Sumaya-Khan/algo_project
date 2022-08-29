#include<iostream>
#include<climits>
#include <algorithm>
#define R 1000

using namespace std;
 
int val = INT_MIN;
int start = 1;
int temp_start = 1;
int end_ind = 1;

// Brute Force ALG 1

void Task1(int A[R], int n)
{
    int start= 0, end= 0, max_sum= INT_MIN;

    for (int i= 0; i< n; i++)
    {
        for (int j= i; j< n; j++)
        {
            int sum= 0;

            for (int k= i; k< j+1; k++)
            {
                sum= sum + A[k];
            }

            if (sum > max_sum)
            {
                max_sum = sum;
                start = i+1;
                end = j+1; 
            }
        }
    }

    cout << start << std::string( n, ' ' ) << end << std::string( n, ' ' ) << max_sum << endl;
}

// Top-Down implementation for ALG 3

int Task3a(int A[R], int n, int index)
{
    int sum;

    // Base case
    if (index == 0)
    {
        sum = A[0];
        return A[0];
    }

    sum = Task3a(A, n, index-1);

    if (sum == A[index-1]) temp_start = index;

    if (sum > val) {
        val = sum;
        start = temp_start;
        end_ind = index;
    }

    return max(A[index], A[index] + sum);

}

// Bottom-up implementation for ALG 3

void Task3b(int A[R], int n)
{
    int sum;
    int start= 1, end= 1, temp_start=1, max_sum= INT_MIN;

    // Base case
    sum = A[0];
    max_sum = sum;
 
    for (int i= 1; i< n; i++)
    {
        sum = std::max(A[i]+sum, A[i]);
      
        if (sum == A[i]) temp_start = i+1;

        if (sum > max_sum)
        {
            max_sum = sum;
            start = temp_start;
            end = i+1;
        }
    }
   
    cout << start << std::string( n, ' ' ) << end << std::string( n, ' ' ) << max_sum << endl;
}


/*Driver program to test Task1*/

int main()
{
    clock_t begin = clock();

    int n;
    int A[R];

    int max_sum;

    printf("Enter the number of elements:\n");
    scanf("%d",&n);

    printf("\nEnter n elements of array A:\n");
    for(int i=0; i< n; i++)
    {
        cin >> A[i];
    }

    Task1 (A, n);
    Task3a (A, n, n);
    cout << start << std::string( n, ' ' ) << end_ind << std::string( n, ' ' ) << val << endl;
    Task3b (A, n);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    cout << time_spent << endl;

    return 0;
}

