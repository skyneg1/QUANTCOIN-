import ctypes

class QuantumBlockchain:
    def __init__(self, lib_path="./cpp/blockchain.so"):
        self.blockchain = ctypes.CDLL(lib_path)
        self.blockchain.init()

    def add_transaction(self, transaction):
        self.blockchain.add_transaction(ctypes.c_char_p(transaction.encode()))

    def mine_block(self):
        self.blockchain.mine_block()