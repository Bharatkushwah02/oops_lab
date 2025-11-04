#include<iostream>
#include<limits>
#include<string>
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



    public : long long input(){ 

        a = get_input("Enter the number ");

        return a;
    }

};


int main(){
    Answer ans;
    long long  num1 , num2 ;
    
    num1 = ans.input();
    num2 = ans.input();

    if (num2 == 0) {
        cout << "Cannot divide by zero!" << endl;
    } else if (num1 % num2 == 0) {
        cout << num1 << " is a multiple of " << num2 << endl;
    } else {
        cout << num1 << " is NOT a multiple of " << num2 << endl;
    }

    return 0;

    


}