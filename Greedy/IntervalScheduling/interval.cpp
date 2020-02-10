#include<bits/stdc++.h>
#include <sstream>
using namespace std;
bool inRange(unsigned low, unsigned high, unsigned x) 
{ 
    return  ((x-low) <= (high-low)); 
} 
void Modified_intervalScheduling(int arr[],int fin[],int n)
{
	int j=1,c=0;
        priority_queue<pair<int, int> > pq;
	vector<pair<int,int>> result1;
	for(int j=0;j<n;j++){
        	pq.push(make_pair(fin[j],arr[j]));
	}
	while(!pq.empty()){
		pair<int, int> max1 = pq.top();
		pq.pop();
		//second is start
		//first is finish
		result1.push_back(make_pair(max1.first,max1.second));
	}
	for(int i=0;i<n-1;){
		if((result1[j].first<=result1[i].second) && (!inRange(result1[i].second,result1[i].first,result1[j].second))
			&& result1[j].first<=result1[i].first)
		{
			cout<<"Job No "<<i+1<<"Scheduled from ("<<result1[i].second<<"-"<<result1[i].first<<" )"<<endl;
			cout<<"Job No "<<j<<"Scheduled from ("<<result1[j].second<<"-"<<result1[j].first<<" )"<<endl;
			i=j;
			j=j+1;
			
		}
		else{
			j=j+1;
			if(j==n){
				c+=1;
				i=c;
				j=i+1;
			}
		}
	}
}
string print24(string str) 
{ 
    // Get hours 
    int h1 = (int)str[1] - '0'; 
    int h2 = (int)str[0] - '0'; 
    int hh = (h2 * 10 + h1 % 10); 
    string str1;
    // If time is in "AM" 
    if (str[8] == 'A') 
    { 
        if (hh == 12) 
        { 
	    str1+="00";
            for (int i=2; i <= 7; i++) 
                str1+=str[i]; 
        } 
        else
        { 
            for (int i=0; i <= 7; i++) 
                str1+=str[i]; 
        } 
    } 
  
    // If time is in "PM" 
    else
    { 
        if (hh == 12) 
        { 
            str1+="12";
	    for (int i=2; i <= 7; i++) 
		str1+=str[i]; 
        } 
        else
        { 
            hh = hh + 12; 
	    str1+=to_string(hh); 
            for (int i=2; i <= 7; i++) 
		str1+=str[i];
        } 
    } 
    return str1;
} 
  
// Driver code 
int main() 
{
	int n,i_value,j_value;
	string str,arrival1,finish1;
	cout<<"Enter number of jobs being processed by user"<<endl;
	cin>>n;
	string arrival,finish;
	int arr[n],fin[n];
	cout<<"Enter the arrival time and finish time of each jobs along with AM/PM (eg. 6AM)"<<endl;
	for(int i=0;i<n;i++){
   		cin>>arrival>>finish;
		stringstream geek1(print24(arrival));
		geek1>>i_value;
		stringstream geek2(print24(finish));
		geek2>>j_value;
		arr[i]=i_value;
		fin[i]=j_value;
	}
	Modified_intervalScheduling(arr,fin,n);  	
   	return 0; 
} 

