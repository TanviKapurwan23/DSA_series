#include <iostream>>
using namespace std;

int main()
{

    int n;
    cin >> n;

    char arr[n + 1];   // why?
    cin >> arr;

    bool check = 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[n - 1 - i])
        {
            check = 0;
            break;
        }
    }

    if (check == true){
        cout<<"The word is a palindrome";
    } else{
        cout<<"The word is not a palindrome";
    }

    return 0;
}