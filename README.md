## Overview

cpp sample program based on docker & cmake

## Tools

- docker -v: 20.10.13
- docker-compose -v: 1.29.2

## Usage

### Initial settings

- `docker-compose build`
- `docker-compose run dev bash`  # if you want to check inside of the container

### Build(cpp17 on ubuntu18)

- `docker-compose up -d`
- `docker-compose exec dev cmake ..`
- `docker-compose exec dev make`
- `docker-compose exec dev ./src/my_app`  # execute app

## Lint(CppLint)
- `docker-compose exec dev cpplint ../src/main.cpp`

## Tests(Google Tests)
- `docker-compose exec dev ctest --verbose`

## References

- [c++ with docker](https://qiita.com/kai_kou/items/1f4b9a45a5d4d6788649)
- [coenvl/googletest
](https://hub.docker.com/r/coenvl/googletest/dockerfile)
- [Ceate better google test env](https://www.jonki.net/entry/2016/06/15/220029)
- [cpp development env widh docker](https://qiita.com/n-jun-k2/items/1b84b5b99351fb835035)
