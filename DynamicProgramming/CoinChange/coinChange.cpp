#include<iostream>
#include<cstring>
using namespace std;

int Min_Coins(int coinsArr[], int amount, int numCoins)
{
  int table[amount+1];
  table[0] = 0; 
  for(int i=1;i<=amount;i++){ 
    table[i] = amount+1;
  }
  for(int currAmount=1;currAmount<=amount;currAmount++) 
  {
    for(int currCoin=0;currCoin<numCoins;currCoin++){ 
      if(coinsArr[currCoin] <= currAmount){ 
        table[currAmount] = min(table[currAmount], table[currAmount-coinsArr[currCoin]]+1); 
      }
    }
  }
  return (table[amount]>amount)?-1:table[amount]; 
}

int main()
{
  int amt,n;
  cout << "Enter the number of coins (assume that each denomination has infinite availability) : ";
  cin>>n;
  cout << "Enter the amount for which we need to be compute change : ";
  cin>>amt;
  int coinarr[n];
  for(int j=0;j<n;j++){
    cout << "Enter the denomination of "<< j+1 << " coin : ";
    cin>>coinarr[j];
  }
  cout << "Minimum number of coins needed: " << Min_Coins(coinarr, amt, n) << "\n";
  return 0;
}
