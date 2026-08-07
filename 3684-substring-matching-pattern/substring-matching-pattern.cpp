class Solution {
public:
    bool hasMatch(string s, string p) {
        int k = p.find("*");

        string a = p.substr(0,k);
        string b = p.substr(k+1);

        int i = s.find(a);

        if(i != string::npos)
        {
            while(s.find(b,i+a.size()) != string::npos)
            return true;
            
            i = s.find(a,i+1);

        }
        return false;

        
    }
};