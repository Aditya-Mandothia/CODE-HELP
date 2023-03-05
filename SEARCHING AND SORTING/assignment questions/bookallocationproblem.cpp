#include <bits/stdc++.h>
using namespace std;

bool isPossibleSolution(int A[], int N, int M, int sol)
{

    int pageSum = 0;
    int c = 1;

    for (int i = 0; i < N; i++) //making permutations
    {
        if (A[i] > sol) //atmost sol karne hain
        {
            return false;
        }

        if (pageSum + A[i] > sol) //matlab agar A[I] extra banra hai toh no. of distribution badhega
        {
            c++;
            pageSum = A[i]; //naya start kardiya distribution A[i] se
            if (c > M)
            {
                return false;
            }
        }
        else
        {
            pageSum += A[i];
        }
    }

    return true; //within m students distribute hogya matlab true and saare books consume hogye toh
}

int findPages(int A[], int N, int M)
{

    if (M > N) // no. of students > no. of books means no allocation possible
    {
        return -1;
    }

    int start = 0;
    int end = accumulate(A, A + N, 0); //answer will fall between start to end (0 to 203 in this case)
    int ans = -1;

    while (start <= end)
    {
        /* code */
        int mid = (start + end) / 2;

        if (isPossibleSolution(A, N, M, mid))  //checking if this no. of max min no. of pages till the end of search space.
        {
            ans = mid; // we reduced the search space and we wanted to find the minimum no. (kya isse bhi kum ho sakta hai maximum pages wali books ka minimum)
            end = mid - 1;
        }
        else
        {   
            //possible nahi hua matlab atmost ye nhi ho sakta toh usse kum toh kya hi hoga to aage badho
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int A[] = {12, 34, 67, 90};
    int N = 4;
    int M = 2;

    cout << findPages(A, N, M);

    return 0;
}