class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills.size() == 0)
            return true;
        
        vector<int> arr(3,0);
        
        for (int x = 0; x < bills.size(); x++) {
            if (bills[x] == 5) arr[0] += 1;
            else if (bills[x] == 10){
                arr[1] += 1;
                if (arr[0] >= 1)
                    arr[0] -= 1;
                else
                    return false;
            }
            else {
                arr[2] += 1;
                if (arr[1] >= 1 && arr[0] >= 1) {
                    arr[0] -= 1;
                    arr[1] -= 1;
                }
                else if (arr[0] >= 3) arr[0] -= 3;
                else return false;
            }
        }
        return true;
    }
};
