FROM ubuntu:latest

MAINTAINER SeveirRoy

RUN apt-get update && \
    apt-get install wget gcc -y --no-install-recommends && \
    cd /home && \
    wget https://raw.githubusercontent.com/SeveirRoy/ioIntensiveApp/master/ioIntensiveApp.c --no-check-certificate && \
    xcode-select --install && \
    gcc -D_REENTRANT ioIntensiveApp.c -o ioIntensiveApp -lpthread 

CMD ["/home/ioIntensiveApp"]
    
