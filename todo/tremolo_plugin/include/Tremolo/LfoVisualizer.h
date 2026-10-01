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
            /*
            juce::Path sine;

            const auto strokeWidth = 6.f;
            const auto halfHeight = getHeight() / 2;
            const auto amplitude = halfHeight - strokeWidth/2.f;
            const auto startingP = 0 - strokeWidth;

            sine.startNewSubPath(startingP, halfHeight + amplitude * std::sin(startingP));

            for (const auto x : std::views::iota(0,getWidth() + strokeWidth)) {
                sine.lineTo(x, halfHeight + amplitude * std::sin(0.1 * x));
            }*/            
            g.setColour(juce::Colours::orange);
            g.strokePath(sineWave, juce::PathStrokeType(strokeWidth));
    
        }
    };
}