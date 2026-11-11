#pragma once

namespace tremolo {
    class RateSlider : public juce::Slider {
public:
        void paint (juce::Graphics& g) override {
    // auto outline = findColour (Slider::rotarySliderOutlineColourId);

    auto sliderPos = (float) valueToProportionOfLength (getValue());
                jassert (sliderPos >= 0 && sliderPos <= 1.0f);

    const auto rotaryParams = getRotaryParameters();
    const auto rotaryStartAngle = rotaryParams.startAngleRadians;
    const auto rotaryEndAngle = rotaryParams.endAngleRadians;

    // auto fill    = findColour (Slider::rotarySliderFillColourId);

    // auto bounds = getLocalBounds().toFloat().reduced (10);

    // auto radius = juce::jmin (bounds.getWidth(), bounds.getHeight()) / 2.0f;
    auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    // auto lineW = juce::jmin (8.0f, radius * 0.5f);
    // auto arcRadius = radius - lineW * 0.5f;

   /* juce::Path backgroundArc;
    backgroundArc.addCentredArc (bounds.getCentreX(),
                                 bounds.getCentreY(),
                                 arcRadius,
                                 arcRadius,
                                 0.0f,
                                 rotaryStartAngle,
                                 rotaryEndAngle,
                                 true);

    g.setColour (outline);
    g.strokePath (backgroundArc, juce::PathStrokeType (lineW, juce::PathStrokeType::curved, juce::PathStrokeType::rounded));
            */
    if (isEnabled())
    {
        juce::Path centerPoint;
        auto centerPointBounds = getLocalBounds().toFloat();
        centerPoint.addEllipse(juce::Rectangle<float>(centerPointBounds.getWidth() / 12, centerPointBounds.getHeight() / 12)
                           .withCentre(centerPointBounds.getCentre()));
        g.setColour(juce::Colours::orange);
        g.fillPath(centerPoint);
        juce::Path valueArc;
        /*
        valueArc.addCentredArc (bounds.getCentreX(),
                                bounds.getCentreY(),
                                arcRadius,
                                arcRadius,
                                0.0f,
                                rotaryStartAngle,
                                toAngle,
                                true); */

        g.setColour (juce::Colours::orange);
        g.fillPath(valueArc); 

        juce::Path newArc;
        auto newArcBounds = getLocalBounds().toFloat().reduced(4.f / 2.f);
        newArc.addArc(newArcBounds.getX(),
                    newArcBounds.getY(),
                    newArcBounds.getWidth(),
                    newArcBounds.getHeight(),
                    rotaryStartAngle,
                    toAngle,
                    true
                    );
        g.setColour(juce::Colours::orange);
        g.strokePath(newArc, juce::PathStrokeType (4.f,juce::PathStrokeType::curved, juce::PathStrokeType::rounded));

        // g.strokePath (valueArc, juce::PathStrokeType (lineW, juce::PathStrokeType::curved, juce::PathStrokeType::rounded));
    }
    
    /* auto thumbWidth = lineW * 2.0f;
    juce::Point<float> thumbPoint (bounds.getCentreX() + arcRadius * std::cos (toAngle - juce::MathConstants<float>::halfPi),
                             bounds.getCentreY() + arcRadius * std::sin (toAngle - juce::MathConstants<float>::halfPi));

    g.setColour (findColour (Slider::thumbColourId));
    g.fillEllipse (juce::Rectangle<float> (thumbWidth, thumbWidth).withCentre (thumbPoint)); */
        }
    };
}