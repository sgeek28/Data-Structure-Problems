#include<stdio.h>
#include<stdlib.h>
#include<chrono>
#include<vector>
#include<fstream>
#include<iostream> 
using namespace std::chrono; 

using namespace std;
class sort
{
	public:
		long a,cm=0;
		
		int i=0,j=0;
		vector<double> v1; 
		void mergesort(int,int);
		void merge_count(int,int,int);
		void countingversion(int);
}; 
static int count_merge=0;

void sort::countingversion(int n)
{
	int i,j;
	int count=0;
	for(j=0;j<n-1;j++)
	{
		for(i=1+j;i<n;i++)
		{
			if(v1[j]>v1[i])
			{
				count++;
			}
		}
	}
	printf("\nNumber of inversion in countinversion: %d",count);
}
void sort::merge_count(int p,int q,int r)
{		int i,j,k,count=0;
		int n1=q-p+1,n2=r-q;
		int L[n1],R[n2];
		for(i=0;i<n1;i++)
			L[i]=v1[p+i];
		for(j=0;j<n2;j++)
			R[j]=v1[q+j+1];
		i=0;j=0,k=p;
		while(i<n1 && j<n2)
		{
			if(L[i]<=R[j])
			{
				v1[k]=L[i];
				i++;
			}
			else 
			{
				v1[k]=R[j];
				j++;	
				count_merge=count_merge+(n1-i);
			}
				k++;
		}
		while(i<n1)
		{
			v1[k]=L[i];
			i++;
			k++;
		}
		while(j<n2)
		{
			v1[k]=R[j];
			j++;
			k++;
		}
}

void sort::mergesort(int p,int r)
{
		if(p<r)
		{
			int q=(p+r)/2;
			mergesort(p,q);
			mergesort(q+1,r);
			merge_count(p,q,r);
		}
}
int main()
{
	sort s;
	int i,j;
	int n;
	printf("Enter the number of input\n");
	scanf("%d",&n);
	/*fstream myfile;
	myfile.open ("average.txt");

    	for (j=0; j<n; j++)
    	{
        	myfile  << (rand()%100000) ;
        	myfile  << endl;
    	}
    	myfile.close();

	myfile.open("average.txt");
	while(myfile>>s.a)
	{
		s.v1.push_back(s.a);
	}*/
	for(int i=0;i<n;i++)
	{
		s.a=(rand()%1000)+1;
		s.v1.push_back(s.a);
	}
	auto start = high_resolution_clock::now();
	s.countingversion(n);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start); 
  	cout << "\nTime taken by function: "<< duration.count() << " microseconds" << endl;
		
	auto start1 = high_resolution_clock::now();
	s.mergesort(0,n-1);
	auto stop1 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(stop1 - start1); 
  			
	//for(i=0;i<n;i++)
	//	cout<<"\n"<<s.v1[i];
	printf("\nNumber of inversion in merge: %d",count_merge);
	cout << "\nTime taken by function: "<< duration1.count() << " microseconds" << endl;

}




















