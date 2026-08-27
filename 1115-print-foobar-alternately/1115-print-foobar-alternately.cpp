class FooBar {
private:
    int n;
    bool lastFoo;

    mutex mtx;
    condition_variable cv;

public:
    FooBar(int n) {
        this->n = n;
        this->lastFoo = false;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock,[this]{
                return !lastFoo;
            });
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            lastFoo = true;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex>lock(mtx);
            cv.wait(lock,[this]{
                return lastFoo;
            });
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            lastFoo = false;
            cv.notify_all();
        }
    }
};