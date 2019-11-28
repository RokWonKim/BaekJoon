class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int diff_x_num = 0;
        int diff_y_num = 0;
        
        for (int i = 0; i < s1.size(); i++) {
            if(s1[i] != s2[i] && s1[i] == 'x')
                diff_x_num++;
            if(s1[i] != s2[i] && s1[i] == 'y')
                diff_y_num++;
        }
        if ( (diff_x_num + diff_y_num)%2 == 1)
            return -1;
        
        if( diff_x_num == 0 || diff_x_num%2 == 0)
            return (diff_x_num + diff_y_num)/2;
        else
            return (diff_x_num + diff_y_num)/2 + 1;
    }
};
