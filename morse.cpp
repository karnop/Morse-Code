#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// input output streams
void inpout()
{
    // getting the input from input.txt
    freopen("input.txt", "r", stdin);

    // printing the output in output.txt
    freopen("output.txt", "w", stdout);
}

// main function
int main()
{
    // input output
    inpout();

    // morse array
    string morse_array[26+10] = {
                              // alphabets 0 - 25
                              ".-",     "-...",     "-.-.",     "-..",
                              ".",      "..-.",     "--.",      "....",
                              "..",     ".---",     "-.-",      ".-..",
                              "--",     "-.",       "---",      ".--.",
                              "--.-",   ".-.",      "...",      "-",
                              "..-",    "..-",      ".--",      "-..-",
                              "-.--",   "--..",
                              // numbers  26  - 35
                              "-----", ".----", "..---", "...--", "....-",
                              ".....", "-....", "--...", "---..", "----."                     
                              };

    
    // morse map for better search
    map<string, char> mp;
    // for alphabets
    for(int i=0; i<26; i++)
    {
        char ch = i+65;
        mp[morse_array[i]] = ch;
    }
    // for numbers
    for(int i=26; i<36; i++)
    {
        char ch = i+(48-26);
        mp[morse_array[i]] = ch;
    }

    // string data input
    string s;
    getline(cin, s); 

    // detection
    // Morse code can only contain lowercase alphabets and numbers 

    bool is_morse = false;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == '-')
        {
            is_morse = true;
            break;
        }
    }

    // conversion
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == ' ')
                cout << " ";

        else if(s[i] == '.' && is_morse == false)
            cout << " ";

        // english to morse
        else if(!is_morse)
        {
            // converting to uppercase
            char ch = toupper(s[i]);
            
            // alphabet
            if(ch >= 65 && ch <= 90)
                cout << morse_array[ch-65] << " ";

            // number (numbers start at array index 26)
            else if(ch >= 48 && ch <= 57)
                cout << morse_array[ch-48 + (26)] << " ";

            // invalid english character
            else
            {
                cout << "\nERROR : INVALID ENGLISH CHARACTER at char : " << i+1 << endl;
                break;
            }
        }


        // morse to english
        else if(is_morse)
        {
            // taking the entire english character's input
            string temp = "";
            while(s[i] != ' ' && s[i] != '\n' && i != (s.size()))
            {
                temp.push_back(s[i]);
                i++;
            }
            // finding the element;
            auto iter = mp.find(temp);

            // if element is found
            if(iter != mp.end())
                cout << iter->second;

            // element not found
            else
                cout << "\nERROR : INVALID Morse string found " << endl;
        }
    }

} 