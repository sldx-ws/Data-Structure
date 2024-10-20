#include <vector>

class CircularQueue 
{
public:
    CircularQueue(int k)
        :_capacity(k + 1)
        , _cq(k + 1)
        , _rear(0)
        , _front(0)
    {}

    bool enQueue(int value) {
        if (isFull()) return false;
        _cq[_rear] = value;
        _rear = (_rear + 1) % _capacity;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        _front = (_front + 1) % _capacity;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return _cq[_front];
    }

    int Rear() 
    {
        if (isEmpty())  return -1;
        return _cq[(_rear - 1 + _capacity) % _capacity];
    }

    bool isEmpty() { return _rear == _front; }
    bool isFull() { return ((_rear + 1) % _capacity) == _front; }

private:
    std::vector<int> _cq;
    int _front;
    int _rear;
    int _capacity;
};