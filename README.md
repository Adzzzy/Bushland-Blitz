# Bushland-Blitz
Object-Oriented Programming Project - A Short JRPG-Style Game

## Overview

The game takes place in the Australian Outback as the player faces a gauntlet of enemies with enemies becoming stronger each time one is defeated.
The enemies and player each have various attacks with different damages, effects, and accuracies.
The player also has attacks called spells that require spirit to cast.
Health comes back with each battle won, but spirit stays the same.

Additionally, the player picks up an item each time they defeat an enemy, with each of these items having various effects.
The effects of these items include: restoring health, restoring spirit, raising max health, raising max spirit, and curing status ailments.

If the player makes it far enough, they'll see new, fierce enemies, and beyond that, something even greater...

## Usage
### Running as a Docker container
The easiest way to run this project across a wide variety of different environments is to run it as a Docker container using the image I've created for it.

**Get Docker Desktop**
- Head to https://www.docker.com/products/docker-desktop/ and click on _Download Docker Desktop_, making sure to choose the right download for your device.
- Open Docker Desktop and make sure it's running. (The bottom left corner of the Docker Desktop window indicates the status of the Docker Engine).

**Run the image as a container**
- Open up any terminal or shell. On Windows, Mac, or Linux simply search "Terminal" and open it up. You could also search for "Command Prompt" or "PowerShell" instead on Windows.
- Paste the following into the terminal and press enter: `docker run -it ghcr.io/adzzzy/bushland-blitz`
    - Note: For a specific version of the image, just add `:<VERSION>` onto the end of the image name. </br> Available versions can be seen here: https://github.com/Adzzzy/Bushland-Blitz/pkgs/container/bushland-blitz
- After a few moments for downloading dependencies and the set-up needed to run on your device, the program will start and you're ready to play!

---------------------------------------------------------------------------------------------------------------------------------------

### Manual Set-up
If you'd rather set up your environment manually to run the project you can do so with the following steps:

**Note:** If you're on Windows it's recommended that you first create a subsystem for Linux within your Windows environment and then follow the steps for Linux. This is because some of the libraries used in the project, such as unistd.h and ncurses, aren't directly supported in Windows. You can learn how to do that here: https://learn.microsoft.com/en-us/windows/wsl/install

**Installing the necessary development tools**
- If you're on Linux then just download a package containing essential development tools with the package manager of your Linux distribution. E.g. on Ubuntu using apt: `sudo apt update && sudo apt install build-essential`
- On Mac install the Xcode Command Line Tools with: `xcode-select --install` which comes with the necessary development tools.

**Installing the ncurses programming library**

- Next, the ncurses programming library needs be installed in order to compile the game, as it takes advantage of the tools it provides to create text-based user interfaces.
- On Linux use the package manager of your distribution to install ncurses. E.g. on Ubuntu using apt: `sudo apt install libncurses-dev`
- On Mac first install the Homebrew package manager: `/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"` After this you can install ncurses with `brew install ncurses`

**Compile the files with Make**
- The development tools installed in the first step come with the Make utility which allows you to compile the project easily using the rules provided by the Makefile. This is as simple as typing `make all` into the command line. This will produce an executable file called "driver".

**Run the compiled executable**
- To run the compiled executable you can either type the full filepath to the executable in the terminal, or navigate to the same folder as the executable file and simply type `./driver`
