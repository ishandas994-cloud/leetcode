class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       unordered_map<string,bool>vmap;
       for(string word :wordList){
        vmap[word]=false;
       } 
       if(vmap.find(endWord)==vmap.end()){
        return 0;
       }
       queue<pair<string,int>>q;
       q.push({beginWord,1});
       vmap[beginWord]=true;
       while(!q.empty()){
            string word=q.front().first;
            int level=q.front().second;
            q.pop();

            if(word==endWord){
                return level;
            }
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(vmap.find(word)!=vmap.end() && vmap[word]==false){
                        vmap[word]=true;
                        q.push({word,level+1});
                    }
                }
                word[i]=original;
            }
       }
       return 0;
    }
};