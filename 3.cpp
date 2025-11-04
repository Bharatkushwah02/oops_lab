#include<iostream>
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
    
    int   get_input( const string msg){

        string str;

        while( true ){
            cout<<msg;
            getline(cin, str);
            if( Is_string(str) ){
                
                    int  val = stoll(str); 
                    return val;
               
            } else {
                cout<<"Enter number is invailid please Try Again"<<endl;
            }
        }
        
       
    }


    public : int input(){ 

        a = get_input("Enter the number ");

        return a;
    }

};


int main(){
    Answer ans ;
    long long num = ans.input();

    string num1 = to_string(num);

    int str = 0 , end = num1.length() - 1;
    while( str < end ){
        if( num1[str] != num1[end] ){
            cout<<"Enter number is not palindrom";
            return 0 ;
        }
        str++;
        end--;
    }
    cout<<"Enter number is palindrom";
}