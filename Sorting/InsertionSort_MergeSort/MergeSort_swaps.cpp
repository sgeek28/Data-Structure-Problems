#include <bits/stdc++.h> 
#include <sys/time.h>
using namespace std; 
using namespace std::chrono;

//Calling merge function to merge the two sorted sub-arrays
void merge(long long int a[], long long int temp[], int l, int m, int r) 
{ 
	int i, j, k; 

	i = l;
	j = m+1; 
	k = l; 
	while ((i <= m) && (j <= r)) 
	{ 
		if (a[i] <= a[j]) 
			temp[k++] = a[i++]; 
		else
			temp[k++] = a[j++]; 
	} 
        
        //copy the remaining elements to the original array from temporary array
	while (i <= m) 
		temp[k++] = a[i++]; 
	while (j <= r) 
		temp[k++] = a[j++]; 
	for (i = l; i <= r; i++) 
		a[i] = temp[i]; 

} 

//MergeSort function to divide the given array in two equal halves
//and recursively call the mergesort function on two halves
//until we are left with single element in sub arrays
void MergeSort(long long int arr[], long long int temp[], int left, int right) 
{ 
	int mid; 
	if (right>left) 
	{ 
		mid = (right + left) / 2; 
		MergeSort(arr, temp, left, mid);
		MergeSort(arr, temp, mid + 1, right); 
		merge(arr, temp, left, mid, right);
    	}  
} 

//Calculating execution time for MergeSort
//using timeval and chrono utility
void execution_time(long long int arr[],long long int temp[],int x,int y)
{
	struct timeval st, end;
	gettimeofday(&st, NULL);
	auto start = high_resolution_clock::now();
	MergeSort(arr, temp,x,y); 
        
        //The number of swaps in case of merge sort is 0
	cout << " Number of swaps are: 0"; 
	gettimeofday(&end, NULL); 
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout<<"The time taken is "<<duration.count()<<" microseconds"<<endl;
	double time_taken; 
  
     
    	time_taken =(end.tv_sec*1e6 + end.tv_usec)-(st.tv_sec*1e6 + st.tv_usec);
	cout<<endl<<"TimeVal utility time "<<time_taken<<" microseconds";
}

int main() 
{ 
	long long int arr[100000];
	long long int temp[10000];
	int n,x;
	cout<<"enter size of array"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
		arr[i]=(rand()%1000)+1;
        //Provide user input to select any of the below mentioned options
	cout<<"Select option"<<endl;
	cout<<"1. Best case"<<endl;
	cout<<"2. Worst case"<<endl;
	cout<<"3. Average case"<<endl;
	cin>>x;
        switch(x)
	{	
		case 1:
		{
			sort(arr, arr+n);
			execution_time(arr,temp,0,n-1);
		}
		break;
		case 2:
		{
			sort(arr,arr+n,greater<>());
			execution_time(arr,temp,0,n-1);
		}
		break;
		case 3:
		{
			sort(arr,arr+n,greater<>());
			execution_time(arr,temp,0,n-1);
		}
		break;
		default:
		cout<<"Invalid option selected";
	} 
	 
	return 0; 
} 

