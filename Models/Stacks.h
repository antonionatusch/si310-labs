

class Stacks {
private:
    int top;
    int capacity;
    int *stack;
public:
    explicit Stacks(int n); ~Stacks();
    void Push(int data); int Pop();
    [[nodiscard]] bool IsFull() const; [[nodiscard]] bool IsEmpty() const;
    void Display(); int Peek(); void Clear();
    [[nodiscard]] int Count() const;
};

