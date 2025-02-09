#include <iostream>
#include <vector>
#include "block.cpp"

class Blockchain {
public:
    std::vector<Block> chain;
    int difficulty;

    Blockchain() {
        difficulty = 3;
        chain.push_back(create_genesis_block());
    }

    Block create_genesis_block() {
        return Block(0, {}, "0");
    }

    Block get_latest_block() {
        return chain.back();
    }

    void add_block(std::vector<std::string> transactions) {
        Block new_block(chain.size(), transactions, get_latest_block().hash);
        new_block.mine_block(difficulty);
        chain.push_back(new_block);
    }
};