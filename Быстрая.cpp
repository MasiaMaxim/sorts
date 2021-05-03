#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;


void quicksort(vector<int> & m, int first, int end)
{
int mid, t;
int f=first, e=end;
mid=m[(f+e) / 2];
do
{
while (m[f]<mid) f++;
while (m[e]>mid) e--;
if (f<=e)
{
t=m[f];
m[f]=m[e];
m[e]=t;
f++;
e--;
}
} while (f<e);
if (first<e) quicksort(m, first, e);
if (f<end) quicksort(m, f, end);
}

int main()
{
	srand(time(0));
	int N;
	N = pow(10, 8);
	vector<int> nums(N);
	for (int i = 0; i < N; i++) { nums[i] = rand(); }
//	    	for (int i = 0; i < N; i++) { cout << nums[i] << endl; }
    	quicksort(nums, 0, N - 1);
//		    cout << "          " << endl;
//			for (int i = 0; i < N; i++) { cout << nums[i] << endl; }
	return 0;

}
