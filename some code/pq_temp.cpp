struct PQ{
    priority_queue <int> pq, rm;
    void psh(int x) {
        pq.push(x);
    }
    int big() {
        while(!rm.empty() && pq.top() == rm.top()) {
            pq.pop();
            rm.pop();
        }
        return pq.top();
    }
    int rmv(int x) {
        rm.push(x);
    }
};
