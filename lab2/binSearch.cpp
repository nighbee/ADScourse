# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

int binSearch(vector<int> arr, int low, int high, int x){ 
    while(low<=high){ 
        int mid = low + (high - low) / 2; 
        if(arr[mid] == x) return mid; 
        if(arr[mid] < x) low = mid + 1; 
        else high = mid - 1; 
    }
}

int main(){ 
vector<int>  a={1,2,3, 5 , 4 ,1  }; 

    int x = 5; 
    int n= sizeof(a)/ sizeof(a[0]); 
    int result= binSearch(a,0, n-1, x ); 
    cout<<"element is on index: "<< result;
} 


// Bitonic array first increase then decrease 
// 1 2 3 4 5 6 7 8 9 10 9 8 7 6 5 4 3 2 1

int ascendingSearch(int arr[], int low, int high, int x){ 
    while( low <= high) { 
        int mid =low+ (high-low)/2; 
        if (arr[mid] == x) return mid;
        if(arr[mid]> x ) high = mid -1; 
        else low = mid + 1;  
    }
    return -1; 
} 

int descendingSearch(int arr[], int low, int high, int x){ 
    
    while( low <= high) { 
        int mid =low+ (high-low)/2; 
        if (arr[mid] == x) return mid;
        if(arr[mid]> x ) high = mid -1; 
        else low = mid + 1;  
    }
    return -1; 
} 

int findBitonicPoint(int arr[], int n, int l, int r){ 
    int mid; 
    int bitonicPoint=0; 
    mid = (r+l)/2; 
    if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
    else if(arr[mid] > arr[mid-1] && arr[mid] < arr[mid+1]) return findBitonicPoint(arr, n, mid, r);
    else if(arr[mid] < arr[mid-1] && arr[mid] > arr[mid+1]) return findBitonicPoint(arr, n, l, mid);
    return bitonicPoint;
}
