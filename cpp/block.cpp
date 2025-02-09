#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <openssl/sha.h>

class Block {
public:
    int index;
    std::string timestamp;
    std::vector<std::string> transactions;
    std::string previous_hash;
    std::string hash;
    int nonce;

    Block(int idx, std::vector<std::string> txns, std::string prev_hash) {
        index = idx;
        transactions = txns;
        previous_hash = prev_hash;
        nonce = 0;
        timestamp = std::to_string(time(nullptr));
        hash = calculate_hash();
    }

    std::string calculate_hash() {
        std::stringstream ss;
        ss << index << timestamp << previous_hash << nonce;
        for (auto txn : transactions) ss << txn;
        std::string input = ss.str();
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256((unsigned char*)&input[0], input.size(), hash);
        std::stringstream hexstream;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
            hexstream << std::hex << (int)hash[i];
        return hexstream.str();
    }

    void mine_block(int difficulty) {
        std::string target(difficulty, '0');
        while (hash.substr(0, difficulty) != target) {
            nonce++;
            hash = calculate_hash();
        }
        std::cout << "⛏️ Block Mined: " << hash << std::endl;
    }
};