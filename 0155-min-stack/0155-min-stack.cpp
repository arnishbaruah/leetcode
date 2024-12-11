class MinStack {
  stack<long long> st;
  long long mini;

public:
  MinStack() {
    while (!st.empty()) st.pop();
    mini = LLONG_MAX;
  }

  void push(long long value) {
    long long val = value;
    if (st.empty()) {
      mini = val;
      st.push(val);
    } else {
      if (val < mini) {
        st.push(2 * val - mini);
        mini = val;
      } else {
        st.push(val);
      }
    }
  }

  void pop() {
    if (st.empty()) return;
    long long el = st.top();
    st.pop();

    if (el < mini) {
      mini = 2 * mini - el;
    }
  }

  long long top() {
    if (st.empty()) return -1;

    long long el = st.top();
    if (el < mini) return mini;
    return el;
  }

  long long getMin() {
    return mini;
  }
};
