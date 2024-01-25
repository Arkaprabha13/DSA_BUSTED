//User function Template for C++
class Solution{   
public:
   
bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

vector<int> getNeighbors(int num) {
    vector<int> neighbors;
    string numStr = to_string(num);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }
            string neighborStr = numStr;
            neighborStr[i] = '0' + j;
            int neighbor = stoi(neighborStr);
            if (isPrime(neighbor)) {
                neighbors.push_back(neighbor);
            }
        }
    }
    return neighbors;
}

int solve(int Num1, int Num2) {
    if (Num1 == Num2) {
        return 0;
    }

    unordered_set<int> visited;
    queue<pair<int, int>> bfsQueue;
    bfsQueue.push(make_pair(Num1, 0));

    while (!bfsQueue.empty()) {
        pair<int, int> currentPair = bfsQueue.front();
        bfsQueue.pop();

        int currentNum = currentPair.first;
        int steps = currentPair.second;

        vector<int> neighbors = getNeighbors(currentNum);

        for (int neighbor : neighbors) {
            if (visited.find(neighbor) == visited.end()) {
                if (neighbor == Num2) {
                    return steps + 1;
                }
                visited.insert(neighbor);
                bfsQueue.push(make_pair(neighbor, steps + 1));
            }
        }
    }

    return -1; // If no path is found
}

};
