#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

#define MAXN 10000
#define TOL 2
#define LEN 74

struct Node
{
    string word;
    int next[2 * LEN];
    //constructors
    Node(string x) : word(x)//initialize word with x(x is the argument passed)
    {
        for (int i = 0; i < 2 * LEN; i++)
            next[i] = 0;//initializing next[i]'s to zeroes
    }
// next array is used to link the current node to its child nodes based on their edit distances from the current node's word.

    Node() {}
};

Node *tree = new Node[MAXN];//array of node objects
Node RT;
int ptr;

int min(int a, int b, int c)
{
    return min(a, min(b, c));
}
//calculation of edit distance O(m*n)
int editDistance(string &a, string &b)
{
    int m = a.length(), n = b.length(); 
    //dp[m+1][n+1]
    int **dp = new int *[m + 1];
    for (int i = 0; i <= m; i++)
        dp[i] = new int[n + 1];

    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int j = 0; j <= n; j++)
        dp[0][j] = j;

    for (int i = 1; i <= m; i++)
    {
        /*if the characters are not equal we find the minimum cost of all 3 operations 
        which are insert,delete and replace*/
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] != b[j - 1])
            {
                dp[i][j] = min(1 + dp[i - 1][j], 1 + dp[i][j - 1], 1 + dp[i - 1][j - 1]);
                //insert,remove and replace
            }
            else
                dp[i][j] = dp[i - 1][j - 1];//when last characters of the strings matches 
        }
    }

    int result = dp[m][n];

    for (int i = 0; i <= m; i++)
        delete[] dp[i];
    delete[] dp;

    return result;
}

void add(Node &root, Node &curr)
{
    if (root.word == "")//when first node 
    {
        root = curr;
        return;
    }

    int dist = editDistance(curr.word, root.word);//get edit distance from root node
    //that is dist equals the edge weight
    //tree is the array of nodes 
    if (tree[root.next[dist]].word == "")//if no node present at this edit distance from the root node we make this node(curr) its child
    {
        ptr++;
        tree[ptr] = curr;
        root.next[dist] = ptr;
    }
    else
    {
        //in case of collision
        //  Therefore, we deal this collision by recursively doing this insertion process on the pre-existing colliding node.
        add(tree[root.next[dist]], curr);
    }
}

vector<string> getSimilarWords(Node &root, string &s)
{
    vector<string> ret;

    if (root.word == "")
        return ret;

    int dist = editDistance(root.word, s);

    if (dist <= TOL)
        ret.push_back(root.word);//if edit distance less than tolerace value adding it to similar words 

    for (int i = 1; i < 2 * LEN; i++)
    {
        if (root.next[i] != 0)
        {
            vector<string> tmp = getSimilarWords(tree[root.next[i]], s);
            ret.insert(ret.end(), tmp.begin(), tmp.end());
        }
    }

    return ret;
}

int main()
{
    fstream file;
    string filename;
    filename = "vocab2.txt";//contains the list of words for the dictionary
    ptr = 0;
    string word;
    vector<string> dictionary;//to store the words in the file
    file.open(filename.c_str());//opening the file filename= vocab.txt
    while (file >> word)
    {
        Node tmp = Node(word);
        add(RT, tmp);//adding the word to the tree
        dictionary.push_back(word);
    }

    file.close();

    string inputSentence;
    cout << "Enter a word/sentence:";
    getline(cin, inputSentence);
    vector<string> wordsInSentence;
    string wordInSentence;
    istringstream iss(inputSentence);
    while (iss >> wordInSentence)
    {
        wordsInSentence.push_back(wordInSentence);
    }
    int flag=-1;
    for (std::string &inputWord : wordsInSentence)//inputWord=wordsInSentence
    {
        vector<string> similarWords = getSimilarWords(RT, inputWord);

        bool isCorrect = false;

        for (const string &word : similarWords)
        {
            if (word == inputWord)//string matches then it's correct
            {
                isCorrect = true;
                break;
            }
        }
        if (isCorrect)
        {
            cout <<inputWord<< " is correct" << endl;
        }
        else
        {
            flag=1;
            cout << inputWord << " "<< "is incorrect \n";
            // for (const string& similarWord : similarWords) {
            //     cout << similarWord << " ";
            // }
        }
    }
    if(flag==1){
        int val;//suggestions for the incorrect words
        cout<<"Enter 1 if you want suggestions for the incorrect words:";
        cin>>val;
        if(val==1){
            for (std:: string& inputWord : wordsInSentence) {
        vector<string> similarWords = getSimilarWords(RT, inputWord);

        bool isCorrect = false;

        for (const string& word : similarWords) {
            if (word == inputWord) {
                isCorrect = true;
                break;
            }
        }

        if (isCorrect) {
            
        } else {
            cout <<"\nDid you mean these instead of "<< inputWord;
            cout<<endl;
            for (const string& similarWord : similarWords) {
                cout << similarWord << " ";
            }
            cout << endl;
        }
    }
        }
    }

    return 0;
}
