// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    unordered_map<int,int>mp;
    public:
    int maxSum(int arr[],int i,int size){
        if(i >= size)
            return 0;
            
            int sum = 0;
        
        sum += arr[i];
        if(mp.find(i+2) == mp.end()){
            sum = arr[i] + maxSum(arr,i+2,size);
            mp.insert({i+2,sum-arr[i]});
        }else
            sum += mp.find(i+2)->second;
             
            
            int sum2 = 0;
        if(mp.find(i+1) == mp.end()){
            sum2 = maxSum(arr,i+1,size);
            mp.insert({i+1,sum2});
        }else
            sum2 += mp.find(i+1)->second;
             
             
        return max(sum,sum2);
        
    }
    int FindMaxSum(int arr[], int n)
    {
        
        int sum = arr[0] + maxSum(arr,2,n);
        mp.insert({2,sum});
        int sum2 = maxSum(arr,1,n);
       
        return max(sum,sum2);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends