FROM ubuntu:latest

MAINTAINER SeveirRoy

RUN apt-get update && \
    apt-get install wget gcc -y --no-install-recommends && \
    cd /home && \
    wget https://github.com/SeveirRoy/ioIntensiveApp/blob/master/ioIntensiveApp.c && \
    gcc -D -REENTRANT ioIntensiveApp.c -o ioIntensiveApp -lpthread 

CMD ["/home/ioIntensiveApp"]
    
