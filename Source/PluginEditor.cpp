/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Test_JUCE_01AudioProcessorEditor::Test_JUCE_01AudioProcessorEditor (Test_JUCE_01AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    gainSlider.setRange(0.0, 1.0, 0.01);
    gainSlider.setValue(0.5);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    addAndMakeVisible(gainSlider);
    setSize (200, 300);
}

Test_JUCE_01AudioProcessorEditor::~Test_JUCE_01AudioProcessorEditor()
{
}

//==============================================================================
void Test_JUCE_01AudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
}

void Test_JUCE_01AudioProcessorEditor::resized()
{
    gainSlider.setBounds(getWidth()/2 - 50, getHeight()/2 - 75, 100, 150);
}
