#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class solution{
    private:

    int parent(int i){
        return (i-1)/2;
    }

    int left(int i){
        return (2*i)+1;
    }

    int right(int i){
        return (2*i)+2;
    }

    void downheapify(vector<int>&arr,int n,int index){
        
        int smallest=index;
        int l=left(index);
        int r=right(index);

        if(l<arr.size() && arr[l]<arr[smallest]){
            smallest=l;
        }

        if(r<arr.size() && arr[r]<arr[smallest]){
            smallest=r;
        }

        if(smallest!=index){
            swap(arr[index],arr[smallest]);
            downheapify(arr,arr.size(),smallest);
        }
    }

    public:

    void heapify(vector<int>arr){
        int n=arr.size();
        for(int i=(n/2)-1;i>=0;i--){
            downheapify(arr,n,i);
        }
    }
};