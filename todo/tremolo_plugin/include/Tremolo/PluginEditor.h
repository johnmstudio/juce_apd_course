#pragma once

namespace tremolo {
class PluginEditor : public juce::AudioProcessorEditor {
public:
  explicit PluginEditor(PluginProcessor&);

  void resized() override;


private:

  Tremolo sigmaTremolo;
  
  juce::ImageComponent background;
  juce::ImageComponent logo;

  juce::Slider rateSlider;
  juce::Slider strokeWidthSlider;
  juce::SliderParameterAttachment rateAttachment;
  juce::Slider rateSlider2;
  juce::SliderParameterAttachment rateAttachment2;

  juce::Slider outputGainSlider;
  juce::SliderParameterAttachment outputGainAttachment;

  juce::Slider modDepthSlider;
  juce::SliderParameterAttachment modDepthAttachment;


  LfoVisualizer lfoVisualizer;
  float strokeWidth;
  juce::Path sineWave;
  

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginEditor)
};
}  // namespace tremolo
