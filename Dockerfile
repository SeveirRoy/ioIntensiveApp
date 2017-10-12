FROM ubuntu:latest

MAINTAINER SeveirRoy

ADD ioIntensiveAPP.c /home

RUN cd /home && \
    gcc -D -REENTRANT ioIntensiveApp.c -o ioIntensiveApp -lpthread 

CMD ["/home/ioIntensiveApp"]
    
