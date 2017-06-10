class Solution {
public:
    /**
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        int len = A.size();
        int count = 0;
        int i = 0;
        while(i < len)
        {
            while(A[i] == elem)
                i++;
            if(i < len)
            {
                A[count] = A[i];
                count++;
                i++;
            }
        }
        return count;
    }
};
