/**
 * \file DelayInterface.h
 */

#ifndef ATK_DELAY_DELAYINTERFACE_H
#define ATK_DELAY_DELAYINTERFACE_H

#include <map>

#include <ATK/Delay/config.h>

namespace ATK
{
  /// Interface for a fixed filter
  class ATK_DELAY_EXPORT DelayInterface
  {
  public:
    virtual ~DelayInterface();
    /// Sets the delay of the filter
  virtual void set_delay(std::size_t delay) = 0;
    /// Returns the delay
    virtual std::size_t get_delay() const = 0;
  };

  /// Interface for a universal filter
  template<class DataType>
  class ATK_DELAY_EXPORT UniversalDelayInterface
  {
  public:
    virtual ~UniversalDelayInterface();
    
    /// Sets the blend of the filter
    virtual void set_blend(DataType blend) = 0;
    /// Returns the blend
    virtual DataType get_blend() const = 0;
    /// Sets the feedback of the filter
    virtual void set_feedback(DataType feedback) = 0;
    /// Returns the feedback
    virtual DataType get_feedback() const = 0;
    /// Sets the feedforward of the filter
    virtual void set_feedforward(DataType feedforward) = 0;
    /// Returns the feedforward
    virtual DataType get_feedforward() const = 0;
  };
}

#endif
