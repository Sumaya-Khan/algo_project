#include<iostream>
#include<climits>
#include <algorithm>
#define R 1000
#define C 1000

using namespace std;
 
// Brute Force ALG for Problem 2

void Task4(int A[R][C], int m, int n)
{

   int s_row= 0, e_row= 0, s_col= 0, e_col= 0, max_sum= INT_MIN;

    for (int i1= 0; i1< m; i1++)
    {
        for (int j1= 0; j1<n; j1++)
        {
            for (int i2= i1; i2< m; i2++)
            {
                for (int j2= j1; j2< n; j2++)
                {
                    int sum= 0;
                    for (int k1= i1; k1< i2+1; k1++)
                    {
                        for (int k2= j1; k2< j2+1; k2++)
                        {
                            sum= sum + A[k1][k2];
                        }
                    }

                    if (sum > max_sum)
                    {
                        max_sum = sum;
                        s_row = i1+1;
                        s_col = j1+1;
                        e_row = i2+1;
                        e_col = j2+1;
                    }
                }
            }
        }
    }

    cout << s_row << std::string( n, ' ' ) << s_col << std::string( n, ' ' )
         << e_row << std::string( n, ' ' ) << e_col << std::string( n, ' ' ) << max_sum << endl;
}

void Task6(int A[R][C], int m, int n)
{
    int aux[m][n];
    int start_row= 1, end_row= 1, start_col=1, end_col =1;
    int temp_sum= INT_MIN, max_sum= INT_MIN;

    int temp_start_row= 1; 

    for (int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            aux[i][j] = 0;
        }
    }

    for (int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            //base case
            if (j == 0) aux[i][j] = A[i][j];
            else aux[i][j] = A[i][j] + aux[i][j-1];
            cout << std::string( n, ' ' ) << A[i][j] << std::string( n, ' ' ) << aux[i][j] << endl;
        }
    }
    

    for (int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            int temp[m];

            for (int k=0; k<m; k++)
            {
                if (i == 0) temp[k]= aux[k][j];
                else temp[k]= aux[k][j]- aux[k][i-1];
            }

            int val= temp[0];
            temp_sum = val;

            for (int x=1; x<m; x++)
            {
                val = std::max(temp[x]+val, temp[x]);
                
                if (val == temp[x]) temp_start_row= x+1; 
                
                if (val > temp_sum)
                {
                    temp_sum = val;
                    start_row = temp_start_row;
                    end_row = x+1;
                }
                //cout << "Start" << start_row << endl;
                //cout << "END ROW" << end_row << endl;
            }
            if (temp_sum > max_sum)
            {
                max_sum = temp_sum;
                start_row = start_row;
                start_col = i+1;
                end_row = end_row;
                end_col = j+1;
            }
        }
    }

    //cout << start << std::string( n, ' ' ) << end << std::string( n, ' ' ) << max_sum << endl;
    //cout << max_sum << endl;
    cout << start_row << std::string( n, ' ' ) << start_col << std::string( n, ' ' )
         << end_row << std::string( n, ' ' ) << end_col << std::string( n, ' ' ) << max_sum << endl;
}

/*Driver program*/

int main()
{
    clock_t begin = clock();

    int m, n;
    int A[R][C];

    int max_sum, sum;

    printf("Enter the number of elements:\n");
    cin >> m >> n;

    printf("\nEnter n elements of array A:\n");
    for(int i=0; i< m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> A[i][j];
        }
    }

    //Task4 (A, m, n);
    Task6 (A, m, n);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    cout << time_spent << endl;

    return 0;
}

