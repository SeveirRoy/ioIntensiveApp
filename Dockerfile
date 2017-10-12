FROM ubuntu:latest

MAINTAINER SeveirRoy

RUN cd /home && \
    git clone https://github.com/chenguolin/scrapy.git && \
    gcc -D -REENTRANT ioIntensiveApp.c -o ioIntensiveApp -lpthread 

CMD ["/home/ioIntensiveApp"]
    
