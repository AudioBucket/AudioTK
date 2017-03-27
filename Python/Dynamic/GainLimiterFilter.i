
%{
#include <ATK/Dynamic/GainLimiterFilter.h>
%}

namespace ATK
{
  template<class DataType>
  class GainLimiterFilter: public BaseFilter
  {
  public:
    GainLimiterFilter(int nb_channels = 1);
    ~GainLimiterFilter();

    void set_threshold(DataType threshold);
    void set_threshold_db(DataType threshold);
    DataType get_threshold() const;
    void set_softness(DataType softness);
    DataType get_softness() const;
  };
}

%template() ATK::GainLimiterFilter<float>;
%template() ATK::GainLimiterFilter<double>;
%template(FloatGainLimiterFilter) ATK::GainFilter<ATK::GainLimiterFilter<float>>;
%template(DoubleGainLimiterFilter) ATK::GainFilter<ATK::GainLimiterFilter<double>>;
