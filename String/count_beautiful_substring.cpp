class Solution {
public:

// bool isBeautiful(const string& substring, int k) {
//     int vowels = 0, consonants = 0;
//     for (char c : substring) {
//         if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
//             vowels++;
//         } else {
//             consonants++;
//         }
//     }
//     return vowels == consonants && (vowels * consonants) % k == 0;
// }
//     long long beautifulSubstrings(string s, int k) {
//     long long count = 0;
//     int n = s.length();

//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j <= n; j++) {
//             if (isBeautiful(s.substr(i, j - i), k)) {
//                 count++;
//             }
//         }
//     }
// return count;
// }

// bool isBeautiful(int vowels, int consonants, int k) {
//     return vowels == consonants && (vowels * consonants) % k == 0;
// }

// long long  beautifulSubstrings(const string& s, int k) {
//     int n = s.length();
//     long long  count = 0;

//     vector<vector<int>> vowelsCount(n + 1, vector<int>(n + 1, 0));
//     vector<vector<int>> consonantsCount(n + 1, vector<int>(n + 1, 0));

//     for (int i = 1; i <= n; ++i) {
//         vowelsCount[i][i] = (s[i - 1] == 'a' || s[i - 1] == 'e' || s[i - 1] == 'i' || s[i - 1] == 'o' || s[i - 1] == 'u');
//         consonantsCount[i][i] = (s[i - 1] != 'a' && s[i - 1] != 'e' && s[i - 1] != 'i' && s[i - 1] != 'o' && s[i - 1] != 'u');
//     }

//     for (int len = 2; len <= n; ++len) {
//         for (int i = 1; i + len - 1 <= n; ++i) {
//             int j = i + len - 1;
//             vowelsCount[i][j] = vowelsCount[i][j - 1] + (s[j - 1] == 'a' || s[j - 1] == 'e' || s[j - 1] == 'i' || s[j - 1] == 'o' || s[j - 1] == 'u');
//             consonantsCount[i][j] = consonantsCount[i][j - 1] + (s[j - 1] != 'a' && s[j - 1] != 'e' && s[j - 1] != 'i' && s[j - 1] != 'o' && s[j - 1] != 'u');
//         }
//     }

//     for (int i = 1; i <= n; ++i) {
//         for (int j = i; j <= n; ++j) {
//             int vowels = vowelsCount[i][j];
//             int consonants = consonantsCount[i][j];
//             count += isBeautiful(vowels, consonants, k);
//         }
//     }

//     return count;
// }

    long long beautifulSubstrings(string s, int k)
    {
        int V = 0, C = 0;
        std::vector<int> diff{0};

        // Keep track of how many vowels (V) and consonants (C) we've seen.
        // We'll also use a vector called "diff" to store the differences between V and C.

        for (char ch : s)
        {
            // Go through each letter in the given word.

            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                V += 1; // If the letter is a vowel, add 1 to the V count.
            else
                C += 1; // If the letter is a consonant, add 1 to the C count.

            diff.push_back(V - C); // Store the difference between V and C in the "diff" vector.
        }

        // Now we've counted the differences between the number of vowels and consonants in the word.

        // Let's count beautiful substrings using these differences.

        // We'll use a special map (like a magical dictionary) to remember where we've seen each difference before.
        std::unordered_map<int, std::vector<int>> pos;

        int count = 0; // This will be our answer, the total number of beautiful substrings.

        for (int i = 0; i < diff.size(); ++i)
        {
            // Now, let's go through each difference and see if we've seen it before.

            int d = diff[i]; // Get the current difference.

            if (pos.find(d) != pos.end())
            {
                // If we've seen this difference before, let's check all the positions we've seen it.

                for (int j : pos[d])
                {
                    // For each position, calculate the length of the substring between the two positions.

                    long t = (i - j) / 2;

                    // If the square of that length is divisible by k, then it's a beautiful substring!

                    if (t * t % k == 0)
                        count += 1;
                }
            }

            // Now, let's remember the position where we saw this difference.
            pos[d].push_back(i);
        }

        // Finally, we've counted all the beautiful substrings, and we return the total count.
        return count;
    }

};
