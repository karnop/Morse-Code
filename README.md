# Morse-Code
Auto conversion of English Text to Morse Code and vice versa

## Features
> Converts Morse Code to English Text   
> Converts English Text to Morse Code  
> Signals Error if Morse Code is mixed with English Text   
> Auto Detects if the Text is Morse Code or English Text  

## Time Complexity
> Takes O(n) for Morse Code/ English Text Detection  
> Takes O(n logn) for morse code to English code Conversion (using HashMaps)  
> Takes O(n) for English Code to Morse Code conversion (using Array)  
> **Overall Time Complexity : O(n logn)**  

## ShortComings
> If the input contains all **“.”** (full stops), then we cannot detect If it is a morse code or English text. Our program assumes it to be English text.  
> We only take the input till newline(enter key is added in the input). This is done for the simplicity of the code.   
