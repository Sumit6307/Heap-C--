#include <iostream>

using namespace std;

class TrieNode
{

public:
    char data;
    TrieNode *children[26];
    bool isterminal;

    TrieNode(char ch)
    {
        data = ch;

        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isterminal = false;
    }

};
class Trie
{

public:
    TrieNode *root;


     Trie () {

          root = new TrieNode('\0');
     }

    void insertUtil(TrieNode *root, string word)
    {
          if(word.length()==0) {
                  root->isterminal = true;
                  return ;
          }
 
         int index = word[0] - 'A';
          TrieNode * child;
    

      if(root->children[index] != NULL) {
          child =root->children[index];
      }
     
       else {
        child = new TrieNode(word[0]);
          
           root->children[index] = child;
       }
        insertUtil(child, word.substr(1));


       }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

   //  Search Word

    bool searchUtil( TrieNode * root , string word) {

          if(word.length()==0) {
            return  root->isterminal; 
            
          }

      int index = word[0] - 'A';
       TrieNode* child;

           if(root->children[index]!= NULL) {
             child =  root->children[index] ;
           }
           else {
              
               return false;
    }
        
        return searchUtil(child, word.substr(1));
    }


       bool searchWord(string word) {
        return searchUtil(root , word);

       }
};



 int main () {
      Trie *t = new Trie ;
         
      t->insertWord("abcd");
     cout<< "Presnet or not"  << t->searchWord("abcdw") << endl;

       return 0;
 }