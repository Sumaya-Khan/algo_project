#include<iostream>
#include<climits>
#include <algorithm>
#define R 1000

using namespace std;
 
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
    cout << "Maximum contiguous sum is "
        << max_sum << endl;
    cout << "Starting index "<< start
        << endl << "Ending index "<< end << endl;
}


// Bottom-up implementation for ALG 3

void Task3b(int A[R], int n)
{
    int sum[n];
    int start= 1, end= 1, temp_start=1, max_sum= INT_MIN;

    // Base case
    sum[0] = A[0];

    for (int i= 1; i< n; i++)
    {
        sum[i] = std::max(A[i]+sum[i-1], A[i]);
      
        if (sum[i] == A[i]) temp_start = i+1;

        if (max_sum > sum[i])
        {
            max_sum = max_sum;
            //start = i+1;
        }
        else
        {
            max_sum = sum[i];
            start = temp_start;
            end = i+1;
        }
    }
   
    cout << "Maximum contiguous sum is "
        << max_sum << endl;
    cout << "Starting index "<< start
        << endl << "Ending index "<< end << endl;
}


/*Driver program to test Task1*/

int main()
{
    clock_t begin = clock();

    int n;
    int A[R];
    int arr[2];

    int max_sum, sum;

    printf("Enter the number of elements:\n");
    scanf("%d",&n);

    printf("\nEnter n elements of array A:\n");
    for(int i=0; i< n; i++)
    {
        cin >> A[i];
    }

    //Task1 (A, n);
    //Task3a (A, n, arr);
    //max_sum, sum = Task3a (A, n);
    //cout << "Maximum contiguous sum is "
    //    << arr[0] << endl;
    //Task3b (A, n);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    cout << time_spent << endl;

    return 0;
}

