#include <iostream>
using std::cin; using std::cout; using std::endl;

class Search
{
    public:

    int size;
    int* arr;  

    Search()
    {
        cout<<"Enter the size of the array:";
        cin>>size;

        arr = new int[size];    

        for(int i = 0; i<size; i++) 
        {
            cout<<"Element "<<i+1<<":";
            cin>>arr[i];
        }
    }

    int Binary_Search(int x, int low, int high)  
    {
        if(high >= low)  
        {
            int mid = (low+high)/2; 

            if(x == arr[mid])  
            {
                return mid;
            }

            else if(x > arr[mid])  
                                   
            {
                low = mid + 1;
                Binary_Search(x, low, high);
            }

            else    
            {
                high = mid - 1;
                Binary_Search(x, low, high);
            }
        }

        else
        {
            return -1;  // element was not  in the array
        }
        
    }

};

int main()
{
    Search s;
    int x;

    cout<<"Enter the element to be searched:";
    cin>>x;

    cout<<"The element was discovered at index:"<<s.Binary_Search(x, 0, s.size)<<endl;
}
