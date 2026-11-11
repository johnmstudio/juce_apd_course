namespace tremolo {

namespace {
    void drawButtonInset(juce::Graphics& g,
    const juce::Rectangle<float> bounds) {
        auto insetGradient = juce::ColourGradient::vertical(juce::Colour{0xFF22232C},
    juce::Colour(0xFF303538), bounds);
    insetGradient.addColour(0.73, juce::Colour(0xFF263235));
    g.setGradientFill(insetGradient);
    g.fillRoundedRectangle(bounds.toFloat(), 4.f);
    }

    void drawBlueGradientButton(juce::Graphics& g, const juce::Rectangle<float> bounds) {
    auto buttonGradient = juce::ColourGradient::vertical(juce::Colour{0xFF4A7090},
        juce::Colour(0xFF324358), bounds);
        buttonGradient.addColour(0.73, juce::Colour(0xFF315160));
        g.setGradientFill(buttonGradient);
        g.fillRoundedRectangle(bounds.toFloat(), 4.f);
    }
} // namespace

juce::Colour CustomLookAndFeel::getColor(Colors colorName) {
    static const std::array colors {
        juce::Colour{0xFFDDECFF}
    };
    return colors.at(juce::toUnderlyingType(colorName));
}

    CustomLookAndFeel::CustomLookAndFeel() {
        setColour(juce::PopupMenu::backgroundColourId, juce::Colour{0xFF153245});
        setColour(juce::PopupMenu::textColourId, getColor(Colors::paleBlue));
        setColour(juce::ComboBox::textColourId, getColor(Colors::paleBlue));
        setColour(juce::Label::textColourId, juce::Colour{0xFF6EABC7});
        setColour(juce::PopupMenu::highlightedBackgroundColourId, juce::Colour{0xFF6EABC7});
    }
void CustomLookAndFeel::drawToggleButton(juce::Graphics& g,
                                        juce::ToggleButton& button,
                                        bool shouldDrawButtonAsHightlighted,
                                        bool shouldDrawButtonAsDown) {
    auto bounds = button.getLocalBounds().toFloat();
    
    drawButtonInset(g, bounds);

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
        g.setColour(getColor(Colors::paleBlue));
        } else {
        drawBlueGradientButton(g, bounds);
        g.setColour(getColor(Colors::paleBlue));
        }   
    }
    g.setFont(atmaRegular().withPointHeight(12.f));
    g.drawText(button.getButtonText(), bounds, juce::Justification::centred, false);
        
}

    void CustomLookAndFeel::drawComboBox(juce::Graphics& g, int width, int height, bool isButtonDown,
        int buttonX, int buttonY, int buttonW, int buttonH,juce::ComboBox& box) {

    auto bounds = box.getLocalBounds().toFloat();
    
    drawButtonInset(g, bounds);

    const auto buttonBounds = bounds.reduced(2);

    drawBlueGradientButton(g, buttonBounds);

    auto arrowBounds = buttonBounds.reduced(2,3);
    arrowBounds.removeFromLeft(98);
    arrowBounds.removeFromRight(4);

    juce::Path arrow;
    arrow.startNewSubPath(arrowBounds.getTopLeft());
    arrow.lineTo(arrowBounds.getTopRight());
    arrow.lineTo(arrowBounds.getCentreX(), arrowBounds.getBottom());
    arrow.closeSubPath();


    g.setColour(getColor(Colors::paleBlue));
    g.fillPath(arrow);
   
}

void CustomLookAndFeel::positionComboBoxText(juce::ComboBox& box, juce::Label& labelToPosition) {
    auto bounds = box.getLocalBounds().reduced(10,6);
    bounds.removeFromRight(12);
    labelToPosition.setBounds(bounds);
    labelToPosition.setJustificationType(juce::Justification::centred);
    labelToPosition.setFont (getComboBoxFont (box));
}

juce::PopupMenu::Options CustomLookAndFeel::getOptionsForComboBoxPopupMenu(juce::ComboBox& box, juce::Label& label) {
    return LookAndFeel_V4::getOptionsForComboBoxPopupMenu(box,label)
    .withStandardItemHeight(24)
    .withMinimumWidth(120);
}

    juce::FontOptions CustomLookAndFeel::atmaRegular() {
        static const auto result = juce::Typeface::createSystemTypefaceFor(assets::AtmaRegular_ttf, 
        assets::AtmaRegular_ttfSize);

        return juce::FontOptions(result);
    }


}  // namespace tremolo
