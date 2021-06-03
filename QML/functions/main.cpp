#include <iostream>
#include <ctime>

using namespace std;

// function call by pointers
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// function call by reference
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void getSeconds(unsigned long *par) {
    *par = time(0);
    //    *par = ctime(&(time(0)));
    return;
}


int main()
{
    int a = 30, b = 40;
    cout << a << b << endl;
    swap(&a, &b);
    cout << a << b << endl;
    swap(a, b);
    cout << a  << b << endl;
    unsigned long sec;
    getSeconds(&sec);
    cout << "Number of seconds :" << sec << endl;
    time_t t = time(0);

    // convert now to string form
//    char* dt = ctime(&now);
    tm* now = localtime(&t);
    cout << "The local date and time is: " << now->tm_year << endl;


    return 0;
}
