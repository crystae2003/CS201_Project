# CS201_Project : BK Trees(Efficient Spell Checking in NLP)
## Introduction.
In this project,we have implemented spell check and prediction of incorrect words with the help of BK(Burkhard Keller)trees.BK Tree  is a data structure that is used to perform spell check based on the Edit Distance (Levenshtein distance) concept. BK trees are also used for approximate string matching. Various auto-correct features in many software can be implemented based on this data structure. 

## Run and Compile 
The code can be compiled and run in terminal/VScode .
<br>
1.As the code is in C++, use g++. That is, type 'g++ code.cpp' and press enter to compile the code. 
<br>
2.Type './a.out'(in linux) or './a.exe'(in windows) to run the programme.
<br>
Alternatively,
<br>
1.In VScode select terminal (in menubar), select 'Run Build Task' then compile using g++ compiler. 
<br>
2.To run go to the terminal and type './code'.

#### Make sure that the text file 'vocab.txt' is in the same directory as the code as it contains list of words.

## Expected input and output
1.First enter a sentence or a word. and the program will indicate whether the entered words are correct or incorrect.
<br>
2.If you want suggestions for the incorrect words, enter '1'. The program will output a list of words that are closer to the incorrect words (within the tolerance value of 2,this tolerance value is simply the maximum edit distance from the misspelled word to the correct words in our dictionary.) helping us to predict what the user might have intended to enter.

## Example:
Enter a word/sentence:computerr  engineering algoritmms project data structue    
<br>
computerr is incorrect 
<br>
engineering is correct
<br>
algoritmms is incorrect 
<br>
project is correct
<br>
data is correct
<br>
structue is incorrect 
<br>
Enter 1 if you want suggestions for the incorrect words:1
<br>
<br>
Did you mean these instead of computerr
<br>
compute computer computed computers
<br>
<br>
Did you mean these instead of algoritmms
<br>
algorithm algorithms
<br>
<br>
Did you mean these instead of structue
<br>
struct structure structures structured

# Contributed by:
NEHA DAHIRE,

HEMLATA GAUTAM,

SMRITI GUPTA


