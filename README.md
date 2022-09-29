## Overview

cpp developint base program with docker & cmake

## Require Tools

- docker -v: 20.10.13
- docker-compose -v: 1.29.2

## Usage

### Initial settings

- `docker-compose build`
- `docker-compose run dev bash`  # if you want to check inside of the container

### Build(ubuntu18)

- `docker-compose up -d`
- `docker-compose exec dev cmake ..`
- `docker-compose exec dev make`
- `docker-compose exec dev ./src/my_app`  # execute app

### Lint(CppLint)
- `docker-compose exec dev cpplint ../src/exe/main.cpp`
- `docker-compose exec dev cpplint ../src/my_math_dll/my_math.cpp`
- `docker-compose exec dev cpplint ../src/my_math_dll/my_math.h`
- `docker-compose exec dev cpplint ../test/my_math_dll_test/my_math_test.cpp`
- `docker-compose exec dev cpplint ../src/hello_dll/hello.cpp`
- `docker-compose exec dev cpplint ../src/hello_dll/hello.h`
- `docker-compose exec dev cpplint ../test/hello_dll_test/hello_test.cpp`

### Tests(Google Tests)
- `docker-compose exec dev ctest --verbose`

### Others
- `docker-compose down`  # if finish developing
- `docker-compose ps`  # check docker image status

## References

- [c++ with docker](https://qiita.com/kai_kou/items/1f4b9a45a5d4d6788649)
- [coenvl/googletest
](https://hub.docker.com/r/coenvl/googletest/dockerfile)
- [Ceate better google test env](https://www.jonki.net/entry/2016/06/15/220029)
- [cpp development env widh docker](https://qiita.com/n-jun-k2/items/1b84b5b99351fb835035)
