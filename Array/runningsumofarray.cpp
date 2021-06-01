#include <bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
        
        int sum = 0;         
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];   
            nums[i] = sum;    
        }
        return nums;
        
    }

int main()
{
    int n ;
    cout << " enter size of vector" << endl ;   
    cin >> n ; 

    vector<int> in , out ; 

    for(int i = 0 ; i < n ; i++)
    {
    	int temp ; 
    	cin >> temp ; 
    	in.push_back(temp);
    }

    out = runningSum(in); 
 
 	for(int i = 0 ; i < n ; i++)
    {
    	cout << out[i] << " " ; 
    }



	return 0 ; 
}
