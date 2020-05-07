# Enhanced Tetris

Author: Nikil Ravi

# Overview of the project

This project is meant to be an enhanced version of the popular, yet simple, Tetris game. Tetris involves falling blocks that have to be placed in the optimal orientation possible. However, it has largely remained the same for decades. My goal is to implement some additional features and to try and make the game more appealing in some ways.

Here is a more concrete version of my goal with this project: the game will be somewhat like Tetris, but will have some modifications- for instance, instead of having the blocks just falling/moving downwards, the blocks will simply appear on the screen, and the user will be able to drag and place them in the main 'tetris area', like in the [Block Puzzle](https://play.google.com/store/apps/details?id=game.puzzle.blockpuzzle&hl=en_US) game on PlayStore. I think of it as more of a cross between jigsaw puzzles and Tetris. The functionality of Tetris, however, will remain in some ways.

Being a simple game, this project does not require much background knowledge per se; that being said, I have played the game a lot, and have some understanding of how I might structure the code. Apart from Cinder, I will use [OpenGL](https://www.opengl.org/) to make the game. My plan is to use it to help with the graphics and rendering the game i.e, to simply the implementation of some of the graphics. 

The following is a rough timeline for this project:
* Week 1: integrate Cinder and OpenGL into the project properly, and set up the game, with the code for the game window, blocks and different screens. At the very least, I'd have a 'code-outline' or a broad code structure that outlines how I will implement the game.
* Week 2: Finish implementing the overall logic for the game, i.e, the core game functionality should work, but need not be aesthetically appealing, and need not have all the features implemented. 
* Week 3: Add additional features, make the game more intuitive and visually appealing, add more screens to change some settings if possible/necessary.

If I manage to get all these tasks done early and have a fully working game along with a good GUI, I'd like to try to introduce more 'settings' into the game; ability to change amount of time the user gets to finish the game, a leaderboard or settings that enable the user to make the GUI different. If I finish very early, I might also add more levels to the game, where the blocks that appear are specifically shaped so as to make it more difficult or easier for the user to get a good score in the given time, depending on the level. This probably requires a fair amount of math/logic, but I'd still like to try this if I get done with the stated goals very early (something like 2 weeks; then I would spend a week implementing these levels).