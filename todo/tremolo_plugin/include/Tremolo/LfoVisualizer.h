namespace tremolo {
    class LfoVisualizer : public juce::Component {
public:
        juce::Path sineWave;
        float strokeWidth = 6.f;

        void setStrokeWidth(float sigma) {
            strokeWidth = sigma;
            repaint();
        }

        void paint (juce::Graphics& g) override {           
            g.setColour(juce::Colours::orange);
            g.strokePath(sineWave, juce::PathStrokeType(strokeWidth));
    
        }
    };
}