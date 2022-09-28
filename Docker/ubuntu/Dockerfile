FROM ubuntu:18.04

ENV GOOGLE_TEST_VERSION 1.12.0

RUN apt-get update \
  && apt-get install -y \
      build-essential \
      clang \
      cmake \
      curl \
      git \
      libssl-dev \
      python3-pip \
      vim \
  && pip3 install cpplint \
  && apt-get clean \
  && rm -r /var/lib/apt/lists/* \
  && mkdir /tmp/src

WORKDIR /tmp/src

RUN curl -OL https://github.com/google/googletest/archive/release-${GOOGLE_TEST_VERSION}.tar.gz \
    && tar -zxvf release-${GOOGLE_TEST_VERSION}.tar.gz \
    && mkdir ./googletest-release-${GOOGLE_TEST_VERSION}/build
WORKDIR /tmp/src/googletest-release-${GOOGLE_TEST_VERSION}/build
RUN cmake .. \
    && make \
    && make install

WORKDIR /tmp
RUN rm -rf ./src/
