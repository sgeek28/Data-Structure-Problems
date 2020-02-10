#include<bits/stdc++.h>
#include <chrono> 
using namespace std;
using namespace std::chrono;

void MaxJobSelection2(vector<int> start2,vector<int> finish2){ 
 
    // Minimum Priority Queue to sort activities in descending order of finishing time (f[i]). 
    priority_queue<pair<int,int>,vector<pair<int,int>>> pqueue2;

    //Choosen activity start and end time
    vector<pair<int,int>> result2;

    //Priority queue with finish[i] as key
    for(int i=0;i<start2.size();i++){  
        pqueue2.push(make_pair(finish2[i],start2[i])); 
    } 

    //printing starting and ending time of all activities stored in priority queue
    /*while (!pqueue2.empty()) { 
	auto ref3=pqueue2.top();
        cout <<ref3.first<<","<<ref3.second<<endl; 
        pqueue2.pop(); 
    } */

    auto ref_pq2=pqueue2.top();
    int start_pq2=ref_pq2.second;
    int finish_pq2=ref_pq2.first;
    pqueue2.pop(); 
    result2.push_back(make_pair(start_pq2,finish_pq2));  

    while(!pqueue2.empty()){ 
        auto ref_pq2 = pqueue2.top(); 
        pqueue2.pop(); 
        if(start_pq2 >= ref_pq2.first){ 
            start_pq2 = ref_pq2.second; 
            finish_pq2 = ref_pq2.first; 
            result2.push_back(make_pair(start_pq2,finish_pq2)); 
        } 
    }

    cout << "Following Activities should be selected when selecting last job to start" << endl; 
  
    for(auto pq_ref=result2.begin();pq_ref!=result2.end();pq_ref++){ 
        cout << "Activity started at: " << (*pq_ref).first << " and ends at  " << (*pq_ref).second << endl; 
    } 
} 

void MaxJobSelection1(vector<int> start1,vector<int> finish1){ 
  
    // Minimum Priority Queue to sort activities in ascending order of finishing time (f[i]). 
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pqueue1;

    //Choosen activity start and end time
    vector<pair<int,int>> result1; 

    //Priority queue with finish[i] as key
    for(int j=0;j<start1.size();j++){  
        pqueue1.push(make_pair(finish1[j],start1[j])); 
    }

    //printing starting and ending time of all activities stored in priority queue
    /*while (!pqueue1.empty()) { 
	auto ref3=pqueue1.top();
        cout <<ref3.first<<","<<ref3.second<<endl; 
        pqueue1.pop(); 
    } */

    auto ref1 = pqueue1.top(); 
    int st1 = ref1.second; 
    int f1 = ref1.first; 
    pqueue1.pop(); 
    result1.push_back(make_pair(st1,f1)); 
  
    while(!pqueue1.empty()){ 
        auto refer1 = pqueue1.top(); 
        pqueue1.pop(); 
        if(refer1.second >= f1){ 
            st1 = refer1.second; 
            f1 = refer1.first; 
            result1.push_back(make_pair(st1,f1)); 
        } 
    } 
    cout << "Following Activities should be selected when selecting first job to start" << endl; 
  
    for(auto refer1=result1.begin();refer1!=result1.end();refer1++){ 
        cout << "Activity started at: " << (*refer1).first << " and ends at  " << (*refer1).second << endl; 
    } 
} 
int main()
{

	vector<int> start;
	vector<int> finish;
	int n,a,b;
	cout<<"Enter the number of activities you want"<<endl;
	cin>>n;
	cout<<"Enter the start time for activities"<<endl;
	for(int i=0;i<n;i++){
		cin>>a;
		start.push_back(a);
	}
	cout<<"Enter the finish time for activities"<<endl;
	for(int j=0;j<n;j++){
		cin>>b;
		finish.push_back(b);
	}	
	//start{1, 3, 0, 5, 8, 5}; 
    	//finish{2, 4, 6, 7, 9, 9}; 
	auto time_start1 = high_resolution_clock::now();
    	MaxJobSelection1(start,finish); 
	auto time_stop1 = high_resolution_clock::now(); 
	auto time_duration1 = duration_cast<microseconds>(time_stop1 - time_start1);
	cout << "\nTime taken by function: "<< time_duration1.count() << " Nanoseconds" << endl<<endl;

	auto time_start2 = high_resolution_clock::now();
    	MaxJobSelection2(start,finish); 
	auto time_stop2 = high_resolution_clock::now(); 
	auto time_duration2 = duration_cast<microseconds>(time_stop2 - time_start2);
	cout << "\nTime taken by function: "<< time_duration2.count() << " Nanoseconds" << endl;

	
	return 0;
}
