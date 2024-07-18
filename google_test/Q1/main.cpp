#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

int solution(std::vector<std::string>& clients) {
    std::unordered_map<std::string, int> assigned_lockers;
    std::set<int> free_lockers;
    int max_locker = 0;
    int last_assigned = 0;

    for (const std::string& client : clients) {
        std::cerr << "Processing client: " << client << std::endl;

        if (assigned_lockers.find(client) != assigned_lockers.end()) {
            // Client already has a locker, free it
            int locker = assigned_lockers[client];
            free_lockers.insert(locker);
            assigned_lockers.erase(client);
            std::cerr << "  Freed locker " << locker << " for " << client << std::endl;
        } else {
            // Assign a new locker
            int locker;
            if (not free_lockers.empty()) {
                // Use the lowest available free locker
                locker = *free_lockers.begin();
                free_lockers.erase(free_lockers.begin());
                std::cerr << "  Assigned free locker " << locker << " to " << client << std::endl;
            } else {
                // No free lockers, assign a new one
                locker = ++max_locker;
                std::cerr << "  Assigned new locker " << locker << " to " << client << std::endl;
            }
            assigned_lockers[client] = locker;
            last_assigned = locker;
        }

        std::cerr << "  Current state:" << std::endl;
        std::cerr << "    Assigned lockers: ";
        for (const auto& pair : assigned_lockers) {
            std::cerr << pair.first << ":" << pair.second << " ";
        }
        std::cerr << std::endl;
        std::cerr << "    Free lockers: ";
        for (int locker : free_lockers) {
            std::cerr << locker << " ";
        }
        std::cerr << std::endl;
        std::cerr << "    Last assigned: " << last_assigned << std::endl;
        std::cerr << std::endl;
    }

    return last_assigned;
}

int main() {
    std::vector<std::string> clients1 = {"Alice", "Eve", "Bob", "Eve", "Carl", "Alice"};
    std::cerr << "Example 1:" << std::endl;
    std::cout << "Example 1: " << solution(clients1) << std::endl
              << std::endl;

    std::vector<std::string> clients2 = {"Alice", "Bob", "Bobby"};
    std::cerr << "Example 2:" << std::endl;
    std::cout << "Example 2: " << solution(clients2) << std::endl
              << std::endl;

    std::vector<std::string> clients3 = {"Bob", "bob", "BoB", "bob", "BOB"};
    std::cerr << "Example 3:" << std::endl;
    std::cout << "Example 3: " << solution(clients3) << std::endl
              << std::endl;

    std::vector<std::string> clients4 = {"Alice", "Alice", "Bob", "Alice"};
    std::cerr << "Example 4:" << std::endl;
    std::cout << "Example 4: " << solution(clients4) << std::endl;

    std::vector<std::string> clients5 = {"Alice", "Eve", "Bob", "Eve", "Carl", "Alice"};
    std::cerr << "Example 5" << std::endl;
    std::cout << "Example 5: " << solution(clients5) << std::endl;

    return 0;
}