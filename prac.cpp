#include<iostream>

using namespace std;

void print(int arr[], int size);
bool check_arr(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        if (arr[i] != i+1)
        {
            return false;
        }
    }

    return true;
}

int * calculate_swaps(int arr[], int size)
{
    int i = 0;
    int j = 1;
    int swaps = 0;
    while(i < size)
    {
        if (arr[i] != j)
        {
            int temp = arr[i];
            if (arr[i] == j+1)
            {
                arr[i] = arr[i+1];
                arr[i+1] = temp;  
            } 
            else if(arr[i] == j-1)
            {
                arr[i] = arr[i-1];
                arr[i-1] = temp;  
            }
            else
            {
                int elem = arr[i]-1;
                arr[i] = arr[elem];
                arr[elem] = temp;
                i++;
                j++;
            }
            swaps++;
        }
        else
        {
            i++;
            j++;
        }

        // print(arr, size);
    }

    // for (int i=0; i<size; i++){
    //     cout << arr[i] << endl;
    // }

    // cout << "\n\n";
    // cout << "Swaps are : " << swaps << endl;

        return arr;
}

void print(int arr[], int size)
{
    cout << "the array state : ";
    for (int i=0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int size;
    int *arr;
    cout << "Enter the size of array: " << endl;
    cin >> size;

    int list[size];

    cout << "Enter the elements for array: " << endl;
    for (int i=0; i<size; i++)
    {
        int val;
        cin >> val;
        list[i] = val;
    }

    bool proceed = false;
    while (!proceed)
    {
        arr = calculate_swaps(list, size);
        proceed = check_arr(arr, size);
        print(arr, size);
    }

    cout << "Final array: \n" << endl;
    print(arr, size);
    // cout << list[list[0]-1];
    return 0;
}