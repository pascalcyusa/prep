#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(std::vector<int>& heartRate, std::vector<string>& activityLevel) {
    std::unordered_map<string, std::pair<int, int>> activity_rates;
    int max_difference = 0;

    for (size_t i = 0; i < heartRate.size(); i++) {
        string& activity = activityLevel[i];
        int rate = heartRate[i];

        if (activity_rates.find(activity) == activity_rates.end()) {
            // initialize activity levels
            activity_rates[activity] = {rate, rate};
        } else {
            // change min and max for this activity level
            auto& [min_rate, max_rate] = activity_rates[activity];
            min_rate = std::min(min_rate, rate);
            max_rate = std::max(max_rate, rate);
        }

        int difference = activity_rates[activity].second - activity_rates[activity].first;
        max_difference = std::max(max_difference, difference);

        // cerr for debugging
        cerr << "min: " << activity_rates[activity].first << endl;
        cerr << "max: " << activity_rates[activity].second << endl;
    }

    return max_difference;
}

vector<int> toIntVector(string str) {
    vector<int> out;
    string i;
    istringstream tokenStream(str);
    while (getline(tokenStream, i, ',')) {
        out.push_back(atoi(i.c_str()));
    }
    return out;
}

vector<string> toStringVector(string str) {
    vector<string> out;
    string i;
    istringstream tokenStream(str);
    while (getline(tokenStream, i, ',')) {
        out.push_back(i);
    }
    return out;
}

int main() {
    string heartRateStr;
    string activityLevelStr;

    cout << "Enter heart rates (comma-separated): ";
    cin >> heartRateStr;

    cout << "Enter activity levels (comma-separated): ";
    cin >> activityLevelStr;

    vector<int> heartRates = toIntVector(heartRateStr);
    vector<string> activityLevels = toStringVector(activityLevelStr);

    cout << "Max heart rate difference: " << solution(heartRates, activityLevels) << endl;
    return 0;
}
