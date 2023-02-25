// CSE240 SPRING 2023 Assignment 04

// Enter your name here

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Read before you start:
// You are given a partially complete program. Complete the functions in order for this program to work successfully.
// All instructions are given above the required functions, please read them and follow them carefully.
// You shoud not modify the function return types or parameters.
// You can assume that all inputs are valid. Ex: If prompted for an integer, the user will input an integer.
// You can use only the strlen() of strings.h library to check string length. Do not use any other string functions
// because you are supposed to use pointers for this homework.
// DO NOT use arrays to store or to index the characters in the string

// Global Macro Values. They are used to define the size of 2D array of characters
#define NUM_STRINGS 4
#define STRING_LENGTH 50

// Forward Declarations
void initializeStrings(char[NUM_STRINGS][STRING_LENGTH]);
void printStrings(char[NUM_STRINGS][STRING_LENGTH]);
int isSorted(int *arr, int size);
void removeDuplicates(char *str);
int count_vowels(char *str);
int count_words(char *str);
int longest_palindrome(char *str);
char most_common_char(char *str);

// Use pointer 'ptr' to traverse the 2D array of characters variable 'strings' (input from user in main()) and set all characters in each
// array to a null terminator so that there is a 4 row and 50 column 2D array full of null terminators.
// The null terminator '\0' is used to denote the end of a string.
void initializeStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
    char *ptr = &strings[0][0];
    // TODO: Implement function using pointers
    char* ptr = &strings[0][0];
    int i, j;
    for (i = 0; i < NUM_STRINGS; i++)
    {
        for (j = 0; j < STRING_LENGTH; j++)
        {
            *ptr = '\0';
            ptr++;
        }
    }
}

// Use pointer 'ptr' to traverse the 2D character array 'strings' and print each string.

void printStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
    char *ptr = &strings[0][0];
    // TODO: Implement function using pointers
    char* ptr = &strings[0][0];
    int i, j;
    for (i = 0; i < NUM_STRINGS; i++)
    {
        for (j = 0; j < STRING_LENGTH; j++)
        {
            if (*ptr == '\0') // break when null terminator is found
            {
                break;
            }
            printf("%c", *ptr);
            ptr++;
        }
        printf("\n");
    }
}

// Function to check if an integer array is sorted in non-decreasing order
int isSorted(int *arr, int size)
{
    // TODO: Implement function using pointers
    int i;
    for (i = 0; i < size - 1; i++)
    {
        if (*(arr + i) > *(arr + i + 1))
        {
            return 0;
        }
    }
    return 1;
}

// Function to remove duplicate characters from a string
void removeDuplicates(char *str)
{
    // TODO: Implement function using pointers
    char* ptr1 = str; // pointer to traverse the string
    char* ptr2; // pointer to store unique characters
    int i, j, len = strlen(str);
    for (i = 0; i < len; i++)
    {
        ptr2 = ptr1 + 1; // start comparison from the next character
        for (j = i + 1; j < len; j++)
        {
            if (*ptr1 == *ptr2) // if a duplicate is found, shift all characters from ptr2 to ptr1
            {
                char* temp = ptr2;
                while (*temp != '\0')
                {
                    *temp = *(temp + 1);
                    temp++;
                }
                len--;
                j--; // update the inner loop index after shifting the characters
            }
            else
            {
                ptr2++;
            }
        }
        ptr1++;
    }
}

// Function to count the number of vowels in a string
int count_vowels(char *str)
{
    // TODO: Implement function using pointers
    char* ptr = str;
    int count = 0;
    while (*ptr != '\0')
    {
        if (tolower(*ptr) == 'a' || tolower(*ptr) == 'e' || tolower(*ptr) == 'i' || tolower(*ptr) == 'o' || tolower(*ptr) == 'u')
        {
            count++;
        }
        ptr++;
    }
    return count;
}

// Function to take a string as input and return the number of words in the string. Words are defined as contiguous sequences of non-space characters.The function should take a pointer to a string as input and return an integer.

int count_words(char *str)
{
    // TODO: Implement function using pointers
    char* ptr = str;
    int count = 0;
    while (*ptr != '\0')
    {
        if (*ptr != ' ' && (*(ptr + 1) == ' ' || *(ptr + 1) == '\0')) // count when a non-space character is followed by a space or null terminator
        {
            count++;
        }
        ptr++;
    }
    return count;
}

//  Function take a string as input and return the length of the longest palindrome that can be formed by deleting zero or more characters from the string. The function should take a pointer to a string as input and return an integer.

