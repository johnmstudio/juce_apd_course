#pragma once

namespace tremolo {
struct Parameters {
  explicit Parameters(juce::AudioProcessor&);

  juce::AudioParameterFloat& rate;
  juce::AudioParameterFloat& outputgain;
  juce::AudioParameterBool& bypassed;
  juce::AudioParameterChoice& waveform;
  juce::AudioParameterFloat& moddepth;

  JUCE_DECLARE_NON_COPYABLE(Parameters);
  JUCE_DECLARE_NON_MOVEABLE(Parameters);

};
}  // namespace tremolo
