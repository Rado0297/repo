#include<iostream>
#include<cstring>
using namespace std;


const int NUM = 300;
class Stack
{
public:
   Stack(); 				// конструктор по подразбиране
   void push(const char&); 		// включва елемент в стек
   void pop(); 		// изключва елемент от стек
   bool empty() const; 		// проверява дали стек е празен
   bool full() const; 			// проверява дали стек е пълен
   void print(); 			// извежда елементите на стек
   char top() const;
private:
   int n; 				// указател към върха на стека
   char arr[NUM]; 			// представяне на стека
};

int arrLength(const char* array)
{
    int n = 0;
    while (array[n] != '\0') {
        n++;
    }

    return n;
}

Stack::Stack(){
    n = 0;
    arr[n] = {'\0'};
}

bool Stack::empty() const
{
    return n == 0;
}

bool Stack::full() const
{
    return n == NUM;
}

void Stack::push(const char &x)
{

    if (!full()) {
        arr[n] = x;
        arr[n+1] = '\0';
        n++;
    }
}
/*
void Stack::pop(char &x)
{
    if(!empty())
    {
        int i = 0;

        char temp[NUM];

        while (arr[i] != '\0') {
            if (arr[i] == x) {
                temp[i] = arr[i+1];
            }

            temp[i] = arr[i];

            i++;
        }
    }
}
*/

void Stack::pop()
{
    if (!empty()) {
        n--;
        arr[n] = '\0';
    }
}

void Stack::print()
{
    int i = 0;
    while (i < n) {
        cout << arr[n-1-i] << endl;
        i++;
    }
}

char Stack::top() const
{
    if(!empty())
        return arr[n-1];
}

int f(int x)
{
    return (x + 1) % 10;
}

int g(int x)
{
    return (x + 9) % 10;
}

int h(int x, int y)
{
    return (x + y) % 10;
}

int main ()
{
    Stack command;
    Stack numbers;

    char c;
    cin>>c;

    command.push(c);
    cin>>c;

    int b=1;
    while(b != 0){
        cin>>c;

        if(c == '(')
            b++;
        else if(c == ')')
            b--;
        else if(c >= '0' && c <= '9')
            numbers.push(c);
        else
            command.push(c);
    }
    //
    int x, y;
    while(!command.empty()){
        c = command.top();
        command.pop();
        x = numbers.top()-'0';
        numbers.pop();

        if(c == 'f')
            numbers.push(f(x)+'0');
        else if(c == 'g')
            numbers.push(g(x)+'0');
        else
        {
            y=numbers.top()-'0';
            numbers.pop();
            numbers.push(h(x, y)+'0');
        }
    }
    x = numbers.top()-'0';
    cout << x << endl;

    return 0;
}
