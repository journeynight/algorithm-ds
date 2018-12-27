#include <iostream>
#include <vector>
using namespace std;
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
const char EMPTY_VAL = '#';
const int ALPHABET_SIZE = 26;
class TrieNode{
   public:
      bool isEnd;
      char val;
      int numChild;
      TrieNode *child[ALPHABET_SIZE];
      TrieNode()
      {
           this->isEnd = false;
           this->val = EMPTY_VAL;
           this->numChild = 0;
           for(auto i = 0;i < ALPHABET_SIZE;++i)
               this->child[i] = NULL;
      }
};
class Solution{
    public:
        TrieNode *root;
        Solution():root(new TrieNode())
        {
             ;
        }
        void Insert(string str)
        {
            int len = str.length();
            int index;
            TrieNode* pCrawl = root;
            for(auto i = 0;i < len;++i){
                index = CHAR_TO_INDEX(str[i]);
                if(pCrawl->child[index] == NULL){
                    pCrawl->child[index] = new TrieNode();
                    pCrawl->child[index]->val = str[i];
                    pCrawl->numChild += 1;
                }
                pCrawl = pCrawl->child[index];
            }
            pCrawl->isEnd = true;
        }
        string GetLcpOfTrie()
        {
            string lcp = "";
            TrieNode* pCrawl = root;
            while(pCrawl->numChild == 1 && !pCrawl->isEnd){
                lcp += pCrawl->val;
                int index = 0;
                while(index < ALPHABET_SIZE && pCrawl->child[index] == NULL)
                    index += 1;
                pCrawl = pCrawl->child[index];
            }
            lcp += pCrawl->val;
            return lcp.substr(1,lcp.length());
        }
        string longestCommonPrefix(vector<string> &strs){
            for(auto i = 0; i < strs.size();++i)
                Insert(strs[i]);
            return this->GetLcpOfTrie();
        }
};
int main()
{
    vector<string> strs = {"flower","flight","fly"};
    Solution so = Solution();
    cout<<so.longestCommonPrefix(strs)<<endl;
    return 0;
}
