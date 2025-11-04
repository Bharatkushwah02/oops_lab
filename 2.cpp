#include<iostream>
using namespace std;

class Answer{
    int a;

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

    int get_input( const string msg){

        string str;

        while( true ){
            cout<<msg;
            getline(cin, str);
            if( Is_string(str) ){

                int val = stoll(str); 
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
    Answer ans;
    int n ;
    n = ans.input();
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < n ; j++ ){
            if( i == 0 || i == n-1 ){
                cout<<"*";
            } else if( j == 0 || j == n - 1 ){
                cout<<"*";
            } else {
                cout<<" ";
            }
        }
        cout<<endl;
    }
}