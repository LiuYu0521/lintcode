// class Solution{
// public:
//     /**
//      * @param colors: A list of integer
//      * @param k: An integer
//      * @return: nothing
//      */
//     void sortColors2(vector<int> &colors, int k) {
//         // write your code here
//         int count[k+1];
//         for(int i = 0;i <=k; i++)
//         {
//             count[i]=0;
//         }
//         for(int i = 0; i < colors.size(); i++)
//         {
//             count[colors[i]]++;
//         }
//         colors.clear();
//         for(int i = 1; i <= k; i++)
//         {
//             for(int j = 0; j < count[i]; j++)
//             {
//                 colors.push_back(i);
//             }
//         }
//     }
// };

class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        quickSort(colors, 0, colors.size() - 1);
    }
    void quickSort(vector<int> &colors, int left, int right)
    {
        if(left >= right)
            return;
        int i = left;
        int j = right;
        int pivot = colors[(left + right) / 2];
        while(i <= j)
        {
            while(i <= j && colors[i] < pivot)
                i++;
            while(i <= j && colors[j] > pivot)
                j--;
            if(i <= j)
            {
                swap(colors[i], colors[j]);
                i++;
                j--;
            }
        }
        quickSort(colors, left, j);
        quickSort(colors, i, right);
    }
};
