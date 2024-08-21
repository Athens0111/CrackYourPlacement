class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int a = s.size() - 1;
        int b = t.size() - 1;
        int c = 0;
        for (int i = a; i >= 0; i--) {
            if (c != 0 && s[i] != '#') {
                while (c) {
                    if (s[i] == '#') {
                        c++;
                    } else {
                        s[i] = '#';
                        c--;
                    }
                    if (c)
                        i--;
                    if (i < 0)
                        break;
                }
            } else if (s[i] != '#')
                continue;
            else
                c++;
        }
        c = 0;
        for (int i = b; i >= 0; i--) {
            if (c != 0 && t[i] != '#') {
                while (c) {
                    if (t[i] == '#') {
                        c++;
                    } else {
                        t[i] = '#';
                        c--;
                    }
                    if (c)
                        i--;
                    if (i < 0)
                        break;
                }
            } else if (t[i] != '#')
                continue;
            else
                c++;
        }
        cout << s << " " << t << endl;
        int i = 0, j = 0;
        while (i <= a && j <= b) {
            while (i <= a and s[i] == '#') {
                i++;
            }

            while (j <= b && t[j] == '#')
                j++;
            cout << i << ":" << j << endl;
            if (s[i] != t[j])
                return false;
            i++;
            j++;
        }

        while (i <= a and s[i] == '#') {
                i++;
        }

        while (j <= b && t[j] == '#')
            j++;
        
        if(i<=a or j<=b)
            return false;
        return true;
    }
};

// class Solution {
// public:
//     bool backspaceCompare(string s, string t) {
//         int a = s.size()-1;
//         int b = t.size()-1;
//         int c = 0;
//        for(int i = a;i>0;i--){

//             if(s[i] == '#'){
//                 int x = i;
//                 while(x>-1 && s[x] != '#')
//                     x--;
//                 s[x] = '#';
//             }
//         }

//        for(int i=b ;i>0; i--){
//             if(t[i] == '#'){
//                 int x = i;
//                 while(x>-1 && t[x] != '#')
//                     x--;
//                 t[x] = '#';
//             }
//         }

//         cout << s << " " << t<<endl;
//         int i = 0, j = 0;
//         while(i <= a && j <= b){
//             while(i <= a and s[i] == '#'){
//                 i++;
//             }

//             while(j<=b && t[j] == '#')
//                 j++;
//             cout<<i<<":"<<j<<endl;
//             if(s[i] != t[j])
//                 return false;
//             i++;
//             j++;

//         }
//         return true;
//     }
// };