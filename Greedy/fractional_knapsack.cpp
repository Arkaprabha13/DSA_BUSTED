//Static function or standalone function for comparison
static bool compare(Item a, Item b) {
    double ratioA = (double)a.value / a.weight;
    double ratioB = (double)b.value / b.weight;
    return ratioA > ratioB;
}

class Solution {
public:
    double fractionalKnapsack(int W, Item arr[], int n) {
        // Sort items based on value-to-weight ratio in descending order
        sort(arr, arr + n, compare);

        double maxValue = 0.0;

        for (int i = 0; i < n; ++i) {
            if (arr[i].weight <= W) {
                // Take the whole item
                W -= arr[i].weight;
                maxValue += arr[i].value;
            } else {
                // Take a fraction of the item
                double fraction = (double)W / arr[i].weight;
                maxValue += fraction * arr[i].value;
                break;
            }
        }

        return maxValue;
    }
};
