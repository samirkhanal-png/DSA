class MyStack {
public:
    queue<int>q;
    MyStack() {

    }

    void push(int x) {
        int size=q.size();//preserve the size before popping up (do not do this mistake in interview)
        q.push(x);
        for(int i=0;i<size;i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int topEl=q.front(); //preserving the front element before popping up
        q.pop();
        return topEl;
    }

    int top() {
        return q.front(); //returning the top element
    }

    bool empty() {
        return q.empty();
    }
};

/*
For queue use front() instead of top

Queue is a FIFO and stack is a LIFO

Since we are using queue we need to add the latest item towards the front and previous items towards the end

We can simulate this behaviour by

1

prevSize=1
push(2)
1>2

1>2>1(pushed)
X pop

2>1
prevSize=2
push(4)
2>1>4 push
X

2>1>4>2(pushed)
X

1>4>2>1
X

*/
