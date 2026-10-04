namespace tremolo {
PluginEditor::PluginEditor(PluginProcessor& p) : AudioProcessorEditor(&p) ,
rateAttachment{p.getParameterRefs().rate, rateSlider} , 
rateAttachment2{p.getParameterRefs().rate, rateSlider2} ,
outputGainAttachment{p.getParameterRefs().outputgain, outputGainSlider} , 
modDepthAttachment{p.getParameterRefs().moddepth, modDepthSlider} {
  background.setImage(juce::ImageCache::getFromMemory(
      assets::Background_png, assets::Background_pngSize));

  logo.setImage(
      juce::ImageCache::getFromMemory(assets::Logo_png, assets::Logo_pngSize));
  addAndMakeVisible(background);
  addAndMakeVisible(logo);
  rateSlider.setSliderStyle(juce::Slider::SliderStyle::Rotary);
  rateSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
  rateSlider.setPopupDisplayEnabled(true,true,this);
  rateSlider.setTextValueSuffix(" Hz");
  addAndMakeVisible(rateSlider);

  strokeWidthSlider.setRange(0,10,1);
  strokeWidthSlider.setValue(6.0, juce::dontSendNotification);
  strokeWidthSlider.onValueChange = [this] {
    lfoVisualizer.setStrokeWidth(strokeWidthSlider.getValue());
  };
  addAndMakeVisible(strokeWidthSlider);

  outputGainSlider.setSliderStyle(juce::Slider::SliderStyle::Rotary);
  outputGainSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
  outputGainSlider.setPopupDisplayEnabled(true,true,this);
  outputGainSlider.setTextValueSuffix("db");
  addAndMakeVisible(outputGainSlider);
  
  modDepthSlider.setSliderStyle(juce::Slider::SliderStyle::Rotary);
  modDepthSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
  modDepthSlider.setPopupDisplayEnabled(true,true,this);
  modDepthSlider.setTextValueSuffix("db");
  addAndMakeVisible(modDepthSlider);

  rateSlider2.setSliderStyle(juce::Slider::SliderStyle::Rotary);
  rateSlider2.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
  rateSlider2.setPopupDisplayEnabled(true,true,this);
  rateSlider2.setTextValueSuffix(" Hz");
  addAndMakeVisible(rateSlider2);

  addAndMakeVisible(lfoVisualizer);
  

  // Make sure that before the constructor has finished, you've set the
  // editor's size to whatever you need it to be.
  setSize(540, 300);
}

void PluginEditor::resized() {
  auto bounds = getLocalBounds();
  DBG("x: " << bounds.getX() << ", y: " << bounds.getY() << ", width: " << bounds.getWidth() << ", height: " << bounds.getHeight());
  bounds.removeFromBottom(30);
  background.setBounds(bounds);
  
  auto foot = getLocalBounds();
  foot.removeFromTop(270);

  auto strokeWidthSliderBounds = foot;
  strokeWidthSliderBounds.removeFromRight(270);
  strokeWidthSlider.setBounds(strokeWidthSliderBounds);

  logo.setBounds({16, 16, 105, 24});
  
  auto rateSliderBounds = bounds;
  rateSliderBounds.removeFromLeft(230);
  rateSliderBounds.removeFromRight(230);
  rateSliderBounds.removeFromTop(40);
  rateSliderBounds.removeFromBottom(150);
  rateSlider.setBounds(rateSliderBounds);

  auto rateSlider2Bounds = bounds;
  rateSlider2Bounds.removeFromLeft(310);
  rateSlider2Bounds.removeFromRight(160);
  rateSlider2Bounds.removeFromTop(50);
  rateSlider2Bounds.removeFromBottom(160);
  rateSlider2.setBounds(rateSlider2Bounds);


  auto outputGainBounds = bounds;
  outputGainBounds.removeFromLeft(80);
  outputGainBounds.removeFromRight(380);
  outputGainBounds.removeFromTop(45);
  outputGainBounds.removeFromBottom(155);
  outputGainSlider.setBounds(outputGainBounds);

  auto modDepthBounds = bounds;
  modDepthBounds.removeFromLeft(410);
  modDepthBounds.removeFromRight(50);
  modDepthBounds.removeFromTop(45);
  modDepthBounds.removeFromBottom(155);
  modDepthSlider.setBounds(modDepthBounds);


  lfoVisualizer.setBounds(18, 149, 504, 92);

  // -- Tremolo LFO variável
  int Current_lfo = static_cast<int>(sigmaTremolo.getlfo());
  std::cout << "Current LFO: " << static_cast<int>(sigmaTremolo.getlfo());

  const auto lfov_halfHeight = lfoVisualizer.getHeight() / 2;
  const auto lfov_amplitude = lfov_halfHeight - 10/2.f;
  const auto lfov_startingP = 0 - lfoVisualizer.strokeWidth;
  // Change lfov_startingP "0" to phase.

  // Dois if. Mudar quando preciso.
  if (Current_lfo == 0){
  lfoVisualizer.sineWave.clear();
  lfoVisualizer.sineWave.startNewSubPath(lfov_startingP, lfov_halfHeight + lfov_amplitude * sin(lfov_startingP));
  for (const auto x : std::views::iota(0, static_cast<int>(lfoVisualizer.getWidth() + lfoVisualizer.strokeWidth))) {
      lfoVisualizer.sineWave.lineTo(x, lfov_halfHeight + lfov_amplitude * sin(0.1 * x));
  }
  } else {
  lfoVisualizer.sineWave.clear();
  lfoVisualizer.sineWave.startNewSubPath(lfov_startingP, lfov_halfHeight + lfov_amplitude * sigmaTremolo.triangle(lfov_startingP));
  for (const auto x : std::views::iota(0, static_cast<int>(lfoVisualizer.getWidth() + lfoVisualizer.strokeWidth))) {
      lfoVisualizer.sineWave.lineTo(x, lfov_halfHeight + lfov_amplitude * sigmaTremolo.triangle(0.1 * x));
  }
}
}
}  // namespace tremolo
