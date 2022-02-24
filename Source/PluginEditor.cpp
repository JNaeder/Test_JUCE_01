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
//    Gain Slider
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    gainSlider.setRange(-60.0, 0.0, 0.01);
    gainSlider.setValue(-20.0);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);
    
//    Overdrive Slider
    overdriveSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    overdriveSlider.setRange(0.0, 4.0, 0.01);
    overdriveSlider.setValue(0.0);
    overdriveSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    addAndMakeVisible(overdriveSlider);
    overdriveSlider.addListener(this);
    
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
    gainSlider.setBounds(getWidth()-100, getHeight()/2 - 75, 100, 150);
    overdriveSlider.setBounds(0, getHeight()/2 -75, 100, 150);
}

void Test_JUCE_01AudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &gainSlider)
    {
        audioProcessor.gain = gainSlider.getValue();
    }
    if(slider == &overdriveSlider)
    {
        audioProcessor.overdrive = overdriveSlider.getValue();
    }
}
