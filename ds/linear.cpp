#include <iostream>
using std::cin; using std::cout; using std::endl;

class Search
{
    int size;
    int* arr;  //int type pointer 

    public:

    Search()
    {
        cout<<"Enter the size of the array";
        cin>>size;

        arr = new int[size]; 

        for(int i = 0; i<size; i++)  // read the elements of the array
        {
            cout<<"Element "<<i+1<<":";
            cin>>arr[i];
        }
    }

    int Linear_Seach(int a)
    {
        for(int i = 0; i < size; i++) // search the array and returning the index
        {
            if(arr[i]==a)
            {
                return i;
            }
        }

        return -1;  // show the element was not  in the array
    }
};

int main()
{
    Search s;  
    int x;

    cout<<"Enter the element to be searched:";
    cin>>x;

    cout<<"The Element was discovered at index:"<<s.Linear_Seach(x)<<endl;
}
