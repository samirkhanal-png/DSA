#include<bits/stdc++.h>
vector<int> alternateNumbers(vector<int>&a) {
 vector<int> pos,neg; //return the ans in the same array a
 for(int i=0;i<a.size();i++){
     if(a[i]>0){
         pos.push_back(a[i]);
     }
     else{
         neg.push_back(a[i]);
     }
 }

 if(pos.size()>neg.size()){ //here array of negative elements is less than positive elements
                            //jun chai less xa tesko anusar fill garne
                            //first filling the positive and negative elements double the number of elements in smaller array  )
   for(int i=0;i<neg.size();i++){
       a[2*i]=pos[i];
       a[2*i+1]=neg[i];
   }

//filling the remaining elements
   int index=neg.size()*2;  //starting index for the ans array for remaining of the greater array
   for(int i=neg.size();i<pos.size();i++)    //here lower index will be equal to that of the array which has less elements so that we can fill the elements in the pos(greater array from the position where it was left off)
   {
       a[index]=pos[i]; //start filling the remaining elements of the greater array
       index++;
   }

 }
 else{ //here array of positive elements is greater than negative elements
    for(int i=0;i<pos.size();i++){
        a[2*i]=pos[i];
        a[2*i+1]=neg[i];
    }

    int index=pos.size()*2; //filling according to the less than array
    for(int i=neg.size();i<pos.size();i++)   //index for the greater remaining elements
    {a[index]=neg[i];
     index++;
    }
 }
return a;
}
//T.C O(n)  Space complexity O(1)    iterates through the original vector for separating pos and neg O(n) and again for filling into ans O(n) so O(2n)
//https://www.naukri.com/code360/problems/alternate-numbers_678344

/*

*/
