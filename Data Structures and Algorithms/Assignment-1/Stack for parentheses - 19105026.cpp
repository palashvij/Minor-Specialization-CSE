//ASSIGNMENT-1 QUESTION-2, PALASH VIJ, 19105026, ECE

// assuming only parenthesis string
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
        // cout << "Stack Overflow";
        return false;
    }
    else {
        a[++top] = s;
        // cout << s << " pushed into stack\n";
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
        // cout<< (x + " popped from stack")<<endl;
        
    }
    return "";
}
string Stack::peek()
{
    if (top < 0) {
        // cout << "Stack is Empty";
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
    //   cout<<"Stack elements are:";
      for(int i=top; i>=0; i--)
        cout<<a[i]<<" ";
      cout<<endl;
   } 
   else{
    // cout<<"Stack is empty"<<endl;
   }
    
}
bool Stack::isEmpty()
{
    return (top < 0);
}

int main()
{
    class Stack s;
    // input string
    cout<<"Enter string consisting of only parenthesis :"<<endl;
    string parenthesis;
    cin>>parenthesis;
    bool poss = true;
    // we are pushing the opposite of opening brackets, which will ensure that 
    //if it is a valid parenthesis
    // then the next closing bracket will always match with the top element of the stack.
    // other wise we set the possible variable to false
    for(auto &ch:parenthesis){
        switch(ch){
            case '(':s.push(")");break;
            case '{':s.push("}");break;
            case '[':s.push("]");break;
            default:
                char front = (s.peek())[0];
                if(s.isEmpty() || (front != ch)){
                    poss = false;
                }
                else{
                    s.pop();
                }
        }
    }
    if(!poss){
        cout<<"Result : Invalid Parenthesis"<<endl;
    }
    else if(s.isEmpty()){
        cout<<"Result : Valid Parenthesis"<<endl;
    }
    else{
        cout<<"Result : Invalid Parenthesis"<<endl;
    }

    return 0;
}