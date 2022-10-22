#include <iostream>

using namespace std;
typedef unsigned int uint;

class Priority_queue
{
private:
    int size{}, *data; // data es un apuntador a mi array de datos
    int count{};       // saber cuantos llevo dentro del arreglo

public:
    Priority_queue(uint size_)
    {
        size = size_;
        data = new int[size];
        count = 0;
    }
    ~Priority_queue()
    {
        delete[] data;
    }

    int right(int i)
    {
        return (i * 2) + 2;
    }

    int left(int i)
    {
        return (i * 2) + 1;
    }

    int parent(int i)
    { // siempre me da entero, para buscar el padre
        return (i - 1) / 2;
    }

    bool full()
    {
        return (size == count); // sin if, para no ser redundante
    }

    bool empty()
    {
        return (0 == count);
    }

    int top()
    {
        return data[0];
    }

    int tam()
    {
        return size;
    }

    void push(int val)
    {
        if (full())
        {
            cout<<"Esta lleno"<<endl;
            return;
        }

        int pos;
        pos = count;
        count++;
        while (pos > 0 && val > data[parent(pos)])
        {
            data[pos] = data[parent(pos)];
            pos = parent(pos);
        }
        data[pos] = val;
    }

    int pop()
    {
        if (empty()){
            cout<<"Esta vacio";
            return 0;
        }

        int aux = data[0];
        data[0]=data[--count];
        reorder(0);
        return aux;
    }

    void reorder(int pos)
    {
        int le = left(pos);
        int ri = right(pos);
        int max = pos;

        if (le < count && data[le] > data[max])
        {
            max = le;
        }
        if (ri < count && data[ri] > data[max])
        {
            max = ri;
        }

        if (max != pos)
        {
            swap(pos, max);
            reorder(max);
        }
    }

    void swap(int i, int j){
        int aux = data[i];
        data[i] = data[j];
        data[j] = aux;
    }


};