#include <iostream>
#include <cmath>
using namespace std;

class Answer{

    double a ;

    bool Is_string(string str){
        int start = 0;
        int count = 0;
        if(str.empty()){
            return false;
        } else if( str[0] == '+' || str[0] == '-' ){
            start = 1;
        }
        for( int i = start ; i < str.size() ; i++ ){
            if( str[i] == '.' && count == 0 ){ // ager user ne 2 bar '.' ka use kra to invalid ayega Ex = 121.11.232.
                count++;
                continue;
            }
            if( !isdigit(str[i])){
                return false;
            }
        }
        return true;
    }
    
    double  get_input( const string msg){

        string str;

        while( true ){
            cout<<msg;
            getline(cin, str);
            if( Is_string(str) ){
                try{
                    double val = stod(str); 
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


    public : double input(){ 

        a = get_input("Enter the number ");

        return a;
    }

};


double roundTo(double num, int places) {
    double factor = pow(10, places);  
    return round(num * factor) / factor;
}

int main() {
    double num;
    Answer ans;
    num = ans.input();
  

    cout << "Original number = " << num << endl;
    cout << "Round To Integer = " << roundTo(num, 0) << endl;
    cout << "Round To Tenth = " << roundTo(num, 1) << endl;
    cout << "Round To Hundredth = " << roundTo(num, 2) << endl;
    cout << "Round To Thousandth = " << roundTo(num, 3) << endl;

    return 0;
}
