# hello-lumina
first version of the test app.
this is master branch


Thinking process:
Divide this project into 2 parts:
1. algorithm part with opencv implementation.
2. UI interface part with imgui.

OPENCV part include
1. Use VideoCapture to get camera stream.
2. Show in Opencv windows.
3. Process the frame and plot the results.

IMGUI part include
1. Design the window layout.
2. Implement the botton/menu functions.

Then intigrate the 2 part into the same application.

Critical Issues met in this challenge:
1. A lot of software packages: I start with a clean SDK. So it spend much time to download, install, and environment setting.
2. Opencv VideoCapture cannot work with my built-in webcam. So I cannot test my implementation.
3. I am empty for IMGUI so it cost much time when studying.

Detailed Description about the code.
I start with the opencv compilation. I downloaded CMAKE and build the opencv library first. Then Use the built lib in the following code:
https://github.com/hcman2/hello-lumina/blob/master/opencv/myApp.cpp
And I use a simple jpg image as an example to calculate the histogram. If the histogram works, other algorithm(vectorscope, etc...) should be the same story.
Then I try to use VideoCapture to get camera input however it can not work well. I spend too much time in solving this issue.
For IMGUI part, I would like to import the imgui code into opencv project. However it cannot work without other multimedia API. So I have to change my main project into the other folder.
https://github.com/hcman2/hello-lumina/tree/master/imgui
This is an example from imgui release. It works with DirectX12 so I can easily to design my window. 
Now I spent most of 4 hours.....

Future work
1. Connect camera with imgui project and show the content.
2. import OPENCV implementation into this project.
3. check the algorithm result and show it in the window.
4. Build a test system and golden test cases to verify the implementation.

