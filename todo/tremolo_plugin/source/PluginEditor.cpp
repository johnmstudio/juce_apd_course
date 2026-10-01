namespace tremolo {
PluginEditor::PluginEditor(PluginProcessor& p) : AudioProcessorEditor(&p) {
  background.setImage(juce::ImageCache::getFromMemory(
      assets::Background_png, assets::Background_pngSize));

  logo.setImage(
      juce::ImageCache::getFromMemory(assets::Logo_png, assets::Logo_pngSize));
  addAndMakeVisible(background);
  addAndMakeVisible(logo);
  addAndMakeVisible(lfoVisualizer);

  // Make sure that before the constructor has finished, you've set the
  // editor's size to whatever you need it to be.
  setSize(540, 270);
}

//

void PluginEditor::resized() {
  const auto bounds = getLocalBounds();
  DBG("x: " << bounds.getX() << ", y: " << bounds.getY() << ", width: " << bounds.getWidth() << ", height: " << bounds.getHeight());
  background.setBounds(bounds);

  logo.setBounds({16, 16, 105, 24});
  lfoVisualizer.setBounds(18, 149, 504, 92);

  // -- Tremolo LFO variável
  int Current_lfo = static_cast<int>(sigmaTremolo.getlfo());
  std::cout << "Current LFO: " << static_cast<int>(sigmaTremolo.getlfo());

  lfoVisualizer.strokeWidth = 6.f;
  const auto lfov_halfHeight = lfoVisualizer.getHeight() / 2;
  const auto lfov_amplitude = lfov_halfHeight - lfoVisualizer.strokeWidth/2.f;
  const auto lfov_startingP = 0 - lfoVisualizer.strokeWidth;

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
