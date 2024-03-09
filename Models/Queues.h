
class Queues {
private:
    int *queue;
    int head;
    int tail;
    int size;
    int capacity;

public:
    explicit Queues(int capacity); ~Queues();
    void Enqueue(int data); int Dequeue();
    bool IsFull() const; bool IsEmpty() const;
    int Size() const; void ShowQueue();
};

