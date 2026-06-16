//
//  main.cpp
//  LeetCode Problem
//
//  Created by Vanhoecke Matthieu on 08/06/2026.
//

#include <iostream>
#include <vector>

/*=====================================================================================================
 Arithmetic progression
 =====================================================================================================*/
class Solution {
public:
    bool canMakeArithmeticProgression(std::vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int diff = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] != diff)
                return false;
        }

        return true;
    }
};
/*=====================================================================================================
 Problème 2: Given a positive integer n, find the pivot integer x such that:
 The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
 Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one
 pivot index for the given input.
 =====================================================================================================*/


class Solution2 {
public:
    int pivotInteger(int n) {
        int sumn = n*(n+1)/2;
        int sqrtsumn = sqrt(sumn);

        if (sqrtsumn * sqrtsumn == sumn){
            return  sqrtsumn;
        }
        else{
            return -1;
        }
    }
};

/*=====================================================================================================
 Problème 3: Palindrome Number
 Given an integer x, return true if x is a palindrome, and false otherwise.
 =====================================================================================================*/

class Solution3 {
public:
    bool isPalindrome(int x) {
        std::string s = std::to_string(x);
        for (int i=0; i < s.size()/2 ;i=i+1){
            if (s[i] != s[s.size()-1-i]){
                return false;
            }
        }
        return true;
    }
};
    
/*=====================================================================================================
 Problème 4: Ugly Number
 An ugly number is a positive integer which does not have a prime factor other than 2, 3, and 5.
 Given an integer n, return true if n is an ugly number.
 =====================================================================================================*/
    
class Solution4 {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3;
        while (n % 5 == 0) n /= 5;
        return n == 1;
    }
};


/*=====================================================================================================
 Problème 5: Smallest Integer Divisible by K
 Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k, and n only contains the digit 1.
 Return the length of n. If there is no such n, return -1.
 Note: n may not fit in a 64-bit signed integer.
 =====================================================================================================*/

class Solution5 {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0)
            return -1;
        int temp = 0;
        for (int len = 1; len <= k; len++) {
            temp = (temp * 10 + 1) % k;

            if (temp == 0)
                return len;
        }
        return -1;
    }
};


/*=====================================================================================================
 Problème 6: Self Dividing Numbers
 A self-dividing number is a number that is divisible by every digit it contains.
 For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
 A self-dividing number is not allowed to contain the digit zero.
 Given two integers left and right, return a list of all the self-dividing numbers in the range [left, right] (both inclusive).
 =====================================================================================================*/

class Solution6 {
public:
    std::vector<int> selfDividingNumbers(int left, int right) {
        std::vector<int> res;

        for (int i = left; i <= right; i++) {
            int x = i;
            bool ok = true;

            while (x > 0) {
                int d = x % 10;

                if (d == 0 || i % d != 0) {
                    ok = false;
                    break;
                }

                x /= 10;
            }

            if (ok) res.push_back(i);
        }

        return res;
    }
};
