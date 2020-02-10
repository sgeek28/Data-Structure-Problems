//01knapsack Dynamic Programming
#include<iostream>
using namespace std;
int max(int x, int y)
{
  return (x>y)? x:y;
}

int Knapsack01(int profit[], int weight[],int knapsack_cap, int no_of_items)
{
  int table[no_of_items+1][knapsack_cap+1];
  for(int i=0;i<=no_of_items;i++)
  {
    for(int w=0;w<=knapsack_cap;w++)
    {
      if(i == 0 || w == 0){ //if no items or Knapsack weight is 0
        table[i][w] = 0; //corresponding profit is 0
      }
      else if(weight[i-1]<= knapsack_cap) //ith object is present at index i-1
      {
        table[i][w] = max(profit[i-1] + table[i-1][w-weight[i-1]], table[i-1][w]);
      }
      else{ // if current object weight more than weight of Knapsack
        table[i][w] = table[i-1][w];
      }
    }
  }
  return table[no_of_items][knapsack_cap];
}

int main()
{
  int n,m;
  cout << "Enter the number of items : ";
  cin>>n;
  cout << "Enter the capacity of Knapsack : ";
  cin>>m;
  int profit[n],weight[n];
  cout<<"Enter the profit and weight for each item"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>profit[i]>>weight[i];
  }
  cout << "Maximum Profit : " << Knapsack01(profit,weight,m,n) << "\n";
  return 0;
}
