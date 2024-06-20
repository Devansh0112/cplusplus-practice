#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Helper function to determine if m bouquets can be made within given days
    bool canMakeBouquets(const vector<int>& bloomDay, int m, int k, int days) {
        int bouquets = 0;
        int flowers = 0;

        for (int bloom : bloomDay) {
            if (bloom <= days) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0; // Reset the count for the next bouquet
                }
            } else {
                flowers = 0; // Reset the count if the flower hasn't bloomed
            }

            if (bouquets >= m) {
                return true;
            }
        }

        return false;
    }

    // Main function to find the minimum number of days to make m bouquets
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        // Check if it's possible to make the required bouquets
        if (n < m * k) {
            return -1;
        }

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        // Binary search
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (canMakeBouquets(bloomDay, m, k, mid)) {
                right = mid; // Try to find a smaller number of days
            } else {
                left = mid + 1; // Increase the number of days
            }
        }

        return left;
    }
};

// Example usage
int main() {
    Solution solution;
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;
    int result = solution.minDays(bloomDay, m, k);
    cout << "Minimum number of days: " << result << endl; // Output: 3
    return 0;
}
