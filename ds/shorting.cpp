#include <iostream>
using std::cin; using std::cout; using std::endl;

template <typename t>
class Sorting
{
    int size;
    t* arr;   
    int comp = 0;

    public:

    Sorting()
    {
        cout<<"Please Enter the size of the array:";
        cin>>size;

        arr = new t[size];    //dynamically making an array 

        for(int i = 0; i<size; i++) //loop to read the elements of the array
        {
            cout<<"Element "<<i+1<<":";
            cin>>arr[i];
        }
    }

    void swap(t& a, t& b)  //Function to swap two numbers. 
    {
        t temp = a;
        a = b;
        b = temp;
    }

    void Bubble_sort()
    {
        for(int i = 0; i < size; i++) 
                                
        {
            for(int j = 0; j < size; j++) 
            {
                comp++;
                if(arr[i]<arr[j])
                {
                    swap(arr[i],arr[j]);  
                }
            }
        }

        cout<<"The number of comparisons made is"<<comp<<endl;
    }

    void Insertion_sort()
    {
        for(int i = 0; i<size; i++)
        {
            for(int j = 0; j<i-1;j++)
            {
                comp++;
                if(arr[i]<arr[j])
                {
                    swap(arr[i],arr[j]);
                }

                else
                {
                    break;
                }
            }
        }

        cout<<"The number of comparisons made is"<<comp<<endl;
    }

    int display() 
    {
        cout<<"{ ";
        for(int i = 0; i < size; i++)
        {
            cout<<arr[i]<<" ";
        }

        cout<<"}";
    }

    void Selection_sort()
    {
        int minimum;
        for(int i = 0; i < size; i++)
        {
           minimum = arr[i];
           for(int j = i; j < size; j++)
           {
                comp++;
                if(arr[j]<minimum)
                {
                    swap(arr[i],arr[j]);
                    minimum = arr[i];
                }
           }
        }

        cout<<"The number of comparisons made is"<<comp<<endl;
    }
};


int main()
{
    Sorting<char> s;
    int choice = 0;

    cout<<"method would you like to sort the array"<<endl;
    cout<<"Bubble Sort"<<endl;
    cout<<"Insertion Sort"<<endl;
    cout<<"Selection Sort\nChoice";
    cin>>choice;

    if(choice ==1)
    {
        s.Bubble_sort();
    }

    else if(choice == 2)
    {
        s.Insertion_sort();
    }

    else if(choice == 3)
    {
        s.Selection_sort();
    }

    else
    {
        cout<<"Enter a valid choice."<<endl;
        return 0;
    }

    s.display();
    return 0;
}
