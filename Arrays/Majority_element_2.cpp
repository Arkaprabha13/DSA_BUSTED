class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
    int size = a.size();
    int candidate1 = -1, candidate2 = -1;
    int count1 = 0, count2 = 0;

    for (int i = 0; i < size; i++) {
        if (a[i] == candidate1) {
            count1++;
        } else if (a[i] == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = a[i];
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = a[i];
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;

    for (int i = 0; i < size; i++) {
        if (a[i] == candidate1) {
            count1++;
        } else if (a[i] == candidate2) {
            count2++;
        }
    }

    vector<int> result;

    if (count1 > size / 3) {
        result.push_back(candidate1);
    }
    if (count2 > size / 3) {
        result.push_back(candidate2);
    }

    return result;
    }
};
