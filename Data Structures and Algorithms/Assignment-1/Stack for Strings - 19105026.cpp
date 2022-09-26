//ASSIGNMENT-1, PALASH VIJ, 19105026, ECE

#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

class Stack {
    int top;

public:
    string a[MAX]; // Maximum size of Stack

    Stack() { top = -1; }
    bool push(string s);
    string pop();
    string peek();
    bool isEmpty();
    void display();
};

bool Stack::push(string s)
{
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        a[++top] = s;
        cout << s << " pushed into stack\n";
        return true;
    }
}

string Stack::pop()
{
    if (top < 0) {
        
        cout<< "Stack Underflow"<<endl;
        
    }
    else {
        string x = a[top--];
        cout<< (x + " popped from stack")<<endl;
        
    }
    return "";
}
string Stack::peek()
{
    if (top < 0) {
        cout << "Stack is Empty";
        return "";
    }
    else {
        string x = a[top];
        return x;
    }
}

void Stack:: display()
{
    if(top>=0) {
      cout<<"Stack elements are:";
      for(int i=top; i>=0; i--)
        cout<<a[i]<<" ";
      cout<<endl;
   } 
   else{
    cout<<"Stack is empty"<<endl;
   }
    
}
// bool Stack::isEmpty()
// {
//     return (top < 0);
// }

int main()
{
    class Stack s;
    cout<<"Implementation of Stack"<<endl;
    
    bool exit  = false;
    while(!exit){
        cout<<"Choose from options: "<<endl;
        cout<<"1. push"<<endl;
        cout<<"2. pop"<<endl;
        cout<<"3. peek"<<endl;
        cout<<"4. Display"<<endl;
        cout<<"5. exit"<<endl;
        int x;
        cin>>x;
        if(x==1){
            cout<<"Enter the string:"<<endl;
            string st;
            cin>>st;
            s.push(st);
            cout<<st<<" pushed into the stack"<<endl;
            
        }
        else if(x==2){
            s.pop();
        }
        else if(x==3){
            cout << "Top element is : " << s.peek() << endl;
        }
        else if(x==4){
            s.display();
        }
        else{
            exit = true;
        }
    }
    

    return 0;
}
