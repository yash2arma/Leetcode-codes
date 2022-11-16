class Solution {
public:
    int guessNumber(int n) {
        
        int front = 1, end = n;
        
        while (front <= end){
            int mid = ((unsigned int)front + (unsigned int)end) >> 1;
            if (guess (mid) == -1){
                end = mid - 1;
            }
            
            else if (guess (mid) == 1){
                front = mid + 1;
            }
            
            else {
                return mid;
            }
        }
        return 0;
    }
};