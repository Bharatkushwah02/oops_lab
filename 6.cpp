#include <iostream>
#include<algorithm>
using namespace std;


class Answer{

    long long a ;

    bool Is_string(string str){
        int start = 0;
        if(str.empty()){
            return false;
        } else if( str[0] == '+' || str[0] == '-' ){
            start = 1;
        }
        for( int i = start ; i < str.size() ; i++ ){
            if( !isdigit(str[i])){
                return false;
            }
        }
        return true;
    }
    
    long long  get_input( const string msg){

        string str;

        while( true ){
            cout<<msg;
            getline(cin, str);
            if( Is_string(str) ){
                try{
                    long long val = stoll(str); 
                    return val;
                }
                catch( out_of_range& ){
                    cout<< " Enter number is Too large Please Try again "<<endl;
                }
            } else {
                cout<<"Enter number is invailid please Try Again"<<endl;
            }
        }
        
       
    }



    public : long long input( string str){ 

        a = get_input(str);

        return a;
    }

};


int gcd(int a, int b) {
    while (b != 0) {

        a = abs(a);
        b = abs(b);
        
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    Answer ans;
    int num1, num2;
    num1 = ans.input("Enter the 1st number ");
    num2 = ans.input("Enter the 2nd number ");

    cout << "GCD of " << num1 << " and " << num2 << " is " << gcd(num1, num2) << endl;

    cout<<"By using built in funtion in C++ we can easily fing GCD of "<<num1<<" and " <<num2<<" is = "<< __gcd( num1 , num2 );
    return 0;
}
