#include <iostream>
#include <unordered_map>
#include <vector>

/*
 * There are two sorted arrays positive and negative，return  two numbers such that they add up to zero
 * 有两个有序数列，一个正整数数列，一个负整数数列，返回相加等于0的两个数。
 *
 * Example:
 *
 *   [2,3,4,5,6] and [-1, -3,-5,-7]
 *
 *   3 + (-3) = 0;
 *
 *   5 + (-5) = 0;
 *
 *   return [1,1],[3,2];
 */

using namespace std;

typedef pair<int, int> pair_num;

class Solution {
public:
    vector<pair_num> addUpToZero(vector<int>& positive, vector<int>& negative) {

        vector<pair_num> result;
        unordered_map<int, int> hashmap;

        int j=0;
        for(int &i:negative) {
            hashmap[i]= j++;
        }

        j=0;
        for(int &i:positive) {
            if(hashmap.find(-i) != hashmap.end()) {
                result.push_back(make_pair(j,hashmap[-i]));
            }
            j++;
        }

        return result;
    }

    vector<pair_num> addUpToZero2(vector<int>& positive, vector<int>& negative) {

        vector<pair_num> result;

        int index2=0;
        for(int index1=0; index1 < positive.size(); index1++) {
            for(;index2 < negative.size();) {
                int sum = positive[index1] + negative[index2];
                if(sum == 0) {
                    result.push_back(make_pair(index1,index2));
                    break;
                }
                else if(sum >0) {
                    index2 ++;
                }
                else {
                    break;
                }
            }
        }

        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    vector<int> positive={2,3,4,5,6};
    vector<int> negative={-1, -3,-5,-7};

    cout << "Solution1:" << endl;
    for(auto &i:solution.addUpToZero(positive,negative)) {
        cout << "[" << i.first << "," << i.second << "]" << endl;
    }

    cout << "Solution2:" << endl;
    for(auto &i:solution.addUpToZero2(positive,negative)) {
        cout << "[" << i.first << "," << i.second << "]" << endl;
    }


    return 0;
}
