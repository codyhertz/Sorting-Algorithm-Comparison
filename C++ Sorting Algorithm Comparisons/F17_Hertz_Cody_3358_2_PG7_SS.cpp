// Roster Number  : 13
// Group number: 4
// Author: Cody Hertz
// Due Date: 12/06/2017
// Assignment Number: 7
// Fall-2017   -CS 3358 -002
// Instructor:  Husain Gholoom
// Benchmark that tests the speed of different algorithms in c++

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

void populateArray(int[], const int); // populates the array with any positive
                                      // number between 1 and 32000,
                                      // since it is the
                                      // largest possible with rand

bool sequentialSearch(int[], int, int&, const int); // searches the array
                                                    // sequentially
                                                    // to find the number passed
                                                    // in

void insertionSort(int[], int, int&); // sorts array using insertion sort
void quickSort(int[], int, int, int&, char); // sorts using quick sort
int nextToMiddlePivot(int); // sets the pivot to the element next to the middle


int main()
{

    srand(time(NULL)); // seed rand

    const int SIZE = 25000; // size of the array
    int arr[SIZE];

    cout << fixed << setprecision(3); // formatting

    // display welcome message
    cout << "Searching / Sorting Benchmark\n\n\nUsing a random number generator"
         << ", we are creating an array of " << SIZE << "\nelements of type "
         << "integer then performing the following\t:\n\n"
         << "\t1. Displaying the first 20 numbers.\n\n\t2. Using recursion,"
         << " Searching for an element in the array using\n\t\tsequential "
         << "search and at the end displaying number of comparisons\n\t\tit "
         << "makes.\n\n\t3. Sorting the array using insertion Sort and at the"
         << " end\n\t\tdisplaying the number of comparisons it makes.\n\n\t4. "
         << "Sorting the array using Quick Sort and at the end displaying\n"
         << "\t\tthe number of recursion calls it makes. Using the next to the"
         << "\n\t\tmiddle value as a pivot value.\n\n\t5. Sorting the same "
         << "array using Quick Sort and at the end\n\t\tdisplaying the number"
         << " of recursion calls it makes. Using the\n\t\tfirst value as a "
         << "pivot value.\n\n\t6. Sorting the same array using Quick sort and "
         << "at the end\n\t\tdisplaying the number of recursion calls it makes."
         << " Using the last value as a pivot value.\n\n\t7. For each of the "
         << "preceding steps ( 2 thru 5 ), calculating and\n\t\tprinting the "
         << "CPU time before each step starts and after each\n\t\tcompleted "
         << "step then calculating the actual CPU time for the\n\t\tcompletion "
         << "of each step.\n\n\n";

    // populate the array
    populateArray(arr,SIZE);

    // display first 20
    cout << "Displaying first 20: ";

    for(int i=0;i<20;i++)
    {
        cout << arr[i] << " ";

        // formating
        if(i==9)
        {
            cout << endl;
            for(int j=0;j<21;j++)
                cout << " ";
        }

    }

    cout << endl << endl;

    clock_t start, end; // create timer
    double timeElapsed;

    // sequential search
    int value = 12345; // number to be searched for
    int comparisons = 0;

    cout << "Sequential Search:\n\nSearching for " << value << endl << endl;

    // timer begin
    start = clock();

    if(sequentialSearch(arr, value, comparisons,SIZE))
    {
        cout << value << " Was found.\n";
    }
    else
    {
        cout << value << " was not found.\n";
    }

    // see how long it took
    end = clock();
    timeElapsed = end-start;
    comparisons+=1; // add one to comparison to better represent the number

    cout << "Start time :\t" << (float)start/CLOCKS_PER_SEC << " seconds"
         << endl;
    cout << "End time   :\t" << (float)end/CLOCKS_PER_SEC << " seconds" << endl;
    cout << "Actual CPU Clock time : " << (float)timeElapsed/CLOCKS_PER_SEC
         << " seconds" << endl;
    cout << "Total number of comparisons :\t" << comparisons << endl << endl;


    // insertion sort
    int temp[SIZE]; // temporary array

    // copy over contents
    for(int i=0;i<SIZE;i++)
    {
        temp[i]=arr[i];
    }

    cout << "Insertion Sort :\n\n";

    // start timer
    start=clock();
    comparisons=0; // reset comparisons

    insertionSort(temp,SIZE,comparisons);

    // see how long it took
    end=clock();
    timeElapsed=end-start;
    comparisons+=1; // add one to comparison to better represent the number

    cout << "Start time :\t" << (float)start/CLOCKS_PER_SEC << " seconds"
         << endl;
    cout << "End time   :\t" << (float)end/CLOCKS_PER_SEC << " seconds" << endl;
    cout << "Actual CPU Clock time : " << (float)timeElapsed/CLOCKS_PER_SEC
         << " seconds" << endl;
    cout << "Total number of comparisons :\t" << comparisons << endl << endl;

    // quick sort next to middle

    // reset temp
    for(int i=0;i<SIZE;i++)
    {
        temp[i]=arr[i];
    }

    start=clock();
    int recursiveCalls=0;

    cout << "Quick Sort - Next to the middle element as a pivot:\n\n";
    quickSort(temp,0,SIZE-1,comparisons,'n');

    // see how long it took
    end=clock();
    timeElapsed=end-start;
    comparisons+=1; // add one to comparison to better represent the number

    cout << "Start time :\t" << (float)start/CLOCKS_PER_SEC << " seconds"
         << endl;
    cout << "End time   :\t" << (float)end/CLOCKS_PER_SEC << " seconds" << endl;
    cout << "Actual CPU Clock time : " << (float)timeElapsed/CLOCKS_PER_SEC
         << " seconds" << endl;
    cout << "Total number of Recursive Calls :\t" << comparisons << endl
         << endl;


    // quick sort first element

    // reset temp
    for(int i=0;i<SIZE;i++)
    {
        temp[i]=arr[i];
    }

    start=clock();
    recursiveCalls=0;

    cout << "Quick Sort - First element as a pivot:\n\n";
    quickSort(temp,0,SIZE-1,comparisons,'f');

    // see how long it took
    end=clock();
    timeElapsed=end-start;
    comparisons+=1; // add one to comparison to better represent the number

    cout << "Start time :\t" << (float)start/CLOCKS_PER_SEC << " seconds"
         << endl;
    cout << "End time   :\t" << (float)end/CLOCKS_PER_SEC << " seconds" << endl;
    cout << "Actual CPU Clock time : " << (float)timeElapsed/CLOCKS_PER_SEC
         << endl;
    cout << "Total number of Recursive Calls :\t" << comparisons << endl
         << endl;


    // quick sort last element

    // reset temp
    for(int i=0;i<SIZE;i++)
    {
        temp[i]=arr[i];
    }

    start=clock();
    recursiveCalls=0;

    cout << "Quick Sort - Last element as a pivot:\n\n";
    quickSort(temp,0,SIZE-1,comparisons,'l');

    // see how long it took
    end=clock();
    timeElapsed=end-start;
    comparisons+=1; // add one to comparison to better represent the number

    cout << "Start time :\t" << (float)start/CLOCKS_PER_SEC << " seconds"
         << endl;
    cout << "End time   :\t" << (float)end/CLOCKS_PER_SEC << " seconds" << endl;
    cout << "Actual CPU Clock time : " << (float)timeElapsed/CLOCKS_PER_SEC
         << " seconds" << endl;
    cout << "Total number of Recursive Calls :\t" << comparisons << endl
         << endl;

    // parting message
    cout << endl << endl << endl;
    cout << "Benchmark Algorithm Implemented by : Cody, Hertz\n12 / 6 / 2017\n";


    return 0;
}


