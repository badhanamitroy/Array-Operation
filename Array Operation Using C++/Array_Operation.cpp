#include<iostream>
using namespace std;

/*Funtion lists*/
int ask();
void underline();
int menu();
void create(int arr[], int &n);
void display(int arr[], int n);
void insertion(int arr[], int &n);
void deletion(int arr[], int &n, int &element);
void linear_search(int arr[], int &n, int &element);
void Binary_search(int arr[], int &n, int &element);
void bubble_sort(int arr[], int &n);
/*Funtion lists*/

//Gloval variables
int n,i;
int arr[50];
int element;
int found=0;
//Gloval variables

void underline()
{
    cout<<endl;
    for(int ul=0; ul<=50; ul++)
    {
        cout<<"-=";
    }
    cout<<"-"<<endl<<endl;
}

void create(int arr[], int &n)
{
    cout<<"Create an Array list first"<<endl;
    underline();
    cout<<"Enter the size of your list (Size should not be more than 50)."<<endl<<endl
        <<"    Size: ";
    cin>>n;

    cout<<endl<<"Enter list items."<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
}

void display(int arr[], int n)
{
    cout<<"Data list."<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertion(int arr[], int &n)
{
    int pos, element;
    cout<<"Enter the position to insert : ";
    cin>>pos;
    cout<<"Enter the element to insert : ";
    cin>>element;
    for(int i=n; i>=pos; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[pos-1]=element;
    n++;
    cout<<endl<<"Insertion Completed."<<endl<<endl;
    cout<<"New Modified ";
    display(arr, n);
}

void deletion(int arr[], int &n, int &element)
{
    int pos;
    cout<<"Enter the element to delete element : ";
    cin>>element;

    for(int i=0; i<n; i++)
    {
        if (arr[i]==element)
        {
            arr[i]=arr[i+1];
        }
    }
    n--;
    cout<<endl<<"Deletion Completed."<<endl<<endl;
    cout<<"New Modified ";
    display(arr, n);
}

void linear_search(int arr[], int &n, int &element)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i]==element)
        {
            cout<<"Indexing the list from 0, The item "<<arr[i]
                <<" is found at the index "<<i<<" ."<<endl;
            found=1;
            break;
        }
    }
    if(found=0)
    {
        cout<<"The item "<<element<<"is not found at list. "<<endl;
    }
}

void bubble_sort(int arr[], int &n)
{
    for(int pass=1; pass<n; pass++)
    {
        for(int i=0; i<n-pass; i++)
        {
            if(arr[i]>arr[i+1])
            {
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
    }
}

void Binary_search(int arr[], int &n, int &element)
{
    bubble_sort(arr, n);
    cout<<"New sorted ";
    display(arr, n);
    cout<<endl;
    int LB = 0, UB = n - 1;

    while (LB <= UB)
    {
        int mid = (LB + UB) / 2;
        if (arr[mid] == element)
        {
            cout << "Indexing the list from 0, The item " << arr[mid]
                 << " is found at the index " << mid << " ." << endl;
            found = 1;
            break;
        }
        else if (arr[mid] > element)
        {
            UB = mid - 1;
        }
        else
        {
            LB = mid + 1;
        }
    }
    if (found == 0)
    {
        cout << "The item " << element << " is not found in the list." << endl;
    }
}

int ask()
{
    underline();

    cout<<"Want to continue to the program?"<<endl<<"   1. Yes"<<endl<<"   2. No"<<endl<<"Your reply: ";
    string ask;
    cin>>ask;
    if((ask=="yes")||(ask=="Yes")||(ask=="1"))
    {
        system("cls");
        menu();
    }
    if((ask=="no")||(ask=="No")||(ask=="2"))
    {
        return 0;
    }
}

int menu()
{
    system("cls");

    cout<<"Which operation do you want to perform?"<<endl
        <<"  1. Display you element list"<<endl
        <<"  2. Insert an element to the list"<<endl
        <<"  3. Delete an element from the list"<<endl
        <<"  4. Search for an element to the list"<<endl
        <<"  5. Exit"<<endl;
    underline();
    cout<<"Your Reply (1/2/3/4/5): ";
    int choice;
    cin>>choice;
    underline();
    if(choice==1)
    {
        display(arr, n);
        ask();
    }
    else if(choice==2)
    {
        cout<<"Existing ";
        display(arr, n);
        underline();
        insertion(arr, n);
        ask();
    }
    else if(choice==3)
    {
        cout<<"Existing ";
        display(arr, n);
        underline();
        deletion(arr, n, element);
        ask();
    }
    else if(choice==4)
    {
        cout<<"Existing ";
        display(arr, n);
        underline();
        cout<<"Insert the element to search"<<endl;
        cin>>element;
        cout<<endl<<"Which type of Searching Algorithm do you want to apply?"<<endl
            <<"   1. Linear Search"<<endl<<"   2. Binary Search"<<endl;
        int search_type;
        cout<<"Search type: ";
        cin>>search_type;
        cout<<endl;

        if(search_type==1)
        {
            linear_search(arr, n, element);
        }
        if(search_type==2)
        {
            Binary_search(arr, n, element);
        }
        ask();
    }
    else if(choice==5)
    {
        return 0;
    }
    else
    {
        cout<<"invalid Choice";
    }

}

int main()
{
    /*Presentation Title*/
    cout<<"Presentation on Array Operation"<<endl
        <<"Course Title: Algorithm Lab"<<endl
        <<"Course Code: CSE 228"<<endl
        <<"Submitted By: Badhan Roy Amit [CSE 02807571] "<<endl
        <<"Submitted To: Mrs. Taofica Amrine [Chairman of CSE depertment, PCIU] "<<endl;
    underline();
    /*Presentation Title*/

    cout<<"Want to continue to the program?"<<endl<<"   1. Yes"<<endl<<"   2. No"<<endl<<"Your reply: ";
    string ask;
    cin>>ask;
    if((ask=="yes")||(ask=="Yes")||(ask=="1"))
    {
        system("cls");
        create(arr, n);
        system("cls");
        menu();
    }
    if((ask=="no")||(ask=="No")||(ask=="2"))
    {
        return 0;
    }
    return 0;
}
