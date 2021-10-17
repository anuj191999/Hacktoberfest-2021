Question
Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.
  Input:
N = 7, K = 4
A[] = {1,2,1,3,4,2,3}
Output: 3 4 4 3
  
  
  Solution
   vector <int> countDistinct (int A[], int n, int k)
    {
        
vector<int> v;
map<int, int> m;
for(int i = 0; i < n; i++){
++m[A[i]];
if(i == k-1){
v.push_back(m.size());
}
if(i > k-1){
int first = i - k;
if(m[A[first]] > 1){
--m[A[first]];
}else{
m.erase(A[first]);
}
v.push_back(m.size());
}
}
return v;
}
    
