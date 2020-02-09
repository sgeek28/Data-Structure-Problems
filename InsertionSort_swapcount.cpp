#include<bits/stdc++.h>
#include<fstream>
#include <sys/time.h>
using namespace std;
using namespace std::chrono; 


//InsertionSort function to sort the vector 
long long int insertionSort_swap(vector<int> arr,int size)
{
	int i, key, j,count=0;  
    	for (i = 1; i < size; i++) 
    	{  
        	key = arr[i];  
        	j = i - 1;  
        	while (j >= 0 && arr[j] > key) 
        	{  
            		arr[j + 1] = arr[j];  
            		j = j - 1;  
			count+=1;
        	}  
        	arr[j + 1] = key;  
		//count+=1;
    	}  
	return count;
}

//Calculation of execution time using chrono and timeval utiltity
void calculate_execution_time(vector<int> numbers,int size)
{
	struct timeval st, end;
	gettimeofday(&st, NULL);
        //Chrono execution time
	auto start = high_resolution_clock::now();
        
	
        //Calling insertionSort function to sort the vectors
	cout<<insertionSort_swap(numbers,size)<<" and time taken to swap is ";
	
        
	auto stop = high_resolution_clock::now();
	gettimeofday(&end, NULL);
	auto duration = duration_cast<microseconds>(stop - start);
	cout<<duration.count()<<" microseconds";
	
        //execution time using timeval utility
	double time_taken;  
	

	time_taken =(end.tv_sec*1e6 + end.tv_usec)-(st.tv_sec*1e6 + st.tv_usec);
        //time_taken=end.tv_usec-st.tv_usec;
	cout<<"TimeVal time: "<<time_taken<<" microseconds";
}

//populating file with vector for the first time
//reading file to populate vector
//calling execution time function to calculate time 
//when insertion sort is called
void populate_file(long long int x,int i)
{
	int n1,value;
	vector<int> numbers;
	/*std::ofstream ofile;
	ofile.open("sort1.txt",std::ios::out | std::ios::trunc); 

	for(int index=0; index<100000; index++)
	{
		value = (rand()%10000)+1;
		ofile << value << endl;
	}
	ofile.close();*/
	ifstream xfile;
	xfile.open("sort.txt");
	while (xfile >> n1 && numbers.size()<x) {
		numbers.push_back(n1);
		}
	xfile.close();
	
	cout<<endl<<"--------------------------------BEGIN-----------------------------------------";
	cout<<endl<<"The number of exchanges in average case after "<<i+1<<" iteration is:\t";
	calculate_execution_time(numbers,numbers.size());

	sort(numbers.begin(),numbers.end());	
	cout<<endl<<"The number of exchanges in best case after "<<i+1<<" iteration is\t";
	calculate_execution_time(numbers,numbers.size());

	cout<<endl<<"The number of exchanges in worst case after "<<i+1<<" iteration is:\t";
	sort(numbers.begin(),numbers.end(),greater<int>());
	calculate_execution_time(numbers,numbers.size());	
		


	cout<<endl<<"--------------------------------END----------------------------------------------";
}
int main()
{
	int n,x,y;
        //USer input to select options
	cout<<"Choose option to sort:"<<endl;
	cout<<"1.Sort all 10000 elements"<<endl;
	cout<<"2.Sort x elements y number of times"<<endl;
	cin>>n;
        switch(n)
	{
		case 1:
		populate_file(10000,0);
		break;				
		case 2:
		{
		cout<<"Enter x"<<endl;
		cin>>x;
		cout<<"Enter y"<<endl;
		cin>>y;
		
		for(int i=0;i<y;i++)
			populate_file(x,i);
		}
		break;
		default:
			cout<<"Invalid option selected";
	}
	return 0;
}
