FROM ubuntu:latest

MAINTAINER SeveirRoy

RUN apt-get update && \
    apt-get install git gcc -y --no-install-recommends && \
    cd /home && \
    git clone https://github.com/SeveirRoy/ioIntensiveApp.git && \
    cd ioIntensiveApp && \
    gcc -D -REENTRANT ioIntensiveApp.c -o ioIntensiveApp -lpthread 

CMD ["/home/ioIntensiveApp"]
    
