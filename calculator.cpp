#include <iostream> 

using namespace std;

bool calculate(double a, double b, char op, double &result){
    switch (op){
        case '+': result = a + b; return true;
        case '-': result = a - b; return true;
        case '*': result = a * b; return true;
        case '/':
            if(b == 0){
                cout << "Error: cannot divide by zero." << endl;
                return false;
            }
            result = a / b;
            return true;
        default:
            cout << "Error: unkown operator " << op << endl; 
            return false;
    }
}

int main(){
    char again = 'y';
    cout << "Simple C++ calculator" << endl; 

    while(again == 'y' || again == 'Y'){
        double a;
        double b;
        double result; 

        char op;

        cout << "\nEnter first number: ";
        cin >> a;

        cout << "Enter operator (+, -, *, /): ";
        cin >> op; 

        cout << "Enter second number: ";
        cin >> b; 

        if(cin.fail()){
            cout << "Error: please enter valid numbers." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else if(calculate(a, b, op, result)){
            cout << a << " " << op << " " << b << " = " << result << endl;
        }

        cout << "\nCalculate again? (y/n) : ";
        cin >> again;
    }
    cout << "Goodbye!" << endl; 

    return 0;
}