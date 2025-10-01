#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
int ans(int num1, int num2, char x)
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
        return -1;
        break;
    }
    return -1;
}
string solve(string num1, string num2, char x)
{
    string res;
    res.push_back(x); // operator first
    res += num1;      // operand1
    res += num2;      // operand2
    return res;
}

int main()
{
    // given = 2+6*4/8-3 using bodmas=2;
    string str = "2+6*4/8-3";
    stack<char> opr; // opreator
    stack<string> nums;
    for (int i = 0; i < str.length(); i++)
    {
        int asc = str[i];
        if (asc > 47 and asc < 58)
        {
            string temp;
            temp.push_back(str[i]);
            nums.push(temp);
        }
        if (isopretor(str[i]))
        {
            if (opr.empty())
            {
                opr.push(str[i]);
            }
            else
            {
                while (!opr.empty() and priority(opr.top()) >= priority(str[i]))
                {
                    string nums2 = nums.top();
                    nums.pop();
                    string nums1 = nums.top();
                    nums.pop();
                    nums.push(solve(nums1, nums2, opr.top()));
                    opr.pop();
                }
                opr.push(str[i]);
            }
        }
    }
    while (!opr.empty())
    {

        string nums2 = nums.top();
        nums.pop();
        string nums1 = nums.top();
        nums.pop();
        nums.push(solve(nums1, nums2, opr.top()));
        opr.pop();
    }
    cout << nums.top()<<endl;
    str = nums.top();
    stack<int> s;
    for (int i = str.length()-1; i >= 0; i--)
    {
        int asc = str[i];
        if (asc > 47 and asc < 58)
        {
            s.push(str[i] - '0');
        }
        else if (isopretor(str[i]))
        {
            int nums1 = s.top();
            s.pop();
            int nums2 = s.top();
            s.pop();
            s.push(ans(nums1, nums2, str[i]));
        }
    }
    cout << s.top();
    return 0;
}