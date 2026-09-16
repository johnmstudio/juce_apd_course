
namespace tremolo {
namespace{
  auto& addParameterToProcessor(juce::AudioProcessor& processor, auto parameter) {
    auto& parameterReference = *parameter;
    processor.addParameter(parameter.release());
    return parameterReference;
  }

  juce::AudioParameterFloat& createModulationRateParameter(juce::AudioProcessor& processor) {
    constexpr auto versionHint = 1;
    auto parameter = std::make_unique<juce::AudioParameterFloat>(
      juce::ParameterID{"modulation.rate", versionHint},
      "Modulation rate",
      juce::NormalisableRange{0.1f,20.f, 0.01f, 0.4f}, 5.f, 
      juce::AudioParameterFloatAttributes{}.withLabel("Hz"));
      return addParameterToProcessor(processor, std::move(parameter));
  }
  juce::AudioParameterFloat& createOutputGainParameter(juce::AudioProcessor& processor) {
    constexpr auto versionHint = 1;
    auto parameter = std::make_unique<juce::AudioParameterFloat>(
      juce::ParameterID{"output.gain", versionHint},
      "Output Gain",
      juce::NormalisableRange{0.f,6.f,0.01f}, 0.5f,
      juce::AudioParameterFloatAttributes{}.withLabel("dB"));
      return addParameterToProcessor(processor, std::move(parameter));
  }
  juce::AudioParameterBool& createBypassedParameter(juce::AudioProcessor& processor) {
    constexpr auto versionHint = 1;
    auto parameter = std::make_unique<juce::AudioParameterBool>(
      juce::ParameterID{"bypassed", versionHint},
      "Bypass", 
      false);
      return addParameterToProcessor(processor, std::move(parameter));
  }
  juce::AudioParameterChoice& createWaveformParameter(juce::AudioProcessor& processor) {
    constexpr auto versionHint = 1;
    auto parameter = std::make_unique<juce::AudioParameterChoice>(
      juce::ParameterID("modulation.waveform", versionHint),
      "Modulation Waveform",
      juce::StringArray("Sine", "Triangle"),
      0);
    return addParameterToProcessor(processor, std::move(parameter));
  }
}
Parameters::Parameters(juce::AudioProcessor& processor)
  : rate{createModulationRateParameter(processor)},
    outputgain{createOutputGainParameter(processor)},
    bypassed{createBypassedParameter(processor)},
    waveform{createWaveformParameter(processor)}
{
}
}  // namespace tremolo
