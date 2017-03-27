/**
 * \file PanFilter.cpp
 */

#include "PanFilter.h"

#include <cmath>
#include <cstdint>

#include <boost/math/constants/constants.hpp>

namespace ATK
{
  template<typename DataType_>
  PanFilter<DataType_>::PanFilter()
  :Parent(1, 2), law(PAN_LAWS::SINCOS_0_CENTER), pan(0)
  {
    
  }
  
  template<typename DataType_>
  PanFilter<DataType_>::~PanFilter()
  {
    
  }
  
  template<typename DataType_>
  void PanFilter<DataType_>::set_pan_law(PAN_LAWS law)
  {
    this->law = law;
  }
  
  template<typename DataType_>
  typename PanFilter<DataType_>::PAN_LAWS PanFilter<DataType_>::get_pan_law() const
  {
    return law;
  }
  
  template<typename DataType_>
  void PanFilter<DataType_>::set_pan(double pan)
  {
    if(pan < -1 || pan > 1)
    {
      throw std::out_of_range("Pan must be a value between -1 and 1");
    }
    this->pan = pan;
  }

  template<typename DataType_>
  double PanFilter<DataType_>::get_pan() const
  {
    return pan;
  }

  template<typename DataType_>
  void PanFilter<DataType_>::process_impl(std::size_t size) const
  {
    double left_coeff = 1;
    double right_coeff = 1;
    
    switch(law)
    {
    case PAN_LAWS::SINCOS_0_CENTER:
        left_coeff = std::sqrt(2) * std::cos((pan + 1) / 4 * boost::math::constants::pi<double>());
        right_coeff = std::sqrt(2) * std::sin((pan + 1) / 4 * boost::math::constants::pi<double>());
        break;
      case PAN_LAWS::SINCOS_3_CENTER:
        left_coeff = std::cos((pan + 1) / 4 * boost::math::constants::pi<double>());
        right_coeff = std::sin((pan + 1) / 4 * boost::math::constants::pi<double>());
        break;
      case PAN_LAWS::SQUARE_0_CENTER:
        left_coeff = std::sqrt(2) * std::sqrt((1 - pan) / 2);
        right_coeff = std::sqrt(2) * std::sqrt((1 + pan) / 2);
        break;
      case PAN_LAWS::SQUARE_3_CENTER:
        left_coeff = std::sqrt((1 - pan) / 2);
        right_coeff = std::sqrt((1 + pan) / 2);
        break;
      case PAN_LAWS::LINEAR_TAPER:
        left_coeff = (1 - pan) / 2;
        right_coeff = (1 + pan) / 2;
        break;
      case PAN_LAWS::BALANCE:
        left_coeff = pan < 0 ? 1 : 1 - pan;
        right_coeff = pan > 0 ? 1 : 1 + pan;
        break;
    }
    
    const DataType* ATK_RESTRICT input = converted_inputs[0];
    DataType* ATK_RESTRICT output0 = outputs[0];
    DataType* ATK_RESTRICT output1 = outputs[1];
    for(std::size_t i = 0; i < size; ++i)
    {
      *(output0++) = static_cast<DataType>(left_coeff * *input);
      *(output1++) = static_cast<DataType>(right_coeff * *(input++));
    }
    
  }
  
  template class PanFilter<std::int16_t>;
  template class PanFilter<std::int32_t>;
  template class PanFilter<int64_t>;
  template class PanFilter<float>;
  template class PanFilter<double>;
}
