namespace tremolo {
PluginEditor::PluginEditor(PluginProcessor& p) : AudioProcessorEditor(&p) {
  background.setImage(juce::ImageCache::getFromMemory(
      assets::Background_png, assets::Background_pngSize));

  logo.setImage(
      juce::ImageCache::getFromMemory(assets::Logo_png, assets::Logo_pngSize));
  addAndMakeVisible(background);
  addAndMakeVisible(logo);
  rateSlider.setSliderStyle(juce::Slider::SliderStyle::Rotary);
  rateSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
  rateSlider.setPopupDisplayEnabled(true,true,this);
  rateSlider.setRange(1,30,0.5);
  rateSlider.onValueChange = [this] {
    DBG("Rate slider value: " << rateSlider.getValue());
  };
  rateSlider.setTextValueSuffix(" Hz");
  addAndMakeVisible(rateSlider);

  strokeWidthSlider.setRange(0,10,1);
  strokeWidthSlider.setValue(6.0, juce::dontSendNotification);
  strokeWidthSlider.onValueChange = [this] {
    lfoVisualizer.setStrokeWidth(strokeWidthSlider.getValue());
  };
  addAndMakeVisible(strokeWidthSlider);

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
