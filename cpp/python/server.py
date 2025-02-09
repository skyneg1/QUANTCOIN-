from flask import Flask, request, jsonify
from quantum_blockchain import QuantumBlockchain

app = Flask(__name__)
qb = QuantumBlockchain()

@app.route('/mine', methods=['GET'])
def mine():
    qb.mine_block()
    return jsonify({"message": "Block mined"})

if __name__ == '__main__':
    app.run(port=5000)