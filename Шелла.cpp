#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;



void ShellSort(int n, vector<int> & m)
{
    int i, j, step;
    int t;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            t = m[i];
            for (j = i; j >= step; j -= step)
            {
                if (t < m[j - step])
                    m[j] = m[j - step];
                else
                    break;
            }
            m[j] = t;
        }
}

int main() {
	srand(time(0));
	int N;
	N = pow(10, 2);
	vector<int> nums(N);
	for (int i = 0; i < N; i++) { nums[i] = rand(); }
			for (int i = 0; i < N; i++) { cout << nums[i] << endl; }
	ShellSort(N, nums);
		    cout << "          " << endl;
			for (int i = 0; i < N; i++) { cout << nums[i] << endl; }
	return 0;
}
