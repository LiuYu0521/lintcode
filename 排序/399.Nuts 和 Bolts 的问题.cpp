/**
 * class Comparator {
 *     public:
 *      int cmp(string a, string b);
 * };
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/
class Solution {
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        // write your code here
        quickSort(nuts, bolts, 0, nuts.size()-1, compare);
    }

private:
    void quickSort(vector<string> &a, vector<string> &b, int l, int r, Comparator compare) {
        int mark, count=0;
        for (int i=l; i<=r; ++i) {
            int t = compare.cmp(a[l], b[i]);
            if (t==0) mark = i;
            else
                if (t==1) ++count;
        }
        swap(a[l], a[l+count]);
        swap(b[mark],b[l+count]);
        mark = l+count;
        int i = l, j = r;
        while (i<mark && j>mark) {
            while (i<mark && compare.cmp(a[i], b[mark])==-1) ++i;
            while (j>mark && compare.cmp(a[j], b[mark])==1) --j;
            if (i<j) swap(a[i++], a[j--]);
        }
        i = l; j = r;
        while (i<mark && j>mark) {
            while (i<mark && compare.cmp(a[mark], b[i])==1) ++i;
            while (j>mark && compare.cmp(a[mark], b[j])==-1) --j;
            if (i<j) swap(b[i++], b[j--]);
        }
        if (l<mark) quickSort(a, b, l, mark-1, compare);
        if (r>mark) quickSort(a, b, mark+1, r, compare);
    }
};
