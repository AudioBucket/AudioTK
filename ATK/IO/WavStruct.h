/**
 * \file WavStruct.h
 */
  
#ifndef ATK_IO_WAVSTRUCT_H
#define ATK_IO_WAVSTRUCT_H

#include <cstdint>

namespace ATK
{
  /// Standard Wav header block
  struct WavHeader
  {
    char FileTypeBlocID[4];
    std::int32_t FileSize;
    char FileFormatID[4];
  };
  
  /// Standard Wav format block
  struct WavFormat
  {
    char FormatBlocID[4];
    std::int32_t BlocSize;
    std::int16_t AudioFormat;
    std::int16_t NbChannels;
    std::int32_t Frequence;
    std::int32_t BytePerSec;
    std::int16_t BytePerBloc;
    std::int16_t BitsPerSample;
  };
  
  /// Standard Wav data block
  struct WavData
  {
    char DataBlocID[4];
    std::int32_t DataSize;
  };
  
  /// Empty traits
  template<typename DataType>
  struct WavTraits
  {
  };
  
  /// Traits for integer 16bits
  template<>
  struct WavTraits<std::int16_t>
  {
    static int get_wav_type()
    {
      return 1;
    }
  };
  
  /// Traits for float 32bits
  template<>
  struct WavTraits<float>
  {
    static int get_wav_type()
    {
      return 3;
    }
  };
  
  /// Traits for double 64bits
  template<>
  struct WavTraits<double>
  {
    static int get_wav_type()
    {
      return 3;
    }
  };
}

#endif
