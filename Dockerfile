FROM ubuntu:18.04

RUN dpkg --add-architecture i386
RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y flex bison build-essential csh libxaw7-dev libc6:i386

# Cleanup
RUN apt-get autoremove && apt-get autoclean
RUN rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*
