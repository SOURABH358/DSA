// GFG - https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/
// Wiki - https://en.wikipedia.org/wiki/Huffman_coding
#include<bits/stdc++.h>
using namespace std;

class minHeap{
    public:
    int fre;
    minHeap* left;
    minHeap* right;
    char c;
    minHeap(char c, int fre)
    {
        left = right = NULL;
        this->c = c;
        this->fre = fre;
    }
};
struct compare{
    bool operator()(minHeap*l, minHeap*r)
    {
        return l->fre>r->fre;
    }
};
class Solution
{
	public:
	void getPrefixCode(minHeap*root, vector<string>&arr, string str)
	{
	    if(!root)
	    return ;
	    if(root->c!='$')
	    {
	        arr.push_back(str);
	    }
	    getPrefixCode(root->left, arr, str+"0");
	    getPrefixCode(root->right, arr, str+"1");
	}
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    minHeap *left, *right, *top;
		    priority_queue<minHeap*, vector<minHeap*>, compare>pq;
		    for(int i=0;i<N;i++)
		    {
		        minHeap*temp = new minHeap(S[i], f[i]);
		        pq.push(temp);
		    }
		    while(pq.size()>1)
		    {
		        left = pq.top();
		        pq.pop();
		        right = pq.top();
		        pq.pop();
		        minHeap*temp = new minHeap('$', left->fre+right->fre);
		        temp->left = left;
		        temp->right = right;
		        pq.push(temp);
		    }
		    top = pq.top();
		    vector<string>res;
		    getPrefixCode(top, res,"");
		    
		    return res;
		}
};

int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
