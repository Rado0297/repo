#include<iostream>
#include<cstring>
using namespace std;

/*
    A linked list - each element has a value field and a link to the next element in the sequence.
    By default, every new element is a new sequence with a single element and the link points to the NULL-pointer.
*/
template<typename T>
struct Node{
    T value;
    Node<T>* link;
    Node<T>(T const&);
};
template<typename T>
Node<T>::Node(T const& v){
    value=v;
    link=NULL;
}


template<typename T>
class Stack{
    private:
        Node<T>* start;                         //pointer to the top element
        void deleteStack();                     //function that deletes the stack
        void copyStack(Stack const&);           //function that copies another stack to the stack
    public:
        Stack();                                //constructor
        ~Stack();                               //destructor
        Stack(Stack const&);                    //copy-constructor
        Stack& operator =(Stack const&);        //operator Equal
        bool empty() const;                     //function that checks if the stack has any elements
        void push(T const&);                    //function that adds an new element on the top of the stack
        void pop();                             //function that removes the top element of the stack
        T top()const;                           //function that returns the top element's value
};

/*
    Constructor:
    Creates the stack.
    By default, start-pointer don't points anything, i.e. points to the NULL-pointer
*/
template<typename T>
Stack<T>::Stack(){
    start=NULL;
}

/*
    Delete function:
    Deletes every single element of the linked list
*/
template<typename T>
void Stack<T>::deleteStack(){
    Node<T>*p;
    while(start){
        p=start;
        start=start->link;
        delete p;
    }
}

/*
    Destructor:
    Deletes the stack
*/
template<typename T>
Stack<T>::~Stack(){
    deleteStack();
}

/*
    Copy function:
    Copies another stack's element to the current stack in the same order.
*/
template<typename T>
void Stack<T>::copyStack(Stack<T> const& other){
    Node<T> *pthis, *pother=other.start;
    Node<T>v(other.start->value);
    start=&v;
    pthis=start;
    while(pother){
        pother=pother->link;
        Node<T>v(pother->value);
        pthis->link=&v;
        pthis=&v;
    }
    pthis->link=NULL;
}

/*
    Copy Constructor:
    Copy a stack to the current empty stack.
*/
template<typename T>
Stack<T>::Stack(Stack const& other){
    copyStack(other);
}

/*
    Operator Equal:
    Deletes the current stack and copies the other stack's elements in it.
*/
template<typename T>
Stack<T>& Stack<T>::operator =(Stack<T> const& other){
    if(*this!=other){
        deleteStack();
        copyStack(other);
    }
}

/*
    Empty function:
    Checks if start points to NULL-pointer, i.e. if there is any elements in the stack.
*/
template<typename T>
bool Stack<T>::empty() const{
    return start==NULL;
}

/*
    Push Function:
    Adds a new element with value=x on the top of the stack.
*/
template<typename T>
void Stack<T>::push(T const& x){
    Node<T>* v=new Node<T>(x);
    if(!empty())
        v->link=start;
    start=v;
}

/*
    Pop function:
    Deletes the top element of the stack.
*/
template<typename T>
void Stack<T>::pop(){
    if(!empty()){
        Node<T>*p;
        p=start;
        start=start->link;
        delete p;
    }
}

/*
    Top function:
    Returns the value of the top element of the stack.
*/
template<typename T>
T Stack<T>::top()const{
    if(!empty())
        return start->value;
}


int f(int x){
    return (x+1)%10;
}

int g(int x){
    return (x+9)%10;
}

int h(int x, int y){
    return (x+y)%10;
}


int main ()
{
    Stack<char>command;
    Stack<int>numbers;
    char c;
    cin>>c;
    command.push(c);
    cin>>c;
    int b=1;
    while(b!=0){
        cin>>c;
        if(c=='(')b++;
        else if(c==')')b--;
        else if(c>='0' && c<='9')numbers.push(c-'0');
        else command.push(c);
    }
    int x, y;
    while(!command.empty()){
        c=command.top();
        command.pop();
        x=numbers.top();
        numbers.pop();
        if(c=='f')numbers.push(f(x));
        else if(c=='g')numbers.push(g(x));
        else{
            y=numbers.top();
            numbers.pop();
            numbers.push(h(x, y));
        }
    }
    x=numbers.top();
    cout<<x<<endl;


    return 0;
}
