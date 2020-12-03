#pragma once

#include <cstddef>
#include <string>
#include <vector>
#include "core/spotify-model/audio_analysis.h"
#include "core/spotify-model/audio_segment.h"
#include "visualizer/sound_color_utils.h"
#include "cinder/gl/gl.h"

namespace musicvisualizer {

namespace visualizer {

using std::string;
using std::vector;
using musicvisualizer::spotifyhandler::AudioAnalysis;
using musicvisualizer::spotifyhandler::Segment;

using namespace soundcolorutil; //using all functions of this namespace

/**
 * Represents the display of music visualization for a Spotify song in Cinder.
 */
class SongVisualizationDisplayer {
  public:
    /**
     * Default constructor for a music visualization displayer.
     */
    SongVisualizationDisplayer() = default;

    /**
     * Constructor for a visualization of a Spotify song, given details for its
     * display in Cinder.
     *
     * @param x_pos   horizontal position for display of visualization.
     * @param y_pos   lower bound for y position of visualization.
     * @param amplification multiplier to amplifying visualizations based on music.
     * @param bar_width pixel width of bars for bar visualizer
     */
    SongVisualizationDisplayer(size_t x_pos, size_t y_pos, size_t amplification,
                               size_t bar_width);

    /**
     * Sets the audio analysis and time details for the visualization of a track.
     *
     * @param timestamp time in seconds progress into the current track.
     * @param analysis  audio analysis used for visualization.
     */
    void SetVisualizationInformation(double timestamp, const AudioAnalysis& analysis);

    /**
     * Sets the current timestamp for the visualization.
     *
     * @param timestamp the time to set.
     */
    void SetTime(double timestamp);

    /**
     * Draws the correct music visualizer display on Cinder.
     */
    void Draw() const;

    /**
     * Switches to the next visualization type for display.
     */
    void SwitchVisualizer();

  private:
    //=====================
    //Member Variables
    //=====================
    size_t visualizer_count_; //number of vis types currently supported.
    size_t current_visualizer_index_; //0-indexed identification of current vis type.

    AudioAnalysis audio_analysis_;
    double timestamp_;

    //display coordinates and positioning details
    size_t x_position_;
    size_t y_position_;
    size_t amplification_factor_;

    size_t bar_visualizer_width_;

    //12 notes' corresponding colors in order: C, C#, D, D#, . . . , B.
    vector<ci::Color> musical_pitch_colors_;

    //=====================
    //Helper Methods
    //=====================
    /**
     * Retrieves corresponding colors for each standard musical note (12 chromatic
     * scale notes).
     * Exact 12 pitches used: F#4, G4, G#4, A4, A#4, B4, C5, C#5, D5, D#5, E5, F5.
     */
    void FetchPitchColors();

    /**
     * Calculate the corresponding color for a note that is a given number of
     * musical half-steps away from the standard fixed note A4.
     *
     * @param half_steps number of half steps away from A4.
     *
     * @return the corresponding color for a given note.
     */
    ci::Color CalculateColorOfNote(int half_steps) const;

    /**
     * Draws the display on Cinder for the bar graph visualizer of a song.
     */
    void DrawBarVisualizer() const;

    /**
     * Draws the display on cinder for the 3D polygon visualizer of a song.
     */
    void DrawPolygonVisualizer() const;
};

} // namespace visualizer

} // namespace musicvisualizer