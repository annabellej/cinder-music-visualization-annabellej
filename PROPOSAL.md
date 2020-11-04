<h3>Spotify Music Visualization</h3>
> CS 126 Final Project Proposal
---
Music visualization is a process that uses certain characteristics of music and 
audio to create either static or dynamic images. By using the unique combination 
of sound that exists in various songs, a huge variety of different visualizations
can be produced. 

Examples (this project will likely be much simpler):

[![](http://img.youtube.com/vi/cWoc4Dr_sd8/0.jpg)](http://www.youtube.com/watch?v=cWoc4Dr_sd8 "")

or

[![](http://img.youtube.com/vi/HBPVhjXgzOM/0.jpg)](http://www.youtube.com/watch?v=HBPVhjXgzOM "")

As a music lover, I think it would be exciting to be able to 
transform music into a visual as well as acoustic experience. Since there are 
an infinite number of ways to translate musical data into images, it will be 
interesting to see what visualizations I can ultimately create.

In addition, to make the music visualization more personal, users would use
their own music and playlists from Spotify to create images and patterns that 
are unique to their music tastes. For instance, a user who prefers more energetic 
or upbeat songs would see a very different visualization compared to someone
who prefers slower and softer songs. 

Ultimately, a user would be able to choose a playlist from Spotify and sequentially
play each song while seeing the visualization for the music as it plays.

In terms of the project's technical work, the tasks over three weeks will be
allocated as follows:

<h5>Week 1: Implement Spotify API</h5>
* acquire user data for songs/playlists and music data for different songs
* should be able to display information from API using Cinder (i.e. album art,
current song, etc.)
* display should have feature to login to Spotify on click to retrieve a user's
music
* option to use any non-user-specific songs/playlists from Spotify

<h5>Week 2: Implement math/calculations for visualization</h5>
* implement the math to create images using numbers from music data
* convert volume (waveform) data into numbers for dimensional details of display
(ex. size/length of certain shapes or patterns)
    * also related to beats in a song
* get frequency data (Fourier transform), convert to RGB color values for display 

<h5>Week 3: Implement visualization display</h5>
* use numbers calculated from Spotify music data to display music in a dynamic 
bar graph/sound wave/shape form.
* colors of display should also be taken from calculations
* display created should be dynamic: shapes should update as music plays
* implement display to play music synchronously with visualization

Apart from experiencing music in an entirely different way, there are variety
of applications for music visualization I could explore if the project is finished
earlier than expected. Examples could include music visualization related games 
such as 
[Osu!](https://en.wikipedia.org/wiki/Osu!) and 
[Beat Hazard](https://store.steampowered.com/app/618740/Beat_Hazard_2/)
(which would involve implementing more user feedback loops), or audio 
visualization as a therapeutic tool for the hearing impaired (which would involve
less emphasize on the beats/rhythm of an audio piece and more on frequencies
and other characteristics).