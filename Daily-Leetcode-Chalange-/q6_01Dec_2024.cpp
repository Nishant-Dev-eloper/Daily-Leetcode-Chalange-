/*
    1346. Check If N and Its Double Exist
    Solved
    Easy
    Topics
    Companies
    Hint
    Given an array arr of integers, check if there exist two indices i and j such that :
    
    i != j
    0 <= i, j < arr.length
    arr[i] == 2 * arr[j]
     
    
    Example 1:
    
    Input: arr = [10,2,5,3]
    Output: true
    Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]
    Example 2:
    
    Input: arr = [3,1,7,11]
    Output: false
    Explanation: There is no i and j that satisfy the conditions.
     
    
    Constraints:
    
    2 <= arr.length <= 500
    -103 <= arr[i] <= 103

  */


class Solution {
public:
// time complexity---> O(n^2)   [Brute force]
    // bool checkIfExist(vector<int>& arr) {
    //     for(int i=0;i<arr.size();i++){
    //         for(int j=0;j<arr.size();j++){
    //             if(arr[i]==2*arr[j] && i!=j){
    //                 return true;

    //             }
    //         }
    //     }
    //     return false;
    // }

    // unordered map--> (approach 2)-->

    bool checkIfExist(vector<int>& arr){
        unordered_map<int,int> mp;

        for(int i:arr){
            if(mp[2*i] ||( !(i&1) && mp[i/2])){
                return true;
            }
            mp[i]++;
        }
        return false;


    }


};
