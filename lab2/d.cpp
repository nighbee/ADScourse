#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<int> findModes(const std::vector<int>& nums) {
    std::unordered_map<int, int> frequency;
    for (int num : nums) {
        frequency[num]++;
    }

    int maxFreq = 0;
    for (const auto& pair : frequency) {
        if (pair.second > maxFreq) {
            maxFreq = pair.second;
        }
    }

    std::vector<int> modes;
    for (const auto& pair : frequency) {
        if (pair.second == maxFreq) {
            modes.push_back(pair.first);
        }
    }

    std::sort(modes.begin(), modes.end(), std::greater<int>());
    return modes;
}

int main() {
    std::vector<int> nums;
    int n, temp;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> temp;
        nums.push_back(temp);
    }

    std::vector<int> modes = findModes(nums);

    for (int mode : modes) {
        std::cout << mode << " ";
    }
    std::cout << std::endl;

    return 0;
}