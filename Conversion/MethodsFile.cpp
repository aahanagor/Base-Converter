#include <iostream>
#include <string>

#include "Methods.h"

std::string trimLeadingZeros(std::string str)
{
    int zeroCount = 0;
    while (str[zeroCount] == '0')
    {
        zeroCount++;
    }
    str.erase(0, zeroCount);

    return str;
}

std::string decToBinary(int number)
{
    if (number == 0)
    {
        return "0";
    }

    int remainder; 
    std::string ans = "";
    while (number > 0)
    {
        remainder = number % 2;
        ans = ans + std::to_string(remainder);
        number /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

std::string binaryTohexadecimal(std::string number)
{
    std::string arr[3], ans = "";
    int length = number.length();
    int index = 2;

    for (int i = number.length(); i > 0; i -= 4)
    {
        if (i < 4)
        {
            arr[index--] = number.substr(0, i);
        }
        else
        {
            arr[index--] = number.substr(i - 4, 4);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        std::string zeros = "";
        if (arr[i].length() < 4 || arr[i] != "")
        {
            for (int j = 0; j < 4 - arr[i].length(); j++)
            {
                zeros += "0";
            }
            arr[i] = zeros + arr[i];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        std::string result = "";
        for (int j = 0; j < 4; j++)
        {
            result += std::to_string((int)((arr[i][j] - '0') * pow(2, 3 - j)));
        }
        arr[i] = result;
    }
    int t[3];
    for (int i = 0; i < 3; i++)
    {
        int temp = 0;
        for (int j = 0; j < 4; j++)
        {
            temp += arr[i][j] - '0';
        }
        t[i] = temp;
    }
    for (int i = 0; i < 3; i++)
    {
        ans += hexConversion(t[i]);
    }
    return  ans;
}
std::string hexToBinary(std::string number)
{
    int arr[3];
    std::string ans;
    for (int i = 0; i < number.length(); i++)
    {
        arr[i] = fromHexConversion(number[i]);
        
        std::string temp = decToBinary(arr[i]);

        while (temp.length() < 4)
        {
            temp = "0" + temp;
        }

        ans += temp;
    }

    return ans;
}

int binaryToDec(std::string number)
{
    int ans = 0;
    reverse(number.begin(), number.end());
    for (int i = 0; i < number.length(); i++)
    {
        ans += (number[i] - '0') * pow(2, i);
    }
    return ans;
}

int fromHexConversion(char c)
{
switch (c)
    {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case 'A': return 10;
        case 'B': return 11;
        case 'C': return 12;
        case 'D': return 13;
        case 'E': return 14;
        case 'F': return 15;
        default:  return 0;
    }
}

std::string hexConversion(int num)
{
    switch (num)
    {
        case 0: return "0";
        case 1: return "1";
        case 2: return "2";
        case 3: return "3";
        case 4: return "4";
        case 5: return "5";            
        case 6: return "6";            
        case 7: return "7";            
        case 8: return "8";
        case 9: return "9";
        case 10: return "A";
        case 11: return "B";
        case 12: return "C";
        case 13: return "D";
        case 14: return "E";
        case 15: return "F";
        default: return "";
    }
}