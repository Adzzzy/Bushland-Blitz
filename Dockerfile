FROM alpine
#use alpine linux instead of ubuntu for the base image
#alpine is more lightweight so things like updating the available package list will require much less time and downloads

LABEL Maintainer="Adam Rebes <https://github.com/Adzzzy>"

#temporarily become root to do elevated actions such as installs without requiring sudo
USER root

#copy the contents of the host machine's present working directory into the image's pwd with COPY . .
COPY . .
#.dockerignore file has been created to specify files that will be ignored in this copy step to reduce overall image size

#refresh available packages (alpine's package manager is apk) then install build-base (includes gcc & make) to use for c++ code compilation (--no-cache to keep the image size smaller)
RUN apk update && apk add --no-cache build-base ncurses-dev
#ncurses library is also installed as it is used for the text-based user interface of Bushland Blitz

#run the all command specified in the makefile. Compiles all the c++ and header files and then uses them to make the "driver" executable for the program
RUN make all

#Set user back to nobody so that the container doesn't have unnecessary permissions when running code
USER nobody

#The entrypoint for the docker container will be the driver executable.
ENTRYPOINT ["./driver"]