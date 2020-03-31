#include <iostream>
#include <stdexcept>
#include "PhoneticFinder.hpp"
#include <bits/stdc++.h>

using namespace std;

bool isSwitched(char a, char b){
    
    
    if (a <= 'Z' && a >= 'A')
        a = a+32;
    if (b <= 'Z' && b >= 'A')
        b = b+32;
    

    if(a==b){
        return true;
    }
    
    int options[26][26];
    options['w' - 97]['v' - 97] = 1;
    options['v' - 97]['w' - 97] = 1;
    options['g' - 97]['j' - 97] = 1;
    options['j' - 97]['g' - 97] = 1;
    options['s' - 97]['z' - 97] = 1;
    options['z' - 97]['s' - 97] = 1;
    options['d' - 97]['t' - 97] = 1;
    options['t' - 97]['d' - 97] = 1;
    options['o' - 97]['u' - 97] = 1;
    options['u' - 97]['o' - 97] = 1;
    options['i' - 97]['y' - 97] = 1;
    options['y' - 97]['i' - 97] = 1;
    options['b' - 97]['p' - 97] = 1;
    options['b' - 97]['f' - 97] = 1;
    options['f' - 97]['b' - 97] = 1;
    options['f' - 97]['p' - 97] = 1;
    options['p' - 97]['b' - 97] = 1;
    options['p' - 97]['f' - 97] = 1;
    options['c' - 97]['q' - 97] = 1;
    options['c' - 97]['k' - 97] = 1;
    options['k' - 97]['c' - 97] = 1;
    options['k' - 97]['q' - 97] = 1;
    options['q' - 97]['c' - 97] = 1;
    options['q' - 97]['k' - 97] = 1;

    
    
    return (options[a-97][b-97]==1);



}

namespace phonetic
{
string find(string text, string word)
{
    string checkspaces = word;
    istringstream wordstream(checkspaces);
    wordstream >> word;
   
    if (word.length() == 0 || !wordstream)
    {
        throw std::invalid_argument("Invalid word");
       
    }
    istringstream stream(text);
    string tempword;
    while(stream >> tempword){        
        
        for (int i = 0; i < word.length()+1||i<tempword.length()+1; i++)
        {
            if (word.length() == tempword.length() && i == word.length())
            {

                return tempword;
            }
            if(isSwitched(tempword[i],word[i])){
            
                continue;
            }
            
            else{
                break;
            }
          
        }
        if(!stream){
            break;
        }
        


    }
    
    
    throw std::invalid_argument("Word isnt found in the text");
}}