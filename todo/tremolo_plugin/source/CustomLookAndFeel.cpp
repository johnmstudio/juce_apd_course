namespace tremolo {
void CustomLookAndFeel::drawToggleButton(juce::Graphics& g,
                                        juce::ToggleButton& button,
                                        bool shouldDrawButtonAsHightlighted,
                                        bool shouldDrawButtonAsDown) {
    auto bounds = button.getLocalBounds();
    
    auto outlineGradient = juce::ColourGradient::vertical(juce::Colour{0xFF22232C},
    juce::Colour(0xFF303538), bounds);
    outlineGradient.addColour(0.73, juce::Colour(0xFF263235));
    g.setGradientFill(outlineGradient);
    // g.setColour(juce::Colours::black);
    g.fillRoundedRectangle(bounds.toFloat(), 4.f);

    bounds.removeFromLeft(2);
    bounds.removeFromRight(2);
    bounds.removeFromTop(2);
    bounds.removeFromBottom(2);

    if (button.getToggleState()) {
        if (button.isOver() == true) {
            auto buttonGradient = juce::ColourGradient::vertical(juce::Colour{0x70FF901A},
            juce::Colour(0x70FFC300), bounds);
            g.setGradientFill(buttonGradient);
            g.fillRoundedRectangle(bounds.toFloat(), 4.f);
            g.setColour(juce::Colour{0xFF501A0B});
        } else {
            auto buttonGradient = juce::ColourGradient::vertical(juce::Colour{0xFFFF901A},
            juce::Colour(0xFFFFC300), bounds);
            g.setGradientFill(buttonGradient);
            g.fillRoundedRectangle(bounds.toFloat(), 4.f);
            g.setColour(juce::Colour{0xFF501A0B});
        }
        
    }
    else {
        if (button.isOver() == true) {
            auto buttonGradient = juce::ColourGradient::vertical(juce::Colour{0x704A7090},
        juce::Colour(0x70324358), bounds);
        buttonGradient.addColour(0.73, juce::Colour(0x70315160));
        g.setGradientFill(buttonGradient);
        g.fillRoundedRectangle(bounds.toFloat(), 4.f);
        g.setColour(juce::Colour{0xFFDDECFF});
        } else {
        auto buttonGradient = juce::ColourGradient::vertical(juce::Colour{0xFF4A7090},
        juce::Colour(0xFF324358), bounds);
        buttonGradient.addColour(0.73, juce::Colour(0xFF315160));
        g.setGradientFill(buttonGradient);
        g.fillRoundedRectangle(bounds.toFloat(), 4.f);
        g.setColour(juce::Colour{0xFFDDECFF});
        }
        
    }
    
    g.drawText(button.getButtonText(), bounds, juce::Justification::centred, false);
    
}
}  // namespace tremolo
