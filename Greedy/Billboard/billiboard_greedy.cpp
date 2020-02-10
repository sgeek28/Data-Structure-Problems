#include<bits/stdc++.h> 
using namespace std; 
int main() 
{ 

	// Initializing a vector
	int n_sites=0,M,rev_total=0,c=0;
	vector<pair<int,int>> result1;
	vector<int> result2;
	int count1=0,count2=0;
	cout<<"Enter the number of sites"<<endl;
	cin>>n_sites; 
	cout<<"Enter the Highway length in kms"<<endl;
	cin>>M;
	int site_distarr[n_sites],revenue_arr[n_sites];
	cout<<"enter the distance of billiboards measured from western end"<<endl;
	for(int i=0;i<n_sites;i++)
		cin>>site_distarr[i];
	cout<<"enter the revenue of billiboards if placed on highway"<<endl;
	for(int j=0;j<n_sites;j++)
		cin>>revenue_arr[j];  

        priority_queue<pair<int, int> > pq; 
	for(int j=0;j<n_sites;j++){
        	pq.push(make_pair(revenue_arr[j],site_distarr[j]));
		result1.push_back(make_pair(revenue_arr[j],site_distarr[j]));
	}
	while(!pq.empty() && pq.size()>1){
		pair<int, int> max1 = pq.top();
		pq.pop();
		pair<int, int> max2 = pq.top();
		pq.pop();
		if(max1.second<max2.second && max2.second-max1.second>5 && (count1==0 && count2==0))
		{
			count2=1;
			rev_total+=max1.first+max2.first;
			pq.push(make_pair(rev_total,max2.second));
		}
		if(max1.second>max2.second && max1.second-max2.second>5 && (count2==0 && count1==0))
		{
			count1=1;
			rev_total+=max1.first+max2.first;
			pq.push(make_pair(rev_total,max2.second));
		}
		else{
			pq.push(make_pair(max1.first,max1.second));
		}
		if(pq.size()==1 && result1.size()>c){
			c+=1;
			result2.push_back(pq.top().first);
			rev_total=0;
			pq.pop();
			count1=0;
			count2=0;
			for(int i=c;i<result1.size();i++){
				pq.push(make_pair(result1[i].first,result1[i].second));
                        }
		}
	}
	sort(result2.begin(),result2.end(),greater<int>());
	cout<<"The maximum revenue is "<<result2[0]<<endl; 	
	return 0; 
} 

