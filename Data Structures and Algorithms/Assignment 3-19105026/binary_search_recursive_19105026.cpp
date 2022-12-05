#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &arr, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == x){
            
            return mid;
        }
            
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<"Enter size of array"<<endl;
    int n;
    cin>>n;
    cout<<"Enter elements of array"<<endl;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<"Enter element to be found:"<<endl;
    int x;
    cin>>x;
    sort(v.begin(),v.end());
    int result = binarySearch(v, 0, n - 1, x);
    (result == -1)? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
}