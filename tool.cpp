#include "arithmometer.h"

struct
{
    set<tuple<int,int>> SET2;
    set<tuple<int,int,int>> SET3;
    set<tuple<int,int,int,int>> SET4;
    set<tuple<int,int,int,int,int>> SET5;
    set<tuple<int,int,int,int,int,int>> SET6;
    set<tuple<int,int,int,int,int,int,int>> SET7;
    set<tuple<int,int,int,int,int,int,int,int>> SET8;
    set<tuple<int,int,int,int,int,int,int,int,int>> SET9;
}repeat;

int randomNum(int , int);
string num_to_string(int);
string array_to_string(int* , char* , int);
bool checkFormula(int , int , int* , char* , int* , int);
bool checkRepeat(int , int* , char*);
void clearRepeat();

int randomNum(int left , int right)//creative a random number in [left,right]
{
    return rand() % (right - left + 1) + left; 
}

string num_to_string(int num)//converts a number to a string
{
    if(!num) return "0";
    vector<char> V;
    while(num)
    {
        V.push_back(num % 10 + '0');
        num /= 10;
    }
    string S;
    for(int i = V.size() - 1 ; i >= 0 ; i--) S += V[i];
    return S;
}

string array_to_string(int *arr , char *brr , int lon)//converts arrays to a string
{
    string S;S += num_to_string(arr[0]);
    for(int i = 0 ; i < lon ; i++)
    {
        if(brr[i] == '+')
            S += "+";
        else if(brr[i] == '-')
            S += "-";
        else if(brr[i] == '*')
            S += "*";
        else if(brr[i] == '/')
            S += "/";
        S += num_to_string(arr[i + 1]);
    }
    return S;
}

bool checkFormula(int min , int max , int *arr , char *brr , int* ans , int lon)//check the equation meets the requirements
{
    int check = arr[0];
    for(int i = 0 ; i < lon ; i++)
    {
        if(brr[i] == '+')
            check += arr[i + 1];
        else if(brr[i] == '-')
            check -= arr[i + 1];
        else if(brr[i] == '*')
            check *= arr[i + 1];
        if(check < min || check > max) return false;
    }
    *ans = check;
    return true;
}

bool checkRepeat(int num , int* arr , char *brr)//check the equation satisfies the duplicate
{
    vector<int> VW50;VW50.push_back(arr[0]);
    for(int i = 0 ; i < num ; i++)
    {
        if(brr[i] == '+') VW50.push_back(arr[i + 1]);else
        if(brr[i] == '-') VW50.push_back(arr[i + 1] * -1);
    }
    sort(VW50.begin() , VW50.end());
    if(num == 2)
    {
        tuple<int,int> T = {VW50[0] , VW50[1]};
        if(repeat.SET2.count(T)) return false;
        else{repeat.SET2.insert(T);return true;}
    }
    else if(num == 3)
    {
        tuple<int,int,int> T = {VW50[0] , VW50[1] , VW50[2]};
        if(repeat.SET3.count(T)) return false;
        else{repeat.SET3.insert(T);return true;}
    }
}

void clearRepeat()//clean up the storage
{
    repeat.SET2.clear();
    repeat.SET3.clear();
    repeat.SET4.clear();
    repeat.SET5.clear();
    repeat.SET6.clear();
    repeat.SET7.clear();
    repeat.SET8.clear();
    repeat.SET9.clear();
}
