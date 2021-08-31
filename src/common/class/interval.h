/**
 * @file interval.h
 * @author _ChingC (chingc.ccmail@gmail.com)
 * @brief 区间类
 * @version 0.1
 * @date 2021-08-30
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PTP__INTERVAL_H
#define PTP__INTERVAL_H

#include <fmt/core.h>

#include <algorithm>
#include <mutex>
#include <utility>

#define EMPTY_SET_STRING "⌀"

namespace ptp {
namespace common {

using Lock = std::lock_guard<std::mutex>;

enum NodeType { UNKNOWN = -1, OPEN = 0, CLOSE = 1 };

template <class T>
class Interval {
 public:
  struct Node {
    T value{};
    NodeType type{UNKNOWN};
    Node() = default;
     Node(const T& value, NodeType type) : value(value), type(type) {}
  };

 private:
  Node start_{};
  Node end_{};
  std::mutex mutex_;

 public:
  Node start() {
    Lock lock(mutex_);
    return start_;
  }

  void start(const Node& element) {
    Lock lock(mutex_);
    start_ = element;
  }

  Node end() {
    Lock lock(mutex_);
    return end_;
  }

  void end(const Node& element) {
    Lock lock(mutex_);
    end_ = element;
  }

 public:
  Interval() = default;
  Interval(const Node& start, const Node& end) : start_(start), end_(end) {
    Lock lock(mutex_);
    if (start_.type == UNKNOWN || end_.type == UNKNOWN) {
      return;
    }
    if (end_.value < start_.value) {
      std::swap(start_, end_);
    }
  }
  Interval(Interval&& another) {
    Lock lock(mutex_);
    start_ = another.start_;
    end_ = another.end_;
  }
  Interval(const Interval& another) {
    Lock lock(mutex_);
    start_ = another.start_;
    end_ = another.end_;
  }
  Interval operator=(Interval&& another) {
    Lock lock(mutex_);
    return Interval(another);
  }
  Interval operator=(const Interval& another) {
    Lock lock(mutex_);
    return Interval(another);
  }
  ~Interval() = default;

 public:
  T Length() {
    Lock lock(mutex_);
    if (!*this) {
      return T();
    }
    return end_.value - start_.value;
  }

  bool IsBelongsTo(const T& element) {
    Lock lock(mutex_);
    if (!*this) {
      return false;
    }

    if (element < end_.value && element > start_.value) {
      return true;
    }

    if (start_.value == element && start_.type == CLOSE) {
      return true;
    }

    if (end_.value == element && end_.type == CLOSE) {
      return true;
    }
    return false;
  }

  Interval Intersection(Interval& another) {
    if (!*this || !another) {
      return Interval();
    }
    Lock lock_this(mutex_);
    Lock lock_another(another.mutex_);

    const Node start_node = this->start_.value > another.start_.value
                                ? this->start_
                                : another.start_;

    const Node end_node =
        this->end_.value < another.end_.value ? this->end_ : another.end_;

    Interval result;
    if (start_node.value < end_node.value ||
        (start_node.value == end_node.value && start_node.type == CLOSE &&
         end_node.type == CLOSE)) {
      result.start_ = start_node;
      result.end_ = end_node;
    }

    return result;
  }

  std::string ToString() {
    Lock lock_this(mutex_);
    if (!*this) {
      return EMPTY_SET_STRING;
    }
    char start_symbol = start_.type == OPEN ? '(' : '[';
    char end_symbol = end_.type == OPEN ? ')' : ']';
    return fmt::format("{}{}, {}{}", start_symbol, start_.value, end_.value,
                       end_symbol);
  }

  operator bool() const {
    if (start_.type == UNKNOWN && end_.type == UNKNOWN) {
      return false;
    }
    return true;
  }
};
}  // namespace common
}  // namespace ptp

#endif