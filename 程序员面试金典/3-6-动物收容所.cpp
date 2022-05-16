#include "LeetCode.h"

class AnimalShelf {
public:
  queue<vector<int>> cat_q_;
  queue<vector<int>> dog_q_;
  AnimalShelf() {}

  void enqueue(vector<int> animal) {
    // 狗
    if (animal[1] == 1) {
      dog_q_.push(animal);
    } else {
      cat_q_.push(animal);
    }
  }

  vector<int> dequeueAny() {
    if (!cat_q_.empty() && !dog_q_.empty()) {
      if (cat_q_.front()[0] < dog_q_.front()[0]) {
        return dequeueCat();
      } else {
        return dequeueDog();
      }
    }
    if (!cat_q_.empty()) {
      return dequeueCat();
    }
    if (!dog_q_.empty()) {
      return dequeueDog();
    }

    return {-1, -1};
  }

  vector<int> dequeueDog() {
    if (dog_q_.empty()) {
      return {-1, -1};
    }

    auto t = dog_q_.front();
    dog_q_.pop();
    return t;
  }

  vector<int> dequeueCat() {
    if (cat_q_.empty()) {
      return {-1, -1};
    }

    auto t = cat_q_.front();
    cat_q_.pop();
    return t;
  }
};
