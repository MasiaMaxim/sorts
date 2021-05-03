#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

const int nmax = 1000000;

void Merg(vector<int> & arr, int begin, int end) 
{
	int i = begin, 
		t = 0, 
		mid = begin + (end - begin) / 2,
		j = mid + 1;
	vector<int> d(nmax);
   	
	while (i <= mid && j <= end){

		if (arr[i] <= arr[j]) { 
			d[t] = arr[i]; i++; 
		}
		else { 
			d[t] = arr[j]; j++;
		}
		t++;
	}

	while (i <= mid){
		d[t] = arr[i]; i++; t++;
	}

	while (j <= end){
		d[t] = arr[j]; j++; t++;
	}

	for (i = 0; i < t; i++)
        arr[begin + i] = d[i];
}

void MergSort(vector<int> & arr, int left, int right)
{
	int  temp;
	if (left<right)
		if (right - left == 1) {
			if (arr[right]<arr[left]){
				temp = arr[left]; 
				arr[left] = arr[right]; 
				arr[right] = temp;
			}
		}
		else {
			MergSort(arr, left, left + (right - left) / 2); 
			MergSort(arr, left + (right - left) / 2 + 1, right);
			Merg(arr, left, right);
		}
}


int main()
{	srand(time(0));
	int N;
	N = nmax;
	vector<int> nums(N);
	for (int i = 0; i < N; i++) { nums[i] = rand(); }
//				for (int i = 0; i < N; i++) { cout << nums[i] << endl; }
	MergSort(nums, 0, N - 1);
//		    cout << "          " << endl;
//			for (int i = 0; i < N; i++) { cout << nums[i] << endl; }
	return 0;

}

