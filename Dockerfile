FROM ubuntu:18.04

RUN apt-get update \
  && apt-get install -y git build-essential cmake clang libssl-dev

RUN apt-get -y install python3-pip

RUN pip3 install cpplint
RUN apt-get install -y vim less

ENV LANG ja_JP.UTF-8
ENV LANGUAGE ja_JP:ja
ENV LC_ALL ja_JP.UTF-8
ENV TZ JST-9
ENV TERM xterm
