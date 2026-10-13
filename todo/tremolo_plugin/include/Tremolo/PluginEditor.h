#pragma once

namespace tremolo {
class PluginEditor : public juce::AudioProcessorEditor {
public:
  explicit PluginEditor(PluginProcessor&);
  ~PluginEditor() override;

  void resized() override;


private:

  Tremolo sigmaTremolo;
  
  juce::ImageComponent background;
  juce::ImageComponent logo;

  // RateSlider rateSlider;
  juce::Slider rateSlider;
  juce::Slider strokeWidthSlider;
  juce::SliderParameterAttachment rateAttachment;
  RateSlider rateSlider2;
  juce::SliderParameterAttachment rateAttachment2;

  RateSlider outputGainSlider;
  juce::SliderParameterAttachment outputGainAttachment;

  RateSlider modDepthSlider;
  juce::SliderParameterAttachment modDepthAttachment;


  juce::ToggleButton bypassButton{"BYPASSED"};
  juce::ButtonParameterAttachment bypassAttachment;

  LfoVisualizer lfoVisualizer;
  float strokeWidth;
  juce::Path sineWave;

  // juce::LookAndFeel_V2 lookAndFeel;
  CustomLookAndFeel lookAndFeel;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginEditor)
};
}  // namespace tremolo
