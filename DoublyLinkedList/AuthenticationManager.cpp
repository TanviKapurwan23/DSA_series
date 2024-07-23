#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class AuthenticationManager {
private:
    int ttl;  // Time to live for each token
    unordered_map<string, int> tokens; // Stores the expiration time for each token

public:
    AuthenticationManager(int timeToLive) : ttl(timeToLive) {}
    
    void generate(string tokenId, int currentTime) {
        // Update or insert token with its expiration time
        tokens[tokenId] = currentTime + ttl;
    }
    
    void renew(string tokenId, int currentTime) {
        // Check if the token is present and not expired
        if (tokens.find(tokenId) != tokens.end() && tokens[tokenId] > currentTime) {
            // Renew the token by updating its expiration time
            tokens[tokenId] = currentTime + ttl;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        // Iterate over the tokens and count those that are still valid
        for (const auto& [tokenId, expirationTime] : tokens) {
            if (expirationTime > currentTime) {
                count++;
            }
        }
        return count;
    }
};

// Helper function to demonstrate the AuthenticationManager class
int main() {
    AuthenticationManager manager(5); // Token expires after 5 units of time

    manager.generate("token1", 1);
    manager.generate("token2", 2);

    cout << "Unexpired tokens at time 3: " << manager.countUnexpiredTokens(3) << endl; // Output: 2

    manager.renew("token1", 4);
    cout << "Unexpired tokens at time 6: " << manager.countUnexpiredTokens(6) << endl; // Output: 1

    manager.generate("token3", 7);
    cout << "Unexpired tokens at time 8: " << manager.countUnexpiredTokens(8) << endl; // Output: 2

    return 0;
}
