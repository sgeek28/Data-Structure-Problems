#include<iostream>
#include <sys/time.h>
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

void bubble_semi(int arr[], int N){
	for(int i=0; i<N; i++){
		int inversion=0;
		for(int j=0; j<N-i-1; j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				inversion++;
			}
		}
	if(inversion==0)
		break;
}
}
void bubble(int a[],int N)
{

for(int i = 0 ;i <= N; i++)
{
for (int j = 0;j<(N-1); j++)
{
if ( a[j] > a[j+1])
{
int tmp = a[j];
a[j] = a[j+1];
a[j+1] = tmp;
}}}
}

void fillRandom (int a[], int N)
{
for(int i=0;i<N;i++)
a[i] = (rand()%1000)+1;
}
void check(int a[],int N) 
{
	for (int i=0;i<(N-1);i++)
		if (a[i]>a[i+1])
		{
			printf("Failed to sort.See item:%d \n\n ",i);
			return;
		}
	printf("Check passed \n\n");
}

int main()
{
	struct timeval st,end;
	double time_taken; 
        //int start_time,end_time,
        int n,a,i;
	cout<<"enter size of array\n";
	cin>>n;
	int ar[n];
	//bubble_semi sort
	fillRandom(ar,n);
	gettimeofday(&st , NULL ) ;
        bubble_semi(ar,n);
	gettimeofday(&end , NULL ) ;
	time_taken =(end.tv_sec*1e6 + end.tv_usec)-(st.tv_sec*1e6 + st.tv_usec);
        printf("\nthe time elapsed while executing semi bubble sort= %f%d%d microseconds\n" ,time_taken) ;
        check(ar,n);


	//bubblesort
	fillRandom(ar,n);
        gettimeofday(&st , NULL ) ;
        bubble(ar,n);
        gettimeofday(&end , NULL ) ;
        time_taken =(end.tv_sec*1e6 + end.tv_usec)-(st.tv_sec*1e6 + st.tv_usec);
        printf("\nthe time elapsed while doing bubble sort = %f%d%d microseconds\n" ,time_taken) ;
        check(ar,n);
}

