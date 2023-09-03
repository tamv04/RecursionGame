//
//  recursion.cpp
//  HW 2
//
//  Created by tam vo on 7/20/23.
//
#include <iostream>
#include <string>
using namespace std;
//
//

// Returns the product of two non-negative integers, m and n,
// using only repeated addition.
int productOfTheSystem(unsigned int m, unsigned int n)
{
    if (n == 0) // making a base case for this function
    return 0;
    return m + productOfTheSystem(m, n-1); // doing so we add m to the amount of times it's being multipled by reducing n each time likee 4 * 3 it would be 4+4+4 down the recursion
    
}

// Returns the number of occurrences of digit in the decimal
// representation of num. digit is an int between 0 and 9
// inclusive.
//
// Pseudocode Example:
// accountForADigit(18838, 8) => 3
// accountForADigit(55555, 3) => 0
// accountForADigit(0, 0) => 0 or 1 (either if fine)
//
int accountForADigit(int num, int digit)
{
    if( num == 0)
        return 0; // base case for this function
    
    int lastDigit = num % 10; // this will get the last digit
    int NumberOfTimesForLastDigit = 0; // counting the number of times the last digit shows up
    
    if (lastDigit == digit)
    {
        NumberOfTimesForLastDigit = 1;
    }
    
    return NumberOfTimesForLastDigit + accountForADigit(num / 10, digit); // "num / 10" will exclude the last digit
}


// Returns a string where the same characters next each other in
// string n are separated by "88" (you can assume the input
// string will not have 8’s)
//
// Pseudocode Example:
// eightClap("goodbye") => "go88odbye"
// eightClap("yyuu") => "y88yu88u"
// eightClap("aaaa") => "a88a88a88a"
//
string eightClap(string n)
{
    // base cases here
    if ( n == "")
    {
        return "";
    }
    else if (n.size() == 1)
    {
        return n;
    }
    else if ( n.size()==2)
    {
        if (n[0] == n[1])
        {
            return string(1,n[0]) + "88" + string(1,n[1]);
        }
        else
        {
            return n;
            
        }
    }
    
    string s = eightClap(n.substr(0, n.size()-1)); // calling the magic function
    char last = n[n.size()-1]; // getting the last letter in string N
    if(s[s.size() -1] == last) // cpmaring the last character in the s string to the last character of N
    {
        return s + "88" + string(1,last);
    }
    else
    {
        return s + string(1,last);
    }
}


// str contains a single pair of the less than and greater than
// signs, return a new string made of only the less than and
// greater than sign and whatever is contained in between
//
// Pseudocode Example:
// coneHeads("abc<ghj>789") => "<ghj>"
// coneHeads("<x>7") => "<x>"
// coneHeads("4agh<y>") => "<y>"
// coneHeads("4agh<>") => "<>"
//
string coneHeads(string str)
{
    // base cases
        if (str == "") // for an empty string
        {
            return "";
        }
        else if (str.substr(0, 1) == "<") // checking if the first character is <
        {
            if (str.substr(str.size() - 1, 1) == ">") // checking if the last character is >
            {
                return str;
            }
            else
                return coneHeads(str.substr(0, str.size() - 1)); //calling the magic function on the first element of the string
        }
        else
            return coneHeads(str.substr(1, str.size() - 1)); // calling the magic function on the last element of the string
}

//
// Return true if the total of any combination of elements in
// the array a equals the value of the target.
//
// Pseudocode Example:
// conglomerateOfNumbers({2, 4, 8}, 3, 10) => true
// conglomerateOfNumbers({2, 4, 8}, 3, 6) => true
// conglomerateOfNumbers({2, 4, 8}, 3, 11) => false
// conglomerateOfNumbers({2, 4, 8}, 3, 0) => true
// conglomerateOfNumbers({}, 0, 0) => true
//
//
bool conglomerateOfNumbers(const int a[], int size, int target)
{
    // base cases
    if(target == 0)
    {
        return true;
    }
    
    if (size == 0)
    {
        return false;
    }
    bool includeFront = conglomerateOfNumbers(a + 1, size - 1, target - a[0]);
    
    bool excludeFront = conglomerateOfNumbers(a + 1, size - 1, target);
    
    return includeFront || excludeFront;
}

// Another way to do it
// the first part before the || is calling the magic function everything excpet for the first element and the second part is calling it on everything along with the first element
//    return (conglomerateOfNumbers(a + 1, size - 1, target - a[0]) || conglomerateOfNumbers(a + 1, size - 1, target));
//    
//
//
//
// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise
bool findAWay(string maze[], int nRows, int nCols,int sr, int sc, int er, int ec)
    {
    // base case
    if (sr == er && sc == ec)
    {
        return true;
    }

    // now we're going to drop crumbs like the lecture slides
    maze[sr][sc] = '#';
    
    // this is like the lecture slides we are going to travel all directions north south west east
        if (sr - 1 >= 0 && maze[sr - 1][sc] == '.') // north
        {
            if (findAWay(maze, nRows, nCols, sr - 1, sc, er, ec))
                return true;
        }

        if (sr + 1 < nRows && maze[sr + 1][sc] == '.') //south
        {
            if (findAWay(maze, nRows, nCols, sr + 1, sc, er, ec))
                return true;
        }

        if (sc - 1 >= 0 && maze[sr][sc - 1] == '.') // west
        {
            if (findAWay(maze, nRows, nCols, sr, sc - 1, er, ec))
                return true;
        }

        if (sc + 1 < nCols && maze[sr][sc + 1] == '.') // east
        {
            if (findAWay(maze, nRows, nCols, sr, sc + 1, er, ec))
                return true;
        }
    
    return false;
}


int main()
{
    return 0;
}
