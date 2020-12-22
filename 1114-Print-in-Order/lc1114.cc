// C++ solution.

// mutex + condition variable.
class Foo {
public:
    Foo() : step_(1) {}

    void first(function<void()> printFirst) {
        // protect shared resource.
        std::unique_lock<std::mutex> lk(m_);

        printFirst();
        step_ = 2;

        // unlock manually before notify other threads.
        lk.unlock();
        cv_.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lk(m_);

        // wait on conditional variable (and deal with spurious wakeup)
        while (step_ != 2) {
            cv_.wait(lk);
        }
        printSecond();
        step_ = 3;
        cv_.notify_one();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lk(m_);

        // wait on conditional variable (and deal with spurious wakeup)
        while (step_ != 3) {
            cv_.wait(lk);
        }
        printThird();
        step_ = 0;
    }

private:
    int step_;
    std::mutex m_;
    std::condition_variable cv_;
};