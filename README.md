# CS201_Project : BK Trees(Efficient Spell Checking in NLP)
## Introduction.
In this project,we have implemented spell check and prediction of incorrect words with the help of BK(Burkhard Keller)trees.BK Tree  is a data structure that is used to perform spell check based on the Edit Distance (Levenshtein distance) concept. BK trees are also used for approximate string matching. Various auto-correct features in many software can be implemented based on this data structure. 

## Run and Compile 
The code can be compiled and run in terminal/VScode .
<br>
1.As the code is in C++, use g++. That is, type 'g++ code.cpp' and press enter to compile the code. 
2.Type './a.out'(in linux) or './a.exe'(in windows) to run the programme.
<br>
Alternatively,
<br>
1.In VScode select terminal (in menubar), select 'Run Build Task' then compile using g++ compiler. 
2.To run go to the terminal and type './code'.

#### Make sure that the text file 'vocab.txt' is in the same directory as the code as it contains list of words.

## Expected input and output
1.First enter a sentence or a word. and the program will indicate whether the entered words are correct or incorrect.
2.If you want suggestions for the incorrect words, enter '1'. The program will output a list of words that are close to the incorrect words (with a tolerance value of 2), helping you predict what the user might have intended to enter.

## Example:
Enter a word/sentence:computerr  engineering algoritmms project data structue    
computerr is incorrect 
engineering is correct
algoritmms is incorrect 
project is correct
data is correct
structue is incorrect 
Enter 1 if you want suggestions for the incorrect words:1

Did you mean these instead of computerr
compute computer computed computers

Did you mean these instead of algoritmms
algorithm algorithms

Did you mean these instead of structue
struct structure structures structured


