class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        int cnt = 0;
        for(int i = 0; i < length; i++)
        {
            if(string[i] == ' ')
                cnt++;
        }
        int new_length = length + cnt * 2;
        int j = new_length - 1;
        int i = length - 1;
        while(i >= 0)
        {
            if(string[i] != ' ')
            {
                string[j] = string[i];
                i--;
                j--;
            }
            else
            {
                string[j] = '0';
                string[j - 1] = '2';
                string[j - 2] = '%';
                i--;
                j = j - 3;
            }
        }
        return new_length;
    }
};