//**********************************************************
// Populates the array with numbers from 1-32k
// Parameters: arr, the array
//             SIZE, the size of the array
//**********************************************************
void populateArray(int arr[], const int SIZE)
{
    for(int i=0;i<SIZE;i++)
    {
        arr[i]=rand()%32000+1;
    }

}

//**********************************************************
// Searches the array sequentially for the value passed in
// Parameters: arr, the array
//             value, the value being searched for
//             comparisons, the number of comparisons
//             SIZE, the size of the array
// returns true if found, false if not found
//**********************************************************
bool sequentialSearch(int arr[], int value, int &comparisons, const int SIZE)
{
    if(arr[comparisons]==value)
    {
        return true;
    }
    else if(comparisons<SIZE)
    {
        comparisons+=1;
        return sequentialSearch(arr,value,comparisons,SIZE);
    }
    else
    {
        return false;
    }
}

//**********************************************************
// Sorts the array using insertion sort
// Parameters: arr, the array
//             comparisons, the number of comparisons
//             SIZE, the size of the array
//**********************************************************
void insertionSort(int arr[], int SIZE, int &comparisons)
{
    int key;
    for(int i=1;i<SIZE;i++)
    {
        key=arr[i];
        int j=i-1;

        if(arr[j]<=key)
        {
            comparisons++; // incase it doesnt enter the while
        }
        while(j>=0&&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;

            comparisons++;
        }
        arr[j+1]=key;
    }


}

//**********************************************************
// Sets the pivot point as middle+1
// Parameters: high, the highest index of the array in the
//                   quick sort function
//**********************************************************
int nextToMiddlePivot(int high)
{
    return (high)/2+1;
}

//**********************************************************
// Sorts the array using quick sort
// Parameters: arr, the array
//             comparisons, the number of comparisons
//             low, the lowest
//             high, the last index of the array
//             pivot, decides what pivot is used
//**********************************************************
void quickSort(int arr[], int low, int high, int &recursiveCalls, char pivot)
{
    recursiveCalls++;
    if(low<high)
    {
        int pivotValue;
        switch (pivot)
        {
            case 'n':
                pivotValue=arr[nextToMiddlePivot(high)];
                break;
            case 'f':
                pivotValue=arr[low];
                break;
            case 'l':
                pivotValue=arr[high];
                break;
        }
        int i=low-1;

        for(int j=low;j<high;j++)
        {

            if(arr[j]<=pivotValue)
            {
                i++; // count elements lower than pivot
                // swap
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;

            }
        }
        // swap
        int temp=arr[i+1];
        arr[i+1]=arr[high];
        arr[high]=arr[i+1];

        int pi=i+1; // where to partition

        quickSort(arr,low,pi-1,recursiveCalls,pivot);
        quickSort(arr,pi+1,high,recursiveCalls,pivot);
    }
}