int longest_palindrome(char *str)
{
    // TODO: Implement function using pointers
    int len = strlen(str);
    int i, j;
    int max_palindrome_len = 0;
    for (i = 0; i < len; i++)
    {
        for (j = len - 1; j >= i; j--)
        {
            int palindrome_len = j - i + 1;
            int start = i;
            int end = j;
            while (start <= end && *(str + start) == *(str + end)) // check if the current substring is a palindrome
            {
                start++;
                end--;
            }
            if (start >= end) // if the substring is a palindrome, check if it is longer than the current maximum
            {
                if (palindrome_len > max_palindrome_len)
                {
                    max_palindrome_len = palindrome_len;
                }
            }
        }
    }
    return max_palindrome_len;
}

//  Function take a string as input and returns the most common character in the string.If there are multiple characters that occur with the same highest frequency, return any one of them. The function should take a pointer to a string as input and return a char.

char most_common_char(char *str)
{
    // TODO: Implement function using pointers
    int count[257] = { 0 }; // an array to store the frequency of each character
    char* ptr = str;
    int max_count = 0;
    char most_common = '\0';
    while (*ptr != '\0')
    {
        count[(int)*ptr]++;
        if (count[(int)*ptr] >= max_count) // check if the frequency of the current character is greater than the maximum
        {
            max_count = count[(int)*ptr];
            most_common = *ptr;
        }
        ptr++;
    }
    return most_common;
}

// You should study and understand how main() works.
// *** DO NOT modify it in any way ***
int main()
{
    char strings[NUM_STRINGS][STRING_LENGTH]; // will store four strings each with a max length of 34
    int i, key;
    char input[STRING_LENGTH];

    printf("CSE240 HW4: Pointers\n\n");
    initializeStrings(strings);

    for (i = 0; i < NUM_STRINGS; i++)
    {
        printf("Enter a string: ");         // prompt for string
        fgets(input, sizeof(input), stdin); // store input string
        input[strlen(input) - 1] = '\0';    // convert trailing '\n' char to '\0' (null terminator)
        strcpy(strings[i], input);          // copy input to 2D strings array
    }

    printStrings(strings);

    // Test cases for each function
    int arr1a[] = {1, 2, 3, 4, 5};
    int arr2a[] = {1, 2, 4, 3, 5};

    // Test isSorted function
    int sorted1 = isSorted(arr1a, 5);
    int sorted2 = isSorted(arr2a, 5);
    printf("isSorted([1, 2, 3, 4, 5]): %d\n", sorted1); // Expected output: 1
    printf("isSorted([1, 2, 4, 3, 5]): %d\n", sorted2); // Expected output: 0

    // Test cases for each function
    char str1b[] = "hello";
    char str2b[] = "this is a test string";

    // Test removeDuplicates function
    removeDuplicates(str1b);
    removeDuplicates(str2b);
    printf("removeDuplicates('hello'): %s\n", str1b);                 // Expected output: helo
    printf("removeDuplicates('this is a test string'): %s\n", str2b); // Expected output: this aerng

    // Test cases for each function
    char str1c[] = "hello";
    char str2c[] = "this is a test string";

    // Test count_vowels function
    int count1 = count_vowels(str1c);
    int count2 = count_vowels(str2c);
    printf("count_vowels('hello'): %d\n", count1);                 // Expected output: 2
    printf("count_vowels('this is a test string'): %d\n", count2); // Expected output: 5

    // Test cases for each function
    char str1d[] = "hello";
    char str2d[] = "this is a test string";

    // Test count_words function
    int word_count1 = count_words(str1d);
    int word_count2 = count_words(str2d);
    printf("count_words('hello'): %d\n", word_count1);                 // Expected output: 1
    printf("count_words('this is a test string'): %d\n", word_count2); // Expected output: 5

    // Test cases for each function
    char str1e[] = "hello";
    char str2e[] = "this is a test string";
    char str3e[] = "racecar";

    // Test longest_palindrome function
    int palindrome_len1 = longest_palindrome(str1e);
    int palindrome_len2 = longest_palindrome(str3e);
    printf("longest_palindrome('hello'): %d\n", palindrome_len1);   // Expected output: 2
    printf("longest_palindrome('racecar'): %d\n", palindrome_len2); // Expected output: 7

    // Test cases for each function
    char str1f[] = "hello";
    char str2f[] = "This is a test string"; // Note that t in "This" is uppercase.

    // Test most_common_char function
    char common_char1 = most_common_char(str1f);
    char common_char2 = most_common_char(str2f);
    printf("most_common_char('hello'): %c\n", common_char1);                 // Expected output: l
    printf("most_common_char('This is a test string'): %c\n", common_char2); // Expected output: s

    return 0;
}
