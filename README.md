<p align="center"><br><img src="https://avatars.githubusercontent.com/u/76786120?v=4" width="128" height="128" style="border-radius: 50px;" /></p>
<h3 align="center">ssibrahimbas cpp-testing</h3>
<p align="center">
  A game of chance and a test of it with google test framework
</p>

### What Is?

In this project, I made a game of chance. Users have balances, lucky numbers and balance rates to deposit per round. The game engine generates a random number between 1-10, the money of the users whose lucky numbers match this random number increases, while the money of other users decreases. The user whose money falls below 1000 will be eliminated. The application continues until 1 user remains.

Apart from the game, there are 40+ unit and integration tests with google test framework. The main purpose of the project is to use google testing framework and write tests.

### Installation and Running

This application was developed in the CLion IDE using CMake. However, you can also run it in Visual Studio and Visual Studio Code by following the documents below.

> For Visual Studio Code you can follow this doc: https://code.visualstudio.com/docs/cpp/cmake-linux

> And for Visual Studio you can follow this doc: https://docs.microsoft.com/tr-tr/cpp/build/cmake-projects-in-visual-studio?view=msvc-170

When you have successfully installed CMake and build tools, it will ask you whether you want to run it from the src or tst folders. The src folder contains the game itself. The tst folder contains tests. You can whatever you want!