// Program 7 −−− some s o r t i n g
// compile : gcc −o program7 program7 . c
// usage : program7 100
// (replace ”100” by the arraysize you want )
// Name:SNEHA SHUKLA
// Date submitted :17th September,2019
// Declarations
#include<iostream>
#include <sys/time.h>
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

void mySort(long long int a[],int);
void bubbleSort(long long int a[]);
void insertSort(long long int a[],int);
void mergeSort (long long int a[],int,int);
void fillRandom (long long int a[]);
void check (long long int a[]);
long long int N ; // Global for array size
int main () 
{
double time_taken;
struct timeval st,end ; // for timing the sorts
//int starttime,endtime ; // for timing the sorts
cout<<"Enter the no of element:";
cin>>N;
long long int a[N];// set size of array


//Time a bubble sort
fillRandom(a);
gettimeofday(&st , NULL ) ;
bubbleSort(a);
gettimeofday(&end , NULL ) ;
time_taken =(end.tv_sec*1e6 + end.tv_usec)-(st.tv_sec*1e6 + st.tv_usec);
printf("Bubble Sort time = %f%d%d microseconds\n" ,time_taken) ;
check(a);


// time an insertion sort
fillRandom(a) ;
gettimeofday(&st,NULL) ;
insertSort(a,N);
gettimeofday(&end , NULL ) ;
time_taken =(end.tv_sec*1e6 + end.tv_usec)-(st.tv_sec*1e6 + st.tv_usec);
printf("Insertion Sort time = %f%d%d microsecond\n" ,time_taken) ;
check(a) ;

// time a merge sort
fillRandom(a) ;
gettimeofday(&st , NULL) ;
mergeSort(a,0,N-1);
gettimeofday(&end , NULL ) ;
time_taken =(end.tv_sec*1e6 + end.tv_usec)-(st.tv_sec*1e6 + st.tv_usec);
printf("Merge Sort time = %f%d%d microseconds\n",time_taken);
check(a);


// time a ”my” sort
fillRandom (a);
gettimeofday(&st,NULL);
mySort(a,N);
gettimeofday(&end , NULL );
time_taken =(end.tv_sec*1e6 + end.tv_usec)-(st.tv_sec*1e6 + st.tv_usec);
printf("\nMySort time = %f%d%d microseconds\n",time_taken);
check(a);
return 0;

}	
void mySort(long long int arr[],int N) 
{
	//improved bubble sort
	for(int i=0; i<N; i++){
		int inversion=0;
		for(int j=0; j<N-i-1; j++){
			if(arr[j]>arr[j+1]){
				long long int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				inversion++;
			}
		}
	if(inversion==0)
		break;
}
}
void bubbleSort(long long int a[])
{
for(int i = 0 ;i <= N; i++)
{
for (int j = 0;j<(N-1); j++)
{
if ( a[j] > a[j+1])
{
long long int tmp = a[j];
a[j] = a[j+1];
a[j+1] = tmp;
}
}
}
return;
}
void insertSort(long long int a[],int n) 
{
	int i, key, j;
	for (i = 1; i <n ; i++)
        {
                key = a[i];
                j = i - 1;
                while (j >= 0 && a[j] > key)
                {
                         a[j + 1] = a[j];
                         j = j - 1;
                        
                 }

        a[j + 1] = key;
        }

}
void mergeSort(long long int a[],int l,int r) 
{
	int n=r+1;
	int merge(long long int*,int,int, int);
   	if(l<r)
	{
	        int mid= (l+r)/2;
		mergeSort(a,l,mid);
		mergeSort(a,mid+1,r);
		merge(a,l,mid,r);
	}
	
}
void merge(long long int a[],int l,int m,int r)
{
	 int n1 = m-l+1;
	// cout<<n1<<endl;
	 int n2 = r-m;
       long long int  L[n1],R[n2];
	for (int i=0;i<n1;i++)
		L[i]=a[l+i];
	for (int j=0;j<n2;j++)
		R[j]=a[m+j+1];
	int i=0;
	int j=0;
	int k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		    {
			    a[k]=L[i];
			    i++;
		    }
		else
		{
			a[k]=R[j];
			j++;
		}
		k++;
	}
	while (i<n1)
	{
		a[k]=L[i];
		i++;
		k++;
	}
	while (j<n2)
	{
		a[k]=R[j];
		j++;
		k++;
	}
}

void fillRandom (long long int a[]) 
{
	for(int i=0;i<N;i++)
		a[i] = (rand()%10000)+1;
}
void check(long long int a[]) 
{
	for (int i=0;i<(N-1);i++)
		if (a[i]>a[i+1])
		{
			printf("Failed to sort.See item:%d \n\n ",i);
			return;
		}
	printf("Check passed \n\n");
}

