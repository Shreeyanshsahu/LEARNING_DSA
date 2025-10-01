#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

bool isopretor(char s)
{
    switch (s)
    {
    case '+':
        return true;
        break;

    case '-':
        return true;
        break;

    case '/':
        return true;
        break;

    case '*':
        return true;
        break;
    case '(':
        return true;
        break;
    case ')':
        return true;
        break;

    default:
        return false;
        break;
    }
    return false;
}
int priority(char s)
{
    switch (s)
    {
    case '+':
        return 0;
        break;

    case '-':
        return 0;
        break;

    case '/':
        return 1;
        break;

    case '*':
        return 1;
        break;

    default:
        return -1; // bracketss ki 
        break;
    }
    return -1;
}
int solve(int num1, int num2, char x)
{
    switch (x)
    {
    case '+':
        return num1 + num2;
        break;

    case '-':
        return num1 - num2;
        break;

    case '/':
        return num1 / num2;
        break;

    case '*':
        return num1 * num2;
        break;
    }
    return -111;
}

int main()
{
    // given = 2+6*4/8-3 using bodmas=2;
    string str = "(2+6*4)/8-3";
    stack<char> opr; // opreator
    stack<int> nums;
    for (int i = 0; i < str.length(); i++)
    {
        int asc = str[i];
        if (asc > 47 and asc < 58)
        {
            nums.push(str[i] - '0');
        }
        if (isopretor(str[i]))
        {
            if (opr.empty())
            {
                opr.push(str[i]);
            }
            else if(str[i]=='('){
                opr.push(str[i]);
            }
            else if(str[i]==')'){
                while (!opr.empty() and opr.top()!='(')
                {
                    int nums2 = nums.top();
                    nums.pop();
                    int nums1 = nums.top();
                    nums.pop();
                    nums.push(solve(nums1, nums2, opr.top()));
                    opr.pop();
                }
                opr.pop();
            }
            else
            {
                while (!opr.empty() and priority(opr.top()) >= priority(str[i]))
                {
                    int nums2 = nums.top();
                    nums.pop();
                    int nums1 = nums.top();
                    nums.pop();
                    nums.push(solve(nums1, nums2, opr.top()));
                    opr.pop();
                }
                opr.push(str[i]);
            }
        }
    }
    while(!opr.empty()){

        int nums2 = nums.top();
        nums.pop();
        int nums1 = nums.top();
        nums.pop();
        nums.push(solve(nums1, nums2, opr.top()));
        opr.pop();
    }
    cout << nums.top();
    return 0;
}