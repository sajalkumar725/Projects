#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;

// checks if a string is a number or not
bool isNumber(string s)
{
    for(auto i : s)
    {
        if(!isdigit(i))
            return false;
    }
    return true;
}


// extracting different strings from one string
vector<string> fun1(string s)
{
    vector<string> result;
    ll i = 0;
    string str = "";
    while(i<s.length())
    {
        if(s[i]!=',')
        {
            str+=s[i];
            i++;
        }
        else
        {
            str+=",";
            string num = "";
            ll j=i+1;
            while(j<s.length() && s[j] !=',')
            {
                num+=s[j];
                j++;
            }
            if(isNumber(num))
            {
                str+=num;
                result.emplace_back(str);
                str="";
            }
            else
            {
                str+=num;
            } 
            i=j;
        }
    }
    for(i=0;i<result.size();i++)
    {
        if(result[i][0]==',')
        {
            result[i].erase(0,1);
        }
    }
    return result;
}
// helper function for sorting
bool compare(pair<string,ll> a,pair<string,ll> b)
{
    return a.second<b.second;
}

vector<pair<string,ll>> fun2(vector<string> input)
{
    vector<pair<string,ll>> result;
    for(auto i : input)
    {
        string num = "";
        ll j = i.length()-1;
        while(j>=0 && isdigit(i[j]))
        {
            num+=i[j];
            j--;
        }
        reverse(num.begin(),num.end());
        ll intNum = stoi(num);
        result.push_back({i,intNum});
    }
    sort(result.begin(),result.end(),compare); // sort vector according to prices
    return result;
}

void printResult(vector<pair<string,ll>> result)
{
    for(auto i : result)    // display output in output.txt
        cout<<i.first<<endl;
    return;
}

int main()
{
    // take input from input.txt and show output in output.txt
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    fast; // for fast input/output in c++
    string str;
    getline(cin,str); // string input
    vector<string> temp = fun1(str); // fun1() -> extracting every string with their prices
    vector<pair<string,ll>> result = fun2(temp); // fun2() -> sorting strings according to their prices
    printResult(result); // display output in output.txt
    return 0;
}