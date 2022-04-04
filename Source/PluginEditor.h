/*
  This code accompanies the textbook:
 
  Digital Audio Effects: Theory, Implementation and Application
  Joshua D. Reiss and Andrew P. McPherson
 
  ---
 
  Robotisation: robot effect using phase vocoder
  See textbook Chapter 8: The Phase Vocoder
 
  Code by Andrew McPherson, Brecht De Man and Joshua Reiss
 
  ---

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
 
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#ifndef __PLUGINEDITOR_H_6E48F605__
#define __PLUGINEDITOR_H_6E48F605__

#include <JuceHeader.h>
#include "PluginProcessor.h"


//==============================================================================

class RobotisationAudioProcessorEditor  : public juce::AudioProcessorEditor,
public juce::Slider::Listener,
public juce::ComboBox::Listener,
public juce::Button::Listener,
public juce::Timer
{
public:
    RobotisationAudioProcessorEditor (RobotisationAudioProcessor& ownerFilter);
    ~RobotisationAudioProcessorEditor() override;

    //==============================================================================
    // This is just a standard Juce paint method...
    void timerCallback() override;
    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider*) override;
    void comboBoxChanged (ComboBox *) override;
	void buttonClicked(Button *) override;
    
private:
    RobotisationAudioProcessor& audioProcessor;
    
    Label fftSizeLabel_, hopSizeLabel_, windowTypeLabel_;
    ComboBox fftSizeComboBox_, windowTypeComboBox_;
    Slider hopSizeSlider_;

	Label studentName_;
	TextButton fftFilterTextButton_;
    
    ComponentBoundsConstrainer resizeLimits_;
    std::unique_ptr<ResizableCornerComponent> resizer_;
    
    RobotisationAudioProcessor* getProcessor() const
    {
        return static_cast <RobotisationAudioProcessor*> (getAudioProcessor());
    }
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RobotisationAudioProcessorEditor)
};


#endif  // __PLUGINEDITOR_H_6E48F605__
