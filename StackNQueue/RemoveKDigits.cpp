class Solution {
public:
    string removeKdigits(string num, int k) {
        string result="";
        int size=num.length();
          // number of operation greater than length we return an empty string
        if(size<= k)   
            return "0";
        
        if(k == 0)
            return num;
        for(int i=0;i<size;i++){
            while(!result.empty()&&num[i]<result.back()&&k>0){
                result.pop_back();
                k--;
            }
            if(!result.empty()||num[i]!='0'){
                result.push_back(num[i]);
            }
        }
        while (k > 0 && !result.empty()) {
            result.pop_back();
            k--;
        }

        // If the result is empty, return "0".
        return result.empty() ? "0" : result;
    }
};

/*
Here the aim is to get the smallest number by deleting k elements but the order of elements cannot be changed.
eg: "1 4 3 2 2 1 9" k=3
       X X X      
Remove 3 elements without changing order and then shift

To get the min elements we arrange the elements in increasing order so that in the most significant place value we have the smallest value.

If we ever find the greater elements before the present value we pop it out till we are able to pop out 3 elements.

Edge case: "1 2 3"
           "1 2 3 0" can push 0 or any number since result is not empty 

           "" if result is empty and not equal to zero can push it otherwise can't push it because it is 0 has no value

*/
