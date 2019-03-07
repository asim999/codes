/*
Chef has N dishes, numbered 1 through N. For each valid i, dish i is described by a string Di containing only 
lowercase vowels, i.e. characters 'a', 'e', 'i', 'o', 'u'.

A meal consists of exactly two dishes. Preparing a meal from dishes i and j (i≠j) means concatenating the 
strings Di and Dj in an arbitrary order into a string M describing the meal. Chef likes this meal if the string M 
contains each lowercase vowel at least once.

Now, Chef is wondering - what is the total number of (unordered) pairs of dishes such that he likes the
 meal prepared from these dishes?

Input
The first line of the input contains a single integer T denoting the number of test cases. 
The description of T test cases follows.
The first line of each test case contains a single integer N.
N lines follow. For each valid i, the i-th of these lines contains a single string Di.
Output
For each test case, print a single line containing one integer - the number of ways to prepare a meal Chef likes.

Constraints
1≤T≤1,000
1≤N≤105
1≤|Di|≤1,000 for each valid i
the sum of all |D_i| over all test cases does not exceed 3⋅107
Subtasks
Subtask #1 (20 points):

1≤T≤100
1≤N≤100
the sum of all |D_i| over all test cases does not exceed 20000
Subtask #2 (80 points): original constraints

Example Input
1
3
aaooaoaooa
uiieieiieieuuu
aeioooeeiiaiei
Example Output
2
Explanation
Example case 1: There are three possible meals:

A meal prepared from dishes 1 and 2 (for example "aaooaoaooauiieieiieieuuu") contains all vowels.
A meal prepared from dishes 1 and 3 (for example "aaooaoaooaaeioooeeiiaiei") does not contain 'u'.
A meal prepared from dishes 2 and 3 (for example "uiieieiieieuuuaeioooeeiiaiei") contains all vowels.
*/
#include<bits/stdc++.h>
using namespace std;
inline void setDishId(string str,long int dish[]){
    int count=0;
    int num=0;
    bool vowel[5]={false,false,false,false,false};
 for(int j=0;j<str.length();j++){
    if(count>=5)
        break;
    if(str[j]=='a'&&vowel[0]==false&&++count)
        {
            num+=16;
            vowel[0]=true;
        }
    else if(str[j]=='e'&&vowel[1]==false&&++count)
        {
            num+=8;
            vowel[1]=true;
        }
    else if(str[j]=='i'&&vowel[2]==false&&++count)
        {
            num+=4;
            vowel[2]=true;
        }
    else if(str[j]=='o'&&vowel[3]==false&&++count)
        {
            num+=2;
            vowel[3]=true;
        }
    else if(str[j]=='u'&&vowel[4]==false&&++count)
        {
            num+=1;
            vowel[4]=true;
        }
    }
    dish[num]++;
}
long int NC2(long int n) {
    if(n%2==0)
    return ((n/2)%MOD*(n-1)%MOD)%MOD;
    else
    return ((n)%MOD*((n-1)/2)%MOD)%MOD;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        long int n;
        cin>>n;
        string arr;
        long int dish[32]={0};
        string str;
        for(long int i=0;i<n;i++){
            cin>>str;
            setDishId(str,dish);
        }
        long int dishCount=0;
        for(int i=0;i<31;i++)
        {
            if(dish[i]==0)
            continue;
            for(int j=i+1;j<31;j++)
            {
                if(dish[j]==0)
                continue;
                int newdish=i|j;
                if(newdish==31)
                {
                    dishCount=(dishCount+(dish[i]%MOD*dish[j]%MOD)%MOD)%MOD;
                }
            }
        }
        dishCount+=(dish[31]%MOD*(n-dish[31])%MOD)%MOD;
        dishCount+=NC2(dish[31]);
        cout<<dishCount<<endl;
    }
    return 0;
}