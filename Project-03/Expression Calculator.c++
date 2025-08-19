#include <iostream>
#include <stack>
#include <cctype>
#include <cmath>
using namespace std;

int precedence(char op) {
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    if(op=='^') return 3;
    return 0;
}

string infixToPostfix(string exp) {
    stack<char> st;
    string postfix="";
    for(char c : exp) {
        if(isalnum(c)) postfix += c;
        else if(c=='(') st.push(c);
        else if(c==')') {
            while(!st.empty() && st.top()!='(') { postfix+=st.top(); st.pop(); }
            st.pop();
        } else {
            while(!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix+=st.top(); st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()) { postfix+=st.top(); st.pop(); }
    return postfix;
}

int evaluatePostfix(string exp) {
    stack<int> st;
    for(char c : exp) {
        if(isdigit(c)) st.push(c-'0');
        else {
            int b=st.top(); st.pop();
            int a=st.top(); st.pop();
            switch(c) {
                case '+': st.push(a+b); break;
                case '-': st.push(a-b); break;
                case '*': st.push(a*b); break;
                case '/': st.push(a/b); break;
                case '^': st.push(pow(a,b)); break;
            }
        }
    }
    return st.top();
}

int main() {
    string infix; cout<<"Enter Expression: "; cin>>infix;
    string post = infixToPostfix(infix);
    cout<<"Postfix: "<<post<<"\n";
    cout<<"Result: "<<evaluatePostfix(post)<<"\n";
}
