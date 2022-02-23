/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class Test_JUCE_01AudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    Test_JUCE_01AudioProcessorEditor (Test_JUCE_01AudioProcessor&);
    ~Test_JUCE_01AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Test_JUCE_01AudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Test_JUCE_01AudioProcessorEditor)
};