/**
 * @file singleton.h
 * @author _ChingC (chingc.ccmail@gmail.com)
 * @brief 单例模式声明和实现
 * @version 0.1
 * @date 2021-08-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef PTP__SINGLETON_H
#define PTP__SINGLETON_H

#define PATTERN_SINGLETON_DECLARE(ClassName)        \
 private:                                           \
  ClassName();                                      \
  ClassName(const ClassName &) = delete;            \
  ClassName &operator=(const ClassName &) = delete; \
                                                    \
 public:                                            \
  static ClassName *Instance();                     \
  virtual ~ClassName();

#define PATTERN_SINGLETON_IMPLEMENT(ClassName) \
  ClassName *ClassName::Instance() {           \
    static ClassName _instance;                \
    return &_instance;                         \
  }

#endif