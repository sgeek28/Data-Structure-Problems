#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
/*struct Test 
{ 
   int first, second, third; 
};*/
void lectureHallSelection(vector<int> start,vector<int> finish)
{
	
	int d,c,s;

	// Min heap stroing start time or finish time as keys and activity number
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pqueue;
	//Min heap storing start time or finish time as keys and value 0/1
	//start =0
	//finish=1
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pqueue2;
	//vector to store start time/finish time and alloted hall number
	vector<pair<int,int>> hallAssignment;
	//vector to store start time/finish time and activity number
	vector<pair<int,int>> hallAssignment2;
	//hall which is already used or new one which is avilable for allotment 
	queue <int> lectureAvailable;
	for(int i=0;i<start.size();i++){
		pqueue2.push(make_pair(start[i],0));
		pqueue.push(make_pair(start[i],i+1));
	}
	for(int j=0;j<finish.size();j++){
		pqueue2.push(make_pair(finish[j],1));
		pqueue.push(make_pair(finish[j],j+1));
	}
	//printing starting and ending time of all activities stored in priority queue
    	/*while (!pqueue.empty()) { 
		auto ref3=pqueue.top();
        	cout <<ref3.first<<","<<ref3.second<<endl; 
        	pqueue.pop(); 
    	} */
	d=0;
	while(!pqueue.empty() && !pqueue2.empty()){
		auto extract_min=pqueue2.top();
		auto extract_min2=pqueue.top();
	//if extract min is start time
		if(extract_min.second==0){
			//there is some hall that was used but is available right now
			if(!lectureAvailable.empty()){
				//assign the available lecture to c to reuse it
				c=lectureAvailable.front();
				lectureAvailable.pop();			
			}
			else{
			//all halls that’s ever used are being used
			// so need to get a new hall			
			d=d+1;
			c=d;
			}
			// assign hall c to an activity
			hallAssignment.push_back(make_pair(extract_min2.first,c)); 
			hallAssignment2.push_back(make_pair(extract_min2.first,extract_min2.second));
					
		}
		else{
			// if extract min is finish time
			// assign hall of an activity to c
			auto refer3=hallAssignment.begin();
			for(auto refer2=hallAssignment2.begin();refer2!=hallAssignment2.end();refer2++)
			{
				if(extract_min2.second==(*refer2).second){ 			
					c=(*refer3).second;
					// release hall c and put it in pool
			        	lectureAvailable.push(c);
				}
				//cout<<"finish time";
				refer3++;
			}		
		}
		pqueue.pop();
		pqueue2.pop();	
	 }
     	auto refer4=hallAssignment2.begin();
	for(auto it=hallAssignment.begin();it!=hallAssignment.end();it++){
		cout<<"Activity No "<<(*refer4).second<<" has been assigned hall no "<<(*it).second<<endl;
		refer4++;
	}
	cout<<endl<<"Minimum number of lecture halls needed is "<<(*max_element(hallAssignment.begin(), hallAssignment.end())).second<<endl; 

}
int main()
{
	int n,a,b;
	vector<int> start;
	vector<int> finish;
	cout<<"Enter the number of lectures we need to complete"<<endl;
	cin>>n;
	cout<<"Enter the start time of all lectures one by one"<<endl;
	for(int i=0;i<n;i++){
		cin>>a;
		start.push_back(a);
	}
	cout<<"Enter the end time of all lectures one by one"<<endl;
	for(int j=0;j<n;j++){
		cin>>b;
		finish.push_back(b);
	}
	auto time_start1 = high_resolution_clock::now();
	lectureHallSelection(start,finish);
	auto time_stop1 = high_resolution_clock::now(); 
	auto time_duration1 = duration_cast<microseconds>(time_stop1 - time_start1);
	cout << "\nTime taken by function: "<< time_duration1.count() << " Nanoseconds" << endl<<endl;
	return 0;
}
