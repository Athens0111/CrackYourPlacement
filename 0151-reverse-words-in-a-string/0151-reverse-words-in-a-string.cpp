class Solution {
public:
    string reverseWords(string s) {
        int i=0, j=s.size()-1;
        int n = s.size();

        while(i<j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
        cout<<"'"<<s<<"'";
        for(int i=0;i<n;i++){
            if(s[i] == ' ')
                continue;
            int j=i;
            while(j<n-1 && s[j+1] != ' ')
                j++;
            int temp = j;
            while(i<j){
                swap(s[i], s[j]);
                i++;j--;
            }
            i = temp +1;
            if(i<n)
                s[i] = '@';
        }
        j = n-1;
        while(s[j] == '@' || s[j] == ' ')
            s[j--] = ' ';
        i=0;
        while(s[i] != '\0'){
            if(s[i] == ' ')
                s.erase(s.begin()+i);
            else if(s[i] == '@')
                s[i++] = ' ';
            else
                i++;
        }

        return s;
    }
};