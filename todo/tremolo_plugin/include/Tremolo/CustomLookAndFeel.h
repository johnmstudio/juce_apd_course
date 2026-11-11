#pragma once

namespace tremolo {
class CustomLookAndFeel : public juce::LookAndFeel_V4 {
public:
    CustomLookAndFeel();

    enum class Colors : size_t { paleBlue };

    static juce::Colour getColor(Colors colorName);

    void drawToggleButton(juce::Graphics&, juce::ToggleButton&, bool shouldDrawButtonAsHighlighted,
    bool shouldDrawButtonAsDown) override;

    void drawComboBox(juce::Graphics&, int width, int height, bool isButtonDown,
        int buttonX, int buttonY, int buttonW, int buttonH,juce::ComboBox&) override;

    juce::Font getComboBoxFont(juce::ComboBox&) override {
        return atmaRegular().withPointHeight(12.f);
    }

    void positionComboBoxText(juce::ComboBox&, juce::Label& labelToPosition) override;

    juce::PopupMenu::Options getOptionsForComboBoxPopupMenu(juce::ComboBox&, juce::Label&) override;

    juce::Font getPopupMenuFont() override {
        return atmaRegular().withPointHeight(12.f);
    }

    juce::Path getTickShape(float height) override {
        return {};
    }

    static juce::FontOptions getSideLabelsFont() {
        return atmaRegular().withPointHeight(10.f);
    }

private:
    static juce::FontOptions atmaRegular();

};
}  // namespace tremolo
